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
//for (const auto& i : v) cout << i << ' ';
using namespace std;
using lld = long long;

vector<vector<int>> v;
vector<int> A;
vector<int> B;
queue<int> q;

int makeTree(int x, int diff, int bound) {
	if (x > bound) return -1;
	if (x - diff < 0) return -1;
	int i;
	int root = A[x];
	i = 0;
	while (B[x - diff + i] != A[x]) i++;
	v[root][0] = makeTree(x + 1, diff + 1, x + i);
	v[root][1] = makeTree(x + i + 1, diff, bound);

	return root;
}

void postOrder(int X) {
	if (v[X][0] != -1) postOrder(v[X][0]);
	if (v[X][1] != -1) postOrder(v[X][1]);
	q.push(X);
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, t, T, N, root;
	cin >> T;
	for (t = 0; t < T; t++) {
		cin >> N;
		A.resize(N);
		B.resize(N);
		v.resize(N, vector<int>(2, 0));
		for (i = 0; i < N; i++) cin >> A[i], A[i]--;
		for (i = 0; i < N; i++) cin >> B[i], B[i]--;
		root = makeTree(0, 0, N - 1);
		postOrder(root);
		while (!q.empty()) cout << q.front() + 1 << ' ', q.pop();
		cout << '\n';
		A.clear();
		B.clear();
		v.clear();
	}
	return 0;
}