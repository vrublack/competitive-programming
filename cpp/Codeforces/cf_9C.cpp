/**
    Author: Valentin Rublack
    Status: Accepted
    Last modified: Tue Jun 13 19:53:08 2017 +0200
    Competition: Codeforces
    Problem id: 9C
    Problem name: Hexadecimal's Numbers
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
typedef unsigned int ui;


int main()
{
    string n;
    cin >> n;

    ll answer = 0;

    // round to nearest smaller or equal number with only 0 & 1
    bool greater_one = false;
    LOOP(i, n.length())
    {
        if (n[i] > '1')
            greater_one = true;
        if (greater_one || n[i] != '0')
            n[i] = '1';
    }

    // convert number in binary to decimal
    LOOP(i, n.length())
    {
        answer = 2 * answer + (n[i] - '0');
    }

    cout << answer;
}
