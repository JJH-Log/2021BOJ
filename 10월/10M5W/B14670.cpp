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
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

map<int, int> m;
queue<int> q;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    bool FLAG;
    int N, M;
    int x, y, t;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        m[x] = y;
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        FLAG = true;
        cin >> t;
        for (int j = 0; j < t; j++) {
            cin >> x;
            if (m.count(x)) q.push(m[x]);
            else FLAG = false;
        }
        while (!q.empty()) {
            if (FLAG) cout << q.front() << ' ';
            q.pop();
        }
        if (!FLAG) cout << "YOU DIED";
        cout << '\n';
    }


    
    return 0;
}
