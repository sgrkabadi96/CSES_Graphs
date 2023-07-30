#include<bits/stdc++.h>
using namespace std ;


bool dfs(int node , vector<int> a[] , vector<int> &vis , int color, int parent) {

    vis[node] = color ;
    for(int &s : a[node]) { 
        if(s == parent) continue ;
        if(vis[s] == color ) return false;
        else if(vis[s] == 0 ) {
            bool x = dfs(s, a , vis , 3 - color , node  );
            if(x == false) return false;
        }
    }
    return true;
}

int  main(){
    int n , m ;
    cin >> n >> m ; 
    vector<int> a[n+1];
    for(int i = 0 ; i < m ; i++){
        int u , v ; 
        cin >> u >> v ;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    vector<int> vis(n+1 , 0 ) ;

    for(int i = 1 ; i <= n ; i++){
        if(vis[i] == 0 ) {
            bool x = dfs(i , a , vis , 1 , 0 ) ; 
            if(x == false ){
                cout <<"IMPOSSIBLE" << endl;
            }
        }
    }

    for(int i = 1 ; i  <= n ; i++){
        cout << vis[i] << " ";
    }
}