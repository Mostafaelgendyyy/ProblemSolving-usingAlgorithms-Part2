#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
struct EdgeStructure
{
    int Forw;
    int Key;
    EdgeStructure() {
        Forw = Key =0;
    }

    EdgeStructure(int t, int w) : Forw(t), Key(w) {}
    bool operator<(const EdgeStructure& e) const
    {
        if (Key > e.Key)
            return true;
        return false;
    }
};
EdgeStructure e;
int dijkstraVal[10000];
vector <EdgeStructure> Graph[10000];
priority_queue <EdgeStructure> PriortyQ;
int dijkstra(int S, int E)
{
    int i, u, v, w;
    dijkstraVal[S] = 0;
    PriortyQ.push(EdgeStructure(S, 0));
    while (!PriortyQ.empty())
    {
        e = PriortyQ.top();
        PriortyQ.pop();
        u = e.Forw;
        for (i = 0; i < (int)Graph[u].size(); i++)
        {
            v = Graph[u][i].Forw;
            w = Graph[u][i].Key;
            if (dijkstraVal[v] > dijkstraVal[u] + w)
            {
                dijkstraVal[v] = dijkstraVal[u] + w;
                PriortyQ.push(EdgeStructure(v, dijkstraVal[v]));
            }
        }
    }
    return dijkstraVal[E];
}
int main()
{
    int cases, i, t, n, m, S, E, x, y, z, Result;
    cin >> cases;
    for (t = 1; t <= cases; t++)
    {
        cin >> n >> m >> S >> E;

        for (i = 0; i < n; i++) {
            dijkstraVal[i] = 2147483647;
        }

        for (i = 0; i < n; i++)  {
            Graph[i].clear();
        }

        for (i = 0; i < m; i++)
        {
            cin >> x >> y >> z;

            Graph[x].push_back(EdgeStructure(y, z));
            Graph[y].push_back(EdgeStructure(x, z));
        }
        Result = dijkstra(S, E);

        if (Result == 2147483647)
            cout << "Case #" << t << ": " << "unreachable" << endl << endl;
        else
            cout << "Case #" << t << ": " << Result << endl << endl;
    }
    return 0;
}