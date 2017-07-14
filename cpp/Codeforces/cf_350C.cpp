/**
    Author: Valentin Rublack
    Status: Accepted
    Last modified: Wed Jun 14 19:18:59 2017 +0200
    Competition: Codeforces
    Problem id: 350C
    Problem name: Bombs
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


struct Coord
{
    ll x, y;

    Coord(ll x, ll y) : x(x), y(y)
    {}

    Coord()
    {}
};

class Compare
{
public:
    bool operator()(Coord a, Coord b)
    {
        // squared euklidean distance from (0, 0)
        return a.x * a.x + a.y * a.y >= b.x * b.x + b.y * b.y;
    }
};


int main()
{
    ui n;
    cin >> n;

    // use vector to read all bombs first and then build pq instead of inserting into pq n times
    vector<Coord> bombs_vec;
    LOOP(i, n)
    {
        Coord c;
        cin >> c.x >> c.y;
        bombs_vec.push_back(c);
    }

    priority_queue<Coord, vector<Coord>, Compare> bombs(bombs_vec.begin(), bombs_vec.end());

    stringstream ops;
    ui ops_n = 0;

    // always pick closest bomb
    LOOP(i, n)
    {
        Coord closest = bombs.top();
        bombs.pop();

        // move
        // the fact that it's the closest bomb guarantees that there is no bomb on the way
        if (closest.x != 0)
        {
            char dir = closest.x > 0 ? 'R' : 'L';
            ops << "1 " << abs(closest.x) << " " << dir << endl;
            ops_n++;
        }
        if (closest.y != 0)
        {
            char dir = closest.y > 0 ? 'U' : 'D';
            ops << "1 " << abs(closest.y) << " " << dir << endl;
            ops_n++;
        }

        // pick up bomb
        ops << "2" << endl;
        ops_n++;

        // go to (0, 0) on the reverse path
        if (closest.x != 0)
        {
            char dir = closest.x > 0 ? 'L' : 'R';
            ops << "1 " << abs(closest.x) << " " << dir << endl;
            ops_n++;
        }
        if (closest.y != 0)
        {
            char dir = closest.y > 0 ? 'D' : 'U';
            ops << "1 " << abs(closest.y) << " " << dir << endl;
            ops_n++;
        }

        // explode
        ops << "3" << endl;
        ops_n++;
    }

    cout << ops_n << endl << ops.str();
}
