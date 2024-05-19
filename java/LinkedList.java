public class LinkedList {
  public Node head;
  public int length;

  LinkedList() {
    this.head = null;
    this.length = 0;
  }

  String print() {
    Node node = this.head;
    String[] result;

    if (node == null) {
      return "null";
    } else {
      result = new String[this.length + 1];
      int i = 0;

      while (node != null) {
        result[i] = node.data + "";
        node = node.next;
        i++;
      }

      result[i] = "null";
    }

    return String.join("->", result);
  }

  void unshift(int data) {
    Node node = new Node(data);

    if (this.head == null) {
      this.head = node;
    } else {
      node.next = this.head;
      this.head = node;
    }

    this.length += 1;
  }

  void push(int data) {
    Node node = new Node(data);

    if (this.head == null) {
      this.head = node;
    } else {
      Node current = this.head;

      while (current != null) {
        if (current.next == null) {
          current.next = node;
          break;
        } else {
          current = current.next;
        }
      }
    }

    this.length += 1;
  }

  void shift() throws Exception {
    Node node = this.head;

    if (node == null) {
      throw new Exception("ZeroLengthException: Linked list length is zero");
    } else {
      this.head = node.next;
    }

    this.length -= 1;
  }

  void pop() throws Exception {
    Node node = this.head;

    if (node == null) {
      throw new Exception("ZeroLengthException: Linked list length is zero");
    } else {
      Node prev = null;

      while (node != null) {
        if (node.next == null) {
          prev.next = null;
          break;
        } else {
          prev = node;
          node = node.next;
        }
      }
    }

    this.length -= 1;
  }

  public static void main(String[] args) {
    LinkedList ll = new LinkedList();

    for (int i = 1; i <= 5; i++) {
      ll.unshift(i * 5);
    }

    System.out.println(ll.print() + ", length: " + ll.length);

    for (int i = 1; i <= 5; i++) {
      ll.push(i * 10);
    }

    System.out.println(ll.print() + ", length: " + ll.length);

    try {
      ll.shift();
    } catch(Exception err) {
      System.out.println(err.getMessage());
    }

    System.out.println(ll.print() + ", length: " + ll.length);

    try {
      ll.pop();
    } catch (Exception err) {
      System.out.println(err.getMessage());
    }

    System.out.println(ll.print() + ", length: " + ll.length);
  }
}

class Node {
  public int data;
  public Node next;

  Node(int data) {
    this.data = data;
    this.next = null;
  }
}
