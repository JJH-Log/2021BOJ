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

vector<int> v;

int find(int X) {
	if (X == v[X]) return X;
	return v[X] = find(v[X]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, N, M, x, a, b;
	cin >> N >> M;
	v.resize(N + 1, 0);
	for (i = 0; i <= N; i++) v[i] = i;
	for (i = 0; i < M; i++) {
		cin >> x >> a >> b;
		if (!x) {
			a = find(a);
			b = find(b);
			if (a > b) swap(a, b);
			v[b] = a;
		}
		else {
			if (find(a) == find(b)) cout << "YES\n";
			else cout << "NO\n";
		}
	}
	return 0;
}