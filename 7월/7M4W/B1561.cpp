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
vector<int> cnt;
int N, M;

lld getCount(lld t) {
    if (t == -1) return 0;
    lld result = 0;
    for (int i = 0; i < M; i++) {
        result += (t / v[i]) + 1;
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int i;
    lld l, r, mid;
    lld ans;
    cin >> N >> M;
    v.resize(M, 0);
    for (i = 0; i < M; i++) cin >> v[i];
    l = 0; r = 7e10 + 1;
    while (l != r) {
        mid = (l + r) / 2;
        ans = getCount(mid);
        if (ans >= N) r = mid;
        else l = mid + 1;
    }
    int bound = getCount(l - 1);
    for (i = 0; i < M; i++) {
        if (!(l % v[i])) bound++;
        if (bound == N) {
            cout << i + 1;
            return 0;
        }
    }
    return 0;
}