#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
#define MOD 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
//for (const auto& i : v) cout << i << ' ';
using namespace std;
using lld = long long;

vector<vector<pair<int, int>>> v;
vector<lld> w; //dijkstra distance
vector<pair<int, int>> e;
int N, M, K;

struct pos {
	int x;
	int y;
	int idx;
};

struct cmp_pos {
	bool operator()(pos& A, pos& B) {
		if (A.x == B.x) {
			if (A.y == B.y) return A.idx > B.idx;
			else return A.y > B.y;
		}
		else return A.x > B.x;
	}
};

priority_queue<pos, vector<pos>, cmp_pos> pqX;
priority_queue<pos, vector<pos>, cmp_pos> pqY;
priority_queue<pair<lld,int>, vector<pair<lld,int>>, greater<pair<lld,int>>> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, x, y;
	cin >> N >> M >> K;
	v.resize(2 * K);
	w.resize(2 * K, -1);

	for (i = 0; i < K; i++) {
		cin >> x >> y;
		x--, y--;
		pqX.push({ x, y, i });
		pqY.push({ y, x, i });

		v[2 * i].push_back({ 2 * i + 1, 1 });
		v[2 * i + 1].push_back({ 2 * i, 1 });

		if (x == 0) {
			w[2 * i] = y;
			w[2 * i + 1] = y + 1;
			pq.push({ w[2 * i], 2 * i });
			pq.push({ w[2 * i + 1], 2 * i + 1 });
		}
		if (x == N - 1) e.push_back({ 2 * i, (M - 1) - y });
		if (y == M - 1) e.push_back({ 2 * i + 1, (N - 1) - x });
	}
	int bx, by, idx, bidx;
	bx = -1, by = -1, bidx = -1;
	while (!pqX.empty()) {
		x = pqX.top().x;
		y = pqX.top().y;
		idx = pqX.top().idx;
		if (bx == x){ 
			v[2 * bidx].push_back({ 2 * idx, y - by });
			v[2 * idx].push_back({ 2 * bidx, y - by });
		}
		bx = x, by = y, bidx = idx;
		pqX.pop();
	}
	while (!pqY.empty()) {
		x = pqY.top().y;
		y = pqY.top().x;
		idx = pqY.top().idx;
		if (by == y) {
			v[2 * bidx + 1].push_back({ 2 * idx + 1, x - bx });
			v[2 * idx + 1].push_back({ 2 * bidx + 1, x - bx });
		}
		bx = x, by = y, bidx = idx;
		pqY.pop();
	}
	lld dist;
	int nidx;
	while (!pq.empty()) {
		dist = pq.top().first;
		idx = pq.top().second;
		if (w[idx] == dist) {
			for (i = 0; i < v[idx].size(); i++) {
				nidx = v[idx][i].first;
				if (w[nidx] == -1 || (w[nidx] > w[idx] + v[idx][i].second)) {
					w[nidx] = w[idx] + v[idx][i].second;
					pq.push({ w[nidx], nidx });
				}
			}
		}
		pq.pop();
	}
	lld result = -1;
	for (i = 0; i < e.size(); i++) {
		if (w[e[i].first] != -1 && (result == -1 || result > w[e[i].first] + e[i].second)) result = w[e[i].first] + e[i].second;
	}
	cout << result;
	return 0;
}