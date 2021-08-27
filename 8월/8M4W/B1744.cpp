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
queue<int> q;
stack<int> s;
int N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, A, B, mcnt;
    lld result = 0;
    cin >> N;
    v.resize(N, 0);
    for (i = 0; i < N; i++) cin >> v[i];
    sort(v.begin(), v.end());
    for (i = 0; i < N; i++) {
        if (v[i] <= 0) q.push(v[i]);
        else s.push(v[i]);
    }
    while (q.size() > 1) {
        A = q.front(); q.pop();
        B = q.front(); q.pop();
        result += ((lld)A * B);
    }
    if (q.size() == 1) result += q.front();
    while (s.size() > 1) {
        A = s.top(); s.pop();
        B = s.top(); s.pop();
        result += max((lld)A + B, ((lld)A * B));
    }
    if (s.size() == 1) result += s.top();

    cout << result;
    return 0;
}