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


int N, M, T, S, G, H;

vector<vector<pair<int, int>>> w;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<int> result;
vector<int> SV, GV, HV;

vector<int> dijkstra(int s) {
	vector<int> ans = vector<int>(N, (int)1e9);
	ans[s] = 0, pq.push({ 0, s });
	while (!pq.empty()) {
		pair<int, int> now = pq.top();
		pq.pop();
		if (ans[now.second] == now.first) {
			for (auto next : w[now.second]) {
				if (ans[next.first] > ans[now.second] + next.second) {
					ans[next.first] = ans[now.second] + next.second;
					pq.push({ ans[next.first], next.first });
				}
			}
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tcase;
	int x, y, d, t, gh;
	cin >> tcase;
	while (tcase--) {
		cin >> N >> M >> T >> S >> G >> H; //S->T == S->G + G-H + H->T
		w.resize(N);

		for (int i = 0; i < M; i++) {
			cin >> x >> y >> d;
			if ((G == x && H == y) || (G == y && H == x)) gh = d;
			x--, y--;
			w[x].push_back({ y,d });
			w[y].push_back({ x,d });
		}
		SV = dijkstra(S - 1);
		GV = dijkstra(G - 1);
		HV = dijkstra(H - 1);
		for (int i = 0; i < T; i++) {
			cin >> t;
			if (SV[t - 1] == SV[G - 1] + gh + HV[t - 1]) result.push_back(t);
			else if (SV[t - 1] == SV[H - 1] + gh + GV[t - 1]) result.push_back(t);
		}
		sort(result.begin(), result.end());
		for (int i = 0; i < result.size(); i++) cout << result[i] << ' ';
		cout << '\n';

		w.clear();
		result.clear();
	}

	return 0;
}