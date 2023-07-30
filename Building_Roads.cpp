#include<bits/stdc++.h>
using namespace std;

void dfs(int s , vector<int> a[] , vector<int> &v ) {
    v[s] = 1;
    for(auto &node : a[s]) {
        if(v[node] == 0 ) {
            dfs(node , a , v);
        }
    }
}

int main(){
    int n , m ;
    cin  >> n >> m ;

    vector<int> a[n+1];

    for(int i = 0 ; i < m ; i++){
        int u , v ;
        cin >> u >> v ;

        a[u].push_back(v);
        a[v].push_back(u);
    }   

    vector<int> vis(n+1 , 0 ) ;
    vector<int> nodes ;
    for(int i = 1 ; i <= n ; i++){
        if(vis[i] == 0 ) {
            nodes.push_back(i);
            dfs(i , a , vis);
        }
    }
    if(nodes.size() == 1 ) {
        cout << 0 << endl;
        return 0;
    }
    cout << nodes.size() -1 << endl;
    for(int i = 0 ; i < nodes.size()  - 1 ; i++){
        cout << nodes[i] << " " << nodes[i+1] << endl;
    }

}