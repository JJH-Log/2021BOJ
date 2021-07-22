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

priority_queue<pair<int, int>,vector<pair<int,int>>, greater<pair<int,int>>> pq[2];
vector<vector<int>> v[2];

map<int, vector<int>> m[2];

void init(int FLAG) {
    int before = -1;
    pair<int,int> now;
    while (!pq[FLAG].empty()) {
        now = pq[FLAG].top();
        pq[FLAG].pop();
        if (!m[FLAG].count(now.first)) m[FLAG][now.first] = vector<int>();
        m[FLAG][now.first].push_back(now.second);
    }
    return;
}

int cntTree(int FLAG, int key, int b1, int b2) {
    if (!m[FLAG].count(key)) return 0;
    //cout << "DEBUG\n";
    //cout << key << ' ' << b1 << ' ' << b2 << '\n';
    //for (int i = 0; i < v[FLAG][key].size(); i++) cout << v[FLAG][key][i] << ' ';
    //cout << "Result : " << upper_bound(v[FLAG][key].begin(), v[FLAG][key].end(), b2) - lower_bound(v[FLAG][key].begin(), v[FLAG][key].end(), b1) << endl;
    return upper_bound(m[FLAG][key].begin(), m[FLAG][key].end(), b2) - lower_bound(m[FLAG][key].begin(), m[FLAG][key].end(), b1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, x1, y1, x2, y2, N, M;
    cin >> N;
    for (i = 0; i < N; i++) {
        cin >> x1 >> y1;
        pq[0].push({ x1, y1 });
        pq[1].push({ y1, x1 });
    }
    int before = -1;
    init(0);
    init(1);
    cin >> M;
    for (i = 0; i < M; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << cntTree(1, y1, x1, x2 - 1) + cntTree(1, y2, x1 + 1, x2) + cntTree(0, x1, y1 + 1, y2) + cntTree(0, x2, y1, y2 - 1) << '\n';
    }



    return 0;
}