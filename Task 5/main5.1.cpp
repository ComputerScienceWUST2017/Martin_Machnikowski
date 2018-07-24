#include<iostream>
#include <string>
#include <sstream>
#include <algorithm>

#ifndef nullptr
#define nullptr NULL
#endif

#define BENCHMARK

using namespace std;

void swap(int &a, int &b) {
  int tmp;
  tmp = b;
  b = a;
  a = tmp;
}


void showArray(int array[], int size){
  int *last = array + size;

  do {
    cout << *array++ << ',';
  } while (array < last);

  cout << endl;
}


void insertSortSlow(int arr[], int n) {
  int tmp;
  int j;

  --n;

  for (int i = n; i >= 0; --i) {
    for (j = i; j < n && arr[j + 1] < arr[j]; ++j) {
      tmp = arr[j];
      arr[j] = arr[j + 1];
      arr[j + 1] = tmp;
    }
  }
}

void insertSort(int arr[], int n) {
  int key;
  int j;

  --n;

  for (int i = n - 1; i >= 0; --i) {
    key = arr[i];

    for (j = i + 1; j <= n && arr[j] < key; ++j) {
      arr[j - 1] = arr[j];
    }

    arr[j - 1] = key;

    showArray(arr, n+1);

  }
}

void bubbleSort(int arr[], int n) {
  --n;

  for (int i = n; i > 0; --i) {
    for (int j = n; j > 0; --j) {
      if (arr[j] < arr [j - 1]) {
        swap(arr[j], arr[j - 1]);
      }
    }


    showArray(arr, n + 1);

  }
}

static int *miarr;
static int misize;

void merge(int*, int, int);

// RECURSIVE
void mergeSort(int arr[], int size) {
  if (size <= 1) {
    return;
  }

  int middle = size / 2;
  int *arr2 = arr + middle;

  mergeSort(arr, middle);
  mergeSort(arr2, size - middle);

  merge(arr, middle, size);


    showArray(miarr, misize);

}

void mergeSortIter(int arr[], int n)
{
  for (int slice = 1; slice <= n-1; slice *= 2)
  {
    for (int leftSide=0; leftSide<n-1; leftSide += 2 * slice)
    {
      int length = min(2 * slice, n - leftSide);

      if (slice >= length) {
        break;
      }

      merge(arr + leftSide, slice, length);
    }

    showArray(arr, n);

  }
}

void merge(int *arr, int middle, int size) {
  // Copy input arrays
  int tmp[size];
  copy(arr, arr + size, tmp);

  int *in = tmp;
  int *in2 = tmp + middle;

  // Pointers to the cells after arrays
  int *past = in2;
  int *past2 = tmp + size;

  // Copy until one array pass
  while (in != past && in2 != past2) {
    if (*in < *in2) {
      *arr++ = *in++;
    } else {
      *arr++ = *in2++;
    }
  }

  // Copy the rest
  while (in2 != past2) {
    *arr++ = *in2++;
  }
  while (in != past) {
    *arr++ = *in++;
  }
}

int * loadArray(int size){
  int *out = new int[size];

  for (int i = 0; i < size; ++i) {
    cin >> out[i];
  }

  return out;
}

bool isCommand(const string command,const char *mnemonic){
  return command==mnemonic;
}

// Test API
int main(){
  string line;
  string command;
  int size=0;
  cout << "START" << endl;
  while(true){
    getline(cin,line);
    std::stringstream stream(line);
    stream >> command;
    if(line=="" || command[0]=='#')
    {
      // ignore empty line and comment
      continue;
    }

    // copy line on output with exclamation mark
    cout << "!" << line << endl;;

    // change to uppercase
    command[0]=toupper(command[0]);
    command[1]=toupper(command[1]);

    // read next argument, one int size
    stream >> size;

    // one-argument command
    if(isCommand(command,"HA")){
      cout << "END OF EXECUTION" << endl;
      break;
    }

    if(isCommand(command,"IS")) //*
    {
      int *arr=loadArray(size);
      showArray(arr,size);
      insertSort(arr,size);
      continue;
    }

    if(isCommand(command,"BS")) //*
    {
      int *arr=loadArray(size);
      showArray(arr,size);
      bubbleSort(arr,size);
      continue;
    }

    if(isCommand(command,"MI")) //*
    {
      int *arr=loadArray(size);
      showArray(arr,size);
      miarr = arr;
      misize = size;
      mergeSortIter(arr,size);
      continue;
    }

    cout << "wrong argument in test: " << command << endl;
  }
  return 0;
}

