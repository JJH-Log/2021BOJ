#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility> 
#include <string>
#include <stack>
#include <map>
using namespace std;

vector<vector<int>> v;
vector<int> cost; //정점 i 에서 X에 도달하기 위한 cost 저장
vector<int> cost2; //정점 X에서 각 i에 도달하기 위한 cost 저장

int N, X;
int getCost(int target) {
	vector<int> visited;
	vector<int> dst;
	visited.resize(N + 1, 0);
	dst.resize(N + 1, -1);
	visited[0] = 1;
	dst[0] = 2000000000;

	int i, FLAG1, FLAG2, srts;
	FLAG1 = 1;
	FLAG2 = 0;
	if (target == X) FLAG2 = 1;

	dst[target] = 0;
	while (FLAG1) {
		visited[target] = 1;
		for (i = 0; i < v[target].size(); i+=2) {
			if (dst[v[target][i]] == -1 || dst[target] + v[target][i + 1] < dst[v[target][i]]) dst[v[target][i]] = dst[target] + v[target][i + 1];
		}
		FLAG1 = 0;
		srts = 2000000000;
		for (i = 0; i < N + 1; i++) {
			if (!visited[i]) {
				FLAG1 = 1;
				if ((dst[i] != -1) && (dst[i] < srts)) {
					target = i;
					srts = dst[i];
				}
			}
		}
	}
	if (FLAG2) {
		for (i = 1; i <= N; i++) cost2[i] = dst[i];
	}
	return dst[X];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int result;
	int i, M;
	int n1, n2, n3;
	cin >> N >> M >> X;
	v.resize(N + 1);
	cost.resize(N + 1);
	cost2.resize(N + 1);
	result = 0;
	for (i = 0; i < M; i++) {
		cin >> n1 >> n2 >> n3;
		v[n1].push_back(n2);
		v[n1].push_back(n3);
	}
	for (i = 1; i <= N; i++) cost[i] = getCost(i);
	for (i = 1; i <= N; i++) result = max(result, cost[i] + cost2[i]);
	cout << result << endl;
	return 0;
}

