package utils;

public class Stack 
{
    private Node top;

    public Stack() {
        this.top = null;
    }

    // Push
    public void push(char data)
    {
        Node new_node = new Node(data, this.top);
        this.top = new_node;
    }

    // Pop
    public char pop()
    {
        if (this.top == null)
        {
            throw new IllegalStateException("Stack is empty");
        }
        char data = this.top.getData();
        this.top = this.top.getNext();
        return data;
    }

    // Pop until get C
    public boolean popContains(char element)
    {
        boolean contain = false;

        while (!contain && top != null)
        {
            char popped = pop();
            if (popped == element)
            {
                contain = true;
            }
        }
        return contain;
    }

    // Height of the stack
    public int stackHeight()
    {
        int height = 0;
        Node temp = this.top;
        while (temp != null)
        {
            height++;
            temp = temp.getNext();
        }
        return height;
    }
}
