import java.util.Scanner;

class Node {
    int element;
    int h;
    Node leftChild;
    Node rightChild;

    public Node() {
        leftChild = null;
        rightChild = null;
        element = 0;
        h = 0;
    }

    public Node(int element) {
        leftChild = null;
        rightChild = null;
        this.element = element;
        h = 0;
    }
}

class ConstructAVLTree {
    private Node rootNode;

    public ConstructAVLTree() {
        rootNode = null;
    }

    public void removeAll() {
        rootNode = null;
    }

    public boolean checkEmpty() {
        if (rootNode == null)
            return true;
        else
            return false;
    }

    public void insertElement(int element) {
        rootNode = insertElement(element, rootNode);
    }

    private int getHeight(Node node) {
        return node == null ? -1 : node.h;
    }

    private int getMaxHeight(int leftNodeHeight, int rightNodeHeight) {
        return leftNodeHeight > rightNodeHeight ? leftNodeHeight : rightNodeHeight;
    }

    private Node insertElement(int element, Node node) {

        if (node == null)
            node = new Node(element);
        else if (element < node.element) {
            node.leftChild = insertElement(element, node.leftChild);
            if (getHeight(node.leftChild) - getHeight(node.rightChild) == 2)
                if (element < node.leftChild.element)
                    node = rotateWithLeftChild(node);
                else
                    node = doubleWithLeftChild(node);
        } else if (element > node.element) {
            node.rightChild = insertElement(element, node.rightChild);
            if (getHeight(node.rightChild) - getHeight(node.leftChild) == 2)
                if (element > node.rightChild.element)
                    node = rotateWithRightChild(node);
                else
                    node = doubleWithRightChild(node);
        } else
            ;
        node.h = getMaxHeight(getHeight(node.leftChild), getHeight(node.rightChild)) + 1;

        return node;

    }

    private Node rotateWithLeftChild(Node node2) {
        Node node1 = node2.leftChild;
        node2.leftChild = node1.rightChild;
        node1.rightChild = node2;
        node2.h = getMaxHeight(getHeight(node2.leftChild), getHeight(node2.rightChild)) + 1;
        node1.h = getMaxHeight(getHeight(node1.leftChild), node2.h) + 1;
        return node1;
    }

    private Node rotateWithRightChild(Node node1) {
        Node node2 = node1.rightChild;
        node1.rightChild = node2.leftChild;
        node2.leftChild = node1;
        node1.h = getMaxHeight(getHeight(node1.leftChild), getHeight(node1.rightChild)) + 1;
        node2.h = getMaxHeight(getHeight(node2.rightChild), node1.h) + 1;
        return node2;
    }

    private Node doubleWithLeftChild(Node node3) {
        node3.leftChild = rotateWithRightChild(node3.leftChild);
        return rotateWithLeftChild(node3);
    }

    private Node doubleWithRightChild(Node node1) {
        node1.rightChild = rotateWithLeftChild(node1.rightChild);
        return rotateWithRightChild(node1);
    }

    public int getTotalNumberOfNodes() {
        return getTotalNumberOfNodes(rootNode);
    }

    private int getTotalNumberOfNodes(Node head) {
        if (head == null)
            return 0;
        else {
            int length = 1;
            length = length + getTotalNumberOfNodes(head.leftChild);
            length = length + getTotalNumberOfNodes(head.rightChild);
            return length;
        }
    }

    public boolean searchElement(int element) {
        return searchElement(rootNode, element);
    }

    private boolean searchElement(Node head, int element) {
        boolean check = false;
        while ((head != null) && !check) {
            int headElement = head.element;
            if (element < headElement)
                head = head.leftChild;
            else if (element > headElement)
                head = head.rightChild;
            else {
                check = true;
                break;
            }
            check = searchElement(head, element);
        }
        return check;
    }

    public void inorderTraversal() {
        inorderTraversal(rootNode);
    }

    private void inorderTraversal(Node head) {
        if (head != null) {
            inorderTraversal(head.leftChild);
            System.out.print(head.element + " ");
            inorderTraversal(head.rightChild);
        }
    }

    public void preorderTraversal() {
        preorderTraversal(rootNode);
    }

    private void preorderTraversal(Node head) {
        if (head != null) {
            System.out.print(head.element + " ");
            preorderTraversal(head.leftChild);
            preorderTraversal(head.rightChild);
        }
    }

    public void postorderTraversal() {
        postorderTraversal(rootNode);
    }

    private void postorderTraversal(Node head) {
        if (head != null) {
            postorderTraversal(head.leftChild);
            postorderTraversal(head.rightChild);
            System.out.print(head.element + " ");
        }
    }
}

public class AVLTree {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        ConstructAVLTree obj = new ConstructAVLTree();

        char choice;

        do {
            System.out.println("\nSelect an operation:\n");
            System.out.println("1. Insert a node");
            System.out.println("2. Search a node");
            System.out.println("3. Get total number of nodes in AVL Tree");
            System.out.println("4. Is AVL Tree empty?");
            System.out.println("5. Remove all nodes from AVL Tree");
            System.out.println("6. Display AVL Tree in Post order");
            System.out.println("7. Display AVL Tree in Pre order");
            System.out.println("8. Display AVL Tree in In order");

            // get choice from user
            int ch = sc.nextInt();
            switch (ch) {
                case 1:
                    System.out.println("Please enter an element to insert in AVL Tree");
                    obj.insertElement(sc.nextInt());
                    break;
                case 2:
                    System.out.println("Enter integer element to search");
                    System.out.println(obj.searchElement(sc.nextInt()));
                    break;
                case 3:
                    System.out.println(obj.getTotalNumberOfNodes());
                    break;
                case 4:
                    System.out.println(obj.checkEmpty());
                    break;
                case 5:
                    obj.removeAll();
                    System.out.println("\nTree Cleared successfully");
                    break;
                case 6:
                    System.out.println("\nDisplay AVL Tree in Post order");
                    obj.postorderTraversal();
                    break;
                case 7:
                    System.out.println("\nDisplay AVL Tree in Pre order");
                    obj.preorderTraversal();
                    break;
                case 8:
                    System.out.println("\nDisplay AVL Tree in In order");
                    obj.inorderTraversal();
                    break;
                default:
                    System.out.println("\n ");
                    break;
            }
            System.out.println("\nPress 'y' or 'Y' to continue \n");
            choice = sc.next().charAt(0);
        } while (choice == 'Y' || choice == 'y');
    }
}