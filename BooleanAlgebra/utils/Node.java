package utils;

public class Node
{
    private char data;
    private Node next;

    public Node(char data, Node next)
    {
        this.data = data;
        this.next = next;
    }

    public Node() {}

    // Getters
    public char getData() {return this.data;}
    public Node getNext() {return this.next;}

    // Setters
    public void setData(char data) {this.data = data;}
    public void setNext(Node next) {this.next = next;}
}
