#include <iostream>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

using namespace std;


void quicksort(int *arr,int p, int r);
int partition(int *arr, int p, int r);
int median_partition(int *arr, int p, int r);
void median_quicksort(int *arr, int p, int r);
void median(int *,int, int);
void swap(int *,int *);

long int count = 0;

int main(){
	// srand(time(NULL));
	int arr[SIZE];
	int med_arr[SIZE];
	for (int i=0;i<SIZE;i++){
		// int num = rand()%1000; 
		int num = rand();
		arr[i] = num;
		med_arr[i]=num;
		// cout<<num<<" ";
	}

	int * a = arr;
	int * ma= med_arr;

	median_quicksort(ma,0,SIZE-1);
	long int  med_count = count;
	count =0;
	quicksort(a,0,SIZE-1);
	cout<<"Count :"<<count<<endl;

	
	cout<<"Median Count :"<<count<<endl;
	cout<<"Diff :"<<count-med_count<<endl;
	double perc_median = ((double)(count-med_count)/(double)count)*100;
	cout<<"median Percent: "<<perc_median<<"\%"<<endl;

	// cout<<"\n**********print out sorted array***********\n";
	// for (int i=0;i<SIZE;i++){
	// 	cout<<arr[i]<<" ";
	// }


	// cout<<"\n**********print out median sorted array***********\n";
	// for (int i=0;i<SIZE;i++){
	// 	cout<<med_arr[i]<<" ";
	// }
	// cout<<endl;

	return 0;
}

//quicksort algorithm
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

//median quicksort
void median_quicksort(int *arr, int p, int r){
	if(p<r){
		int q = median_partition(arr,p,r);
		median_quicksort(arr, p,q-1);
		median_quicksort(arr, q+1, r);
	}
}

int median_partition(int * arr, int p, int r){
	median(arr,p,r);
	
	return partition(arr,p,r);
}



void median(int * arr,int p, int r){
	int center = (p+r)/2;
	if(arr[p]>arr[center])
		swap(&arr[p],&arr[center]);
	if(arr[p]>arr[r])
		swap(&arr[p],&arr[r]);
	if(arr[center]>arr[r])
		swap(&arr[center],&arr[p]);

	swap(&arr[center],&arr[r]);
}

void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}



