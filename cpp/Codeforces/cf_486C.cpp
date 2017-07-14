/**
    Author: Valentin Rublack
    Status: Accepted
    Last modified: Fri Jun 9 15:58:02 2017 +0200
    Competition: Codeforces
    Problem id: 486C
    Problem name: Palindrome Transformation
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
    int n, p;
    cin >> n >> p;
    string s;
    cin >> s;

    // We can always optimally solve the problem in the half where p is. For simplicity, move p into the first half.
    if (p > n / 2)
    {
        p = n - p + 1;
    }
    // make it 0-based
    p--;

    int up_down = 0;

    int first_unequal = -1;
    int last_unequal = -1;
    LOOP(i, n / 2)
    {
        int diff = abs(s[i] - s[n - i - 1]);
        int necessary_shifts = min(diff, 26 - diff);
        if (necessary_shifts > 0)
        {
            if (first_unequal == -1)
                first_unequal = i;
            last_unequal = i;
        }
        up_down += necessary_shifts;
    }

    if (up_down == 0)
    {
        cout << 0 << endl;
        return 0;
    }

    int left_right;
    // compute necessary left/right movements
    if (first_unequal <= p && last_unequal >= p)
    {
        int to_left = p - first_unequal;
        int to_right = last_unequal - p;
        left_right = min(to_left * 2 + to_right, to_left + to_right * 2);
    } else
    {
        left_right = max(abs(p - first_unequal), abs(p - last_unequal));
    }

    cout << (up_down + left_right) << endl;

    return 0;
}
