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

vector<int> v;
stack<int> s;
queue<int> q;
int N;
void flip(int idx) {
    for (int i = 0; i <= idx; i++) s.push(v[i]);
    for (int i = 0; i <= idx; i++) v[i] = s.top(), s.pop();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, T, tar, idx;
    cin >> T;
    while (T--) {
        cin >> N;
        v.resize(N, 0);
        for (i = 0; i < N; i++) cin >> v[i];
        tar = N; idx = -1;
        while (tar) {
            for (i = 0; i < N; i++) {
                if (v[i] == tar) {
                    idx = i;
                    break;
                }
            }
            if (idx == tar - 1) {
                tar--;
                continue;
            }
            if (idx == 0) {
                flip(tar - 1);
                q.push(tar);
                tar--;
            }
            else {
                flip(idx);
                q.push(idx + 1);
            }
        }
        cout << q.size() << ' ';
        while (!q.empty()) cout << q.front() << ' ', q.pop();
        cout << '\n';
    }
    return 0;
}