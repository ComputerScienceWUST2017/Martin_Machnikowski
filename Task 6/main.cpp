#include <iostream>
#include <string.h>
#include <cstdlib>
#include <time.h>       /* clock_t, clock, CLOCKS_PER_SEC */
#include <cstdio>

using namespace std;

void insertSort(int array[], int size){
	int procent = size/100;
	int bufor;
	for(int i = size-2; i>=0; i--)
	{
		int j=size-1;
		bufor = array[i];
		while (j>i && bufor<array[j])
			j--;
		for (int k=i;k<j;k++)
		{
			array[k]=array[k+1];
		}
		array[j]=bufor;
		//if (i%procent==0) cout<<i/procent<<endl;
	}
}

void bubbleSort(int array[], int size){

	for(int i = 0; i<size-1; i++)
	{
		bool isChanged = false;
		for (int j = size - 1; j>i ; j--)
		{
			if (array[j] < array[j-1])
			{
				swap(array[j],array[j-1]);
				isChanged = true;
			}

		}

		//if (!isChanged) return;
	}
}
void bubbleSort2(int array[], int size){

	for(int i = 0; i<size-1; i++)
	{
		bool isChanged = false;
		for (int j = size - 1; j>i ; j--)
		{
			if (array[j] < array[j-1])
			{
				swap(array[j],array[j-1]);
				isChanged = true;
			}

		}

		if (!isChanged) return;
	}
}

int * loadArray(int size){
	int* a = new int[size];
	for (int i = 0; i < size; i++)
		a[i] = 4;

	return a;
}

void mergeArr(int arr[], int arrAux[], int nFrom, int nCenter, int nTo)
{
	if (nTo-nFrom == 1)
	{
		//cout<<"Index "<<nFrom<<" is alone. Leaving in peace"<<endl;
		return;
	}
	if (nTo-nFrom == 2)
	{
		if (arr[nFrom]>arr[nTo-1])
		{
			swap(arr[nFrom],arr[nTo-1]);
			//cout<<"Swapping indexes "<<nFrom<<" with "<<nTo-1<<endl;
		}
		//else cout<<"Comparing "<<nFrom<<" with "<<nTo-1<<" = correct order"<<endl;
		return;
	}

	int i=nFrom,j=nCenter,k=0;
	/*cout<<"Merging phase - ";
	for (i;i<j;i++) cout<<arr[i]<<", ";
	cout<<"with: ";
	for (j;j<nTo;j++) cout<<arr[j]<<", ";
	cout<<endl;

	i=nFrom;
	j=nCenter;*/

	while (i<nCenter && j<nTo)
	{
		if (arr[i]<arr[j])
		{
			arrAux[k]=arr[i];
			i++;
		}
		else
		{
			arrAux[k]=arr[j];
			j++;
		}
		k++;
	}
	while (j<nTo)
	{
		arrAux[k] = arr[j];
		j++;
		k++;
	}
	while (i<nCenter)
	{
		arrAux[k] = arr[i];
		i++;
		k++;
	}

	for(int z=0;z<k;z++)
	{
		arr[nFrom]=arrAux[z];
		nFrom++;
	}

}

void auxMergeSort(int arr[],int arrAux[], int nFrom, int nTo)
{
	if(nFrom<nTo-1)
	{
		int nCenter=(nFrom+nTo)/2;
		auxMergeSort(arr,arrAux,nFrom,nCenter);
		auxMergeSort(arr,arrAux,nCenter,nTo);
		mergeArr(arr,arrAux,nFrom,nCenter,nTo);
	}
}

void mergeSort(int arr[],int len)
{
	int *arr2=new int[len];
	auxMergeSort(arr,arr2,0,len);
	delete []arr2;
}

void sortings(int size, int loop)
{
	cout<<"---------------Loading "<<size<<" elements "<<loop<<" times-----------"<<endl;

	//INSERTSORT
	clock_t calosc = clock();
	for(int i=0; i<loop; i++)
	{
		clock_t t;
		t = clock();
		insertSort(loadArray(size),size);
		t = clock() - t;
	}
	calosc = clock() - calosc;
	//printf ("Insertsort: %d clicks (%f seconds).\n",calosc,((float)calosc)/CLOCKS_PER_SEC);
	printf("Insertsort: %f seconds average.\n\n",(((float)calosc)/CLOCKS_PER_SEC)/loop);

	// BUBBLESORT 1
	 calosc = clock();
	for(int i=0; i<loop; i++)
	{
		clock_t t;
		t = clock();
		bubbleSort(loadArray(size),size);
		t = clock() - t;
	}
	calosc = clock() - calosc;
	//printf ("Bubblesort: %d clicks (%f seconds).\n",calosc,((float)calosc)/CLOCKS_PER_SEC);
	printf ("Bubblesort: %f seconds average.\n\n",(((float)calosc)/CLOCKS_PER_SEC)/loop);

	//MERGESORT
	calosc = clock();
	for(int i=0; i<loop; i++)
	{
		clock_t t;
		t = clock();
		mergeSort(loadArray(size),size);
		t = clock() - t;
	}
	calosc = clock() - calosc;
	//printf ("Mergesort: %d clicks (%f seconds).\n",calosc,((float)calosc)/CLOCKS_PER_SEC);
	printf ("Mergesort: %f seconds average.\n\n",(((float)calosc)/CLOCKS_PER_SEC)/loop);
}
int main()
{
	sortings(100,2000);
	sortings(500,2000);
	sortings(1000,200);
	sortings(5000,100);
	sortings(10000,10);
	sortings(50000,2);
	sortings(100000,1);


	system("pause");
	return 1;
}
