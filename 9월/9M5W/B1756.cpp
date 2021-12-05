#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <math.h>
#include <set>
#include <cassert>
#include <sstream>
#define MOD 1000000007
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

int D, N;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<int> v;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x, height, pidx;
	cin >> D >> N;
	for (int i = 0; i < D; i++) cin >> x, pq.push({ x, i });
	v.resize(N);
	for (int i = 0; i < N; i++) cin >> v[i];
	height = D - 1;
	pidx = 0;
	while (!pq.empty() && pidx != N) {
		if (pq.top().second > height) {
			pq.pop();
			continue;
		}
		pair<int, int> now = pq.top();
		if (now.first >= v[pidx]) pidx++, height--;
		else height = now.second - 1;
	}
	if (pidx == N) cout << height + 2;
	else cout << 0;
	return 0;
}