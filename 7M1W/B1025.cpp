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
int N, M;


bool issquare(int x) {
	if (!x) return true;
	int rx = (int)sqrt(x);
	return x == rx * rx;
}

int ans(int x, int y, int dx, int dy) {
	if (dx == 0 && dy == 0) return -1;
	queue<int> q;
	int FLAGx, FLAGy, temp, total, result;
	FLAGx = 1;  FLAGy = 1;
	while (FLAGx && FLAGy) {
		q.push(v[x][y]);
		if (FLAGx) x += dx;
		if (FLAGy) y += dy;
		if (x < 0 || x >= N) FLAGx = 0;
		if (y < 0 || y >= M) FLAGy = 0;
	}
	total = 0;
	result = -1;
	while (!q.empty()) {
		temp = q.front();
		q.pop();
		total *= 10;
		total += temp;
		if (issquare(total)) result = total;
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int i, j, dx, dy, result;
	string s;
	cin >> N >> M;
	v.resize(N, vector<int>(M, 0));
	for (i = 0; i < N; i++) {
		cin >> s;
		for (j = 0; j < M; j++) v[i][j] = s[j] - '0';
	}
	result = -1;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			for (dx = -10; dx < 10; dx++) {
				for (dy = -10; dy < 10; dy++) {
					result = max(result, ans(i, j, dx, dy));
				}
			}
		}
	}
	cout << result;
	return 0;
}