#include <bits/stdc++.h>
using namespace std;
class Prim
{
public:
    int V;                 // Number of vertices in the graph
    vector<vector<int>> G; // vector of vector
    Prim();
    void Prim_Algo(vector<vector<int>>);
};
Prim ::Prim()
{
    cout << "Enter the no of vertices in graph : ";
    cin >> V;
    cout << "Enter the adjacency matrix of size " << V << " X " << V << " : \n";
    for (int i = 0; i < V; i++)
    {
        vector<int> temp; // temporary vector
        for (int j = 0; j < V; j++)
        {
            int x;
            cin >> x;
            temp.push_back(x);
        }
        G.push_back(temp);
    }
}
void Prim ::Prim_Algo(vector<vector<int>> G)
{
    int total_cost = 0;

    int no_edge; // number of edge

    // create a array to track selected vertex
    // selected will become true otherwise false
    int selected[V];

    // set selected false initially
    memset(selected, false, sizeof(selected));

    // set number of edge to 0
    no_edge = 0;

    // the number of egde in minimum spanning tree will be
    // always less than (V -1), where V is number of vertices in
    //graph

    // choose 0th vertex and make it true
    selected[0] = true;

    int x; //  row number
    int y; //  col number

    // print for edge and weight
    cout << "Edge" << " : " << "Weight";
    cout << endl;
    while (no_edge < V - 1)
    {

        int min = INT_MAX;
        x = 0;
        y = 0;

        for (int i = 0; i < V; i++)
        {
            if (selected[i])
            {
                for (int j = 0; j < V; j++)
                {
                    if (!selected[j] && G[i][j])
                    { // not in selected and there is an edge
                        if (min > G[i][j])
                        {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        total_cost = total_cost + G[x][y];

        cout << x << " - " << y << " :  " << G[x][y];
        cout << endl;
        selected[y] = true;
        no_edge++;
    }
    cout << "Total Cost : " << total_cost;
}
int main()
{
    Prim P;
    P.Prim_Algo(P.G);

    return 0;
}
