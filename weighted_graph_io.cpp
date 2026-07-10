// Input output of weighted undirected graph 

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Adjacency matrix presentation 

    int n,m; // n-> Nodes ; m-> edges

    cin>>n>>m;

    int adj[n+1][n+1];


    // Adjacency list presentation
    vector<pair<int,int>> adj_list[n+1];
    memset(adj,-1,sizeof adj);

    for(int i =0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u][v]=w;
        adj[v][u]=w;

        adj_list[u].push_back({v,w});
        adj_list[v].push_back({u,w});

    }

    // output of adjacency matrix
    for(int i =1;i<n+1;i++){
        for(int j = 1;j<n+1;j++){
            cout<<adj[i][j]<<" ";

        }
        cout<<endl;
    }

    cout<<endl;


    // output of adjacency list 
    for(int i =1;i<n+1;i++){
        cout<<i<<" : ";
        for(auto u : adj_list[i]){
            cout<<"("<<u.first<<","<<u.second<<")";
        }
        cout<<endl;
    }




    return 0;
}
