/**
    Author: Valentin Rublack
    Status: Submitted large
    Last modified: Sun Jun 25 22:11:19 2017 +0200
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
#include <stack>

#define INF INT_MAX
#define LOOP(x, n) for(ll x = 0; x < n; x++)

using namespace std;

typedef long long int ll;
typedef unsigned int ui;

ll mod = 1000000007;


char reverse(char C, char D)
{
    int num = C - D;
    if (num < 0)
        num += 26;
    return num + 'A';
}

int main()
{
    cin.sync_with_stdio(false);

    ui T;
    cin >> T;

    LOOP(t, T)
    {
        string C;
        cin >> C;
        ui W = C.length();

        if (W % 2 == 1)
        {
            cout << "Case #" << t + 1 << ": AMBIGUOUS" << endl;
            continue;
        }

        char dec[W];
        dec[W - 2] = C[W - 1];
        dec[1] = C[0];

        for (int i = 3; i < W; i += 2)
        {
            dec[i] = reverse(C[i - 1], dec[i - 2]);
        }

        for (int i = W - 4; i >= 0; i -= 2)
        {
            dec[i] = reverse(C[i + 1], dec[i + 2]);
        }

        stringstream D;
        for (char d : dec)
        {
            D << d;
        }
        cout << "Case #" << t + 1 << ": " << D.str() << endl;
    }
}
