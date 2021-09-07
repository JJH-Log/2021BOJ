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

vector<int> v, w;
multiset<int> ms, ms2;
int N, M, EP;
bool ZERO, FLAG1, FLAG2;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, d, now;
    M = MAXINT;
    ZERO = false;
    multiset<int>::iterator it;
    cin >> N;

    v.resize(N, 0);
    for (i = 0; i < N; i++) {
        cin >> v[i];
        M = min(M, v[i]);
    }
    for (i = 0; i < N; i++) {
        if (v[i] == M) {
            if (!ZERO) ZERO = true;
            else {
                cout << "No";
                return 0;
            }
        }
        else w.push_back(v[i] - M);
    }
    sort(w.begin(), w.end());
    now = 1;
    for (i = 0; i < N - 1; i++) {
        if (w[i] == w[0] * now) {
            EP = i;
            now++;
        }
        else {
            ms.insert(w[i]);
            ms2.insert(w[i]);
        }
    }
    ms2.insert(w[EP]);

    d = (*ms.begin()); FLAG1 = true; now = 1;
    for (it = ms.begin(); it != ms.end(); it++) {
        if ((*it) == d * now) now++;
        else {
            FLAG1 = false;
            break;
        }
    }
   
    d = (*ms2.begin()); FLAG2 = true; now = 1;
    for (it = ms2.begin(); it != ms2.end(); it++) {
        if ((*it) == d * now) now++;
        else {
            FLAG2 = false;
            break;
        }
    }
    if (FLAG1 || FLAG2) cout << "Yes";
    else cout << "No";
    return 0;
}