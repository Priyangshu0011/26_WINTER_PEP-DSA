//Graph Traversal
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 10 // MAX NOF VERTICES IN A GRAPH

int adj[MAX][MAX]; // ADJACENCY MATRIX
int visited[MAX]; // VISITED ARRAY
int vertices; // NUMBER OF VERTICES IN THE GRAPH

void BFS(int start)
{
    queue<int> q; // CREATE A QUEUE FOR BFS
    visited[start] = true; // MARK THE STARTING VERTEX AS VISITED
    q.push(start); // ENQUEUE THE STARTING VERTEX

    while(!q.empty())
    {
        int current = q.front(); // GET THE FRONT ELEMENT OF THE QUEUE
        cout << current << " "; // PRINT THE CURRENT VERTEX
        q.pop(); // DEQUEUE THE FRONT ELEMENT

        for(int i=0; i<vertices; i++)
        {
            if(adj[current][i] == 1 && !visited[i]) // CHECK FOR ADJACENT UNVISITED VERTICES
            {
                visited[i] = true; // MARK THE ADJACENT VERTEX AS VISITED
                q.push(i); // ENQUEUE THE ADJACENT VERTEX
            }
        }
    }
}

int main()
{
    int start;
    cout<<"Enter the number of vertices: ";
    cin>>vertices;
    //initialize the adjacency matrix
    for(int i=0; i<vertices; i++)
    {
        for(int j=0; j<vertices; j++)
        {
            adj[i][j] = 0; // INITIALIZE ALL ENTRIES IN THE ADJACENCY MATRIX TO 0
        }
    }

    int edges;
    cout<<"Enter the number of edges: ";
    cin>>edges;

    cout<<"Enter edges (u v): "<<endl;
    for(int i=0; i<edges; i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u][v] = 1; // MARK THE EDGE IN THE ADJACENCY MATRIX
        adj[v][u] = 1; // FOR UNDIRECTED GRAPH, MARK THE EDGE IN BOTH DIRECTIONS, NOT REQUIRED FOR DIRECTED GRAPH
    }
    

    cout<<"Enter the starting vertex: ";
    cin>>start;
    for(int i=0; i<vertices; i++)
    {
        visited[i] = false; // INITIALIZE ALL VERTICES AS UNVISITED
    }

    BFS(start); // CALL BFS FUNCTION TO TRAVERSE THE GRAPH
    //cout<<"Graph Traversal"<<endl;
    return 0;   
}