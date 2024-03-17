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

vector<pair<int, int>> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, s, e, x, y, N, result;
    cin >> N;
    v.resize(N);
    for (i = 0; i < N; i++) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());
    s = v[0].first, e = v[0].second;
    result = 0;
    for (i = 1; i < N; i++) {
        if (e < v[i].first) {
            result += e - s;
            s = v[i].first;
        }
        e = max(e, v[i].second);
    }
    result += e - s;
    cout << result;
    return 0;
}