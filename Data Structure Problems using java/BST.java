public class BST {
    class Node {
        int key;
        Node left, right;

        public Node(int item) {
            key = item;
            left = right = null;
        }
    }

    private Node root;

    public BST() {
        root = null;
    }

    public void insert(int key) {
        if (root == null) {
            root = new Node(key);
        } else {
            insertnode(this.root, key);
        }
    }

    public Node insertnode(Node root, int key) {
        if (root == null) {
            root = new Node(key);
            return root;
        } else if (key < root.key) {
            root.left = insertnode(root.left, key);
        } else {
            root.right = insertnode(root.right, key);
        }
        return root;
    }

    public Node deletenode(Node root, int k) {

        if (root == null)
            return root;
        if (root.key > k) {
            root.left = deletenode(root.left, k);
            return root;
        } else if (root.key < k) {
            root.right = deletenode(root.right, k);
            return root;
        }
        if (root.left == null) {
            Node temp = root.right;
            return temp;
        } else if (root.right == null) {
            Node temp = root.left;
            return temp;
        } else {
            Node succParent = root;
            Node succ = root.right;
            while (succ.left != null) {
                succParent = succ;
                succ = succ.left;
            }
            if (succParent != root)
                succParent.left = succ.right;
            else
                succParent.right = succ.right;
            root.key = succ.key;
            return root;
        }
    }

    public void Inorder() {
        Inorderrec(this.root);
    }

    public void Inorderrec(Node root) {
        if (root != null) {
            Inorderrec(root.left);
            System.out.print(root.key + " ");
            Inorderrec(root.right);
        }
    }

    public static void main(String[] args) {
        BST b = new BST();
        b.insert(10);
        b.insert(12);
        b.insert(1);
        b.insert(100);
        System.out.println("Before Delete");
        b.Inorder();
        b.deletenode(b.root, 12);
        System.out.println();
        System.out.println("After Delete");
        b.Inorder();
    }
}