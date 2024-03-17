#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <set>
#include <cassert>
#include <sstream>
#define MOD 10007
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

struct info {
    int x, y, z;
};
vector<info> v;
vector<vector<int>> w;
vector<int> bp, bq, vtd;

bool compare(info A, info B) {
    if (A.x == B.x) {
        if (A.y == B.y) return A.z > B.z;
        return A.y > B.y;
    }
    return A.x > B.x;
}

bool bipartite(int now) {
    vtd[now] = 1;
    for (auto next : w[now]) {
        if(bq[next] == -1 || (!vtd[bq[next]] && bipartite(bq[next]))){
            bp[now] = next;
            bq[next] = now;
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;

    v.resize(N);
    for (int i = 0; i < N; i++) cin >> v[i].x >> v[i].y >> v[i].z;
    sort(v.begin(), v.end(), compare);

    w.resize(2 * N);
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (v[i].y >= v[j].y && v[i].z >= v[j].z) {
                w[2 * i].push_back(j);
                w[2 * i + 1].push_back(j);
            }
        }
    }
    
    bp.resize(2 * N, -1);
    bq.resize(N, -1);
    int result = 0;
    for (int i = 0; i < 2 * N; i++) {
        vtd.resize(2 * N, 0);
        if (bipartite(i)) result++;
        vtd.clear();
    }
    cout << N - result;

    return 0;
}
