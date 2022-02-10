#include <iostream>
#include <vector>
#include <string> //substr
#include <map>
#include <queue>
#include <stack>
#include <utility>  //pair
#include <algorithm> //sort, reverse
#include <math.h> // sqrt
#include <set>
#include <cassert>
#define MOD 1000000007
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;


vector<vector<pair<int, int>>> w; //next, cost
vector<lld> v;
vector<int> cost;
int N, M, X, Y;

//for cycle check
vector<bool> vtd;
queue<int> q;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> X >> Y >> M;
    w.resize(N);
    v.resize(N, 5e9);
    vtd.resize(N, false);
    cost.resize(N);

    int i, t, x, y, d, now;
    for (i = 0; i < M; i++) {
        cin >> x >> y >> d;
        w[x].push_back({ y , d });
    }
    for (i = 0; i < N; i++) cin >> cost[i];

    v[X] = -cost[X];
    for (t = 0; t < N - 1; t++) {
        for (now = 0; now < N; now++) {
            if (v[now] == 5e9) continue;
            for (auto& next : w[now]) {
                if (v[next.first] > v[now] + next.second - cost[next.first]) v[next.first] = v[now] + next.second - cost[next.first];
            }
        }
    }

    if (v[Y] == 5e9) cout << "gg";
    else {
        for (now = 0; now < N; now++) {
            if (v[now] == 5e9) continue;
            for (auto& next : w[now]) {
                if (v[next.first] > v[now] + next.second - cost[next.first]) vtd[next.first] = true, q.push(next.first);
            }
        }
        while (!q.empty()) {
            now = q.front();
            q.pop();
            for (auto& next : w[now]) if (!vtd[next.first]) vtd[next.first] = true, q.push(next.first);
        }
        if (vtd[Y]) cout << "Gee";
        else cout << -v[Y];
    }

    return 0;
}