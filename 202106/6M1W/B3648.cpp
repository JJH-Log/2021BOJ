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
#define MOD 1000000007
//for (const auto& i : v) cout << i << ' ';
using namespace std;
using lld = long long;

vector<vector<int>> v;
vector<vector<int>> w;
vector<int> d;
vector<int> f;
stack<int> s;
int dfsn, gid;

int init(int X) {
	int i, next, result;
	d[X] = ++dfsn;
	result = d[X];
	s.push(X);
	for (i = 0; i < v[X].size(); i++) {
		next = v[X][i];
		if (!d[next]) result = min(result, init(next));
		if (!f[next]) result = min(result, d[next]);
	}
	if (result == d[X]) {
		vector<int> temp;
		gid++;
		while (true) {
			int t = s.top();
			s.pop();
			f[t] = gid;
			temp.push_back(t);
			if (t == X) break;
		}
		w.push_back(temp);
	}
	return result;
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, x, y, N, M, result;
	while (true) {
		cin >> N >> M;
		if (cin.eof()) break;
		v.resize(2 * N + 1);
		d.resize(2 * N + 1, 0);
		f.resize(2 * N + 1, 0);
		v[N - 1].push_back(N + 1);
		for (i = 0; i < M; i++) {
			cin >> x >> y;
			v[(-1) * x + N].push_back(y + N);
			v[(-1) * y + N].push_back(x + N);
		}
		dfsn = 0; gid = 0;
		w.push_back({ -1 }); //dummy
		result = 1;
		for (i = 0; i <= 2 * N; i++) {
			if (i != N && !d[i]) init(i);
		}
		for (i = 1; i <= N; i++) {
			if (f[N + i] == f[N - i]) result = 0, i = N;
		}
		if (result) cout << "yes\n";
		else cout << "no\n";
		v.clear();
		w.clear();
		d.clear();
		f.clear();
	}
	return 0;
}