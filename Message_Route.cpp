#include<bits/stdc++.h>
using namespace std;

int main(){
    int n , m ;
    cin >> n >> m ;

    vector<int> a[n+1];

    for(int i =0 ; i < m ; i++){
        int u , v ;
        cin >> u >> v ;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    vector<int> vis(n+1 , 0 ) ;

    vis[1] = 1 ; 

    queue<int> q;
    q.push(1);
    int parent[n+1];

    memset(parent , -1 , sizeof parent);

    vector<int> ans ;

    while(q.size()) {
        int f = q.front();
        if(f == n ) {
            int x = f ;
            while(parent[f] != -1) {
                ans.push_back(f);
                f = parent[f];
            }
            ans.push_back(1);
            break;
        }
        q.pop();
        for(int &node : a[f]){
            if(vis[node] == 0 ) {
                vis[node] = 1 ; 
                parent[node] = f ; 
                q.push(node);
            } 
        }
    }
    if(ans.size() == 0 ){
        cout << "IMPOSSIBLE" ;
        return 0;
    }
    cout <<ans.size() << endl;
    for(int i = ans.size() -1 ; i >= 0 ; i--){
        cout << ans[i] << " ";
    }
}