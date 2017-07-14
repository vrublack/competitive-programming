/**
    Author: Valentin Rublack
    Status: Accepted
    Last modified: Sun Jun 11 16:44:22 2017 +0200
    Competition: Codeforces
    Problem id: 152C
    Problem name: Pocket Book
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
    uint n, m;
    cin >> n >> m;
    vector<string> names;
    LOOP(i, n)
    {
        string s;
        cin >> s;
        names.push_back(s);
    }

    ll total = 1;

    // basically, the answer is [unique letters at column 0] * [unique letters at column 1] * ...
    LOOP(i, m)
    {
        unordered_set<char> col_set;
        uint unique_cnt = 0;

        LOOP(j, n)
        {
            char c = names[j][i];
            if (col_set.find(c) == col_set.end())
            {
                unique_cnt++;
                col_set.insert(c);
            }
        }

        total *= unique_cnt;
        total %= 1000000007;
    }

    cout << total;
}