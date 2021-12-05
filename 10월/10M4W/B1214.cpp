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

lld gcd(lld X, lld Y) {
    if (Y == 0) return X;
    return gcd(Y, X % Y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    lld D, P, Q, A, g;
    lld result = 1e10;
    cin >> D >> P >> Q;
    if (P > Q) swap(P, Q);
    
    g = gcd(Q, P);
    if (D >= (P / g - 1) * (Q / g - 1) * g) {
        if (D % g) result = ((D / g) + 1) * g;
        else result = D;
    }
    else if ((D % Q) == 0 || (P % Q) == 0) result = D;
    else {
        lld target = (D / Q);
        result = Q * (target + 1);
        for (int t = 0; t <= target; t++) {
            lld now = D - Q * t;
            if (now % P) result = min(result, Q * t + P * ((now / P) + 1));
            else result = D;
        }
    }
    cout << result;
    return 0;
}
