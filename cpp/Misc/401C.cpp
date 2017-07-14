/**
    Author: Valentin Rublack
    Status: Accepted
    Last modified: Sun Jun 4 16:40:33 2017 +0200
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>
#include <algorithm>

#define INF INT_MAX

using namespace std;

typedef long long int ll;
typedef unsigned int uint;


int main()
{
    ll ones, zeros;
    cin >> zeros >> ones;

    ll prev_ones = 0;
    ll prev_zeros = 0;

    stringstream result;

    while (ones + zeros > 0)
    {
        if (prev_ones <= 1 && zeros <= (ones - 1) + 1)
        {
            result << "1";
            prev_ones++;
            prev_zeros = 0;
            ones--;
        } else if (prev_zeros == 0 && ones <= 2 * (zeros - 1) + 2)
        {
            result << "0";
            prev_zeros++;
            prev_ones = 0;
            zeros--;
        } else
        {
            cout << "-1" << endl;
            return 0;
        }
    }

    cout << result.str() << endl;

    return 0;
}
