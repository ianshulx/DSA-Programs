#include<iostream>
using namespace std;

void swap(int *a, int *b){

	 int temp= *a;
  	 *a = *b;
     *b=temp;
     
}

void printarray(int a[], int n)
{
	for (int i=0; i<n; i++){
		cout<<a[i]<<" ";
				
	}
	cout<<endl;
}

void selection(int a[], int n)
{
	for(int i=0; i<n-1; i++)
	{
		int min = i;
			for(int j = i+1; j<n; j++)
					  {
	     			   		 if(a[j]<a[min]){
							      			 		   		 	min=j;
								 }
	}
	
		swap(a[i], a[min]);
	
}
}

int main(){
	int a[]={5, 12, 10, 15, 2};
	int size = sizeof(a) / sizeof(a[0]);
	selection(a, size);
	cout<<"array in assending order is";
	printarray(a, size);
	return 0;
	
	
	
}