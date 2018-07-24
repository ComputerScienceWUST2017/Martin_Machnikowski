#include<iostream>
#include <string>
#include <sstream>

using namespace std;


struct Element
{
    int key;
    int value;
};

struct ElementLL
{
    Element elem;
    ElementLL *next, *prev;
};

// Two-way ordered cycled list with sentinel
struct List2W
{
    ElementLL *sentinel;
};

void init(List2W& l)
{
    l.sentinel=new ElementLL();
    l.sentinel->next=l.sentinel;
    l.sentinel->prev=l.sentinel;
}

void insertElem(List2W & l, Element elem)
{
    ElementLL *newEl = new ElementLL;
    newEl->elem=elem;
    if(l.sentinel->next==l.sentinel)
    {
        newEl->next=l.sentinel;
        newEl->prev=l.sentinel;
        l.sentinel->next=newEl;
        l.sentinel->prev=newEl;
    }
    else
    {
        ElementLL *ptr=l.sentinel->next;
        while(ptr->elem.key <= newEl->elem.key && ptr!=l.sentinel)
            ptr=ptr->next;
        newEl->next=ptr;
        newEl->prev=ptr->prev;
        newEl->next->prev=newEl;
        newEl->prev->next=newEl;
    }
}

bool findKey(List2W & l,int key, Element &elem)
{
    ElementLL *ptr = l.sentinel->next;
    while(ptr != l.sentinel)
    {
        if (ptr->elem.key == key)
        {
            elem = ptr->elem;
            return true;
        }
        ptr=ptr->next;
    }
    return false;
}

void removeAllKeys(List2W& l, int key)
{
    ElementLL *ptr = l.sentinel->next;
    ElementLL *temp;
    while(ptr != l.sentinel)
    {
        if (ptr->elem.key == key)
        {
            temp = ptr;
            ptr=ptr->next;
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }
        else
            ptr=ptr->next;
    }
}

void showListFromHead(List2W& l)
{
    ElementLL *ptr = l.sentinel->next;
    while(ptr != l.sentinel)
    {
        cout<<ptr->elem.key<<"("<<ptr->elem.value<<"),";
        ptr=ptr->next;
    }
    cout<<endl;
}

void showListFromTail(List2W& l)
{
    ElementLL *ptr = l.sentinel->prev;
    while(ptr != l.sentinel)
    {
        cout<<ptr->elem.key<<"("<<ptr->elem.value<<"),";
        ptr=ptr->prev;
    }
    cout<<endl;
}

void clearList(List2W& l)
{
    ElementLL *ptr = l.sentinel->next;
    ElementLL *temp;
    while(ptr != l.sentinel)
    {
        temp = ptr;
        ptr=ptr->next;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }
}

void addList(List2W& l1,List2W& l2)
{
    if (l1.sentinel != l2.sentinel && l2.sentinel != l2.sentinel->next)
    {
        ElementLL *ptr1 = l1.sentinel->next;
        ElementLL *ptr2 = l2.sentinel->next;
        ElementLL *temp;
        if (l1.sentinel == l1.sentinel->next)
        {
            l1.sentinel->next=l2.sentinel->next;
            l1.sentinel->prev=l2.sentinel->prev;
            l1.sentinel->next->prev=l1.sentinel;
            l1.sentinel->prev->next=l1.sentinel;
            l2.sentinel->next=l2.sentinel;
            l2.sentinel->prev=l2.sentinel;
        }
        else
        {
            while (ptr2 != l2.sentinel)
            {
                temp = ptr2;
                ptr2=ptr2->next;

                while (temp->elem.key >= ptr1->elem.key && ptr1 != l1.sentinel)
                    ptr1=ptr1->next;
                temp->next = ptr1;
                temp->prev = ptr1->prev;
                temp->next->prev = temp;
                temp->prev->next = temp;

            }
            l2.sentinel->next = l2.sentinel;
            l2.sentinel->prev = l2.sentinel;
        }
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
    List2W *list;
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

        // zero-argument command
        if(isCommand(command,"HA"))
        {
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
