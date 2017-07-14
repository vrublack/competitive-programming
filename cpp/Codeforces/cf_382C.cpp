/**
    Author: Valentin Rublack
    Status: Finally accepted (Jesus...)
    Last modified: Sun Jun 11 20:33:50 2017 +0200
    Competition: Codeforces
    Problem id: 382C
    Problem name: Arithmetic Progression
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
    vector<ll> cards(n, 0);
    LOOP(i, n) cin >> cards[i];

    sort(cards.begin(), cards.end());

    if (n == 1)
    {
        cout << -1;
    } else
    {
        int diff_i;
        int diff1_cnt = 0;
        int exception_i = -1;
        bool valid = true;

        LOOP(i, n - 1)
        {
            ll d = cards[i + 1] - cards[i];

            if (diff1_cnt == 0 || cards[diff_i + 1] - cards[diff_i] == d)
            {
                diff_i = i;
                diff1_cnt++;
            } else if (exception_i == -1)
            {
                exception_i = i;
            } else if (diff1_cnt == 1 && cards[exception_i + 1] - cards[exception_i] == d)
            {
                // swap
                int tmp = diff_i;
                diff_i = exception_i;
                exception_i = tmp;
                diff1_cnt = 2;
            } else
            {
                valid = false;
                break;
            }
        }

        vector<ll> add_cards;

        if (valid)
        {
            ll diff = cards[diff_i + 1] - cards[diff_i];

            if (exception_i == -1)
            {
                add_cards.push_back(cards[0] - diff);
                if (diff != 0)
                    add_cards.push_back(cards[n - 1] + diff);
            }

            if (n == 2 && diff != 0 && diff % 2 == 0)
                add_cards.push_back(cards[0] + diff / 2);
            else if (exception_i != -1)
            {
                // does squeezing one in between fix it?
                if (cards[exception_i + 1] - cards[exception_i] == 2 * diff)
                    add_cards.push_back(cards[exception_i] + diff);
                // in some cases we don't know if the exception isn't the rule
                if (n == 3 && diff == 2 * (cards[exception_i + 1] - cards[exception_i]))
                    add_cards.push_back(cards[diff_i] + cards[exception_i + 1] - cards[exception_i]);
            }
        }

        sort(add_cards.begin(), add_cards.end());

        cout << add_cards.size() << endl;
        for (ll add_card : add_cards)
        {
            cout << add_card << " ";
        }
    }

}
