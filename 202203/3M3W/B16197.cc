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
#include <random>
#include <numeric>
#define MOD 1000000007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

struct pos{
	int x, y;
};

struct state{
	pos p[2];
	int t;
};

int N, M, v[20][20], res;
queue<state> q;
state S;
string s;

bool inRange(pos a){
	return (a.x >= 0) && (a.x < N) && (a.y >= 0) && (a.y < M);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	bool FLAG = false;
	for(int i = 0; i < N; i++){
		cin >> s;
		for(int j = 0; j < M; j++){
			if (s[j] == 'o') {
				if(!FLAG) S.p[0] = {i, j}, FLAG = true;
				else S.p[1] = {i, j};
			}
			if (s[j] == '#') v[i][j] = 1;
		}
	}
	S.t = 0;

	q.push(S);
	while(!q.empty()){
		state now = q.front();
		q.pop();
		if(!inRange(now.p[0]) && !inRange(now.p[1])) continue;
		if(!inRange(now.p[0]) || !inRange(now.p[1])){
			cout << now.t;
			return 0;
		}
		if(now.t == 10) continue;
		for(int i = 0; i < 4; i++){
			state next;
			for(int j = 0; j < 2; j++){
				int dx = now.p[j].x + "2011"[i] - '1';
				int dy = now.p[j].y + "1120"[i] - '1';
				if(inRange({dx, dy}) && v[dx][dy] == 1) next.p[j] = now.p[j];
				else next.p[j] = {dx, dy};
			}
			next.t = now.t + 1;
			q.push(next);
		}
	}
	cout << -1;

	return 0;
}