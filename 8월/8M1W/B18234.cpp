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

vector<pair<int, int>> v; //pi, wi 순
int N, T;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int i;
    lld result = 0;
    cin >> N >> T;
    v.resize(N);
    for (i = 0; i < N; i++) cin >> v[i].second >> v[i].first;
    sort(v.begin(), v.end(), greater<pair<int,int>>());
    for (i = N - 1; i >= 0; i--) result += ((lld)v[i].first * (T - i)) + (v[i].second - v[i].first);
    cout << result;
    return 0;
}