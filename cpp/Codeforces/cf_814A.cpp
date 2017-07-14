/**
    Author: Valentin Rublack
    Status: Accepted, better solution
    Last modified: Wed Jun 7 20:18:40 2017 +0200
    Competition: Codeforces
    Problem id: 814A
    Problem name: An abandoned sentiment from past
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <sstream>
#include <algorithm>
#include <queue>

#define INF INT_MAX
#define LOOP(x, n) for(int x = 0; x < n; x++)

using namespace std;

typedef long long int ll;
typedef unsigned int uint;


int main()
{
    // Solved after editorial http://codeforces.com/blog/entry/52449

    uint n, k;
    cin >> n >> k;
    vector<int> a(n, 0);
    vector<int> b(n, 0);
    LOOP(i, n)
    {
        cin >> a[i];
    }
    LOOP(i, k)
    {
        cin >> b[i];
    }

    if (k >= 2)
    {
        cout << "Yes" << endl;
        return 0;
    }

    // insert into only 0 and check
    int zero_pos = find(a.begin(), a.end(), 0) - a.begin();
    a[zero_pos] = b[0];

    LOOP(i, n - 1)
    {
        if (a[i] >= a[i + 1])
        {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}
