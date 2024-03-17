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
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

vector<int> v, w;
int N;
void backTracking(int idx, int cnt) {
    if (cnt == 6) {
        for (int i = 0; i < 6; i++) cout << v[w[i]] << ' ';
        cout << '\n';
        return;
    }
    for (int i = idx; i < N; i++) {
        w[cnt] = i;
        backTracking(i + 1, cnt + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true) {
        cin >> N;
        if (!N) break;
        v.resize(N);
        w.resize(N);
        for (int i = 0; i < N; i++) cin >> v[i];
        sort(v.begin(), v.end());
        backTracking(0, 0);
        cout << '\n';
        v.clear();
    }
    return 0;
}