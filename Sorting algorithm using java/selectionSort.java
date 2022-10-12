class SelectionSortProgram {  
    public static void selectionSortAlgorithm(int[] arr){    //Function to sort the array using selection sort
        for (int i = 0; i < arr.length - 1; i++)  
        {  
            int index = i;  
            for (int j = i + 1; j < arr.length; j++){  
                if (arr[j] < arr[index]){  //comparing values to find the smaller
                    index = j;
                }  
            }  
            int smallerNumber = arr[index];   
            arr[index] = arr[i];  
            arr[i] = smallerNumber;  
        }  
    }  
       
    public static void main(String a[]){   //Main function
        int[] arr1 = {9,14,3,2,43,11,58,22};  
        System.out.println("Before Selection Sort array \n");   //Loop to print the array before Selection Sort
        for(int i = 0; i < arr1.length - 1; i++){  
            System.out.print(arr1[i]+" ");  
        }  
        System.out.println();  
          
        selectionSortAlgorithm(arr1);  //Functional call and passing the array
         
        System.out.println(" \nAfter Selection Sort Array  \n");  
        for(int i = 0; i < arr1.length - 1; i++){   //Loop to print the array after Selection Sort 
            System.out.print(arr1[i]+" ");  
        }  
    }  
}  