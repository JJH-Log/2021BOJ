#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <set>
#include <cassert>
#include <bitset>
#include <sstream>
#include <cmath>
#define MOD 1000000007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;

struct info {
	int idx;
	int state;
};

map<string, int> ec;
string dc[8000];

int N, M, num;
int v[9][9];
bool vtd[81][8000];
int dp[81][8000];
int result;
queue<info> q;
bool inQ[810000];

int encode(string X) {
	if (!ec.count(X)) {
		ec[X] = num;
		dc[num] = X;
		return num++;
	}
	return ec[X];
}

string init() {
	string ans = "";
	for (int i = 0; i < M; i++) ans += '0';
	return ans;
}

bool check(string X) { //0을 설치해도 되는지 검사
	if (X[0] == '0') return true;
	for (int i = 1; i < M; i++) if (X[i] == X[0]) return true;
	return false;
}

bool check2(string X) { //컴포넌트가 하나뿐인지 검사
	bool FLAG = false;
	for (int i = 0; i < M; i++) {
		if (X[i] != '0' && X[i] != '1') return false;
		if (X[i] == '1') FLAG = true;
	}
	return FLAG;
}


string normalization(string X) {
	int linked[10] = { 0, };
	int num = 1;
	string ans = "";
	for (int i = 0; i < M; i++) if (X[i] != '0' && linked[X[i] - '0'] == 0) linked[X[i] - '0'] = num++;
	for (int i = 0; i < M; i++) ans += (X[i] == '0') ? '0' : ('0' + linked[X[i] - '0']);
	return ans;
}


void pushNext(int idx, string now, char c) {
	string next = "";

	if (c == '-') {
		for (int i = 1; i < M; i++) next += (now[i] == now[M - 1]) ? now[0] : now[i];
		next = normalization(next + now[0]);
	}
	else next = normalization(now.substr(1) + c);

	int bstate, nstate, ans;
	bstate = encode(now);
	nstate = encode(next);
	ans = idx ? dp[idx - 1][bstate] : 0;
	if ((int)(next[M - 1] - '0')) ans += v[idx / M][idx % M];

	if (!vtd[idx][nstate]) {
		vtd[idx][nstate] = true;
		dp[idx][nstate] = ans;
	}
	else dp[idx][nstate] = min(dp[idx][nstate], ans);
	if (check2(next)) result = min(result, dp[idx][nstate]);

	if ((idx + 1) != N * M && !inQ[(idx + 1) * 8000 + nstate]) {
		inQ[(idx + 1) * 8000 + nstate] = true;
		q.push({ idx + 1, nstate });
	}
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cin >> v[i][j];
	}

	q.push({ 0, encode(init()) });
	inQ[0] = true;
	while (!q.empty()) {
		info now = q.front();
		string now_state = dc[now.state];
		q.pop();

		if (check(now_state)) pushNext(now.idx, now_state, '0');
		if ((now.idx % M) == 0) {
			if (now_state[0] == '0') pushNext(now.idx, now_state, '9');
			else pushNext(now.idx, now_state, now_state[0]);
		}
		else {
			if (now_state[0] == '0' && now_state[M - 1] == '0') pushNext(now.idx, now_state, '9');
			else if (now_state[0] == '0' && now_state[M - 1] != '0') pushNext(now.idx, now_state, now_state[M - 1]);
			else if (now_state[0] != '0' && now_state[M - 1] == '0') pushNext(now.idx, now_state, now_state[0]);
			else {
				if (now_state[0] == now_state[M - 1]) pushNext(now.idx, now_state, now_state[0]);
				else pushNext(now.idx, now_state, '-');
			}
		}
	}
	cout << result;

	return 0;
}
