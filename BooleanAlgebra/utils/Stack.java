package utils;

public class Stack<T> 
{
    private Node<T> top;

    public Stack() {
        this.top = null;
    }

    // Push
    public void push(T data)
    {
        Node<T> new_node = new Node<>(data, this.top);
        this.top = new_node;
    }

    // Pop
    public T pop()
    {
        if (this.top == null)
        {
            throw new IllegalStateException("Stack is empty");
        }
        T data = this.top.getData();
        this.top = this.top.getNext();
        return data;
    }

    // Pop until get C
    public boolean popContains(T element)
    {
        boolean contain = false;

        while (!contain && top != null)
        {
            T popped = pop();
            if (popped.equals(element))
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
        Node<T> temp = this.top;
        while (temp != null)
        {
            height++;
            temp = temp.getNext();
        }
        return height;
    }
}
