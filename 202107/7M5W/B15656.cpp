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
vector<int> w;
int N, M;

void backTracking(int cnt) {
    if (cnt == M) {
        for (int i = 0; i < M; i++) cout << w[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 0; i < N; i++) {
        w[cnt] = v[i];
        backTracking(cnt + 1);
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    v.resize(N, 0);
    w.resize(M, 0);
    for (int i = 0; i < N; i++) cin >> v[i];
    sort(v.begin(), v.end());
    backTracking(0);

    return 0;
}