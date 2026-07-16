/*
Syrjälä's network has n computers and m connections. 
Your task is to find out if Uolevi can send a message to Maija, and if it is possible, what is the minimum number of computers on such a route.

Input
The first input line has two integers n and m: the number of computers and connections. 
The computers are numbered 1,2,\dots,n. 
Uolevi's computer is 1 and Maija's computer is n.
Then, there are m lines describing the connections. 
Each line has two integers a and b: there is a connection between those computers.
Every connection is between two different computers, and there is at most one connection between any two computers.

Output
If it is possible to send a message, first print k: the minimum number of computers on a valid route. 
After this, print an example of such a route.
You can print any valid solution.
If there are no routes, print "IMPOSSIBLE".

Constraints

2 \le n \le 10^5
1 \le m \le 2 \cdot 10^5
1 \le a,b \le n

Example
Input:
5 5
1 2
1 3
1 4
2 3
5 4

Output:
3
1 4 5

Ans :

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
    vector<int>adj_list[n+1];
    vector<int>visited(n+1,0);
    vector<int>level(n+1,0);

    for(int i =0 ;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    int src=1;
    level[src]=0;
    visited[src]=1;

    vector<int>prev(n+1,0);
    vector<int>ans;

    queue<int>q;
    q.push(src);
    while(!q.empty()){
        int a = q.front();
        q.pop();
        for(auto u : adj_list[a]){
            if(visited[u]==0){
                visited[u]=1;
                q.push(u);
                level[u]=level[a]+1;
                prev[u]=a;
            }
        }
    }


    
    for(int cur = n; cur != 0; cur = prev[cur]){
        ans.push_back(cur);
    }

   

    int flag = true;

    if(!visited[n]){
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    if(flag){
        cout<<ans.size()<<endl;
    reverse(ans.begin(),ans.end());
    for(auto u : ans)cout<<u<<" ";
    cout<<endl;

    }else{
        cout<<"IMPOSSIBLE"<<endl;
    }



    return 0;
}

