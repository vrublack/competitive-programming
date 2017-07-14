/**
    Author: Valentin Rublack
    Status: Accepted
    Last modified: Fri Jun 9 17:44:06 2017 +0200
    Competition: Codeforces
    Problem id: 363C
    Problem name: Fixing Typos
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
    string s;
    cin >> s;

    int last_streak = 0;
    int current_streak = 0;
    uint n = s.length();
    LOOP(i, n)
    {
        bool remove = false;
        if (i > 0 && s[i - 1] == s[i])
        {
            if (current_streak == 1 && last_streak >= 2)
            {
                // cut
                remove = true;
            } else if (current_streak >= 2)
            {
                // cut to two
                remove = true;
            }
        } else
        {
            last_streak = current_streak;
            current_streak = 0;
        }

        if (!remove)
        {
            cout << s[i];
            current_streak++;
        }
    }

    return 0;
}
