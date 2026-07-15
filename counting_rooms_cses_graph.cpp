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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    char grid[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int visited[n][m];
    memset(visited, 0, sizeof(visited));

    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {1, 0, -1, 0};

    int rooms = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            if (grid[i][j] == '#' || visited[i][j] == 1)
                continue;

            rooms++;

            queue<pair<int, int>> q;
            q.push({i, j});
            visited[i][j] = 1;

            while (!q.empty()) {

                pair<int, int> p = q.front();
                q.pop();

                int x = p.first;
                int y = p.second;

                for (int k = 0; k < 4; k++) {

                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if (nx >= 0 && nx < n &&
                        ny >= 0 && ny < m &&
                        grid[nx][ny] == '.' &&
                        visited[nx][ny] == 0) {

                        visited[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }

    cout << rooms << endl;

    return 0;
}
