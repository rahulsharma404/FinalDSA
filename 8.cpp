#include <bits/stdc++.h>
using namespace std;
class Dijkstra
{
public:
    int n; // no. of vertices
    int src;
    vector<vector<int>> graph; // vector of vector
    Dijkstra();
    int minDistance(int dist[], bool sptSet[]);
    int printSolution(int dist[], int n);
    void dijkstra_algo();
};
Dijkstra ::Dijkstra()
{
    cout << "Enter the no. of vectices in graph : ";
    cin >> n;
    cout << "Enter the matrix of size " << n << " x " << n << " : " << endl;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            temp.push_back(x);
        }
        graph.push_back(temp);
    }
}
int Dijkstra ::minDistance(int dist[], bool sptSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < n; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// A utility function to print the constructed distance array
int Dijkstra ::printSolution(int dist[], int n)
{
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < n; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void Dijkstra ::dijkstra_algo()
{
    int dist[n]; // The output array.  dist[i] will hold the shortest
    // distance from src to i

    bool sptSet[n]; // sptSet[i] will be true if vertex i is included in shortest
    // path tree or shortest distance from src to i is finalized

    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < n - 1; count++)
    {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in the first iteration.
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < n; v++)

            // Update dist[v] only if is not in sptSet, there is an edge from
            // u to v, and total weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // print the constructed distance array
    printSolution(dist, n);
}

int main()
{
    Dijkstra D;
    bool flag = true;
    while (flag)
    {
        cout << "\nEnter the source index : ";
        cin >> D.src;
        D.dijkstra_algo();


        char ch;
        cout << "\nDo you want to continue (y/n) ? : ";
        cin >> ch;
        if (ch == 'n')
        {
            flag = false;
        }
    }
    return 0;
}
