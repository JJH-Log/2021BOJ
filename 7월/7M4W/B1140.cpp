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
vector<pair<int, int>> cutLine;
int dfsn;

int dfsCutLine(int now, int parent) {
    /*============================================
    vector<vector<int>> w : adj graph
    vector<int> dn : check for dfsn (init with 0)
    vector<pair<int,int>> cutLine : check for Articulation Line
    int dfsn : dfs number
    ============================================*/
    int next, child, ans, FLAG;
    dn[now] = ++dfsn;
    FLAG = dn[now];
    for (int i = 0; i < w[now].size(); i++) {
        next = w[now][i];
        if (parent == next) continue;
        if (dn[next]) FLAG = min(FLAG, dn[next]);
        else {
            ans = dfsCutLine(next, now);
            if (ans > dn[now]) cutLine.push_back({ min(now, next), max(now, next) });
            FLAG = min(FLAG, ans);
        }
    }
    return FLAG;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    int i, now, x, y;
    cin >> N >> M;
    w.resize(N);
    dn.resize(N, 0);
    dfsn = 0;
    for (i = 0; i < M; i++) {
        cin >> x >> y;
        w[x - 1].push_back(y - 1);
        w[y - 1].push_back(x - 1);
    }
    for (i = 0; i < N; i++) if (!dn[i]) dfsCutLine(i, -1);
    sort(cutLine.begin(), cutLine.end());
    cout << cutLine.size() << '\n';
    for (auto& c : cutLine) cout << c.first + 1 << ' ' << c.second + 1 << '\n';

    return 0;
}