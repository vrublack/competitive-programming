/**
    Author: Valentin Rublack
    Status: Correct
    Last modified: Mon Jul 10 23:48:00 2017 +0200
    Competition: ICPC
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>

#define LOOP(x, n) for (int x = 0; x < n; x++)

using namespace std;


bool dfs(int start, int end, vector<vector<int>> &adj_list, vector<bool> &visited)
{
    if (start == end)
        return true;

    for (int adj : adj_list[start])
    {
        if (!visited[adj])
        {
            visited[adj] = true;
            if (dfs(adj, end, adj_list, visited))
                return true;
        }
    }

    return false;
}


int main()
{
    int n, m;
    cin >> n >> m;

    map<string, int> nations;

    vector<vector<int>> NYT(193, vector<int>());
    vector<vector<int>> NYT_rev(193, vector<int>());
    //vector<vector<int>> Trump;

    LOOP(i, n)
    {
        string nat1, nat2;
        cin >> nat1;
        string useless;
        LOOP(j, 3)cin >> useless;
        cin >> nat2;

        if (nations.find(nat1) == nations.end())
        {
            nations[nat1] = nations.size();
        }
        if (nations.find(nat2) == nations.end())
        {
            nations[nat2] = nations.size();
        }

        int node1 = nations.find(nat1)->second;
        int node2 = nations.find(nat2)->second;

        NYT[node1].push_back(node2);
        NYT_rev[node2].push_back(node1);
    }

    LOOP(i, m)
    {
        string nat1, nat2;
        cin >> nat1;
        string useless;
        LOOP(j, 3)cin >> useless;
        cin >> nat2;

        if (nat1 == nat2)
        {
            cout << "Alternative Fact" << endl;
        } else if (nations.find(nat1) == nations.end() || nations.find(nat2) == nations.end())
        {
            cout << "Pants on Fire" << endl;
        } else
        {
            int node1 = nations.find(nat1)->second;
            int node2 = nations.find(nat2)->second;

            vector<bool> visited(193, false);
            if (dfs(node1, node2, NYT, visited))
            {
                cout << "Fact" << endl;
            } else
            {
                vector<bool> visited2(193, false);
                if (dfs(node1, node2, NYT_rev, visited2))
                {
                    cout << "Alternative Fact" << endl;
                } else
                {
                    cout << "Pants on Fire" << endl;
                }
            }
        }
    }

}
