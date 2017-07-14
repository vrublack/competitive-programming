/**
    Author: Valentin Rublack
    Status: Accepted
    Last modified: Wed Jun 7 21:21:51 2017 +0200
    Competition: Codeforces
    Problem id: 814B
    Problem name: An express train to reveries
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
typedef unsigned int uint;


void print_vector(vector<int> &a)
{
    LOOP(i, a.size())
    {
        cout << a[i];
        if (i < a.size() - 1)
            cout << " ";
    }
    cout << endl;
}

bool equal_but_one(vector<int> &a, vector<int> &b)
{
    int diff = 0;
    LOOP(i, a.size())
    {
        if (a[i] != b[i])
            diff++;

        if (diff >= 2)
            return false;
    }

    return true;
}


int main()
{
    uint n;
    cin >> n;
    vector<int> a(n, 0);
    vector<int> b(n, 0);
    LOOP(i, n)
    {
        cin >> a[i];
    }
    LOOP(i, n)
    {
        cin >> b[i];
    }

    unordered_set<int> a_set;
    int a_dup;
    LOOP(i, n)
    {
        if (a_set.find(a[i]) != a_set.end())
        {
            a_dup = a[i];
        }

        a_set.insert(a[i]);
    }

    int a_not;
    LOOP(i, n)
    {
        if (a_set.find(i + 1) == a_set.end())
        {
            a_not = i + 1;
            break;
        }
    }

    auto fix_pos_1 = find(a.begin(), a.end(), a_dup);
    auto fix_pos_2 = find(fix_pos_1 + 1, a.end(), a_dup);

    *fix_pos_1 = a_not;
    if (equal_but_one(a, b))
    {
        print_vector(a);
    } else
    {
        *fix_pos_1 = a_dup;
        *fix_pos_2 = a_not;
        // this has to work
        print_vector(a);
    }

    return 0;
}
