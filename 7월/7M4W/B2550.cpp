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

vector<int> v;
vector<int> w; // for LIS
vector<int> idx; // for LIS idx
vector<int> tr; // for LIS trace
vector<int> result;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int>::iterator it;
    int i, t, N, p, now;
    cin >> N;
    v.resize(N + 1, 0);
    tr.resize(N + 1, -1);
    w.push_back(-1);
    idx.push_back(-1);

    for (i = 1; i <= N; i++) {
        cin >> t;
        v[t] = i;
    }
    for (i = 1; i <= N; i++) {
        cin >> t;
        it = lower_bound(w.begin(), w.end(), v[t]);
        p = it - w.begin();
        if (p == w.size()) {
            w.push_back(v[t]);
            idx.push_back(t);
        }
        else {
            w[p] = v[t];
            idx[p] = t;
        }
        tr[t] = idx[p - 1];
    }
    now = idx[idx.size() - 1]; 
    while (now != -1) {
        result.push_back(now);
        now = tr[now];
    }
    //for (i = 0; i < w.size(); i++) cout << w[i] << ' ';
    //cout << endl;
    sort(result.begin(), result.end());
    cout << result.size() << '\n';
    for (i = 0; i < result.size(); i++) cout << result[i] << ' ';

    return 0;
}