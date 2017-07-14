/**
    Author: Valentin Rublack
    Status: Runtime error on test 13
    Last modified: Fri Jun 2 00:12:49 2017 +0200
    Competition: Codeforces
    Problem id: 762C
    Problem name: Two strings
*/

#include <iostream>
#include <vector>
#include <climits>
#include <unordered_set>
#include <map>
#include <set>

#define INF INT_MAX

using namespace std;

typedef long long int ll;


auto prev_element(map<int, int> m, int key)
{
    auto itlow = m.lower_bound(key);
    if (itlow->first == key)
        return itlow;
    else if (itlow != m.begin())
        itlow--;
    return itlow;

}

int main()
{
    string A, B;
    cin >> A >> B;

    // how long of a prefix of A a prefix of B would need to be fully matched as a subsequence
    vector<int> p(B.length(), INF);
    // same with suffixes
    vector<int> s(B.length(), INF);

    // two pointers
    int u = 0;
    int v = 0;

    while (v < B.length())
    {
        while (u < A.length() && A[u] != B[v])
            u++;

        if (A[u] != B[v])
            break;

        p[v] = u + 1;
        v++;
        u++;
    }

    // do the whole thing backwards
    u = A.length() - 1;
    v = B.length() - 1;

    while (v >= 0)
    {
        while (u >= 0 && A[u] != B[v])
            u--;

        if (A[u] != B[v])
            break;

        s[v] = A.length() - u;
        v--;
        u--;
    }

    // dummy values representing the start/the end of the array
    p.insert(p.begin(), 0);
    s.push_back(0);


    int best_u, best_v;

    // Iteratively increase prefix and see how big of a suffix we can choose. Keep track of the optimum solution.
    map<int, int> s_map;
    for (int i = 0; i < s.size(); i++)
        s_map[s[i]] = i;

    int max_sum = 0;
    for (int i = 0; i < p.size(); i++)
    {
        auto longest_suffix = prev_element(s_map, A.length() - p[i]);
        if (longest_suffix != s_map.end())
        {
            int suffix_pos = longest_suffix->second;
            int suffix_length = s.size() - suffix_pos - 1;
            int sum = i + suffix_length;
            if (p[i] + longest_suffix->first <= A.length() && sum >= max_sum)
            {
                max_sum = sum;
                best_u = i;
                best_v = suffix_pos;
            }
        }
    }

    string sol = B.substr(0, best_u) + B.substr(best_v);
    if (sol.empty())
        sol = '-';
    cout << sol << endl;

    return 0;
}
