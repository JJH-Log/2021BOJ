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

vector<pair<int, lld>> v, ans;
int N, S;

int getBound(int l, int r, int key) {
    int mid = (l + r + 1) / 2;
    if (l == r) return l;
    if (key < ans[mid].first) return getBound(l, mid - 1, key);
    else return getBound(mid , r, key);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int i;
    cin >> N >> S;
    v.resize(N);
    for (i = 0; i < N; i++) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());

    ans.push_back({ -1e9, 0 });
    for (i = 0; i < N; i++) {
        int t = getBound(0, ans.size() - 1, v[i].first - S);
        ans.push_back({ v[i].first, max(ans[i].second, ans[t].second + v[i].second) });
    }
    cout << ans[N].second;
    return 0;
}