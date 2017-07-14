/**
    Author: Valentin Rublack
    Status: Correct
    Last modified: Tue Jul 11 22:53:04 2017 +0200
    Competition: Codeforces
    Problem id: 828B
    Problem name: Black Square
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <climits>

#define FASTIN cin.sync_with_stdio(false);
#define INF INT_MAX
#define LOOP(x, n) for(int x = 0; x < n; x++)
#define READLV(a, n) vector<long long int> a(n, 0); LOOP(i, n) cin >> a[i];
#define READBV(a, n) vector<bool> a(n, 0); LOOP(i, n) {int v; cin >> v; a[i] = (bool) v; }
#define pb push_back

using namespace std;

typedef long long int ll;


int main()
{
    int n, m;
    cin >> n >> m;
    int min_r = INF;
    int max_r = -1;
    int min_c = INF;
    int max_c = -1;
    vector<vector<char>> sheet(n, vector<char>(m, ' '));
    LOOP(r, n)
    {
        LOOP(c, m)
        {
            cin >> sheet[r][c];
            if (sheet[r][c] == 'B')
            {
                min_r = min(min_r, r);
                max_r = max(max_r, r);
                min_c = min(min_c, c);
                max_c = max(max_c, c);
            }
        }
    }

    if (max_r == -1)
    {
        cout << 1;
        return 0;
    }

    int dist_r = max_r - min_r + 1;
    int dist_c = max_c - min_c + 1;
    int side_length = max(dist_r, dist_c);
    int count = 0;
    int r_steps, c_steps;
    bool done = false;
    for (r_steps = 0; r_steps < side_length; r_steps++)
    {
        for (c_steps = 0; c_steps < side_length; c_steps++)
        {
            int r = max(0, max_r - side_length + 1) + r_steps;
            int c = max(0, max_c - side_length + 1) + c_steps;

            if (r >= n || c >= m)
            {
                done = true;
                break;
            }

            if (sheet[r][c] == 'W')
                count++;
        }

        if (done)
            break;
    }

    if (r_steps == side_length && c_steps == side_length)
        cout << count;
    else
        cout << -1;
}
