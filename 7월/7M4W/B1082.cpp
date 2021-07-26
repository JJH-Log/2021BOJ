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

vector<int> cost;
vector<string> v;
int N, K;
string maxStr(string s1, string s2) {
    if (s2[0] == '0') return s1;
    if (s1.size() > s2.size()) return s1;
    else if (s1.size() < s2.size()) return s2;
    if (s1 > s2) return s1;
    else return s2;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, j;
    cin >> N;
    cost.resize(N, 0);
    v.resize(51, "");
    for (i = 0; i < N; i++) {
        cin >> cost[i];
        v[cost[i]] = maxStr(v[cost[i]], to_string(i));
    }
    for (i = 0; i <= 50; i++) {
        for (j = 0; j < N; j++) {
            if (i + cost[j] <= 50) v[i + cost[j]] = maxStr(v[i + cost[j]], v[i] + to_string(j));
        }
    }
    cin >> K;
    if (v[K] == "") cout << 0;
    else cout << v[K];
    return 0;
}