package utils;

public class Node<T> {
    private T data;
    private Node<T> next;

    public Node(T data, Node<T> next) {
        this.data = data;
        this.next = next;
    }

    public Node() {}

    // Getters
    public T getData() { return this.data; }
    public Node<T> getNext() { return this.next; }

    // Setters
    public void setData(T data) { this.data = data; }
    public void setNext(Node<T> next) { this.next = next; }
}
