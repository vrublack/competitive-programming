/**
    Author: Valentin Rublack
    Status: Accepted
    Last modified: Tue Jun 13 18:44:23 2017 +0200
    Competition: Codeforces
    Problem id: 388A
    Problem name: Fox and Box Accumulation
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
    ui n;
    cin >> n;
    vector<ui> a(n, 0);
    LOOP(i, n) cin >> a[i];

    sort(a.begin(), a.end());

    // size of each pile
    priority_queue<int, std::vector<int>, std::greater<int>> pile_sizes;
    pile_sizes.push(0);

    LOOP(i, n)
    {
        int smallest_pile = pile_sizes.top();

        if (smallest_pile <= a[i])
        {
            // element can be placed under previous ones in that pile
            pile_sizes.pop();
            pile_sizes.push(smallest_pile + 1);
        } else
        {
            // new pile
            pile_sizes.push(1);
        }
    }

    cout << pile_sizes.size();
}
