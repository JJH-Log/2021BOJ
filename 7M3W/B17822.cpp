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
#define INT_MIN -2147483647
#define INT_MAX 2147483647
//for (const auto& i : v) cout << i << ' ';
using namespace std;
using lld = long long;

vector<vector<int>> v;
vector<vector<int>> w; //copy of v
vector<int> head;
int N, M, T, FLAG;

void rowAdjacent(int now) {
	int p = head[now];
	for (int i = 0; i < M; i++) {
		if (v[now][(p + i) % M] != 0 && (v[now][(p + i) % M] == v[now][(p + i + 1) % M])) {
			w[now][(p + i) % M] = 0;
			w[now][(p + i + 1) % M] = 0;
			FLAG = 0;
		}
	}
	return;
}

void colAdjacent(int move) {
	for (int i = 0; i < N - 1; i++) {
		if (v[i][(head[i] + move) % M] != 0 && (v[i][(head[i] + move) % M] == v[i + 1][(head[i + 1] + move) % M])) {
			w[i][(head[i] + move) % M] = 0;
			w[i + 1][(head[i + 1] + move) % M] = 0;
			FLAG = 0;
		}
	}
	return;
}

void reviseVal() {
	int i, j, total, cnt;
	total = 0, cnt = 0;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			total += v[i][j];
			if (v[i][j]) cnt++;
		}
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (v[i][j]) {
				if (cnt * v[i][j] > total) v[i][j]--;
				else if (cnt * v[i][j] < total) v[i][j]++;
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, t;
	int x, d, k;
	double mean;
	cin >> N >> M >> T;
	v.resize(N, vector<int>(M, 0));
	w.resize(N, vector<int>(M, 0));
	head.resize(N, 0);
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) cin >> v[i][j];
	}
	for (t = 0; t < T; t++) {
		cin >> x >> d >> k;
		for (i = x; i <= N; i+=x) {
			if (d) head[i - 1] = (head[i - 1] + k) % M;
			else head[i - 1] = (head[i - 1] + M - k) % M;
		}
		FLAG = 1;
		w = v;
		for (i = 0; i < N; i++) rowAdjacent(i);
		for (i = 0; i < M; i++) colAdjacent(i);
		
		if (FLAG) reviseVal();
		else v = w, w.clear();
	}
	int result = 0;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) result += v[i][j];
	}
	cout << result;
	return 0;
}