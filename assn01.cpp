#include <iostream>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

using namespace std;

void insertion_sort(int *arr, int size);
void quicksort(int *arr,int p, int r);


int main(){
	int arr[SIZE];
	for (int i=0;i<SIZE;i++){
		int n = rand();
		cout<<n<<" ";
	}
	return 0;
}