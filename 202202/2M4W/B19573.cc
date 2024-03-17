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
#define BOUND 100000
#define MININT -2147483647
#define MAXINT 2147483647
#define DEAD -1000000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;

struct info {
	int bx, by;
	int x, y;
	int state;
};

map<string, int> ec;
string dc[BOUND];

int N, num;
lld F;
lld v[12][12];
bool vtd[12][12][BOUND];
lld dp[12][12][BOUND];
lld result;
queue<info> q;
bool inQ[12 * 12 * BOUND];

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
	for (int i = 0; i < N - 1; i++) ans += '0';
	return ans;
}

bool isOnly(string X) { // 첫번째 글자가 유일한 지 검사
	if (X[0] == '0') return false;
	for (int i = 1; i < X.size(); i++) {
		if (X[i] == X[0]) return false;
	}
	return true;
}

bool isOnly2(string X) { // 첫 두 글자가 유일한 지 검사
	if (X[0] == '0' && X[1] == '0') return false;
	if (X[1] == '0') return isOnly(X);
	if (X[0] == '0') return isOnly(X.substr(1));
	for (int i = 2; i < X.size(); i++) {
		if (X[i] == X[0]) return false;
	}
	return true;
}

bool check2(string X) { //컴포넌트가 하나뿐인지 검사
	bool FLAG = false;
	for (int i = 0; i < X.size(); i++) {
		if (X[i] > '1') return false;
		if (X[i] == '1') FLAG = true;
	}
	return FLAG;
}


string normalization(string X) {
	int linked[10] = { 0, };
	int num = 1;
	string ans = "";
	for (int i = 0; i < X.size(); i++) if (X[i] != '0' && linked[X[i] - '0'] == 0) linked[X[i] - '0'] = num++;
	for (int i = 0; i < X.size(); i++) ans += (X[i] == '0') ? '0' : ('0' + linked[X[i] - '0']);
	return ans;
}


void pushNext(int bx, int by, int nx, int ny, string now, char c) {
	string next = "";

	if (c == '-') {
		for (int i = 0; i < now.size(); i++) next += (now[i] == now[now.size() - 1]) ? now[1] : now[i];
		next += now[1];
	}
	else next = now + c;
	//cout << "NEXT : " << next << endl;
	if (ny == 0 && nx < N) next = normalization(next);
	else if (v[nx][ny + 1] == DEAD && nx >= N) next = normalization(next.substr(2));
	else next = normalization(next.substr(1));
	//cout << "NEXT AFTER : " << next << endl;
	int bstate, nstate;
	lld ans;
	bstate = encode(now);
	nstate = encode(next);
	ans = (bx != -1)? dp[bx][by][bstate] : 0;
	if ((int)(next[next.size() - 1] - '0')) ans += v[nx][ny];
	//cout << "pushNext : " << bx << ' ' << by << ' ' << nx << ' ' << ny << ' ' << now << ' ' << next << ' ' <<  c << ' ' << dp[bx][by][bstate] << ' ' << endl;
	if (!vtd[nx][ny][nstate]) {
		vtd[nx][ny][nstate] = true;
		dp[nx][ny][nstate] = ans;
	}
	else dp[nx][ny][nstate] = max(dp[nx][ny][nstate], ans);
	if (check2(next)) result = max(result, dp[nx][ny][nstate]);

	int ex, ey;
	ex = nx, ey = ny + 1;
	if (v[ex][ey] == DEAD) ex = nx + 1, ey = 0;
	if (v[ex][ey] == DEAD) return;

	if (!inQ[(ex * 12 + ey) * BOUND + nstate]) {
		inQ[(ex * 12 + ey) * BOUND + nstate] = true;
		q.push({ nx, ny, ex, ey, nstate });
	}
}


void fillhoney() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) v[i][j] = DEAD;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N + i; j++) cin >> v[i][j], v[i][j] = max(v[i][j], -F);
	}
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < (2 * N - 2) - i; j++) cin >> v[N + i][j], v[N + i][j] = max(v[N + i][j], -F);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	cin >> N >> F;
	fillhoney();

	if (N == 1) {
		cout << max(v[0][0], (lld)0);
		return 0;
	}

	q.push({ -1, -1, 0, 0, encode(init()) });
	inQ[0] = true;
	while (!q.empty()) {
		info now = q.front();
		string now_state = dc[now.state];
		q.pop();

		//cout << "NOW : " << now.bx << ' ' << now.by << ' ' << now.x << ' ' << now.y << ' ' << now.state << ' ' << now_state << ' ' << endl;
		//Part of Pass
		if (now.y == 0 && now.x < N) pushNext(now.bx, now.by, now.x, now.y, now_state, '0');
		else if (v[now.x][now.y + 1] == DEAD && now.x >= N) {
			if (!isOnly2(now_state)) pushNext(now.bx, now.by, now.x, now.y, now_state, '0');
		}
		else if (!isOnly(now_state)) pushNext(now.bx, now.by, now.x, now.y, now_state, '0');

		//Part of Connection
		if (now.y == 0) {
			if (now.x < N) {
				if (now_state[0] == '0') pushNext(now.bx, now.by, now.x, now.y, now_state, '9');
				else pushNext(now.bx, now.by, now.x, now.y, now_state, now_state[0]);
			}
			else {
				if (now_state[0] == '0' && now_state[1] == '0') pushNext(now.bx, now.by, now.x, now.y, now_state, '9');
				else if(now_state[0] == '0') pushNext(now.bx, now.by, now.x, now.y, now_state, now_state[1]);
				else pushNext(now.bx, now.by, now.x, now.y, now_state, now_state[0]);
			}
		}
		else {
			if (N == 2 && now.x == 0 && now.y == 1) { //N = 2, x = 0, y = 1일 때의 예외처리
				if(now_state[1] == '0') pushNext(now.bx, now.by, now.x, now.y, now_state, '9');
				else pushNext(now.bx, now.by, now.x, now.y, now_state, now_state[1]);
			}
			else if (now.x < N && v[now.x][now.y + 1] == DEAD) { //x < N 일때 끝부분 예외처리
				if (now_state[0] == '0' && now_state[now_state.size() - 1] == '0') pushNext(now.bx, now.by, now.x, now.y, now_state, '9');
				else if (now_state[0] != '0') pushNext(now.bx, now.by, now.x, now.y, now_state, now_state[0]);
				else pushNext(now.bx, now.by, now.x, now.y, now_state, now_state[now_state.size() - 1]);
			}
			else {
				if (now_state[0] == '0' && now_state[1] == '0' && now_state[now_state.size() - 1] == '0') pushNext(now.bx, now.by, now.x, now.y, now_state, '9');
				else if (now_state[0] != '0') pushNext(now.bx, now.by, now.x, now.y, now_state, now_state[0]);
				else if (now_state[0] == '0' && now_state[1] != '0' && now_state[now_state.size() - 1] == '0') pushNext(now.bx, now.by, now.x, now.y, now_state, now_state[1]);
				else if (now_state[0] == '0' && now_state[1] == '0' && now_state[now_state.size() - 1] != '0') pushNext(now.bx, now.by, now.x, now.y, now_state, now_state[now_state.size() - 1]);
				else if (now_state[0] == '0' && now_state[1] != '0' && now_state[now_state.size() - 1] != '0') pushNext(now.bx, now.by, now.x, now.y, now_state, '-');
			}

		}

	}
	//cout << num << endl;
	cout << result;

	return 0;
}
