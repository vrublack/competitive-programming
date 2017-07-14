/**
    Author: Valentin Rublack
    Status: Changed own solution similar to the one in editorial; sync_with_stdio was necessary as well.
    Last modified: Wed Jun 21 16:27:22 2017 +0200
    Competition: Codeforces
    Problem id: 385C
    Problem name: Bear and Prime Numbers
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <sstream>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <map>
#include <unordered_map>

#define INF INT_MAX
#define LOOP(x, n) for(int x = 0; x < n; x++)

using namespace std;

typedef long long int ll;
typedef unsigned int ui;
typedef pair<ll, ll> pr;

// find all primes up to n
vector<ll> find_primes(ll n)
{
    vector<bool> prime(n + 1, true);

    // sieve of Eratosthenes
    for (ll i = 2; i <= sqrt(n); i++)
    {
        if (prime[i])
        {
            for (ll j = i * i; j <= n; j += i)
            {
                prime[j] = false;
            }
        }
    }

    vector<ll> prime_list;
    LOOP(i, prime.size())
    {
        if (prime[i] && i >= 2)
            prime_list.push_back(i);
    }

    return prime_list;
}


int main()
{
    cin.sync_with_stdio(false);

    ui n;
    cin >> n;
    // x_hist[i] = how many i there are
    vector<ll> x_hist(10000000, 0);
    ll max_x = -1;
    LOOP(i, n)
    {
        ll xi;
        cin >> xi;
        max_x = max(max_x, xi);
        x_hist[xi]++;
    }
    ui m;
    cin >> m;
    vector<pr> queries(m, pr());
    LOOP(i, m) cin >> queries[i].first >> queries[i].second;

    ll max_query_right = max_element(queries.begin(), queries.end(), [](pr &lhs, pr &rhs)
    {
        return lhs.second < rhs.second;
    })->second;
    ll max_prime = min(max_query_right, max_x);
    vector<ll> primes = find_primes(max_prime);     // max_prime <= 10^7, so in O(n log log n) ~ O(10^7)

    // this was suggested in the editorial
    // f_acc[p] = # numbers from x_i that are divisible by prime q <= p
    vector<ll> f_acc(max_prime + 1, 0);
    ll prev_cnt = 0;

    for (int i = 0; i < primes.size(); i++)
    {
        ll p = primes[i];

        for (ll j = i > 0 ? (primes[i - 1] + 1) : 0; j < p; j++)
            f_acc[j] = prev_cnt;

        f_acc[p] = prev_cnt;

        for (ll j = 1; j <= max_x / p; j++)
        {
            f_acc[p] += x_hist[p * j];
        }

        prev_cnt = f_acc[p];
    }

    for (ll j = primes.back() + 1; j < f_acc.size(); j++)
        f_acc[j] = prev_cnt;

    for (pr query: queries)
    {
        ll left = f_acc[min(query.first - 1, max_prime)];
        ll right = f_acc[min(query.second, max_prime)];

        cout << right - left << endl;
    }


    return 0;
}
