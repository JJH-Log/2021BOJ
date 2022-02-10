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

int cnt[5] = { 0, };

bool isFilled(vector<vector<int>> v, int x, int y, int l) {
    for (int i = x; i < x + l; i++) {
        for (int j = y; j < y + l; j++) {
            if (i >= 10 || j >= 10) return false;
            if (v[i][j] == 0) return false;
        }
    }
    return true;
}

vector<vector<int>> fillZero(vector<vector<int>> now, int x, int y, int l) {
    for (int i = x; i < x + l; i++) {
        for (int j = y; j < y + l; j++) now[i][j] = 0;
    }
    return now;
}

int backTracking(vector<vector<int>> now, int idx) {
    int result = 100;
    for (int i = idx; i < 100; i++) {
        int x = i / 10;
        int y = i % 10;
        if (now[x][y]) {
            for (int j = 5; j >= 1; j--) {
                if (isFilled(now, x, y, j) && cnt[j - 1] < 5) {
                    cnt[j - 1]++;
                    result = min(result, backTracking(fillZero(now, x, y, j), i + 1));
                    cnt[j - 1]--;
                }
            }
            return result;
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) if (now[i][j] == 1) return 100;
    }
    result = 0;
    for (int i = 0; i < 5; i++) result += cnt[i];
    return result;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<int>> init;
    init.resize(10, vector<int>(10, 0));

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) cin >> init[i][j];
    }
    int ans = backTracking(init, 0);
    if (ans == 100) cout << -1;
    else cout << ans;
    return 0;
}