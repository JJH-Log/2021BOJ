#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility> 
#include <string>
#include <stack>
#include <map>
using namespace std;

vector<vector<int>> v; //정점의 parent 탐색 [0]-parent [1]-cnt [2]-total dist
vector<vector<int>> E;
bool compare(vector<int> A, vector<int> B) { return A[2] < B[2]; }

int find(int target) {
	if (v[target][0] == target) return target;
	else return find(v[target][0]);
}

void concat(int A, int B, int D) {
	if (A > B) swap(A, B);
	v[B][0] = A;
	v[A][1] += v[B][1];
	v[B][1] = 0;
	v[A][2] += v[B][2] + D;
	v[B][2] = 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, N, M;
	int A, B;
	cin >> N >> M;
	v.resize(N + 1, vector<int>(3, 0));
	E.resize(M, vector<int>(3, 0));
	for (i = 1; i <= N; i++) { v[i][0] = i; v[i][1] = 1; }
	for (i = 0; i < M; i++) cin >> E[i][0] >> E[i][1] >> E[i][2];
	sort(E.begin(), E.end(), compare);
	i = 0;
	while (true) {
		//정점 [i][0] 과 정점 [i][1]의 parent 탐색 (find)
		A = find(E[i][0]);
		B = find(E[i][1]);
		//두 parent를 union
		if (A != B) concat(A, B, E[i][2]);
		//1의 개수(cnt) 가 N개면 break
		if (v[1][1] == N) break;
		i++;
	}
	cout << v[1][2];
}

