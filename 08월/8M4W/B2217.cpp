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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    lld result;
    cin >> N;
    v.resize(N, 0);
    for (int i = 0; i < N; i++) cin >> v[i];
    sort(v.begin(), v.end(), greater<int>());
    result = 0;
    for (int i = 1; i <= N; i++) result = max(result, (lld)i * v[i - 1]);
    cout << result;
    return 0;
}