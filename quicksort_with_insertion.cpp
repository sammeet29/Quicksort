
#include <iostream>
#include <stdlib.h>
#include <time.h>

#define SIZE 100000

using namespace std;

void insertion_sort(int *arr, int size);
void quicksort(int *arr,int p, int r);
void quicksort_with_insertion(int *arr, int p, int r);
void insertion_sort(int *arr, int p,int r);
int partition(int *arr, int p, int r);
void swap(int *,int *);

long int count = 0;

int main(){
	srand(time(NULL));
	int arr[SIZE];
	int ins_arr[SIZE];

	for (int i=0;i<SIZE;i++){
		int num = rand();
		// int num = rand()%1000;
		arr[i] = num;
		ins_arr[i] = num;
		// cout<<num<<" ";
	}

	int * a = arr;
	int * ins_a = ins_arr;
	quicksort_with_insertion(ins_a,0,SIZE-1);
	long int ins_count = count;
	count = 0;
	quicksort(a,0,SIZE-1);



	cout<<"insertion Count :"<<ins_count<<endl;
	cout<<"quicksort count :"<<count<<endl;
	cout<<"Diff :"<<count-ins_count<<endl;
	double perc_ins= ((double)(count-ins_count)/(double)count)*100;
	cout<<"insertion Percent: "<<perc_ins<<"\%"<<endl;
	
	// cout<<"\n**********print out sorted array***********\n";
	// for (int i=0;i<SIZE;i++){
	// 	cout<<arr[i]<<" ";
	// }
	// cout<<endl;
	// cout<<"\n**********print out sorted array***********\n";
	// for (int i=0;i<SIZE;i++){
	// 	cout<<ins_arr[i]<<" ";
	// }
	// cout<<endl;

	return 0;
}

//quicksort algorithms

void quicksort(int *arr, int p, int r){
	if(p<r){
		int q = partition(arr,p,r);
		quicksort(arr, p,q-1);
		quicksort(arr, q+1, r);
	}
}

int partition(int * arr, int p, int r){
	int pivot = arr[r];
	int i = p - 1;
	for(int j=p;j<r;j++){
		count++;
		if(arr[j]<=pivot){
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[r]);
	return i+1;
}


//quicksort with insertion sort

void quicksort_with_insertion(int *arr, int p, int r){
	if((r-p)<10){
		insertion_sort(arr,p,r);
	}else{
		
		int q = partition(arr,p,r);
		quicksort_with_insertion(arr, p,q-1);
		quicksort_with_insertion(arr, q+1, r);		
	}
}

void insertion_sort(int *arr, int p, int r){
	for(int i =p; i<=r;i++){
		int x = arr[i];
		int j = i-1;
		while(j>=0 && arr[j]>x){
			count++;
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=x;
	}
}

void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}