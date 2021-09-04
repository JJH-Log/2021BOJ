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

vector<pair<int, int>> v;
int N;

bool compare(pair<int, int> A, pair<int, int> B) {
    if (A.first == B.first) return A.second < B.second;
    return A.first < B.first;
}

bool isExist(int tar_x, int tar_y) {
    int it = lower_bound(v.begin(), v.end(), make_pair(tar_x, tar_y), compare) - v.begin();
    if (it != N && v[it].first == tar_x && v[it].second == tar_y) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, i, j, dx, dy, T;
    bool FLAG;
    int result;
    cin >> T;
    while (T--) {
        cin >> N;
        v.resize(N);
        result = 0;
        for (i = 0; i < N; i++) cin >> v[i].first >> v[i].second;
        sort(v.begin(), v.end());
        for (i = 0; i < N - 3; i++) {
            for (j = i + 1; j < N - 2; j++) {
                dx = v[j].first - v[i].first;
                dy = v[j].second - v[i].second;
                if (dy >= 0) FLAG = isExist(v[i].first + dy, v[i].second - dx) && isExist(v[j].first + dy, v[j].second - dx);
                else FLAG = isExist(v[i].first - dy, v[i].second + dx) && isExist(v[j].first - dy, v[j].second + dx);
                if (FLAG) result = max(result, dx * dx + dy * dy);
            }
        }
        cout << result << '\n';
        v.clear();
    }
    return 0;
}