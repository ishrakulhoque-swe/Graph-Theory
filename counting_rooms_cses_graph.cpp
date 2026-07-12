// CSES Problemset / Graph Algorithm / Counting rooms

// You are given a map of a building, and your task is to count the number of its rooms. The size of the map is n \times m squares, and each square is either floor or wall. You can walk left, right, up, and down through the floor squares.
// Input
// The first input line has two integers n and m: the height and width of the map.
// Then there are n lines of m characters describing the map. Each character is either . (floor) or # (wall).
// Output
// Print one integer: the number of rooms.
// Constraints

// 1 \le n,m \le 1000

// Example
// Input:
// 5 8
// ########
// #..#...#
// ####.#.#
// #..#...#
// ########

// Output:
// 3




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
    char grid[n][m];
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            cin>>grid[i][j];
        }
    }

    int rooms = 0;
    
    int dx[4]={0,-1,0,1};
    int dy[4]={1,0,-1,0};

    int visited[n][m];
    memset(visited,-1,sizeof visited);

    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){

            for(int k =0;k<4;k++){
                if(visited[i][j]==1 || grid[i][j]=='#')continue;

                queue<pair<int,int>>q;

                q.push({i,j});
                visited[i][j]=1;
                rooms++;

                while(!q.empty()){

                    pair<int,int> p = q.front();
                    q.pop();

                    int x,y;
                    x = p.first;
                    y = p.second;

                    for(int k =0;k<4;k++){
                        int r = x+dx[k];
                        int c = y+dy[k];

                        if(r>=0 && r<n && c>=0 && c<m){
                            if(grid[r][c]=='.' && visited[r][c]==-1){
                                q.push({r,c});
                                visited[r][c]=1;
                            }
                        }
                    }

                }


            }
        }
    }

    cout<<rooms<<endl;

    return 0;
}
