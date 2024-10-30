public class NthNodeFromEndOfLinkedlist {
  Node head;

  static class Node {
    int data;
    Node next;

    Node(int d) {
      this.data = d;
      this.next = null;
    }
  }

  int nthNodeFromEnd(Node head, int n) {
    Node temp = head;
    int len = 0;
    while (temp != null) {
      len++;
      temp = temp.next;
    }
    temp = head;
    if (len < n)
      return -1;
    for (int i = 1; i < len - n + 1; i++) {
      temp = temp.next;
    }
    return temp.data;

  }

  void printList() {
    Node temp = head;
    while (temp != null) {
      System.out.print(temp.data + " -> ");
      temp = temp.next;
    }
    System.out.print("Null");
  }

  public static void main(String[] args) {
    NthNodeFromEndOfLinkedlist nnfl = new NthNodeFromEndOfLinkedlist();
    nnfl.head = new Node(0);

    Node a = new Node(1);
    Node b = new Node(2);
    Node c = new Node(3);
    Node d = new Node(4);
    Node e = new Node(5);
    nnfl.head.next = a;
    a.next = b;
    b.next = c;
    c.next = d;
    d.next = e;
    System.out.println(nnfl.nthNodeFromEnd(a, 2));
    nnfl.printList();
  }
}