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

vector<vector<int>> w; //adj
vector<int> bp; //Bipartite P : 몇번째를 가르키고 있는가
vector<int> bq; //Bipartite Q : 누가 가르키고 있는가
vector<bool> vtd;
int N, M;

bool binMatch(int now) {
    vtd[now] = true;
    for (auto& next : w[now]) {
        if (bq[next] == -1 || !vtd[bq[next]] && binMatch(bq[next])) {
            bp[now] = next;
            bq[next] = now;
            return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, j, x, y, t, T;
    cin >> T;

    for (t = 0; t < T; t++) {
        cin >> M >> N;
        w.resize(N);
        bp.resize(N, -1);
        bq.resize(M, -1);
        for (i = 0; i < N; i++) {
            cin >> x >> y;
            for (j = x - 1; j <= y - 1; j++) w[i].push_back(j);
        }

        int result = 0;
        for (i = 0; i < N; i++) {
            if (bp[i] == -1) {
                vtd.clear();
                vtd.resize(N, false);
                if (binMatch(i)) result++;
            }
        }
        cout << result << '\n';

        bp.clear();
        bq.clear();
        w.clear();
    }

    return 0;
}