/**
    Author: Valentin Rublack
    Status: Accepted
    Last modified: Wed Jul 5 22:43:58 2017 +0200
    Competition: Codeforces
    Problem id: 464A
    Problem name: No to Palindromes!
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
#include <array>
#include <stack>
#include <iomanip>

#define FASTIN cin.sync_with_stdio(false);
#define INF INT_MAX
#define LOOP(x, n) for(int x = 0; x < n; x++)
#define READLV(a, n) vector<long long int> a(n, 0); LOOP(i, n) cin >> a[i];
#define READBV(a, n) vector<bool> a(n, 0); LOOP(i, n) {int v; cin >> v; a[i] = (bool) v; }
#define pb push_back

using namespace std;

typedef long long int ll;


int main()
{
    int n, p;
    cin >> n >> p;
    string s;
    cin >> s;

    int i = n - 1;
    bool changed = false;
    // increase s[i] as long as it's causing a palindrome on the left side, and move left if s[i] larger than p
    while (!changed || !((i == 0 || s[i] != s[i - 1]) && (i <= 1 || s[i] != s[i - 2])))
    {
        s[i]++;
        changed = true;
        if (s[i] - 'a' > p - 1)
        {
            s[i] = 'a';
            i--;
            if (i < 0 || i == 0 && s[i] - 'a' == p - 1)
            {
                cout << "NO";
                return 0;
            }
            changed = false;
        }
    }

    for (; i < n; i++)
    {
        while (!((i == 0 || s[i] != s[i - 1]) && (i <= 1 || s[i] != s[i - 2])))
        {
            s[i]++;
        }
    }

    cout << s;
}
