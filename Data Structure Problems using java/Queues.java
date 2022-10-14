import java.util.LinkedList;
import java.util.Queue;
import java.util.*;

public class Queues {

    public static void main(String[] args) {
        Queue<Integer> q = new LinkedList<>();
        Scanner sc = new Scanner(System.in);

        int size = q.size();
        System.out.println("Initial size of queue- " + size);
        System.out.print("Enter the size of queue- ");
        int n = sc.nextInt();
        System.out.print("Enter the elements of the queue- ");
        for (int i = 0; i < n; i++) {
            int x = sc.nextInt();
            q.add(x);
        }

        System.out.println("Elements of queue " + q);

        int head = q.peek();
        System.out.println("head of queue- " + head);

        int removedelement = q.remove();
        System.out.println("removed element- " + removedelement);

        System.out.println("Modified queue after removing an element " + q);

        int head1 = q.peek();
        System.out.println("head of queue- " + head1);

        int size1 = q.size();
        System.out.println("Size of modified queue- " + size1);

        System.out.print("Enter new element to queue- ");
        int x = sc.nextInt();
        q.add(x);

        System.out.println("Modified queue after adding new element " + q);
        int size2 = q.size();
        System.out.println("Size of modified queue- " + size2);
        sc.close();
    }
}
