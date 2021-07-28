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

vector<lld> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    vector<lld>::iterator tar;
    vector<int> ans = { 0, 1, 2, 2, 3, 3, 4, 4, 4, 5, 5 };
    v = { 0,1,2,4,6,9 };
    cin >> N;
    if (N <= 10) {
        cout << ans[N];
        return 0;
    }
    int idx = 5;
    while (v[v.size() - 1] < N) {
        tar = upper_bound(v.begin(), v.end(), idx);
        tar--;
        v.push_back(v[idx] + (int)(tar - v.begin()));
        idx++;
    }
    tar = upper_bound(v.begin(), v.end(), N);
    tar--;
    cout << tar - v.begin();

    return 0;
}