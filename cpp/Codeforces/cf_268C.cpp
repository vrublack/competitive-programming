/**
    Author: Valentin Rublack
    Status: Accepted
    Last modified: Tue Jun 6 21:59:08 2017 +0200
    Competition: Codeforces
    Problem id: 268C
    Problem name: Beautiful Sets of Points
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>
#include <algorithm>

#define INF INT_MAX
#define LOOP(x, n) for(int x = 0; x < n; x++)

using namespace std;

typedef long long int ll;
typedef unsigned int uint;


int main()
{
    int n, m;
    cin >> n >> m;

    // compute all pythagorean triples
    vector<vector<int>> pyth_triples;

    for (int a = 1; a <= n; a++)
        for (int b = a + 1; b <= m; b++)
        {
            double r = sqrt(a * a + b * b);

            if (r == (int) r)
            {
                pyth_triples.push_back(vector<int>(3, 0));
                pyth_triples.back()[0] = a;
                pyth_triples.back()[1] = b;
                pyth_triples.back()[2] = (int) r;
            }
        }

    vector<pair<int, int>> beautiful_set;

    int x = n;
    int y = 0;

    while (x >= 0 && y <= m)
    {
        beautiful_set.push_back(pair<int, int>(x, y));
        x--;
        y++;
    }

    /*
    // CHECK
    for (pair<int, int> p : beautiful_set)
    {
        for (pair<int, int> q : beautiful_set)
        {
            if (p == q)
                continue;

            int a = p.first - q.first;
            int b = p.second - q.second;

            double r = sqrt(a * a + b * b);
            if (r == (int) r)
            {
                cout << "error" << endl;
            }
        }
    }*/

    cout << beautiful_set.size() << endl;
    for (pair<int, int> p : beautiful_set)
        cout << p.first << " " << p.second << endl;

    return 0;
}
