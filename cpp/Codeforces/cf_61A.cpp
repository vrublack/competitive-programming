/**
    Author: Valentin Rublack
    Status: Accepted
    Last modified: Fri Jun 9 16:09:04 2017 +0200
    Competition: Codeforces
    Problem id: 61A
    Problem name: Ultra-Fast Mathematician
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
    string s, u;
    cin >> s >> u;

    LOOP(i, s.length())
    {
        int xored = (s[i] - '0') ^(u[i] - '0');
        cout << xored;
    }

    return 0;
}
