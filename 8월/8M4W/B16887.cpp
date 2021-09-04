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

map<lld,int> m;
priority_queue<lld, vector<lld>, greater<lld>> pq;

int findGrundy(lld X) {
    double l, r;
    bool FLAG = false;
    vector<int> v = { 1,1,1,1,1 };
    l = sqrt(sqrt(X));
    r = sqrt(X);
    for (auto it = m.begin(); it != m.end(); it++) {
        if (FLAG) {
            if (it->first > r) break;
            v[it->second] = 0;
        }
        else if (it->first >= l) {
            FLAG = true;
            if (it->first - 1 > l) it--;
            v[it->second] = 0;
        }
    }
    for (int i = 0; i < 5; i++) if (v[i]) return i;
    return 5;
}

int getGrundy(lld X) {
    auto it = m.upper_bound(X);
    it--;
    return it->second;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    m[0] = 0;
    m[4] = 1;
    pq.push(4);
    lld now, next;
    while (!pq.empty()) {
        now = pq.top();
        if (now != 4) m[now] = findGrundy(now);
        if (now  <= 1000000) pq.push(now * now);
        if (now <= 1001) {
            now--;
            pq.push(now * now * now * now + 1);
        }
        pq.pop();
    }

    int i, N, result;
    lld temp;
    cin >> N;
    result = 0;
    for (i = 0; i < N; i++) {
        cin >> temp;
        result = result ^ getGrundy(temp);
    }
    if (result) cout << "koosaga";
    else cout << "cubelover";
    return 0;
}