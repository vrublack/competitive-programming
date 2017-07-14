/**
    Author: Valentin Rublack
    Status: Accepted
    Last modified: Wed Jun 14 14:26:46 2017 +0200
    Competition: Codeforces
    Problem id: 339C
    Problem name: Xenia and Weights
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


// backtracking
bool has_answer(set<int> &weights, int left_sum, int right_sum, int last_weight, int m, vector<int> &solution)
{
    if (m == 0)
        return true;

    for (int w : weights)
    {
        if (w == last_weight)
            continue;

        bool success;
        if (m % 2 == 0)
            success = (left_sum + w) > right_sum && has_answer(weights, left_sum + w, right_sum, w, m - 1, solution);
        else
            success = (right_sum + w) > left_sum && has_answer(weights, left_sum, right_sum + w, w, m - 1, solution);

        if (success)
        {
            solution.push_back(w);
            return true;
        }
    }

    return false;
}


int main()
{
    // similar to editorial idea, except using trees implicitly with backtracking

    set<int> weights;
    string w_str;
    cin >> w_str;
    LOOP(i, w_str.length())
    {
        if (w_str[i] == '1')
            weights.insert(i + 1);
    }
    int m;
    cin >> m;

    vector<int> solution;

    if (has_answer(weights, 0, 0, -1, m, solution))
    {
        reverse(solution.begin(), solution.end());
        cout << "YES" << endl;
        LOOP(j, m)
        {
            cout << solution[j] << ' ';
        }
    } else
    {
        cout << "NO";
    }
}
