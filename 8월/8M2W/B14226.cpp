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

vector<vector<int>> v;
vector<vector<bool>> w;
queue<pair<int, int>> q;

void check(int x, int y, int val) {
	w[x][y] = true;
	v[x][y] = val;
	q.push({ x, y });
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, now, clip, val;
	cin >> N;
	v.resize(N + 1, vector<int>(N + 1, 10000));
	w.resize(N + 1, vector<bool>(N + 1, false));

	v[1][0] = 0, w[1][0] = true;
	q.push({ 1, 0 });

	while (!q.empty()) {
		now = q.front().first;
		clip = q.front().second;
		val = v[now][clip] + 1;
		q.pop();
		if (now == N) {
			cout << val - 1;
			return 0;
		}
		if (!w[now][now]) check(now, now, val);
		if (now + clip <= N && !w[now + clip][clip]) check(now + clip, clip, val);
		if (now >= 1 && !w[now - 1][clip]) check(now - 1, clip, val);
	}
	return 0;
}