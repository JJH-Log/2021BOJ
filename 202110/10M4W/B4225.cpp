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
#define MOD 1000000
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

struct pos {
    lld x, y;
};
int N;
pos base;
vector<pos> v;
vector<pos> w;
stack<pos> s;

lld ccw(pos A, pos B, pos C) {
    return A.x * B.y + B.x * C.y + C.x * A.y - A.y * B.x - B.y * C.x - C.y * A.x;
}

bool cmpPos(pos A, pos B) {
    if (A.x == B.x) return A.y < B.y;
    return A.x < B.x;
}

bool cmpCCW(pos A, pos B) {
    if (ccw(base, A, B) == 0) return (abs(A.x - base.x) + abs(A.y - base.y)) < (abs(B.x - base.x) + abs(B.y - base.y));
    return (ccw(base, A, B) > 0);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cout << fixed;
    cout.precision(2);
    int T = 1;
    while (true) {
        cin >> N;
        if (!N) break;
        v.resize(N);
        for (int i = 0; i < N; i++) cin >> v[i].x >> v[i].y;
        sort(v.begin(), v.end(), cmpPos);
        base = v[0];
        sort(v.begin(), v.end(), cmpCCW);

        s.push(v[0]);
        s.push(v[1]);
        
        for (int i = 2; 2 <= i && i <= N ; i++) {
            if (i == N) i = 0;
            while (true) {
                if (s.size() == 1) {
                    s.push(v[i]);
                    break;
                }
                pos B = s.top();
                s.pop();
                pos A = s.top();
                if (ccw(A, B, v[i]) > 0) {
                    s.push(B);
                    s.push(v[i]);
                    break;
                }
            }
        }
        while (!s.empty()) w.push_back(s.top()), s.pop();
        double result = 1e9;
        for (int i = 1; i < w.size(); i++) {
            pos A = w[i];
            pos B = w[i - 1];
            double l2 = (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
            double ccw2max = 0;
            for (int j = 0; j < v.size(); j++) {
                double ccw2 = (double)ccw(A, B, v[j]) * ccw(A, B, v[j]);
                ccw2max = max(ccw2max, ccw2);
            }
            result = min(result, ccw2max / l2);
        }
        cout << "Case " << T << ": " << sqrt(result) + 0.005 << '\n';


        v.clear();
        w.clear();
        T++;
    }

    return 0;
}
