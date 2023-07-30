#include <bits/stdc++.h>
using namespace std;

char a[1000][1000];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int i, int j, int n , int m)
{
    a[i][j] = '#';
    for(int k = 0 ; k < 4 ; k++){
        int ni = i + dx[k];
        int nj = j + dy[k];
        if(ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
        if(a[ni][nj] == '#') continue;
        if(a[ni][nj] == '.') dfs(ni , nj , n , m );
    }
    return ;
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == '.')
            {
                count++;
                dfs(i, j, n , m);
            }
        }
    }

    cout << count << endl;
}