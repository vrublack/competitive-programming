/**
    Author: Valentin Rublack
    Status: Correct small and large
    Last modified: Sat Jun 24 19:15:42 2017 +0200
    Competition: Google-Code-Jam
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
#define LOOP(x, n) for(ll x = 0; x < n; x++)

using namespace std;

typedef long long int ll;
typedef unsigned int ui;


bool match(string A, string B)
{
    ui n = A.length();
    ui m = B.length();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

    LOOP(i, n + 1)
    {
        LOOP(j, m + 1)
        {
            if (i == 0 && j == 0 || A[i - 1] == B[j - 1] && dp[i - 1][j - 1])
            {
                dp[i][j] = true;
            } else if (i >= 1 && A[i - 1] == '*')
            {
                // * can match up to four characters
                int allowed_match = 4;
                for (int back = 0; back <= allowed_match && j - back >= 0; back++)
                {
                    if (dp[i - 1][j - back])
                    {
                        dp[i][j] = true;
                        break;
                    }

                    if (j - back - 1 >= 0 && B[j - back - 1] == '*')
                        allowed_match++;
                }
            } else if (j >= 1 && B[j - 1] == '*')     // same for B
            {
                // * can match up to four characters
                int allowed_match = 4;
                for (int back = 0; back <= allowed_match && i - back >= 0; back++)
                {
                    if (dp[i - back][j - 1])
                    {
                        dp[i][j] = true;
                        break;
                    }

                    if (i - back - 1 >= 0 && A[i - back - 1] == '*')
                        allowed_match++;
                }
            } else
            {
                dp[i][j] = false;
            }
        }
    }

    return dp[n][m];
}


int main()
{
    ui T;
    cin >> T;
    LOOP(t_, T)
    {
        string A, B;
        cin >> A >> B;
        cout << "Case #" << t_ + 1 << ": " << (match(A, B) ? "TRUE" : "FALSE") << endl;
    }
}
