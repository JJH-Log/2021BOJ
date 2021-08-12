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

vector<int> c; //cost
vector<vector<int>> v; // {False(Child Also False), False(At least one Child is True), True}
vector<vector<int>> w; //adjacent graph
int N;

void dfs(int now, int parent) {
    //내가 True일 때의 최댓값 vs False일 때의 최댓값
    if (w[now].size() == 1 && w[now][0] == parent) {
        v[now] = { 0, -1, c[now] };
        return;
    }
    else v[now] = { 0, 0, c[now] };
    int FLAG, cnt, diff;
    FLAG = 0; cnt = 0;
    diff = 2e9;

    for (auto& next : w[now]) {
        if (next == parent) continue;
        if (v[next][0] == -1) dfs(next, now);
        //now = True 면 자식들은 무조건 False여야 한다
        v[now][2] += max(v[next][0], v[next][1]);

        //now = False면 자식 중 하나는 True 여야 한다. 
        if (v[next][1] == -1) {
            cnt++; //무조건 자식을 True로 선택해야 하는 경우
            FLAG = 1; //이거 놓침
            v[now][1] += v[next][2];
        }
        else {
            if (v[next][1] <= v[next][2]) FLAG = 1; //내가 False이기 때문에 v[next][0]은 고려하지 않음
            else if (v[next][1] - v[next][2] < diff)  diff = v[next][1] - v[next][2];
            v[now][1] += max(v[next][1], v[next][2]);
            v[now][0] += v[next][1];
        }
    }
    if (!FLAG && diff != 2e9) v[now][1] -= diff;
    if (cnt) v[now][0] = 0;
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, x, y;
    cin >> N;
    c.resize(N, 0);
    v.resize(N, { -1, -1, -1 });
    w.resize(N);
    for (i = 0; i < N; i++) cin >> c[i];
    for (i = 1; i < N; i++) {
        cin >> x >> y;
        x--, y--;
        w[x].push_back(y);
        w[y].push_back(x);
    }
    dfs(0, -1);
    int result = 0;
    for (i = 0; i < 3; i++) result = max(result, v[0][i]);
    cout << result;
    return 0;
}