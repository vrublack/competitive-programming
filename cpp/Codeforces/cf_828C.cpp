/**
    Author: Valentin Rublack
    Status: Correct
    Last modified: Tue Jul 11 22:53:36 2017 +0200
    Competition: Codeforces
    Problem id: 828C
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <climits>
#include <array>

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
    FASTIN

    int n;
    cin >> n;
    array<int, 4000000> t_index{};
    array<int, 4000000> t_length{};
    vector<string> ts;
    int max_pos = -1;

    LOOP(i, n)
    {
        string t;
        cin >> t;
        ts.pb(t);
        int k;
        cin >> k;
        LOOP(j, k)
        {
            int pos;
            cin >> pos;

            if (t.length() > t_length[pos - 1])
            {
                t_length[pos - 1] = t.length();
                t_index[pos - 1] = i;
            }

            max_pos = max(max_pos, pos - 2 + (int) t.length());
        }
    }

    int i = 0;
    while (i <= max_pos)
    {
        if (t_length[i] == 0)
        {
            cout << 'a';
            i++;
        } else
        {
            int j = 0;
            while (j < t_length[i] && (t_length[i + j] <= t_length[i] - j))
                cout << ts[t_index[i]][j++];
            i += j;
        }
    }

}
