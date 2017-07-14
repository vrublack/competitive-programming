/**
    Author: Valentin Rublack
    Status: Pretests passed
    Last modified: Sun Jun 25 18:09:29 2017 +0200
    Competition: Codeforces
    Problem id: 821C
    Problem name: Okabe and Boxes
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <sstream>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <stack>

#define INF INT_MAX
#define LOOP(x, n) for(ll x = 0; x < n; x++)

using namespace std;

typedef long long int ll;
typedef unsigned int ui;

ll mod = 1000000007;


int main()
{
    cin.sync_with_stdio(false);

    ui n;
    cin >> n;

    ui last_removed = 0;
    ui reorders = 0;
    vector<ui> stack;

    LOOP(i, 2 * n)
    {
        string command;
        cin >> command;

        if (command == "add")
        {
            ui num;
            cin >> num;

            stack.push_back(num);
        } else
        {
            if (!stack.empty() && stack.back() > last_removed + 1)
            {
                // reorder necessary
                stack.clear();
                reorders++;
            } else if (!stack.empty())
            {
                stack.pop_back();
            }

            last_removed++;
        }
    }

    cout << reorders;
}
