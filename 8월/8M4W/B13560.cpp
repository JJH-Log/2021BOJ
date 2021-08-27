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
lld N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int result;
    lld i, total = 0;
    cin >> N;
    v.resize(N, 0);
    for (i = 0; i < N; i++) {
        cin >> v[i];
        total += v[i];
    }
    result = 1;

    if (total != N * (N - 1) / 2) result = -1;
    else{
        sort(v.begin(), v.end());
        total = 0;
        for (i = 0; i < N; i++) {
            total += v[i];
            if (i * (i + 1) / 2 > total) result = -1;
        }
    }
    cout << result;
    return 0;
}