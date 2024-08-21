import java.util.Scanner;

import utils.AlgebraSolver;

public class Main
{
    public static void main(String[] args)
    {
        AlgebraSolver solver = new AlgebraSolver();
        Scanner sc = new Scanner(System.in);
        
        String algebra = new String();
        int variables_count = 0;
        while ((variables_count = sc.nextInt()) != 0)
        {   
            if (variables_count < 0)
            {
                algebra = sc.nextLine();
                System.out.println(solver.solveAlgebra(algebra, new int[0]));
            }
            else
            {
                int variables[] = new int[variables_count];
                for (int i = 0; i < variables_count; i++)
                {
                    variables[i] = sc.nextInt();
                }
    
                algebra = sc.nextLine();
                System.out.println(solver.solveAlgebra(algebra, variables));
            }
        }

        sc.close();
    }
}