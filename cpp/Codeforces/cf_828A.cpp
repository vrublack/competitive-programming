/**
    Author: Valentin Rublack
    Status: Correct
    Last modified: Tue Jul 11 22:52:38 2017 +0200
    Competition: Codeforces
    Problem id: 828A
    Problem name: Restaurant Tables
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>

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
    int n, a, b;
    cin >> n >> a >> b;
    READLV(t, n)

    int b_one = 0;
    int b_two = b;
    int denied = 0;
    LOOP(i, t.size())
    {
        if (t[i] == 1)
        {
            if (a > 0)
                a--;
            else if (b_two > 0)
            {
                b_two--;
                b_one++;
            } else if (b_one > 0)
                b_one--;
            else
                denied++;
        } else
        {
            if (b_two > 0)
                b_two--;
            else
                denied += 2;
        }
    }

    cout << denied;
}
