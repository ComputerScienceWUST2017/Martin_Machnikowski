#include<iostream>
#include <string>
#include <sstream>

#ifndef nullptr
#define nullptr NULL
#endif

using namespace std;


// Two-way unordered cycled list without sentinel
typedef struct ElemLL
{
    int key;
    ElemLL *next,*prev;
} Element;

typedef struct
{
    Element *head;
} List2W;

void init(List2W& l)
{
    l.head=NULL;
}

void insertHead(List2W& l, int x)
{
    ElemLL *newEl=new ElemLL;
    newEl->key=x;
    if(l.head == NULL)
    {
        l.head = new ElemLL;
        l.head=newEl;
        l.head->next=l.head;
        l.head->prev=l.head;
    }
    else
    {
        newEl->prev=l.head->prev;
        l.head->prev=newEl;
        newEl->next=l.head;
        l.head=newEl;
        l.head->prev->next=l.head;
    }
}

bool deleteHead(List2W& l, int &value)
{
    if(l.head==NULL)
        return false;
    else
    {
        ElemLL *temp=l.head;
        if(l.head->next==l.head)
        {
            delete l.head;
            l.head=NULL;
        }
        else
        {
            l.head = l.head->next;
            l.head->prev=temp->prev;
            temp->prev->next=l.head;
        }
        delete temp;
    }
    return true;
}

void insertTail(List2W& l, int x)
{
    ElemLL *newEl=new ElemLL;
    newEl->key=x;
    if(l.head == NULL)
    {
        l.head=newEl;
        l.head->next=l.head;
        l.head->prev=l.head;
    }
    else
    {
        newEl=l.head;
        l.head->prev=newEl;
        newEl->next=l.head;
        newEl->key=x;
    }
}

bool deleteTail(List2W& l, int &value)
{
    if(l.head==NULL)
        return false;
    else
    {
        l.head->prev->prev->next=l.head->prev->next;
        l.head->prev->next->prev=l.head->prev->prev;
        ElemLL *temp=l.head->prev;
        l.head->prev = temp->next;
        delete temp;
    }
    return true;
}

int findValue(List2W& l, int value)
{
    int i = 0;
    ElemLL* temp=l.head;
    while(temp)
    {
        if(temp->key==value) return i;
        temp=temp->next;
        i++;
        if(temp==l.head) break;
    };
    return -1;
}

void removeAllValue(List2W& l, int value)
{
    ElemLL* temp=l.head;
    while(temp)
    {
        if(temp->key==value)
        {
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            delete temp;
            temp=l.head;
        }
        temp=temp->next;
        if(temp==l.head) break;
    };
}

void showListFromHead(List2W& l)
{
    if (!l.head) return;
    ElemLL* temp=l.head;
    while(temp)
    {
        cout << temp->key << ", ";
        temp=temp->next;
        if(temp==l.head) break;
    };
    cout << endl;
}

void showListFromTail(List2W& l)
{
    ElemLL* temp=l.head->prev;
    while(temp)
    {
        cout << temp->key << ", ";
        temp=temp->prev;
        if(temp==l.head->prev) break;
    };
    cout << endl;
}

void clearList(List2W& l)
{
    int temp;
    while(deleteHead(l,temp));
}

void addList(List2W& l1,List2W& l2)
{
    if(l1.head!=l2.head)
    {
        ElemLL *t1end=l1.head->prev,*t2end=l2.head->prev;
        l1.head->prev=t2end;
        t2end->next=l1.head;
        t1end->next=l2.head;
        l2.head->prev=t1end;
        init(l2);
    }
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
    List2W *list = nullptr;
    int currentL=0;
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
