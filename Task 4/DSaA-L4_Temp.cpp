#include<iostream>
#include <string>
#include <sstream>

using namespace std;


struct Element{
	int key;
	int value;
};

struct ElementLL{
	Element elem;
	ElementLL *next, *prev;
};

// Two-way ordered cycled list with sentinel
struct List2W{
	ElementLL *sentinel;
};

void init(List2W& l){
	l.sentinel=new ElementLL();
	l.sentinel->next=l.sentinel;
	l.sentinel->prev=l.sentinel;
}

void insertElem(List2W & l, Element elem){
}

bool findKey(List2W & l,int key, Element &elem){
		return false;
}

void removeAllKeys(List2W& l, int key){
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

		// zero-argument command
		if(isCommand(command,"HA")){
			cout << "END OF EXECUTION" << endl;
			break;
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

		if(isCommand(command,"FK"))
		{
			Element elem;
			bool ret=findKey(list[currentL], value, elem);
			if(ret)
				cout << elem.key << '(' << elem.value << ')' << endl;
			else
				cout << "false" << endl;
			continue;
		}

		if(isCommand(command,"RK"))
		{
			removeAllKeys(list[currentL],value);
			continue;
		}

		if(isCommand(command,"CH"))
		{
			currentL=value;
			continue;
		}

		if(isCommand(command,"IE"))
		{
			int variable2;
			stream >> variable2;
			Element elem;
			elem.key=value;
			elem.value=variable2;
			insertElem(list[currentL],elem);
			continue;
		}

		if(isCommand(command,"GO"))
		{
			list=new List2W[value];
			continue;
		}

		if(isCommand(command,"AD"))
		{
			addList(list[currentL],list[value]);
			continue;
		}
		cout << "wrong argument in test: " << command << endl;
	}
	return 0;
}
