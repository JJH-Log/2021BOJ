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

vector<lld> v, w;
int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    lld result = 0;
    cin >> N;
    v.resize(2 * N + 1, 0);
    w.resize(2 * N + 1, 0);
    for (int i = 1; i <= N; i++) {
        cin >> v[i];
        v[i + N] = v[i];
    }
    for (int i = 1; i <= 2 * N; i++) w[i] = w[i - 1] + v[i];
    double K = w[N];
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (w[j + i] - w[j] < 0) result += ceil((double)(w[j] - w[j + i]) / K);
        }
    }
    cout << result;
    

    return 0;
}
