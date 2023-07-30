#include <bits/stdc++.h>

using namespace std;

vector<int> ans;

bool dfs(int s, vector<int> a[], vector<int> &vis, int p)
{
    vis[s] = 1;

    for (int &node : a[s])
    {
        if (node == p)
            continue;
        if (vis[node] == 1)
        {
            ans.push_back(node);
            ans.push_back(s);
            return true;
        }
        else
        {
            bool f = dfs(node, a, vis, s);
            if (f)
            {
                ans.push_back(s);
                if (s == ans[0])
                {
                    cout << ans.size() << endl;
                    for (int i = ans.size() - 1; i >= 0; i--)
                    {
                        cout << ans[i] << " ";
                    }
                }
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> a[n + 1];

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    vector<int> vis(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            bool f = dfs(i, a, vis, 0);
            if (f)
            {

                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
}