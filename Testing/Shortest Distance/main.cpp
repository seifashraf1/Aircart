#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector<int> dist, parent;

void dijkstra(int src, vector<vector<pair<int, int>> > graph){
    int N = graph.size();
    dist.resize(N);
    parent.resize(N);

    for (int i = 0; i < N; i++)
    {
        parent[0] = -1;
        dist[i] = INT_MAX;
    }

    set<pair< int, int> > s;
    s.insert(make_pair(0, src));
    dist[src] = 0;

    while(!s.empty()){
        pair<int, int> tmp = *(s.begin());
        s.erase(s.begin());

        int u = tmp.second;

        for (int i = 0; i < graph[u].size(); ++i)
        {
            int v = graph[u][i].first;
            int weight = graph[u][i].second;

            if (dist[v] > dist[u] + weight)
            {
                if (dist[v] != INT_MAX)
                    s.erase(s.find(make_pair(dist[v], v)));

                dist[v] = dist[u] + weight;
                s.insert(make_pair(dist[v], v));
                parent[v] = u;
            }
        }
    }

}

void addEdge( vector<vector<pair<int, int> > >& adj, int u, int v, int w){
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

void printPath( int j)
{

    // Base Case : If j is source
    if (parent[j] == - 1)
        return;

    printPath( parent[j]);

    printf("%d ", j);
}

int printSolution(int dest)
{
    int src = 0, V = parent.size();
    printf("Vertex\t Distance\tPath");
        printf("\n%d -> %d \t\t %d\t\t%d ",
               src, dest, dist[dest], src);
        printPath( dest);
}

int main(){
    int N = 9;
    vector<pair<int, int> > temp;
    vector<vector<pair<int, int> > > adj(N, temp);

    cout<<"Please enter the name of the required place"<<endl;
    int dest;
    cin>>dest;

    addEdge( adj, 0, 1, 4);
    addEdge( adj, 0, 7, 8);
    addEdge( adj, 1, 2, 8);
    addEdge( adj, 1, 7, 11);
    addEdge( adj, 2, 3, 7);
    addEdge( adj, 2, 8, 2);
    addEdge( adj, 2, 5, 4);
    addEdge( adj, 3, 4, 9);
    addEdge( adj, 3, 5, 14);
    addEdge( adj, 4, 5, 10);
    addEdge( adj, 5, 6, 2);
    addEdge( adj, 6, 7, 1);
    addEdge( adj, 6, 8, 6);
    addEdge( adj, 7, 8, 7);

    dijkstra(0, adj);
    printSolution(dest);
}