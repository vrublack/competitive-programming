/**
    Author: Valentin Rublack
    Status: Accepted
    Last modified: Sun Jun 4 11:11:42 2017 +0200
    Competition: Codeforces
    Problem id: 489C
    Problem name: Given Length and Sum of Digits...
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
    int m, s;
    cin >> m >> s;

    if (s == 0)
    {
        if (m == 1)
            cout << "0 0" << endl;
        else
            cout << "-1 -1" << endl;

        return 0;
    }

    if (s > m * 9)
    {
        cout << "-1 -1" << endl;
        return 0;
    }

    // largest number is always '9'*x + (s - 9*x)
    int largest_9s = s / 9;
    int largest_r = s - largest_9s * 9;
    int largest_zeros = m - largest_9s - 1;
    string largest_num;
    if (largest_zeros < 0)
        largest_num = string(largest_9s, '9');
    else
        largest_num = string(largest_9s, '9') + to_string(largest_r) + string(m - largest_9s - 1, '0');

    int smallest_9s = (s - 1) / 9;
    int smallest_r = (s - 1) - smallest_9s * 9;
    int smallest_zeros = m - smallest_9s - 2;
    string lowest_num;
    if (smallest_zeros < 0)
    {
        lowest_num = string(largest_num);
        reverse(lowest_num.begin(), lowest_num.end());
    } else
    {
        // for the smallest number it's slightly more difficult since we can't pad with 0s in the front
        lowest_num = '1' + string(smallest_zeros, '0') + to_string(smallest_r) + string(smallest_9s, '9');
    }

    cout << lowest_num << " " << largest_num << endl;

    return 0;
}
