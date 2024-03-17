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
#define MOD 10007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXS 30000
using namespace std;
using lld = long long;
using pii = pair<int, int>;



struct info {
	int idx;
	int state;
};

map<string, int> ec;
string dc[MAXS];


int N, M, num;
int v[10][10];
bool vtd[100][MAXS];
int dp[100][MAXS];
int result;
queue<info> q;
bool inQ[100 * MAXS];

int encode(string X) {
	if (!ec.count(X)) {
		ec[X] = num;
		dc[num] = X;
		return num++;
	}
	return ec[X];
}

string init() {
	string ans = "1";
	for (int i = 1; i < M; i++) ans += '0';
	ans += '4';
	for (int i = 1; i < M; i++) ans += '0';
	return ans;
}

bool check(string X) { //0을 설치해도 되는지 검사
	if (X[M] >= '4') return false;
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

string normalization2(string X) {
	string ans = "";
	
	for (int i = 0; i < M - 1; i++) ans += (X[M + i] >= '4') ? X[i] : '0';
	ans += X[M - 1];
	for (int i = 0; i < M - 1; i++) ans += (X[M + i] >= '4') ? '4' : '0';
	ans += X[2 * M - 1];
	return ans;
}

void pushNext(int idx, string now, char c, char b) {
	if (b >= '4' && (idx / M == (N - 1)) && (idx != N * M - 1)) return;
	if ((b == '1' || b == '3' || b == '6') && (idx % M == (M - 1))) return;
	if (b >= '1' && v[idx / M][idx % M]) return;

	string next = "";
	string pipes = now.substr(M + 1, M - 1) + b;

	if (c == '-') {
		for (int i = 1; i < M; i++) next += (now[i] == now[M - 1]) ? now[0] : now[i];
		next = normalization(next + now[0]);
	}
	else next = normalization(now.substr(1, M - 1) + c);
	next += pipes;
	next = normalization2(next);

	int bstate, nstate, ans;
	bstate = encode(now);
	nstate = encode(next);
	ans = idx ? dp[idx - 1][bstate] : 1;

	if (!vtd[idx][nstate]) {
		vtd[idx][nstate] = true;
		dp[idx][nstate] = ans % MOD;
	}
	else dp[idx][nstate] = (dp[idx][nstate] + ans) % MOD;

	if (idx == N * M - 1) {
		if (check2(next) && next[2 * M - 1] >= '4') {
			result = (result + ans) % MOD;
		}
		return;
	}
	else {
		if (!inQ[(idx + 1) * MAXS + nstate]) {
			inQ[(idx + 1) * MAXS + nstate] = true;
			q.push({ idx + 1, nstate });
		}
	}
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < M; j++) v[i][j] = (tmp[j] == '#');
	}

	q.push({ 0, encode(init()) });
	inQ[0] = true;
	while (!q.empty()) {
		info now = q.front();
		string now_state = dc[now.state];
		q.pop();
		if (check(now_state)) {
			if (now_state[M] <= '3' && now_state[2 * M - 1] != '1' && now_state[2 * M - 1] != '3' && now_state[2 * M - 1] != '6') pushNext(now.idx, now_state, '0', '0');
		}
		if ((now.idx % M) == 0) {
			if (now_state[0] == '0') pushNext(now.idx, now_state, '9', '6');
			else {
				if (now_state[M] >= '4') {
					pushNext(now.idx, now_state, now_state[0], '3');
					pushNext(now.idx, now_state, now_state[0], '4');
				}
				else pushNext(now.idx, now_state, '9', '6');
			}
		}
		else {
			if (now_state[0] == '0' && now_state[M - 1] == '0') pushNext(now.idx, now_state, '9', '6');
			else if (now_state[0] == '0' && now_state[M - 1] != '0') {
				if (now_state[2 * M - 1] == '1' || now_state[2 * M - 1] == '3' || now_state[2 * M - 1] == '6') {
					pushNext(now.idx, now_state, now_state[M - 1], '1');
					pushNext(now.idx, now_state, now_state[M - 1], '5');
				}
				else pushNext(now.idx, now_state, '9', '6');
			}
			else if (now_state[0] != '0' && now_state[M - 1] == '0') {
				if (now_state[M] >= '4') {
					pushNext(now.idx, now_state, now_state[0], '3');
					pushNext(now.idx, now_state, now_state[0], '4');
				}
				else if(check(now_state)) pushNext(now.idx, now_state, '9', '6');
			}
			else {
				if (now_state[2 * M - 1] == '1' || now_state[2 * M - 1] == '3' || now_state[2 * M - 1] == '6') {
					if (now_state[M] >= '4') {
						if (now_state[0] != now_state[M - 1]) pushNext(now.idx, now_state, '-', '2');
					}
					else {
						if(check(now_state)) pushNext(now.idx, now_state, now_state[M - 1], '1');
						if(check(now_state)) pushNext(now.idx, now_state, now_state[M - 1], '5');
					}
				}
				else {
					if (now_state[M] >= '4') {
						pushNext(now.idx, now_state, now_state[0], '3');
						pushNext(now.idx, now_state, now_state[0], '4');
					}
					else {
						if (check(now_state)) pushNext(now.idx, now_state, '9', '6');
					}
				}
			}
		}
	}
	cout << result;
	
	return 0;
}
