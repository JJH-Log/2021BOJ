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
vector<vector<int>> w;
vector<int> result;
queue<int> q;
int N, S, P;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> S >> P;
    w.resize(N);
    v.resize(N, -1);

    int i, x, y, now;
    for (i = 0; i < S; i++) v[i] = 0, q.push(i);

    for (i = 1; i < N; i++) {
        cin >> x >> y;
        x--, y--;
        w[x].push_back(y);
        w[y].push_back(x);
    }

    while (!q.empty() && result.size() < 2) {
        now = q.front();
        q.pop();
        for (auto& next : w[now]) {
            if (next == P - 1) result.push_back(v[now] + 1);
            else if (v[next] == -1) {
                v[next] = v[now] + 1;
                q.push(next);
            }
        }
    }

    cout << N - result[0] - result[1] - 1;
    return 0;
}