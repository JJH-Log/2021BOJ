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

vector<vector<int>> w;
vector<int> dn;
int N, M, dfsn;
bool isCactus;


int dfs(int now, int parent) {
    dn[now] = ++dfsn;
    int FLAG = dn[now];
    int ans, cnt;
    cnt = 0;
    for (auto& next : w[now]) {
        if (next == parent) continue;
        if (!dn[next]) ans = dfs(next, now);
        else ans = dn[next];
        if (ans <= dn[now]) cnt++;
        FLAG = min(FLAG, ans);
    }
    if (cnt > 1) isCactus = false;
    return FLAG;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    w.resize(N);
    dn.resize(N, 0);
    dfsn = 0;
    int i, x, y, result;
    for (i = 0; i < M; i++) {
        cin >> x >> y;
        x--, y--;
        w[x].push_back(y);
        w[y].push_back(x);
    }
    result = 0;
    for (i = 0; i < N; i++) {
        if (!dn[i]) {
            isCactus = true;
            dfs(i, -1);
            if (isCactus) result++;
        }
    }

    cout << result;
    return 0;
}