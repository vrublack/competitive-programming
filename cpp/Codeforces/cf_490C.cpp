/**
    Author: Valentin Rublack
    Status: Accepted
    Last modified: Fri Jun 9 22:38:41 2017 +0200
    Competition: Codeforces
    Problem id: 490C
    Problem name: Hacking Cypher
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
    string key;
    ll a, b;
    cin >> key >> a >> b;

    // key[:i] % a
    vector<ll> left_mod(key.length(), 0);

    ll num = 0;
    LOOP(i, key.length())
    {
        num = 10 * num + (key[i] - '0');
        num %= a;
        left_mod[i] = num;
    }

    num = 0;
    ll ten_pot = 1;
    for (int i = key.size() - 1; i >= 1; i--)
    {
        num = num + (key[i] - '0') * ten_pot;
        ten_pot *= 10;
        ten_pot %= b;
        num %= b;

        if (key[i] != '0' && num == 0 && left_mod[i - 1] == 0)
        {
            cout << "YES" << endl << key.substr(0, i) << endl << key.substr(i);
            return 0;
        }
    }

    cout << "NO";

    return 0;
}
