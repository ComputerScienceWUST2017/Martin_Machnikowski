#include <iostream>
#include <string.h>

using namespace std;

struct Queue{
	int *arr;
	int size;
	int end;
};

void init(Queue& q, int size){
	q.arr = new int[size+1];
	q.size = size;
	q.end = 0;
	return;
}

bool isEmpty(Queue& q){
	if (q.end == 0)
		return true;
	else
		return false;
}

bool isFull(Queue& q){
	if (q.end == q.size)
		return true;
	else
		return false;
}

bool enqueue(Queue& q, int value){
	if (isFull(q)) return false;
	q.arr[q.end] = value;
	q.end++;
	return true;
}

bool dequeue(Queue& q, int &value)
{
	if (isEmpty(q)) return false;
	value = q.arr[0];
	for (int i = 0; i < q.size; i++)
		q.arr[i] = q.arr[i+1];
	q.end--;
	return true;
}

void show(Queue& q){
	for (int i=0;i<q.end;i++)
		cout<<q.arr[i]<<",";
	cout<<endl;
}


void showBool(bool val){
	if(val)
		cout << "true" << endl;
	else
		cout << "false" << endl;
}

bool isCommand(const char *command,const char *mnemonic){
	return strcmp(command,mnemonic)==0;
}

int main(){
	const int commandSize=2;
	const int MAXLINE=100;
	char line[MAXLINE];
	char command[commandSize+1]; // for '\0'
	Queue *queue;
	int currentQ=0;
	int value;
	command[commandSize]='\0';
	while(true){
		cin >> command[0];
		if(command[0]=='#')
		{
			cin.getline(line, MAXLINE);
			continue;
		}
		cin >> command[1];

		if(isCommand(command,"HA"))
			break;
		// zero-argument command
		if(isCommand(command,"EM"))
		{
			showBool(isEmpty(queue[currentQ]));
			continue;
		}
		if(isCommand(command,"FU"))
		{
			showBool(isFull(queue[currentQ]));
			continue;
		}
		if(isCommand(command,"SH"))
		{
			show(queue[currentQ]);
			continue;
		}
		if(isCommand(command,"DE"))
		{
			int ret=-9999;
			bool retBool=dequeue(queue[currentQ],ret);
			if(!retBool)
				cout << "false" << endl;
			else
				cout << ret << endl;
			continue;
		}

		// read next argument, one int value
		cin >> value;

		if(isCommand(command,"GO"))
		{
			queue=new Queue[value];
			continue;
		}
		if(isCommand(command,"CH"))
		{
			currentQ=value;
			continue;
		}

		if(isCommand(command,"IN"))
		{
			init(queue[currentQ],value);
			continue;
		}

		if(isCommand(command,"EN"))
		{
			bool retBool=enqueue(queue[currentQ],value);
			showBool(retBool);

			continue;
		}

	}
	cout << "END OF EXECUTION" << endl;
}
