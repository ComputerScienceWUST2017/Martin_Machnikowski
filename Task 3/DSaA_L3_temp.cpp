#include<iostream>
#include <string>
#include <sstream>

using namespace std;


// Two-way unordered cycled list without sentinel
struct Element{
};

struct List2W{
};

void init(List2W& l){
}

void insertHead(List2W& l, int x){
}

bool deleteHead(List2W& l, int &value){
	return false;
}

void insertTail(List2W& l, int x){
}

bool deleteTail(List2W& l, int &value){
	return false;
}

int findValue(List2W& l, int value){
	return -1; 
}

void removeAllValue(List2W& l, int value){
}

void showListFromHead(List2W& l){
}

void showListFromTail(List2W& l){
}

void clearList(List2W& l){
}

void addList(List2W& l1,List2W& l2){
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
	List2W *list;
	int currentL=0;
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

		if(isCommand(command,"HA")){
			cout << "END OF EXECUTION" << endl;
			break;
		}


		// zero-argument command
		if(isCommand(command,"DH")) //*
		{
			int retValue;
			bool retBool=deleteHead(list[currentL],retValue);
			if(retBool)
				cout << retValue << endl;
			else
				showBool(retBool);
			continue;
		}
		if(isCommand(command,"DT")) //*
		{
			int retValue;
			bool retBool=deleteTail(list[currentL],retValue);
			if(retBool)
				cout << retValue << endl;
			else
				showBool(retBool);
			continue;
		}

		if(isCommand(command,"SH")) //*
		{
			showListFromHead(list[currentL]);
			continue;
		}

		if(isCommand(command,"ST")) //*
		{
			showListFromTail(list[currentL]);
			continue;
		}

		if(isCommand(command,"CL")) //*
		{
			clearList(list[currentL]);
			continue;
		}

		if(isCommand(command,"IN")) //*
		{
			init(list[currentL]);
			continue;
		}

		// read next argument, one int value
		stream >> value;
		
		if(isCommand(command,"FV")) //*
		{
			int ret;
			ret=findValue(list[currentL],value);
			cout << ret << endl;
			continue;
		}

		if(isCommand(command,"RV")) //*
		{
			removeAllValue(list[currentL],value);
			continue;
		}


		if(isCommand(command,"AD")) //*
		{
			addList(list[currentL],list[value]);
			continue;
		}

		if(isCommand(command,"CH")) //*
		{
			currentL=value;
			continue;
		}

		if(isCommand(command,"IH")) //*
		{
			insertHead(list[currentL],value);
			continue;
		}

		if(isCommand(command,"IT")) //*
		{
			insertTail(list[currentL],value);
			continue;
		}

		if(isCommand(command,"GO")) //*
		{
			list=new List2W[value];
			continue;
		}

		cout << "wrong argument in test: " << command << endl;
	}
}
