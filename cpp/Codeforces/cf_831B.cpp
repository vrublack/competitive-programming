/**
    Author: Valentin Rublack
    Status: Accepted
    Last modified: Thu Jul 13 22:40:07 2017 +0200
    Competition: Codeforces
    Problem id: 831B
    Problem name: Keyboard Layouts
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
#include <sstream>

#define FASTIN cin.sync_with_stdio(false);
#define INF INT_MAX
#define INF_LL LLONG_MAX
#define LOOP(x, n) for(int x = 0; x < n; x++)
#define READLV(a, n) vector<long long int> a(n, 0); LOOP(i, n) cin >> a[i];
#define READBV(a, n) vector<bool> a(n, 0); LOOP(i, n) {int v; cin >> v; a[i] = (bool) v; }
#define pb push_back

using namespace std;

typedef long long int ll;
typedef unsigned int ui;
typedef pair<long, int> ii;


int main()
{
    FASTIN

    string l1, l2, s;
    cin >> l1 >> l2 >> s;

    int hist_l1[26];
    LOOP(i, l1.length())hist_l1[l1[i] - 'a'] = i;

    stringstream ss;
    LOOP(i, s.length())
    {
        if (s[i] >= '0' && s[i] <= '9')
            ss << s[i];
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            ss << (char) (l2[hist_l1[s[i] - 'A']] + ('A' - 'a'));
        } else
        {
            ss << (char) l2[hist_l1[s[i] - 'a']];
        }
    }

    cout << ss.str();
}
