/**
    Author: Valentin Rublack
    Status: Pretests passed
    Last modified: Sun Jul 2 18:57:56 2017 +0200
    Competition: Codeforces
    Problem id: 822B
    Problem name: Crossword solving
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>
#include <algorithm>
#include <queue>
#include <climits>
#include <numeric>
#include <map>

#define INF INT_MAX
#define LOOP(x, n) for(int x = 0; x < n; x++)

using namespace std;

typedef long long int ll;


int main()
{
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;

    int min_replacements = -1;
    int opt_s_start;

    for (int s_start = 0; s_start <= t.length() - s.length(); s_start++)
    {
        int replacements = 0;

        LOOP(i, s.length())
        {
            if (s[i] != t[s_start + i])
                replacements++;
        }

        if (min_replacements == -1 || replacements < min_replacements)
        {
            min_replacements = replacements;
            opt_s_start = s_start;
        }
    }

    cout << min_replacements << endl;
    LOOP(i, s.length())
    {
        if (s[i] != t[opt_s_start + i])
            cout << (i + 1) << " ";
    }


}
