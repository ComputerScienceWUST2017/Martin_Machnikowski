#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// size from 2 to 20
void drawTriangle(int size)
{
    for(int i=(size-1); i>=0; i--)
    {
        for(int j=size-i; j>0; j--)
            cout << "X";
        cout << endl;
    }
}

// size from 2 to 20
void drawSquare(int size)
{
    for(int i=0; i<size; i++)
        cout << "X";
    cout << endl;
    for(int i=2; i<size; i++)
    {
        cout << "X";
        for(int j=2; j<size; j++)
            cout << " ";
        cout << "X" << endl;
    }
    for(int i=0; i<size; i++)
        cout << "X";
    cout << endl;
}

// size from 1 to 20
void drawPyramid(int size)
{
    for(int i=0; i<size; i++)
    {
        for(int k=i+1; k<size; k++)
            cout<<" ";
        for(int j=2*i+1; j>0; j--)  //2n+1
        {

            cout << "X";
        }
        cout << endl;
    }

}

// size from 1 to 20
void drawChristmasTree(int size)
{
    for(int l=size; l>=0; l--)                  //amount of repetitions
    {
        for(int i=0; i<size-l; i++)          //amount of lines in each repetition
        {
            for(int k=i+1; k<size; k++)         //offset
                cout<<" ";
            for(int j=2*i+1; j>0; j--)          //2n+1
            {
                cout << "X";
            }
            cout << endl;
        }

//        drawPyramid(i); //won't work, needs a global offset
    }
}

// size from 2 to 20
void drawFigureX(int size)
{
}

// size from 2 to 20
void drawFigureY(int size)
{
}

// size from 3 to 20
void drawFigureZ(int size)
{
}

// size from 2 to 20
void drawFigureW(int size)
{
}

bool isCommand(const string command,const char *mnemonic)
{
    return command==mnemonic;
}

int main()
{
    string line;
    string command;
    int value;
    cout << "START" << endl;
    while(true)
    {
//		cin.getline(line, MAXLINE);
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

        // read next argument, one int value
        stream >> value;

        if(isCommand(command,"TR"))
        {
            drawTriangle(value);
            continue;
        }
        if(isCommand(command,"SQ"))
        {
            drawSquare(value);
            continue;
        }
        if(isCommand(command,"PY"))
        {
            drawPyramid(value);
            continue;
        }
        if(isCommand(command,"CT"))
        {
            drawChristmasTree(value);
            continue;
        }
        if(isCommand(command,"FX"))
        {
            drawFigureX(value);
            continue;
        }
        if(isCommand(command,"FY"))
        {
            drawFigureY(value);
            continue;
        }
        if(isCommand(command,"FZ"))
        {
            drawFigureZ(value);
            continue;
        }
        if(isCommand(command,"FW"))
        {
            drawFigureW(value);
            continue;
        }

        cout << "wrong argument in test: " << command << endl;
    }

}
