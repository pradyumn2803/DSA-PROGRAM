#include <iostream>
#include <vector>

using namespace std;

// time complexity is O(N+E)
// where N-no. of nodes,E- travelling through adkacent nodes
// Space complexity is O(N+E)+O(N)+O(N)
 

class solution
{
    void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &storedfs)
    {
        storedfs.push_back(node);
        vis[node] = 1;
        for (auto iter : adj[node])
        {
            if (!vis[iter])
            {
                dfs(iter, adj, vis, storedfs);
            }
        }
    }

public:
    vector<int> search(int v, vector<int> adj[])
    {
        vector<int> storedfs;
        vector<int> vis(v + 1, 0);

        for (int i = 1; i <= v; i++)
        {
            if (!vis[i])
            {
                dfs(i, adj, vis, storedfs);
            }
        }

        return storedfs;
    }
};

int main()
{
    int m, n;
    cin >> m >> n;
    solution s;

    vector<int> adj[n + 1];

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> a;

    a = s.search(n, adj);

    for (auto i : a)
    {
        cout << i << " ";
    }
    return 0;
}