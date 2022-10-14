public class QuickSort {
    static int ar[] = { 10, 7, 8, 9, 1, 5 };

    public static void quicksort(int l, int r) {
        if (l < r) {
            int mid = partition(l, r);
            quicksort(l, mid - 1);
            quicksort(mid + 1, r);
        }
    }

    public static int partition(int l, int r) {
        int pivot = ar[r];
        int i = (l - 1);

        for (int j = l; j <= r - 1; j++) {
            if (ar[j] < pivot) {
                i++;
                int temp = ar[i];
                ar[i] = ar[j];
                ar[j] = temp;
            }
        }
        int temp = ar[i + 1];
        ar[i + 1] = ar[r];
        ar[r] = temp;
        return (i + 1);
    }

    public static void main(String[] args) {
        System.out.println("Before Sorting");
        for (Integer integer : ar) {
            System.out.print(integer + " ");
        }
        System.out.println();
        quicksort(0, ar.length - 1);
        System.out.println("After Sorting");
        for (Integer integer : ar) {
            System.out.print(integer + " ");
        }
        System.out.println();
    }

}