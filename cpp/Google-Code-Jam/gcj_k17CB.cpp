/**
    Author: Valentin Rublack
    Status: Finally solved (f*** this)
    Last modified: Tue Jun 27 15:29:57 2017 +0200
    Competition: Google-Code-Jam
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <sstream>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <stack>

#define INF INT_MAX
#define LOOP(x, n) for(ll x = 0; x < n; x++)

using namespace std;

typedef long long int ll;
typedef unsigned int ui;
typedef pair<ll, ll> pr;

ll mod = 1000000007;


void answer(int t, string answer)
{
    cout << "Case #" << t + 1 << ": " << answer << endl;
}

int main()
{
    // implemented editorial solution

    cin.sync_with_stdio(false);

    ui T;
    cin >> T;

    LOOP(t, T)
    {
        ui n;
        cin >> n;
        vector<vector<char>> board(n, vector<char>(n, ' '));
        LOOP(r, n) LOOP(c, n) cin >> board[r][c];

        bool possible = true;

        vector<vector<int>> row_X(n, vector<int>());
        // rows
        LOOP(r, n)
        {
            // where are the x's?
            LOOP(c, n)
            {
                if (board[r][c] == 'X')
                    row_X[r].push_back(c);
            }
        }

        vector<bool> row_matched(n, false);
        bool encountered_one_r = false;
        LOOP(r, n)
        {
            if (row_matched[r])
                continue;

            if (row_X[r].size() == 1)
            {
                if (encountered_one_r)
                {
                    possible = false;
                } else
                {
                    encountered_one_r = true;
                }

                row_matched[r] = true;

                // check if there is no other X in that column
                LOOP(r2, n)
                {
                    if (r2 == r)
                        continue;

                    if (row_X[r2][0] == row_X[r][0] || row_X[r2][1] == row_X[r][0])
                    {
                        possible = false;
                        break;
                    }
                }
            } else if (row_X[r].size() == 2)
            {
                // check if X's correspond to two X's in previous row (forming a rectangle)
                LOOP(r2, n)
                {
                    if (r2 == r)
                        continue;

                    if (row_X[r2] == row_X[r])
                    {
                        if (row_matched[r2] || row_matched[r])
                        {
                            possible = false;
                            break;
                        } else
                        {
                            row_matched[r2] = true;
                            row_matched[r] = true;

                            // don't break because there might be another corresponding row in which case the result is IMPOSSIBLE
                        }
                    } else if (row_X[r2].size() == 2 &&
                               (min(row_X[r2][0], row_X[r2][1]) == min(row_X[r][0], row_X[r][1])
                                || max(row_X[r2][0], row_X[r2][1]) == max(row_X[r][0], row_X[r][1])))
                    {
                        // only one coordinate corresponds -> always false
                        possible = false;
                        break;
                    }
                }
            } else
            {
                possible = false;
            }

            if (!row_matched[r])
                possible = false;

            if (!possible)
                break;
        }

        // finally check if every row has a corresponding row\
        if (possible)
        {
            LOOP(r, n)
                if (!row_matched[r])
                {
                    possible = false;
                    break;
                }
        }

        if (possible)
            answer(t, "POSSIBLE");
        else
            answer(t, "IMPOSSIBLE");
    }
}
