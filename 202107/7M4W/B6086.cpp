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


vector<vector<int>> nc;
vector<vector<int>> nf;
vector<int> tr;
vector<vector<int>> w;

int getIdx(char X) {
    if (X >= 'A' && X <= 'Z') return X - 'A';
    else return X - 'a' + 26;
}

int maxFlow(int S, int E) {
    int now, next, f, result;
    queue<int> q;
    result = 0;
    while (true) {
        tr.clear();
        tr.resize(52, -1);
        q.push(S);
        while (!q.empty()) {
            now = q.front();
            q.pop();
            for (int i = 0; i < w[now].size(); i++) {
                next = w[now][i];
                if (nc[now][next] - nf[now][next] > 0  && tr[next] == -1) {
                    q.push(next);
                    tr[next] = now;
                    if (next == E) break;
                }
            }
        }
        if (tr[E] == -1) break;
        f = 1001;
        for (now = E; now != S; now = tr[now]) f = min(f, nc[tr[now]][now] - nf[tr[now]][now]);
        for (now = E; now != S; now = tr[now]) {
            nf[tr[now]][now] += f;
            nf[now][tr[now]] -= f;
        }
        result += f;
    }
    return result;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, d, N;
    char x, y;
    cin >> N;
    nc.resize(52, vector<int>(52, 0));
    nf.resize(52, vector<int>(52, 0));
    w.resize(52);
    for (i = 0; i < N; i++) {
        cin >> x >> y >> d;
        x = getIdx(x);
        y = getIdx(y);
        nc[x][y] += d, nc[y][x] += d;
        w[x].push_back(y);
        w[y].push_back(x);
    }
    cout << maxFlow(0, 25);

    return 0;
}