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

struct block {
	int num;
	int e;
	int h;
	int w;
};

vector<vector<int>> v;
vector<int> index;
vector<block> b;
queue<int> q;

bool compare(block& A, block& B) {
	return A.e > B.e;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, N, maxh, maxw;
	cin >> N;
	v.resize(N, vector<int>(10001, 0));
	index.resize(N, -1);
	b.resize(N);

	for (i = 0; i < N; i++) {
		cin >> b[i].e >> b[i].h >> b[i].w;
		b[i].num = i + 1;
	}

	sort(b.begin(), b.end(), compare);
	for (j = 1; j <= b[0].w; j++) v[0][j] = b[0].h;
	for (i = 1; i < N; i++) {
		maxh = 0;
		for (j = b[i].w + 1; j <= 10000; j++) {
			if (v[i - 1][j] > maxh) maxh = v[i - 1][j], index[i] = j;
			v[i][j] = v[i - 1][j];
		}
		for (j = 1; j <= b[i].w; j++) v[i][j] = max(v[i - 1][j], maxh + b[i].h);
		v[i][0] = maxh;
	}
	maxh = 0;
	for (j = 1; j <= 10000; j++) {
		if (maxh <= v[N - 1][j]) maxh = v[N - 1][j], maxw = j;
	}
	for (int now = N - 1; now >= 0; now--) {
		if (v[now][maxw] == v[now][0] + b[now].h) maxw = index[now], q.push(b[now].num);
	}
	cout << q.size() << '\n';
	while (!q.empty()) {
		cout << q.front() << '\n';
		q.pop();
	}

	return 0;
}