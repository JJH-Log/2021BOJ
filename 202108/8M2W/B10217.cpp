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
vector<vector<vector<int>>> w;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; //dist, now

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, T, i, x, y, c, d, now, tar;
    int N, M, K;
    int result;

    cin >> T;
    for (t = 0; t < T; t++) {
        cin >> N >> M >> K;
        w.resize(N);
        v.resize(N * (M + 1), (int)2e9);
        for (i = 0; i < K; i++) {
            cin >> x >> y >> c >> d;
            x--, y--;
            w[x].push_back({ y, c, d });
        }
        pq.push({ 0, 0 });
        v[0] = 0;
        result = (int)2e9;
        while (!pq.empty()) {
            d = pq.top().first;
            now = pq.top().second;
            pq.pop();
            if (v[now] == d) { 
                c = now % (M + 1);
                now /= (M + 1);

                if (now == N - 1) result = min(result, d);
                for (auto& next : w[now]) {
                    tar = next[0] * (M + 1) + c + next[1];
                    if ((c + next[1] <= M) && v[tar] > d + next[2]) {
                        v[tar] = d + next[2];
                        pq.push({ d + next[2], tar });
                    }

                }
            }

        }

        if (result == 2e9) cout << "Poor KCM\n";
        else cout << result << '\n';
        
        w.clear();
    }
    return 0;
}