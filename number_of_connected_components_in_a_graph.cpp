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

    //Find the number of connected components in a graph
    
    int n,m;
    cin>>n>>m;
    vector<int> adj_list[n+1];
    //vector<int> nodes;
    for(int i =0;i<m;i++){
        int u ,v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);

    }

    

    int isVisited[n+1];
    memset(isVisited,-1,sizeof isVisited);

    
    
    int connectedComponents = 0;

    for(int i =1;i<=n;i++)
    {
        if(isVisited[i]==-1){
            queue<int>q;
            int src = i;
            q.push(src);
            isVisited[src]=1;
            while(!q.empty()){
                int n = q.front();
                q.pop();
                for(auto u : adj_list[n]){
                    if(isVisited[u]==-1){
                        q.push(u);
                        isVisited[u]=1;
                    }
                }
            }
            connectedComponents++;
        }

        
    }

    cout<<connectedComponents<<endl;
    
    

    return 0;
}
