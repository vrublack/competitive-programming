/**
    Author: Valentin Rublack
    Status: Accepted
    Last modified: Thu Jul 13 22:39:56 2017 +0200
    Competition: Codeforces
    Problem id: 831A
    Problem name: Unimodal Array
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

    int n;
    cin >> n;
    READLV(a, n)

    bool unimodal = true;
    int mode = 0;
    LOOP(i, n - 1)
    {
        if (a[i] < a[i + 1])
        {
            if (mode > 0)
            {
                unimodal = false;
                break;
            }
        } else if (a[i] == a[i + 1])
        {
            if (mode > 1)
            {
                unimodal = false;
                break;
            }

            mode = 1;
        } else
        {
            mode = 2;
        }
    }

    if (unimodal)
        cout << "YES";
    else
        cout << "NO";
}
