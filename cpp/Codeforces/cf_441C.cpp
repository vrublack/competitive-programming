/**
    Author: Valentin Rublack
    Status: Accepted
    Last modified: Fri Jun 9 14:09:11 2017 +0200
    Competition: Codeforces
    Problem id: 441C
    Problem name: Valera and Tubes 
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
    uint n, m, k;
    cin >> n >> m >> k;

    int row = 0;
    int col = 0;
    int dir = 1;

    LOOP(i, k)
    {
        int r;
        if (i < k - 1)
            r = n * m / k;
        else
            r = n * m / k + (n * m) % k;

        cout << r;

        LOOP(j, r)
        {
            cout << " " << (row + 1) << " " << (col + 1);

            int next_col = col + dir;
            if (next_col < 0 || next_col >= m)
            {
                dir *= -1;
                row++;
            } else
            {
                col = next_col;
            }
        }

        cout << endl;
    }


    return 0;
}
