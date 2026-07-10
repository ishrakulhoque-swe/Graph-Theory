// Taking input for unweighted graph using adjacency  matrix and adjacency list representation

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

    
    int n,m; // n-> Nodes ; m-> edges
    cin>>n>>m;

    // Adjacency matrix presentation

    int adj[n+1][n+1];
    memset(adj,0,sizeof adj);

  
    // Adjacency list representation 
    vector<int> adj_list[n+1];

  
    
    for(int i =0;i<m;i++){
        int u,v;
        cin>>u>>v;

        // marking 1 if there is a edge between two nodes in matrix , otherwise it will remain zero
        adj[u][v]=1;
        adj[v][u]=1;

        // here v is a adjacent node of u , so we pushing v in adjacency vector list of u ; for node u , we are doing vice versa
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);

    }
    

    // output for matrix 
    for(int i =1;i<n+1;i++){
        for(int j = 1;j<n+1;j++){
            cout<<adj[i][j]<<" ";

        }
        cout<<endl;
    }

    cout<<endl;

    // output for list 
    for(int i =1;i<n+1;i++){
        cout<<i<<" : ";
        for(auto u : adj_list[i]){
            cout<<u<<" ";
        }
        cout<<endl;
    }




    return 0;
}
