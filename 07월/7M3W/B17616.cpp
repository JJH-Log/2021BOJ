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

vector<vector<int>> v; //정방향
vector<vector<int>> w; //역방향
queue<int> q;
vector<bool> cv; //check visited

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, N, M, X;
	int x, y;
	int under, upper;
	cin >> N >> M >> X;
	X--;
	v.resize(N);
	w.resize(N);
	for (i = 0; i < M; i++) {
		cin >> x >> y;
		v[x - 1].push_back(y - 1);
		w[y - 1].push_back(x - 1);
	}

	cv.resize(N, false);
	under = 0;
	cv[X] = true;  q.push(X);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			if (!cv[next]) {
				under++;
				cv[next] = true;
				q.push(next);
			}
		}
	}
	cv.clear();

	cv.resize(N, false);
	upper = 0;
	cv[X] = true;  q.push(X);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (i = 0; i < w[now].size(); i++) {
			int next = w[now][i];
			if (!cv[next]) {
				upper++;
				cv[next] = true;
				q.push(next);
			}
		}
	}
	cv.clear();

	cout << 1 + upper << ' ' << N - under;

	return 0;
}