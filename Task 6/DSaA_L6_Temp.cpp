#include<iostream>
#include <string>
#include <sstream>

using namespace std;


struct Heap{
	int *arr;
	int size;
	int pos;
};

void init(Heap& h, int size){
}

void heapAdjustment(Heap &h){
}

void loadAndMakeHeap(Heap &h, int howMany){
}


void add(Heap &h, int value){
}


void makeSorted(Heap& h){
}

void show(Heap& h){
  for(int i=0;i<h.pos;i++)
  {
	  cout << h.arr[i] << ",";
  }
  cout << endl;
}


void showBool(bool val){
	if(val)
		cout << "true" << endl;
	else
		cout << "false" << endl;
}

bool isCommand(const string command,const char *mnemonic){
	return command==mnemonic;
}

int main(){
	string line; 
	string command;
	Heap *heap;
	int currentH=0;
	int value;
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

		// zero-argument command
		if(isCommand(command,"HA")){
			cout << "END OF EXECUTION" << endl;
			break;
		}

		if(isCommand(command,"SH")) //*
		{
			show(heap[currentH]);
			continue;
		}

		if(isCommand(command,"MS")) //*
		{
			makeSorted(heap[currentH]);
			continue;
		}

		// read next argument, one int value
		stream >> value;
		
		if(isCommand(command,"IN")) //*
		{
			init(heap[currentH],value);
			continue;
		}

		if(isCommand(command,"LD")) 
		{
			loadAndMakeHeap(heap[currentH],value);
			continue;
		}

		if(isCommand(command,"AD")) 
		{
			add(heap[currentH],value);
			continue;
		}

		if(isCommand(command,"CH")) 
		{
			currentH=value;
			continue;
		}

		if(isCommand(command,"GO")) 
		{
			heap=new Heap[value];
			continue;
		}

		cout << "wrong argument in test: " << command << endl;
	}
	return 0;
}
