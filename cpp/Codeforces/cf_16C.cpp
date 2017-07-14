/**
    Author: Valentin Rublack
    Status: Accepted
    Last modified: Mon May 29 20:25:24 2017 +0200
    Competition: Codeforces
    Problem id: 16C
    Problem name: Monitor
*/

#include <iostream>

using namespace std;

typedef long long int ll;

ll gcd(ll a, ll b)
{
    if (b == 0)
    {
        if (a >= 0)
            return a;
        else
            return -a;
    } else
    {
        return gcd(b, a % b);
    }
}


int main()
{
    long a, b, x, y;
    cin >> a >> b >> x >> y;

    ll g = gcd(x, y);
    x /= g;
    y /= g;


    // find largest c such that x * c <= a and y * c <= b

    long c = min(a / x, b / y);
    long p = x * c;
    long q = y * c;

    cout << p << " " << q << endl;

    return 0;
}