/**
    Author: Valentin Rublack
    Status: Accepted
    Last modified: Sun Jun 11 17:02:52 2017 +0200
    Competition: Codeforces
    Problem id: 109A
    Problem name: Lucky Sum of Digits
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

    // n = 4*x + 7*y

    // try out all values for x and see if we can solve the above equation
    for (int x = 0; x <= n / 4; x++)
    {
        if ((n - x * 4) % 7 == 0)
        {
            ui y = (n - x * 4) / 7;
            cout << string(x, '4') + string(y, '7');
            return 0;
        }
    }

    cout << -1;
}