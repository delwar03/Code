#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;


void solve() {
    int n, m; cin>>n>>m;
    int adj_mat[n + 1][n + 1];
    memset(adj_mat, 0, sizeof(adj_mat));
    for(int i = 0; i < m; i++) {
      int u, v; cin>>u>>v;
      adj_mat[u][v] = 1;
    }
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) cout<<adj_mat[i][j]<<" ";
         cout<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        solve();
    }
}
 
/*
i/p: 
o/p: 
*/ 