#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility> 
#include <string>
#include <stack>
#include <map>
#include <set>
//for (const auto& i : v) cout << i << ' ';
using namespace std;

vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, a, b, N, M;
	cin >> N >> M;
	v.resize(N, 0);
	for (i = 0; i < N; i++) cin >> v[i];
	for (i = 1; i < N; i++) v[i] += v[i - 1];
	for (i = 0; i < M; i++) {
		cin >> a >> b;
		if (a == 1) cout << v[b - 1] << "\n";
		else cout << v[b - 1] - v[a - 2] << "\n";
	}
	return 0;
}