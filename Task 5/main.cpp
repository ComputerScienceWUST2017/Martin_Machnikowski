//joanna zawislan
#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

void showArray(int array[], int size){
	for(int i = 0 ; i < size ; i++)
	{
		cout<<array[i]<<",";
	}
	cout<<endl;
}

void insertSort(int array[], int size){
	int bufor;
	for(int i = size-1; i>=0; i--)
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
		showArray(array,size);
	}
}

void bubbleSort(int array[], int size){
	int temp;
	for(int i = 0; i<size-1; i++)
	{
		for (int j = 0; j<size-1; j++)
		{
			if (array[j] > array[j+1])
			{
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
		showArray(array,size);
	}
}

void mergeArr(int arr[], int arrAux[], int nFrom, int nCenter, int nTo)
{
	if (nTo-nFrom == 1)
	{
		cout<<"Index "<<nFrom<<" is alone. Leaving in peace"<<endl;
		return;
	}
	if (nTo-nFrom == 2)
	{
		if (arr[nFrom]>arr[nTo-1])
		{
			swap(arr[nFrom],arr[nTo-1]);
			cout<<"Swapping indexes "<<nFrom<<" with "<<nTo-1<<endl;
		}
		else cout<<"Comparing "<<nFrom<<" with "<<nTo-1<<" = correct order"<<endl;
		return;
	}

	int i=nFrom,j=nCenter,k=0;/*
	cout<<"Merging phase - ";
	for (i;i<j;i++) cout<<arr[i]<<", ";
	cout<<"with: ";
	for (j;j<nTo;j++) cout<<arr[j]<<", ";
	cout<<endl;*/

	i=nFrom;
	j=nCenter;

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

int * loadArray(int size){
	int *data = new int[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = rand()%100;
	}
	return data;
}

//int * loadArray(int size){
//	int* a = new int[size];
//	for (int i = 0; i < size; i++)
//		cin >> a[i];
//	return a;
//}

bool isCommand(const char *command,const char *mnemonic){
	return strcmp(command,mnemonic)==0;
}

int main(){
	const int commandSize=2;
	const int MAXLINE=100;
	char line[MAXLINE];
	char command[commandSize+1]; // for '\0'
	int size;
	command[commandSize]='\0';
	while(true){
		cin >> command[0];
		if(command[0]=='#')
		{
			cin.getline(line, MAXLINE);
			continue;
		}
		cin >> command[1];

		if(isCommand(command,"HA")){
			cout << "END OF EXECUTION" << endl;
			break;
		}

		// read next argument, one int value
		cin >> size;

		if(isCommand(command,"IS"))
		{
			cout << "insertSort" << endl;
			int *arr=loadArray(size);
			showArray(arr,size);
			insertSort(arr,size);
			continue;
		}

		if(isCommand(command,"BS"))
		{
			cout << "bubbleSort" << endl;
			int *arr=loadArray(size);
			//showArray(arr,size);
			bubbleSort(arr,size);
			continue;
		}

		if(isCommand(command,"MS"))
		{
			cout << "mergeSort" << endl;
			int *arr=loadArray(size);
			showArray(arr,size);
			mergeSort(arr,size);
			showArray(arr,size);
			continue;
		}

		cout << "wrong argument in test: " << command << endl;
		return 1;
	}
}
