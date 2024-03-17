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


int Adb[31];
struct info {
    vector<int> A;
    int D;
};

vector<info> v;
int N, K, B;

bool compare(info A, info B) {
    return A.D < B.D;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, a;
    cin >> N >> K >> B;
    v.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> t >> v[i].D;
        for (int j = 0; j < t; j++) {
            cin >> a;
            v[i].A.push_back(a);
        }
    }
    sort(v.begin(), v.end(), compare);
    
    lld result = 0;
    int idx1, idx2, now, cnt1, cnt2;
    idx1 = idx2 = cnt1 = cnt2 = 0;


    for (;idx2 < N; idx2++){
        for (int i = 0; i < v[idx2].A.size(); i++) {
            now = v[idx2].A[i];
            if (!Adb[now]) cnt1++;
            Adb[now]++;
        }

        for (; v[idx2].D - v[idx1].D > B; idx1++) {
            for (int i = 0; i < v[idx1].A.size(); i++) {
                now = v[idx1].A[i];
                Adb[now]--;
                if (!Adb[now]) cnt1--;
            }
        }
        cnt2 = 0;
        for (int i = 1; i <= 30; i++) if (Adb[i] == idx2 - idx1 + 1) cnt2++;
        result = max(result, ((lld)cnt1 - cnt2) * ((lld)idx2 - idx1 + 1));
    }
    cout << result;

    return 0;
}
