#include<iostream>
#include<string.h>
#include <sstream>

using namespace std;

#define INFINITY 10000000

struct Elem
{
    double weight;
};

struct Graph
{
    Elem *matrix = new Elem;
    int vertices,edges;
};


void loadGraph(Graph &g, int n, int m)
{
    g.matrix = new Elem [n*n];  //square matrix containing all edges between vertices
    for (int i=0;i<(n*n);i++)
        g.matrix[i].weight=-1;
    for (int i=0; i<n; i++)
        g.matrix[i*(n+1)].weight=0;
    g.vertices = n;
    g.edges = m;
    int u,v;
    double w;
    for(int i=0; i<m; i++)
    {
        cin >> u >> v >> w;
        g.matrix[g.vertices*u+v].weight=w;
    }
}

void insertEdge(Graph &g, int u, int v, double weight)
{
    g.matrix[g.vertices*u+v].weight=weight;
}

bool findEdge(Graph &g, int u, int v, double &weight)
{
    if ((g.matrix[g.vertices*v+u].weight!=-1)&&(g.matrix[g.vertices*v+u].weight!=0))
    {
        weight=g.matrix[g.vertices*v+u].weight;
        return 1;
    }

    return 0;
}

void showAsMatrix(Graph &g)
{
    for(int i=0; i<(g.vertices); i++)
    {
        for(int j=0; j<(g.vertices); j++)
        {
            if (g.matrix[i*g.vertices+j].weight!=-1)
            cout << g.matrix[i*g.vertices+j].weight << ",";
            else
                cout << "-,";
        }
        cout << endl;
    }
}

void showAsArrayOfLists(Graph &g)
{
    double w;
    for(int i=0; i<g.vertices; i++)
    {
        cout << i << ":";
        for (int j=0; j<g.vertices; j++)
        {
            if (findEdge(g,j,i,w))
                cout << j << "(" << w << "),";
        }
        cout << endl;
    }
}

bool isCommand(const string command,const char *mnemonic)
{
    return command==mnemonic;
}


int main()
{
    string line;
    string command;
    Graph *graph;
    int currentT=0;
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
        // zero-argument command
        if(isCommand(command,"SM"))
        {
            showAsMatrix(graph[currentT]);
            continue;
        }

        if(isCommand(command,"SA"))
        {
            showAsArrayOfLists(graph[currentT]);
            continue;
        }


        // read next argument, one int value
        stream >> value;

        if(isCommand(command,"LG"))
        {
            int m;
            stream >> m;
            loadGraph(graph[currentT],value,m);
            continue;
        }

        if(isCommand(command,"IE"))
        {
            int v;
            double w;
            stream >> v >> w;
            insertEdge(graph[currentT],value,v,w);
            continue;
        }

        if(isCommand(command,"FE"))
        {
            int v;
            stream >> v;
            double w;
            bool ret=findEdge(graph[currentT],value,v,w);

            if(ret)
                cout << w << endl;
            else
                cout << "false" << endl;
            continue;
        }


        if(isCommand(command,"CH"))
        {
            currentT=value;
            continue;
        }

        if(isCommand(command,"GO"))
        {
            graph=new Graph[value];
            continue;
        }

        cout << "wrong argument in test: " << command << endl;
        return 1;
    }
}

