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
#define MOD 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

struct info {
	int x;
	int y;
	int cost;
};

struct cmp {
	bool operator()(info& A, info& B) {
		return A.cost > B.cost;
	}
};

priority_queue<info, vector<info>, cmp> pq;
vector<int> w; //connection check (union - find)
vector<char> g; //gender

int find(int X) {
	if (w[X] == X) return X;
	return w[X] = find(w[X]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, N, M;
	int x, y, d;
	int cnt, result;

	cin >> N >> M;
	w.resize(N);
	g.resize(N);
	
	for (i = 0; i < N; i++) {
		cin >> g[i];
		w[i] = i;
	}
	for (i = 0; i < M; i++) {
		cin >> x >> y >> d;
		x--, y--;
		if (g[x] != g[y]) pq.push({ x, y, d });
	}
	cnt = 0, result = 0;
	while (cnt != N - 1 && !pq.empty()) {
		info now = pq.top();
		x = find(now.x);
		y = find(now.y);
		if (x != y) {
			if (x < y) w[y] = x;
			else w[x] = y;
			result += now.cost, cnt++;
		}
		pq.pop();
	}
	if (cnt != N - 1) cout << -1;
	else cout << result;
	return 0;
}