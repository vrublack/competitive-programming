/**
    Author: Valentin Rublack
    Status: Accepted. cin.sync_with_stdio(false) did the trick
    Last modified: Sun Jun 11 13:06:36 2017 +0200
    Competition: Codeforces
    Problem id: 463C
    Problem name: Gargari and Bishops
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
typedef unsigned int uint;


int main()
{
    int n;
    cin.sync_with_stdio(false);
    cin >> n;
    vector<vector<ll>> b(n, vector<ll>(n, 0));
    LOOP(i, n)LOOP(j, n)cin >> b[i][j];

    uint max_diag = (uint) (n);
    vector<ll> white_diag_right(max_diag, 0);
    vector<ll> black_diag_right(max_diag, 0);
    vector<ll> white_diag_left(max_diag, 0);
    vector<ll> black_diag_left(max_diag, 0);

    int black_ptr = 0;
    int white_ptr = 0;

    // start in start_col and go down right
    for (int start_col = -(n - 1); start_col < n; start_col++)
    {
        ll diag_sum = 0;

        for (int row = max(0, -start_col); row < n; row++)
        {
            int col = start_col + row;
            if (col >= n)
                break;
            diag_sum += b[row][col];
        }

        if (start_col % 2 == 0)
            white_diag_right[white_ptr++] = diag_sum;
        else
            black_diag_right[black_ptr++] = diag_sum;
    }

    black_ptr = 0;
    white_ptr = 0;

    // start in start_col and go down left
    for (int start_col = 0; start_col < 2 * n - 1; start_col++)
    {
        ll diag_sum = 0;

        for (int row = max(0, start_col - n + 1); row < n; row++)
        {
            int col = start_col - row;
            if (col < 0)
                break;
            diag_sum += b[row][col];
        }

        if (start_col % 2 == 0)
            white_diag_left[white_ptr++] = diag_sum;
        else
            black_diag_left[black_ptr++] = diag_sum;
    }

    // one of the bishops will be placed on a white field, the other one on a black field

    ll max_white = -1;
    pair<uint, uint> max_white_pos;
    ll max_black = -1;
    pair<uint, uint> max_black_pos;
    // find the max intersection
    // iterate over all fields
    LOOP(row, n)
    {
        LOOP(col, n)
        {
            int right_diag = (col - row + n - 1) / 2;
            int left_diag = (col + row) / 2;

            if ((row + col) % 2 == 0)   // white field
            {
                // don't count the field twice
                ll value = white_diag_right[right_diag] + white_diag_left[left_diag] - b[row][col];

                if (value > max_white)
                {
                    max_white = value;
                    max_white_pos = pair<uint, uint>(row, col);
                }

            } else  // black field
            {
                ll value = black_diag_right[right_diag] + black_diag_left[left_diag] - b[row][col];

                if (value > max_black)
                {
                    max_black = value;
                    max_black_pos = pair<uint, uint>(row, col);
                }
            }
        }
    }

    cout << max_white + max_black << endl << (max_white_pos.first + 1) << " " << (max_white_pos.second + 1) << " "
         << (max_black_pos.first + 1) << " " << (max_black_pos.second + 1);

    return 0;
}
