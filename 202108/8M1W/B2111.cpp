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


queue<int> cn; //size of cactus
vector<vector<int>> w;
vector<int> dn;
int N, M, dfsn;
bool isCactus;


pair<int, int> dfs(int now, int parent) {
    dn[now] = ++dfsn;
    int FLAG = dn[now];
    int FLAG2 = 0;
    pair<int, int> ans;
    int cnt, nxdn, cycn;
    cnt = 0; cycn = 0;
    for (auto& next : w[now]) {
        if (next == parent) continue;
        if (!dn[next]) {
            ans = dfs(next, now);
            nxdn = ans.first;
            cycn = ans.second;
        }
        else nxdn = dn[next], cycn = 0;
        if (nxdn < dn[now]) cnt++, FLAG2 = cycn + 1;
        else if (nxdn == dn[now]) cn.push(cycn + 1);
        FLAG = min(FLAG, nxdn);
    }
    if (cnt > 1) isCactus = false;
    return { FLAG, FLAG2 };
}



string strMod(string s1, string s2) {
    if (s1.size() < s2.size()) swap(s1, s2);
    string result = "";
    vector<lld> num;
    num.resize(s1.size() + s2.size() + 1, 0);
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    int i, j, u;
    for (i = 0; i < s2.size(); i++) {
        for (j = 0; j < s1.size(); j++) {
            num[i + j] += (s1[j] - '0') * (s2[i] - '0');
        }
    }
    u = 0;
    for (i = 0; i < num.size(); i++) {
        num[i] += u;
        if (num[i] >= 10) u = num[i] / 10;
        else u = 0;
        result += ('0' + (num[i] % 10));
    }
    reverse(result.begin(), result.end());
    for (i = 0; i < result.size(); i++) {
        if (result[i] != '0') return result.substr(i);
    }
    return "0";
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    w.resize(N);
    dn.resize(N, 0);
    dfsn = 0, isCactus = true;
    int i, j, d, before, now;
    for (i = 0; i < M; i++) {
        cin >> d;
        if (d) {
            cin >> before;
            before--;
            for (j = 1; j < d; j++) {
                cin >> now;
                now--;
                w[before].push_back(now);
                w[now].push_back(before);
                before = now;
            }
        }
    }
    dfs(0, -1);

    for (i = 0; i < N; i++) if (!dn[i]) isCactus = false;

    if (!isCactus) cout << 0;
    else {
        string result = "1";
        while(!cn.empty()) {
            result = strMod(result, to_string(cn.front() + 1));
            cn.pop();
        }
        cout << result;
    }
    return 0;
}