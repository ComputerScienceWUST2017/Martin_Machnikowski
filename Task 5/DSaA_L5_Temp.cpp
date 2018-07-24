#include<iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

void showArray(int array[], int size){
}

void insertSort(int array[], int size){
}

void bubbleSort(int array[], int size){
}


void mergeSortIter(int array[], int size){
}

int * loadArray(int size){
	// TODO !!!
	return NULL;
}

bool isCommand(const string command,const char *mnemonic){
	return command==mnemonic;
}

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
			mergeSortIter(arr,size);
			continue;
		}

		cout << "wrong argument in test: " << command << endl;
	}
	return 0;
}
