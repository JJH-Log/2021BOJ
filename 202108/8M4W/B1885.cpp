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
#define MOD 10007
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

vector<int> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, N, K, temp, cnt, result;
    cin >> N >> K;
    v.resize(K + 1, false);
    cnt = 0; result = 1;
    for (i = 0; i < N; i++) {
        cin >> temp;
        if (v[temp] != result) {
            v[temp] = result;
            cnt++;
        }
        if (cnt == K) cnt = 0, result++;
    }
    cout << result;
    return 0;
}