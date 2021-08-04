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

vector<vector<int>> w;
int N;

int dfs(int now) {
    int i, result = 0;
    vector<int> ans;
    for (auto& next : w[now]) ans.push_back(dfs(next));
    sort(ans.begin(), ans.end(), greater<int>());
    for (i = 0; i < ans.size(); i++) {
        result = max(result, ans[i] + i + 1);
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, temp;
    cin >> N;
    w.resize(N);
    cin >> temp;
    for (i = 1; i < N; i++) {
        cin >> temp;
        w[temp].push_back(i);
    }
    cout << dfs(0);

    return 0;
}