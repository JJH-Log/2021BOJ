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

vector<int> v;
vector<vector<pair<int,int>>> w;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //dist, now

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int V, E, i, x, y, t, k;
    cin >> V >> E;
    v.resize(2 * V, 2e9 + 2);
    w.resize(2 * V);
    for (i = 0; i < E; i++) {
        cin >> x >> y >> t >> k;
        x--, y--;
        w[x].push_back({ y, t });
        w[y].push_back({ x, t });
        w[x + V].push_back({ y + V, t });
        w[y + V].push_back({ x + V, t });
        w[x].push_back({ y + V, t - k }); 
        w[y].push_back({ x + V, t - k });
    }
    v[0] = 0;
    int now, dist;
    pq.push({ 0,0 });

    while (!pq.empty()) {
        dist = pq.top().first;
        now = pq.top().second;
        pq.pop();
        for (auto& next : w[now]) {
            if (v[next.first] > v[now] + next.second) {
                v[next.first] = v[now] + next.second;
                pq.push({ v[next.first], next.first });
            }
        }
    }
    for (i = V + 1; i < 2 * V; i++) cout << v[i] << '\n';

    return 0;
}