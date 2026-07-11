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

    // graph traversal (unweighted && undirected) - BFS ( Breadth First Search)

    int n, m;
    cin>>n>>m;

    vector<int> adj_list[n+1];

    for(int i = 0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);

    }

    // printing all the adjacent nodes for each node

    for(int i =1;i<=n;i++){
        
        cout<<"Node : "<<i<<" -> Adjacent nodes : ";
        for(auto u : adj_list[i]){
            cout<<u<<" ";
        }
        cout<<endl;
    }


    // Travelling through the graph 
    
    // Here , i am maintaining a queue for nodes 
    // And an array to mark the level of each node
    // Traversal will complete if the queue is empty 
    // 1. We will take first element from the array 
    // 2. Then we will take the adjacent nodes of that picked node from queue 
    // 3. Assign them level ; the level will be (level + 1) of picked noded from the queue
    // 4. we will put the adjacent nodes from the step 2 in the queue (If they are unvisited) and pop out the current picked node from the queue (1st element of the queue)
    // Once the queue is empty , we will stop our operation 

    int level[n+1];

    int is_visited[n+1];

    memset(is_visited, -1 , sizeof is_visited);

    queue<int>nodes;

    int src_node = 1;

    nodes.push(src_node);

    level[src_node]=0;

    is_visited[src_node]=1;
    
    while(!nodes.empty()){

        int n = nodes.front();

        nodes.pop();

        for(auto u : adj_list[n]){
            if(is_visited[u]==-1){
                level[u]=level[n]+1;
                nodes.push(u);
                is_visited[u]=1;

            }
        }

    }
    
    cout<<endl;

    // Checking level of all the nodes

    for(int i =1;i<=n;i++){
        cout<<"Node : "<<i<<" -> Level : "<<level[i]<<endl;
    }







    return 0;
}
