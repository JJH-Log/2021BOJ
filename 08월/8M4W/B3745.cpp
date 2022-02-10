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

    int i, N, T, now, idx;
    while (true) {
        cin >> N;
        if (cin.eof()) break;
        v.push_back(0);
        for (i = 0; i < N; i++) {
            cin >> now;
            idx = lower_bound(v.begin(), v.end(), now) - v.begin();
            if (idx == v.size()) v.push_back(now);
            else v[idx] = now;
        }
        cout << v.size() - 1 << '\n';
        v.clear();
    }
    return 0;
}