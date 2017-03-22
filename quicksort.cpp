#include <iostream>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

using namespace std;


void quicksort(int *arr,int p, int r);
int partition(int *arr, int p, int r);
void swap(int *,int *);

static long int count = 0;

int main(){
	//srand(time(NULL));
	int arr[SIZE];
	for (int i=0;i<SIZE;i++){
		int num = rand()%1000;
		arr[i] = num;
		cout<<num<<" ";
	}

	int * a = arr;

	quicksort(&arr,0,SIZE-1);

	cout<<"Count :"<<count<<endl;

	cout<<"\n**********print out sorted array***********\n";
	for (int i=0;i<SIZE;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	return 0;
}

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

void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}