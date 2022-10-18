// Prepared By:    Muhammad Wajahat Asif
// Reg No:         FA19 - BSE - 027
// Section:        BSE - 3A

package queue;

public class Queue 
{
    public static void main(String[] args) 
    {
        QueueClass q = new QueueClass();
        
        q.enQueue(2);
        q.enQueue(4);
        q.enQueue(6);
        q.enQueue(8);
        q.enQueue(10);
        q.show();
        System.out.println("Size : " + q.getSize());
       
        q.deQueue();
        q.deQueue();
        System.out.println("Size : " + q.getSize());
        q.show();
    
        q.enQueue(12);
        System.out.println("Size : " + q.getSize());
        q.show();
    }
}

class QueueClass
{
    int queue [] = new int [5];
    int size = 0;
    int front = 0;
    int rear = 0;
    
    public void enQueue (int data)
    {
        if (isFull())
        {
            System.out.println("Queue Overflow!");
        }
        else
        {
            queue [rear] = data;
            rear = (rear + 1) % queue.length;
            size++;
        }
    }
    
    public int deQueue ()
    {
        if (isEmpty())
        {
            System.out.println("Queue Underflow!");
            return 0;
        }
        int data = queue[front] = 0;
        front = (front + 1) % queue.length;
        size--;
        return data;
    }
    
    public boolean isFull ()
    {
        return getSize() == queue.length ;
    }
    
    public boolean isEmpty()
    {
        return getSize() <= 0;
    }
    
    public int getSize ()
    {
        return size;
    }
    
    public void show()
    {
        System.out.print("Elements : ");
 
//        for (int i = 0; i < size; i++)
//        {
//            System.out.print(queue [(front + i) % queue.length] + " ");
//        }
        
        for (int n : queue)
        {
            System.out.print(n + " ");
        }
        System.out.println();
    }
}

// Prepared By:    Muhammad Wajahat Asif
// Reg No:         FA19 - BSE - 027
// Section:        BSE - 3A