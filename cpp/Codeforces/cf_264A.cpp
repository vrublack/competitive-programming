/**
    Author: Valentin Rublack
    Status: Accepted
    Last modified: Wed Jun 28 23:05:28 2017 +0200
    Competition: Codeforces
    Problem id: 264A
    Problem name: Escape from Stones
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
#include <map>
#include <list>

#define INF INT_MAX
#define LOOP(x, n) for(ll x = 0; x < n; x++)
#define IT(x, l) for (auto x = l.begin(); x != l.end(); x++)

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pr;

ll mod = 1000000007;


int main()
{
    cin.sync_with_stdio(false);

    string s;
    cin >> s;

    list<int> stones;
    auto pos = stones.insert(stones.begin(), 1);

    for (int i = 0; i < s.length() - 1; i++)
    {
        if (s[i] == 'l')
            pos = stones.insert(pos, i + 2);
        else
            pos = stones.insert(++pos, i + 2);
    }

    IT(it, stones)
    {
        cout << *it << endl;
    }
}
