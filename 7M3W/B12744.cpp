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
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXLEN 10000000
//for (const auto& i : v) cout << i << ' ';
using namespace std;
using lld = long long;

vector<int> cake;
vector<bool> check;
map<string, int> state;
vector<vector<int>> v;
queue<pair<string, int>> q;
int N, gCnt;

void backTracking(int cnt) {
	if (cnt == N) {
		string ans = "";
		for (int i = 0; i < N; i++) ans += to_string(cake[i]);
		state[ans] = gCnt - 1;
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!check[i]) {
			check[i] = true;
			if (cnt == N - 1) gCnt++;
			cake[cnt] = i;
			backTracking(cnt + 1);
			check[i] = false;
		}
	}
	return;
}

void update(pair<string, int> X) {
	int i, j;
	string now = X.first;
	int sign = X.second;
	int val = v[state[now]][sign];
	for (i = 0; i < N; i++) {
		string next = now;
		int next_sign = 0;
		for (j = 0; j <= i; j++) {
			next[j] = now[i - j];
			if ((sign & (1 << (i - j))) == 0) next_sign += (1 << j);
		}
		for (j = i + 1; j < N; j++) next_sign += (sign & (1 << j));
		if (v[state[next]][next_sign] > val + 1) {
			v[state[next]][next_sign] = val + 1;
			q.push({ next, next_sign });
		}
	}
	return;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string temp, now, target;
	int sign;
	char c;
	cin >> N;
	cake.resize(N, 0);
	check.resize(N, false);

	backTracking(0);
	v.resize(gCnt, vector<int>((1 << N), 1e9));
	
	target = "";
	now = "";
	sign = 0;
	for (int i = 0; i < N; i++) {
		target += to_string(i);
		cin >> c;
		now += c - 1;
		cin >> c;
		if (c == '-') sign += (1 << i);
	}
	v[state[now]][sign] = 0;
	q.push({ now, sign });
	while (v[state[target]][0] == 1e9) {
		update(q.front());
		q.pop();
	}
	cout << v[state[target]][0];
	return 0;
}