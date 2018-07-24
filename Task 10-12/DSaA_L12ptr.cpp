#include <iostream>
#include <string.h>
#include <sstream>


using namespace std;

#define INFINITY 10000000

enum Color {BLACK, GREY, WHITE};

struct Graph
{
    int **matrix;
    Color *color;
    int *array;
    int arrSize;
    int size;
};

int minDistance(Graph &g, bool isIncluded[])
{
    int min = INFINITY;
    int minIndex = 0;
    for(int i = 0; i<g.size; i++)
    {
        if(!isIncluded[i] && g.array[i]<=min)
        {
            min = g.array[i];
            minIndex = i;
        }
    }
    return minIndex;
}

int* singleSourceShortestPath(Graph &g,int value)
{
    bool isIncluded[g.size];
    for(int i = 0; i<g.size; i++)
    {
        g.array[g.arrSize++] = INFINITY;
        isIncluded[i]= false;
    }

    g.array[value] = 0;
    for(int i = 0; i<g.size; i++)
    {
        for(int c = 0; c<g.size-1; c++)
        {
            int u = minDistance(g,isIncluded);
            isIncluded[u] = true;
            for(int j = 0; j<g.size; j++)
            {
                if(!isIncluded[j] &&
                        g.matrix[u][j]!= INFINITY &&
                        g.array[u]!= INFINITY &&
                        g.array[u]+g.matrix[u][j] < g.array[j])
                {
                    g.array[j] =g.array[u] +  g.matrix[u][j];
                }
            }
        }
    }
    return g.array;
}

void printSSSP(int *array, int size)
{
    for(int i = 0; i<size; i++)
    {
        cout<<i<<"("<<array[i]<<")"<<endl;
    }
}

int dequeue(Graph &g)
{
    int x = -1;
    if(g.arrSize > 0)
    {
        x = g.array[0];
        for(int i = 0; i < g.arrSize-1; i++)
        {
            g.array[i] = g.array[i+1];
        }
    }
    g.arrSize--;
    return x;
}

void bfsVisit(Graph &g, int value)
{
    for(int i = 0; i<g.size; i++)
    {
        if(g.matrix[value][i] != 0 && g.matrix[value][i] != INFINITY)
        {
            if(g.color[i] == WHITE)
            {
                cout<<i<<",";
                g.color[i] = GREY;
                g.array[g.arrSize++] = i;
            }
        }
    }
    g.color[value] = BLACK;
}

void breadthFirstSearch(Graph &g, int value)
{
    for(int i = 0; i<g.size; i++)
    {
        g.color[i] = WHITE;
    }
    cout<<value<<",";
    g.color[value] = GREY;
    g.array[g.arrSize++] = value;
    while(g.arrSize != 0)
    {
        value = dequeue(g);
        if(value == -1)
        {
            return;
        }
        bfsVisit(g,value);
    }
    cout<<"\n";
}



void dsfVisit(Graph &g, int u)
{
    g.color[u] = GREY;
    cout<<u<<",";
    for(int i = 0; i<g.size; i++)
    {
        if(g.matrix[u][i] != 0 && g.matrix[u][i] != INFINITY)
        {
            if(g.color[i] == WHITE)
            {
                dsfVisit(g,i);
            }
        }
    }
    g.color[u] = BLACK;
}

void depthFirstSearch(Graph &g, int value)
{
    for(int i = 0; i<g.size; i++)
    {
        g.color[i] = WHITE;
    }
    if(value < g.size)
    {
        dsfVisit(g,value);
    }
    cout<<"\n";

}


void loadGraph(Graph &g, int n, int m)
{
    g.array = new int[n];
    g.arrSize = 0;
    g.size = n;
    g.color = new Color[n];
    g.matrix = new int*[n];

    for(int i = 0; i<n; i++)
    {
        g.matrix[i]= new int[n];
        for(int j = 0; j<n; j++)
        {
            g.matrix[i][j] = INFINITY;
            if(i==j)
            {
                g.matrix[i][j] = 0;
            }
        }
    }
    for(int j = 0; j<m; j++)
    {
        int a, b;
        int c;
        cin>>a;
        cin>>b;
        cin>>c;
        g.matrix[a][b] = c;
    }
}

void insertEdge(Graph &g, int u, int v, double weight)
{
    if(u != v)
        g.matrix[u][v] = weight;
}

bool findEdge(Graph &g, int u, int v, double &weight)
{
    if(u != v)
    {
        if(g.matrix[u][v] != INFINITY)
        {
            weight = g.matrix[u][v];
            return true;
        }
    }
    return false;
}

void showAsMatrix(Graph &g)
{
    for(int i = 0; i<g.size; i++)
    {
        for(int j = 0; j<g.size; j++)
        {
            if(g.matrix[i][j] == INFINITY)
            {
                cout<<"-,";
            }
            else
            {
                cout<<g.matrix[i][j]<<",";
            }
        }
        cout<<"\n";
    }
}

void showAsArrayOfLists(Graph &g)
{
    for(int i = 0; i < g.size; i++)
    {
        cout<<i<< ":";
        for(int j = 0; j < g.size; j++)
        {
            if(g.matrix[i][j] != 0 && g.matrix[i][j] != INFINITY)
            {
                cout<<j<<"("<<g.matrix[i][j]<<")"<<",";
            }
        }
        cout<<"\n";
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
    Graph *graph = new Graph;
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
            continue;
        }
        cout << "!" << line << endl;;
        command[0]=toupper(command[0]);
        command[1]=toupper(command[1]);
        if(isCommand(command,"HA"))
        {
            cout << "END OF EXECUTION" << endl;
            break;
        }
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
        stream >> value;
        if(isCommand(command,"BF"))
        {
            breadthFirstSearch(graph[currentT],value);
            continue;
        }
        if(isCommand(command,"DF"))
        {
            depthFirstSearch(graph[currentT],value);
            continue;
        }
        if(isCommand(command,"SS"))
        {
            int* output;
            output = singleSourceShortestPath(graph[currentT],value);
            printSSSP(output,graph[currentT].size);
            continue;
        }
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
            bool x=findEdge(graph[currentT],value,v,w);

            if(x)
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
