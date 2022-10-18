package quicksort;

public class QuickSort 
{
    static int partition(int arr[], int low, int high) 
    { 
        int pivot = arr[high];  
        int i = low - 1; 
        for (int j = low; j < high; j++) 
        { 
            if (arr[j] < pivot) 
            { 
                i++; 
                int temp = arr[i]; 
                arr[i] = arr[j]; 
                arr[j] = temp; 
            } 
        }   
        int temp = arr[i + 1]; 
        arr[i + 1] = arr[high]; 
        arr[high] = temp; 
        
        return i+1; 
    } 

    static void Sort(int arr[], int low, int high) 
    { 
        if (low < high) 
        { 
            int pi = partition(arr, low, high); 
  
            Sort(arr, low, pi - 1);
            Sort(arr, pi + 1, high); 
        } 
    } 
  
    static void printArray(int [] a)
    {
        for (int i = 0; i < a.length; i++)
        {
            System.out.print(a[i] + " ");
        }
        System.out.println();
    }
    
    public static void main(String[] args)
    {
        int [] a = {8,4,6,9,2,3,1};
        
        System.out.print("Unsorted Array : ");        
        printArray(a);

        Sort(a, 0, a.length - 1);
        
        System.out.print("Sorted Array : ");
        printArray(a);
    }
}