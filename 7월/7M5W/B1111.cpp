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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, N, a, b, ans, bv;
    bool FLAG;
    cin >> N;
    v.resize(N);
    for (i = 0; i < N; i++) cin >> v[i];
    if (N <= 2) {
        if (N == 2 && v[0] == v[1]) cout << v[0];
        else cout << "A";
        return 0;
    }

    ans = 1e9;
    for (a = -200; a <= 200; a++) {
        bv = v[1]; b = v[1] - a * v[0]; FLAG = true;
        for (i = 2; i < N; i++) {
            if (v[i] != (lld)a * bv + b) FLAG = false, i = N;
            else bv = v[i];
        }
        if (FLAG) {
            if (ans != 1e9 && ans != (lld)a * bv + b) {
                cout << "A";
                return 0;
            }
            else ans = (lld)a * bv + b;
        }
    }
    if (ans == 1e9) cout << "B";
    else cout << ans;
    return 0;
}