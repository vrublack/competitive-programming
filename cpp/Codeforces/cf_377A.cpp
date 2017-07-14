/**
    Author: Valentin Rublack
    Status: Accepted
    Last modified: Mon Jun 19 16:27:06 2017 +0200
    Competition: Codeforces
    Problem id: 377A
    Problem name: Maze
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <sstream>
#include <algorithm>
#include <queue>
#include <unordered_set>

#define INF INT_MAX
#define LOOP(x, n) for(int x = 0; x < n; x++)

using namespace std;

typedef long long int ll;
typedef unsigned int ui;


int main()
{
    ui n, m, k;
    cin >> n >> m >> k;
    vector<vector<char>> maze(n, vector<char>(m, ' '));
    ui empty_fields = 0;
    pair<ui, ui> *first_empty = NULL;
    LOOP(i, n) LOOP(j, m)
        {
            cin >> maze[i][j];
            if (maze[i][j] == '.')
            {
                empty_fields++;
                if (first_empty == NULL)
                    first_empty = new pair<ui, ui>(i, j);
            }
        }

    if (first_empty != NULL)
    {
        // the last k empty fields in a bfs should be turned into a wall
        queue<pair<ui, ui>> Q;
        vector<vector<bool>> in_queue(n, vector<bool>(m, false));
        Q.push(*first_empty);
        in_queue[first_empty->first][first_empty->second] = true;

        while (!Q.empty())
        {
            pair<ui, ui> V = Q.front();
            Q.pop();

            int row = V.first;
            int col = V.second;
            if (k >= empty_fields--)
                maze[row][col] = 'X';

            // corners might have been created
            for (int i = row - 1; i <= row + 1; i++)
            {
                for (int j = col - 1; j <= col + 1; j++)
                {
                    if (i >= 0 && j >= 0 && i < n && j < m && (abs(row - i) + abs(col - j) == 1) && maze[i][j] == '.' &&
                        !in_queue[i][j])
                    {
                        Q.push(pair<ui, ui>(i, j));
                        in_queue[i][j] = true;
                    }
                }
            }
        }
    }


    LOOP(i, n)
    {
        LOOP(j, m) cout << maze[i][j];

        cout << endl;
    }

}
