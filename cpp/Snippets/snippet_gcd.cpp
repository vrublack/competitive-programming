/**
    Author: Valentin Rublack
    Status: Own implementation of extended Euclidean algorithm to compute the gcd of two numbers and Bezouts identity
    Last modified: Thu Jun 29 12:16:36 2017 +0200
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
#include <map>
#include <list>
#include <climits>
#include <cstring>

#define INF INT_MAX
#define LOOP(x, n) for(ll x = 0; x < n; x++)
#define IT(x, l) for (auto x = l.begin(); x != l.end(); x++)

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pr;
typedef pair<long, int> ii;
typedef array<ll, 3> GUV;

/**
 * Extended Euclidean algorithm
 * @param a
 * @param b
 * @return gcd of a and b, and x, y with x*a + y*b = gcd
 */
GUV gcd(ll a, ll b)
{
    if (b == 0)
    {
        if (a >= 0)
            return GUV{a, 1, 0};
        else
            return GUV{-a, -1, 0};
    } else
    {
        GUV res = gcd(b, a % b);
        return GUV{res[0], res[2], res[1] - a / b * res[2]};
    }
}


int main()
{

}
