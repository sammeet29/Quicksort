#include <iostream>
#include <stdlib.h>
#include <time.h>

#define SIZE 100000

using namespace std;


void quicksort(int *arr,int p, int r);
int partition(int *arr, int p, int r);
void random_quicksort(int *arr,int p, int r);
int random_partition(int *arr, int p, int r);
void swap(int *,int *);

static long int count = 0;
static long int rand_count =0;

int main(){
	srand(time(NULL));
	int arr[SIZE];
	int ran_arr[SIZE];
	for (int i=0;i<SIZE;i++){
		// int num = rand()%1000; 
		int num = rand();
		arr[i] = num;
		ran_arr[i]=num;
		// cout<<num<<" ";
	}

	int * a = arr;
	int * ra= ran_arr;

	random_quicksort(ra,0,SIZE-1);
	rand_count = count;
	count =0;
	quicksort(a,0,SIZE-1);
	cout<<"Count :"<<count<<endl;

	
	cout<<"Randomized Count :"<<rand_count<<endl;
	cout<<"Diff :"<<count-rand_count<<endl;
	double perc_rand = ((double)(count-rand_count)/(double)count)*100;
	cout<<"Randomized Percent: "<<perc_rand<<"\%"<<endl;

	// cout<<"\n**********print out sorted array***********\n";
	// for (int i=0;i<SIZE;i++){
	// 	cout<<arr[i]<<" ";
	// }


	// cout<<"\n**********print out random sorted array***********\n";
	// for (int i=0;i<SIZE;i++){
	// 	cout<<ran_arr[i]<<" ";
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

void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}


//quicksort with random pivot selection

void random_quicksort(int *arr, int p, int r){
	if(p<r){
		int q = random_partition(arr,p,r);
		random_quicksort(arr, p,q-1);
		random_quicksort(arr, q+1, r);
	}
}

int random_partition(int * arr, int p, int r){
	int n = (rand()%(r-p))+p;
	//cout<<"n:"<<n<<endl;
	swap(&arr[n],&arr[r]);
	int pivot = partition(arr,p,r);
	return pivot;
}
