#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define endl "\n"

struct Edge {
	int cost;
	int p1;
	int p2;
};

struct cmp {
	bool operator()(Edge a, Edge b) {
		return a.cost > b.cost;
	}
};

priority_queue < Edge, vector<Edge>, cmp> que;
int parent[1001];
int n, m, ans;

int find(int a) {
	if (parent[a] == -1) return a;
	return parent[a] = find(parent[a]);
}

bool merge(int a, int b) {
	a = find(a);
	b = find(b);

	if (a == b) return false;
	parent[a] = b;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	fill(parent, parent + n + 1, -1);

	int p1, p2, cost;

	for (int i = 0; i < m; i++) {
		cin >> p1 >> p2 >> cost;
		if (p1 == p2) continue;
		que.push({ cost, p1, p2 });
	}

	while(!que.empty()) {
		Edge e = que.top(); que.pop();
		if (merge(e.p1, e.p2)) {
			ans += e.cost;
		}
	}

	cout << ans << endl;
}