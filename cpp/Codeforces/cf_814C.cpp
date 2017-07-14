/**
    Author: Valentin Rublack
    Status: Accepted
    Last modified: Thu Jun 8 12:06:40 2017 +0200
    Competition: Codeforces
    Problem id: 814C
    Problem name: An impassioned circulation of affection
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
    uint n;
    cin >> n;
    string s;
    cin >> s;
    uint q;
    cin >> q;
    vector<pair<int, char>> plans(q, pair<int, char>(0, 0));
    LOOP(i, q)
    {
        cin >> plans[i].first >> plans[i].second;
    }

    // how many occurrences of one letter up to i (point X letter)
    vector<vector<int>> letter_cnt(n, vector<int>(26, 0));
    LOOP(c, 26)
    {
        LOOP(i, n)
        {
            letter_cnt[i][c] = (i > 0 ? letter_cnt[i - 1][c] : 0) + (s[i] == c + 'a');
        }
    }

    // c X m
    vector<vector<int>> best(26, vector<int>(n + 1, 0));

    // iterate over all intervals
    for (int start = 0; start < n; start++)
    {
        for (int end = start; end < n; end++)
        {
            for (char c = 0; c < 26; c++)
            {
                int cs_in_interval = letter_cnt[end][c] - (start > 0 ? letter_cnt[start - 1][c] : 0);
                int m_needed = end - start + 1 - cs_in_interval;
                int painted_interval = (end - start + 1);
                best[c][m_needed] = max(best[c][m_needed], painted_interval);
            }
        }
    }

    // m_needed might always be smaller than the query, but you can of course paint a max series and use less than you have
    LOOP(c, 26)
    {
        LOOP(i, n + 1)
        {
            if (i > 0)
                best[c][i] = max(best[c][i], best[c][i - 1]);
        }
    }

    for (pair<int, char> plan : plans)
    {
        cout << best[plan.second - 'a'][plan.first] << endl;
    }

    return 0;
}
