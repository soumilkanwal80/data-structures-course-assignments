#include "header.h"
using namespace std;

class edge
{
public:
	float weight;
	bool hasEdge;
    
	edge()
	{
        weight = 0;
        hasEdge = false;
	}
};


class Graph
{
private:

	int numVertices;
	vector<string> nameVertices;
    vector <vector<edge> > graph;
    vector<vector<edge> > graphNoWeight;
	bool isReachable(int from, int to);
	int minDistance(float dist[], bool visited[]);
public:
 
    Graph(vector<string> names);
    int getIndex(string name);
	void insert(string from, string to, float weight);
	void dijkstra(string from, string to, int choice);
	void printDijkstra(int parent[], int from, int end);
	void largestArea();

};

Graph::Graph(vector<string> names)
{
	nameVertices = names;
	numVertices = (int) names.size();
	graph.resize(numVertices, vector<edge> (numVertices));
    graphNoWeight.resize(numVertices, vector<edge> (numVertices));

}

int Graph::getIndex(string name)
{
	for(int i=0;i<nameVertices.size();i++)
	{
		if(nameVertices[i] == name)
		{
			return i;
		}
	}
    return -1;
}

int Graph::minDistance(float dist[], bool visited[])
{
	float min = INT_MAX*1.0;
	int idx = 0;
	for(int i=0;i<numVertices;i++)
	{
		if(visited[i] == 0 && dist[i]<=min)
		{
			min = dist[i];
			idx = i;
		} 
	}
	return idx;
}

bool Graph::isReachable(int from, int to)
{
	if(from == to)
		return 1;

	bool visited[numVertices];
	for(int i=0;i<numVertices;i++)
		visited[i] = 0;

	visited[from] = 1;

	list<int> l;
	l.push_back(from);
	while(!l.empty())
	{
		int cv = l.back();
		l.pop_back();
		for(int i=0;i<numVertices;i++)
		{
			if(!visited[i] && graph[cv][i].hasEdge == 1)
			{
				visited[i] = 1;
				l.push_back(i);
			}
		}
	}

	return visited[to];
}

void Graph::insert(string from, string to, float weight)
{
	int from_idx = getIndex(from);
	int to_idx = getIndex(to);


//    cout<<from_idx<<" "<<to_idx<<" "<<weight<<endl;
	graph[from_idx][to_idx].weight = weight;
	graph[from_idx][to_idx].hasEdge = 1;
}

void Graph::dijkstra(string from, string to, int choice)
{

	int from_idx = getIndex(from);
	int to_idx = getIndex(to);

	if(from_idx == -1 || to_idx == -1)
    {
        cout<<"One or more cities doesn't exist...\n";
        return;
    }
    

	if(isReachable(from_idx, to_idx) == 0)
	{
		cout<<"Given cities are not connected...\n";
		return;
	}

    vector<vector<edge> > to_use;
    if(choice == 1)
        to_use = graph;
    else
    {
        for(int i=0;i<numVertices;i++)
        {
            for(int j=0;j<numVertices;j++)
            {
                if(graph[i][j].hasEdge == 1)
                {
                    graphNoWeight[i][j].hasEdge = 1;
                    graphNoWeight[i][j].weight = 1;
                }
            }
        }
        to_use = graphNoWeight;
    }

	float dist[numVertices];
	bool visited[numVertices];
	int parent[numVertices];

	for(int i=0;i<numVertices;i++)
	{
		dist[i] = INT_MAX*1.0;
		visited[i] = 0;
	}

	dist[from_idx] = 0;

	for(int i=0;i<numVertices-1;i++)
	{
		int u = minDistance(dist, visited);
		visited[u] = 1;
		for(int j=0;j<numVertices;j++)
		{
			if(visited[j] == 0 && to_use[u][j].hasEdge == 1 && dist[u] + to_use[u][j].weight<dist[j])
			{
				parent[j] = u;
				dist[j] = dist[u] + to_use[u][j].weight;
			}
		}
	}
    
    parent[from_idx] = -1;
    
	printDijkstra(parent, from_idx, to_idx);
    cout<<dist[to_idx]<<"\n";
}

void Graph::printDijkstra(int parent[], int start, int end)
{
	if(-1 == end)
        return;
    
    printDijkstra(parent, start, parent[end]);
    cout<<nameVertices[end]<<" ";

}

void Graph::largestArea()
{
    int max_idx = 0, max_count = 0;
    for(int j=0;j<numVertices;j++)
    {
        int count = 0;
        for(int i=0;i<numVertices;i++)
        {
            if(graph[j][i].hasEdge == 1)
                count++;
        }
        
        if(count>max_count)
        {
            max_count = count;
            max_idx = j;
        }
    }
    
    cout<<nameVertices[max_idx]<<endl;
            
    
}





