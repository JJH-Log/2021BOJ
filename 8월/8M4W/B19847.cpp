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

queue<int> q;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << fixed;
    cout.precision(12);
    int i, N, temp, now, before;
    cin >> N;
    now = 1000001;
    for (i = 0; i < N; i++) {
        cin >> temp;
        if (now > temp) q.push(temp), now = temp;
    }
    v.resize(q.front(), 1);
    before = q.front();
    q.pop();
    while (!q.empty()) {
        now = q.front();
        for (i = now; i < before; i++) v[i % now] += v[i];
        before = now;
        q.pop();
    }
    double result = 0;
    for (i = 0; i < before; i++) result += (double)i * v[i];
    cout << (double)result / v.size();
    return 0;
}