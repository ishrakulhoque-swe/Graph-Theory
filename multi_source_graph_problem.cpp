/*
    Given an undirected graph with n nodes and m edges.
    Initially, k nodes are burning.
    Every second, fire spreads from a burning node to all of its adjacent nodes. 
    Determine the minimum number of seconds required for every node in the graph to catch fire. 
    If some nodes can never catch fire, output -1.

    Sample Input : 
    10 10        <- n,m
    1 3
    1 2
    3 5
    2 6
    2 4
    4 7 
    4 8
    7 9
    8 9
    6 10
    3            <- k (numbers of burning nodes)
    1            
    5
    8

    Sample output :
    3

*/


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

    int n,m;
    cin>>n>>m;

    vector<int> adj_list[n+1];

    for(int i =0;i<m;i++){
        int u , v;
        cin>>u>>v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    int visited[n+1];
    memset(visited, -1 , sizeof visited);
    
    int k;
    cin>>k;
    vector<int>fire(k);
    for(int i =0;i<k;i++){
        cin>>fire[i];
    }

    queue<int>q;
    for(int i =0;i<k;i++){
        q.push(fire[i]);
    }

    int level[n+1];
    memset(level, -1,sizeof level);
    for(int i =0;i<k;i++){
        level[fire[i]]=0;
        visited[fire[i]]=1;
    }

    while(!q.empty()){
        int frnt = q.front();
        q.pop();
        for(auto u : adj_list[frnt]){
            if(visited[u]==-1){
                visited[u]=1;
                level[u]=level[frnt]+1;
                q.push(u);
            }
        }
    }

    
    int ans = 0;

    for(int i=1;i<=n;i++){
    if(level[i] == -1){
        cout << -1 << endl;
        return 0;
        }
        
        ans = max(ans, level[i]);
    }

    cout << ans << endl;



    return 0;
}
