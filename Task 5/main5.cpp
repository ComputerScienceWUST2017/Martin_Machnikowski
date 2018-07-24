#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

void showArray(int array[], int size)
{
    for(int i = 0 ; i < size ; i++)
    {
        cout<<array[i]<<",";
    }
    cout<<endl;
}

void insertSort(int array[], int size)
{
    int bufor;
    for(int i = size-2; i>=0; i--)
    {
        int j=size-1;
        bufor = array[i];
        while (j>i && bufor<array[j])
            j--;
        for (int k=i; k<j; k++)
        {
            array[k]=array[k+1];
        }
        array[j]=bufor;
        showArray(array,size);
    }
}

void bubbleSort(int array[], int size)
{

    for(int i = 0; i<size-1; i++)
    {
//        bool isChanged = false;
        for (int j = size - 1; j>i ; j--)
        {
            if (array[j] < array[j-1])
            {
                swap(array[j],array[j-1]);
//                isChanged = true;
            }

        }
        showArray(array,size);
    }
}

void mergeArr(int arr[], int arrAux[], int nFrom, int nCenter, int nTo)
{
    if (nTo-nFrom == 1)
    {
        return;
    }
    if (nTo-nFrom == 2)
    {
        if (arr[nFrom]>arr[nTo-1])
        {
            swap(arr[nFrom],arr[nTo-1]);
        }
        return;
    }

    int i=nFrom,j=nCenter,k=0;

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

    for(int z=0; z<k; z++)
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

void merge(int*arr,int left,int mid,int right){
    int l=left,r=mid+1,k=0;
    int *tempArr=new int[right-left+1];

    while(l<=mid && r<=right){
        if(arr[l]<=arr[r]){
            tempArr[k]=arr[l];
            ++l;
        }
        else{
            tempArr[k]=arr[r];
            ++r;
        }
        ++k;
    }

    while(l<=mid){
        tempArr[k]=arr[l];
        ++l;
        ++k;
    }

    while(r<=right){
        tempArr[k]=arr[r];
        ++r;
        ++k;
    }

    k=0;
    for(int i=left;i<=right;++i,++k){
        arr[i]=tempArr[k];
    }

        delete[] tempArr;

}


void mergeSortIter(int array[], int size)
{
    int width,left,mid,right;

    for (width=1; width<=size-1; width*=2)
    {

        for (left=0; left<size-1; left+=2*width)
        {
            right = left+2*width-1;
            if(right>size-1)
            {
                right=size-1;
            }

            mid=left+width-1;

            if(mid<=right)
            {
                merge(array,left,mid,right);
            }


        }
        showArray(array,size);
    }
}

int * loadArray(int size)
{
    int* a = new int[size];
    for (int i = 0; i < size; i++)
        cin >> a[i];
    return a;
}

bool isCommand(const char *command,const char *mnemonic)
{
    return strcmp(command,mnemonic)==0;
}

int main()
{
    const int commandSize=2;
    const int MAXLINE=100;
    char line[MAXLINE];
    char command[commandSize+1]; // for '\0'
    int size;
    command[commandSize]='\0';
    while(true)
    {
        cin >> command[0];
        if(command[0]=='#')
        {
            cin.getline(line, MAXLINE);
            continue;
        }
        cin >> command[1];

        if(isCommand(command,"HA"))
        {
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
            showArray(arr,size);
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
        if(isCommand(command,"MI"))
        {
            int *arr=loadArray(size);
            showArray(arr,size);
            mergeSortIter(arr,size);
            continue;
        }
        cout << "wrong argument in test: " << command << endl;
        return 1;
    }
}
