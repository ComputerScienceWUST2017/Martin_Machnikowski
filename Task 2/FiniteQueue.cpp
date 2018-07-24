#include<iostream>
#include<string.h>
#include <string>
#include <sstream>

using namespace std;

class Queue
{
public:
    int *arr;
    int size,begin,end;
};

void init(Queue& q, int size)
{
    q.begin=0;
    q.end=0;
    q.arr=new int [size+1];
    q.size=size+1;
}
bool isFull(Queue& q)
{
    if((q.begin==0 && q.end ==q.size-1)||(q.begin==q.end+1))
        return true;
    return false;
}

bool isEmpty(Queue& q)
{
    if(q.begin==q.end)
        return true;
    return false;
}

bool enqueue(Queue& q, int value)
{
    if(!isFull(q)&&q.size<20)
    {
        q.arr[q.end++]=value;
        if(q.end>=q.size)
            q.end=0;
        return true;
    }
    return false;
}

bool dequeue(Queue& q, int &value)
{
    if(!isEmpty(q))
    {
        value=q.arr[q.begin++];
        if(q.begin>=q.size)
            q.begin=0;
        return true;
    }
    return false;
}

void show(Queue& q)
{
    if(q.begin<q.end)
    {
        for(int i=q.begin; i<q.end; i++)
        {
            cout << q.arr[i] << ",";
        }
    }
    else
    {
        for(int i=q.begin; i<=q.size-1; i++)
        {
            cout << q.arr[i] << ",";
        };
        for(int i=0; i<q.end; i++)
            cout << q.arr[i] << ",";

    }
    cout << endl;
}



void showBool(bool val)
{
    if(val)
        cout << "true" << endl;
    else
        cout << "false" << endl;
}

bool isCommand(const string command,const char *mnemonic)
{
    return command==mnemonic;
}

int main()
{
    string line;
    string command;
    Queue *queue=NULL;
    int currentQ=0;
    int value;
    cout << "START" << endl;
    while(true)
    {
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

        if(isCommand(command,"HA"))
        {
            cout << "END OF EXECUTION" << endl;
            break;
        }

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
            int ret;
            bool retBool=dequeue(queue[currentQ],ret);
            if(!retBool)
                cout << "false" << endl;
            else
                cout << ret << endl;
            continue;
        }

        // read next argument, one int value
        stream >> value;

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
        cout << "wrong argument in test: " << command << endl;
    }
}
