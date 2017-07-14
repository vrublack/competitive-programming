/**
    Author: Valentin Rublack
    Status: Accepted
    Last modified: Tue Jul 4 14:00:56 2017 +0200
    Competition: Codeforces
    Problem id: 283A
    Problem name: Cows and Sequence
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

using namespace std;

typedef long long int ll;


int main()
{
    FASTIN

    cout << setprecision(10);

    ll n;
    cin >> n;

    ll count = 1;
    ll sum = 0;
    // position -> an individual addition up to that position
    multimap<ll, ll> additions;
    stack<ll> elements;
    elements.push(0);

    LOOP(i, n)
    {
        int command;
        cin >> command;
        if (command == 1)
        {
            // add x to the first a elements
            int a, x;
            cin >> a >> x;
            additions.insert(pair<ll, ll>(a, x));
            sum += a * x;
        } else if (command == 2)
        {
            // add element
            int k;
            cin >> k;
            sum += k;
            count++;
            elements.push(k);
        } else
        {
            // remove last element
            // what's the value of the last element?
            ll last_element = elements.top();
            auto it = additions.lower_bound(count);
            // all the additions up to the element can be combined into one since they go up to the same index now
            ll x = 0;
            while (it != additions.end())
            {
                auto this_it = it;
                it++;
                x += this_it->second;
                additions.erase(this_it);
            }
            additions.insert(pair<ll, ll>(count - 1, x));
            last_element += x;

            elements.pop();
            count--;
            sum -= last_element;
        }

        cout << (double) sum / count << endl;
    }
}
