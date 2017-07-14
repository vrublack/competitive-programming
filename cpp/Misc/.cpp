/**
    Author: Valentin Rublack
    Status: Algorithm to find prime numbers (Sieve of Eratosthenes)
    Last modified: Mon Jul 3 15:17:49 2017 +0200
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
#include <set>

#define INF INT_MAX
#define LOOP(x, n) for(int x = 0; x < n; x++)

using namespace std;


/**
 * Sieve of Eratosthenes
 * @param n Upper bound for primes
 * @return All primes <= n
 */
vector<unsigned int> find_primes(unsigned int n)
{
    vector<bool> prime(n + 1, true);

    for (unsigned int p = 2; p <= n / p; p++)
    {
        if (prime[p])
            for (unsigned int i = p * 2; i <= n; i += p)
                prime[i] = false;
    }

    vector<unsigned int> prime_list;

    for (unsigned int p = 2; p <= n; p++)
        if (prime[p])
            prime_list.push_back(p);

    return prime_list;
}

int main()
{

}
