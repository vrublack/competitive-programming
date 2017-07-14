/**
    Author: Valentin Rublack
    Status: Square-and-multiply algorithm to compute the power of a number
    Last modified: Thu Jun 29 12:34:53 2017 +0200
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>
#include <algorithm>
#include <queue>
#include <climits>

#define INF INT_MAX
#define LOOP(x, n) for(int x = 0; x < n; x++)

using namespace std;

typedef long long int ll;
typedef unsigned int uint;


/**
 * Square-and-multiply algorithm to compute the power of a number.
 * @param a Base
 * @param e Exponent
 * @param mod Calculation will be modulus this number
 * @return
 */
ll my_pow(ll a, ll e, ll mod)
{
    if (e == 0)
        return 1;

    // square and multiply
    if (e % 2 == 0)
    {
        ll partialRes = my_pow(a, e / 2, mod);
        return (partialRes * partialRes) % mod;
    } else
    {
        return (a * my_pow(a, e - 1, mod)) % mod;
    }
}

int main()
{

}
