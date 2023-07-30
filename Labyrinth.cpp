#include <bits/stdc++.h>

using namespace std;

char a[1000][1000];

int main()
{
    int n, m;
    cin >> n >> m;
    int sr = -1, sc = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 'A')
            {
                sr = i;
                sc = j;
            }
        }
    }
    if(sr == -1 ) {
        cout <<"NO" << endl;
        return 0;
    }
    
    queue<pair<string, pair<int, int>>> q;
    q.push({"", {sr, sc}});
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    string path[4] = {"D", "U", "R", "L"};
    a[sr][sc] = '#';

    while (q.size() > 0)
    {
        auto f = q.front();
        q.pop();
        string curr = f.first;
        int r = f.second.first;
        int c = f.second.second;

        for (int k = 0; k < 4; k++)
        {
            int nr = r + dx[k];
            int nc = c + dy[k];
            if (nr >= 0 && nc >= 0 && nr < n && nc < m && a[nr][nc] != '#')
            {
                if (a[nr][nc] == 'B')
                {
                    cout << "YES" << endl
                         << curr.length() + 1 << endl
                         << curr + path[k] << endl;
                    return 0;
                }
                a[nr][nc] = '#';
                q.push({curr + path[k], {nr, nc}});
            }
        }
    }
    cout << "NO" << endl;
}