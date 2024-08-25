package utils;

public class AlgebraSolver
{
    private Stack eval_stack;

    public AlgebraSolver()
    {
        this.eval_stack = new Stack();
    }

    // Solve the expression
    public char solveAlgebra(String algebra, int[] variables)
    {
        algebra = formatExpression(algebra, variables);
        char[] algebra_array = algebra.toCharArray();

        for (char c : algebra_array)
        {
            if (c == ')')
            {
                this.eval_stack.push(solveSubexpression());
            }
            else
            {
                this.eval_stack.push(c);
            }
        }

        return this.eval_stack.pop();
    }

    // Solve a Subexpression
    private char solveSubexpression()
    {
        Stack aux_stack = new Stack();
        char c;
        while ((c = this.eval_stack.pop()) != '(')
        {
            aux_stack.push(c);
        }
        c = this.eval_stack.pop();
        switch(c){
            case 'a':
                c = aux_stack.popContains('0') ? '0' : '1';
                break;
            case 'o':
                c = aux_stack.popContains('1') ? '1' : '0';
                break;
            case 'n':
                c = aux_stack.popContains('0') ? '1' : '0';
                break;
        }

        return c;
    }


    // Just format the expression like: and(A, B, C) to -> a(110) (if A == 1, B == 1, C == 0)
    public String formatExpression(String algebra, int[] variables)
    {
        char[] result_array = algebra.toCharArray();
        int variables_count = variables.length;
        int algebra_length = algebra.length();
        int original_string_index = 0;
        int new_string_index = 0;

        while (original_string_index < algebra_length)
        {
            char c = result_array[original_string_index];
            int verify_substitution = (c - 'A');

            if (c == 'a' || c == 'n')
            {
                result_array[new_string_index++] = c;
                original_string_index += 3;
            }
            else if (c == 'o')
            {
                result_array[new_string_index++] = c;
                original_string_index += 2;
            }
            else if (verify_substitution >= 0 && verify_substitution < variables_count)
            {
                result_array[new_string_index++] = (char)(variables[(int)(c - 'A')] + '0');
                original_string_index++;
            }
            else if (c != ',' && c != ' ')
            {
                result_array[new_string_index++] = c;
                original_string_index++;
            }
            else
            {
                original_string_index++;
            }
        }

        return new String(result_array, 0, new_string_index);
    }
}
