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
	bool operator==(pos t){
		return x == t.x && y == t.y;
	}
};

int N, M;
int v[10][10];
bool res;
pos R, B, O;

pos move(pos now, pos other, int d){
	int dx = now.x + "2011"[d] - '1';
	int dy = now.y + "1120"[d] - '1';
	if(pos{dx, dy} == O) return {-1, -1};
	if(pos{dx, dy} == other || v[dx][dy]) return now;
	return move({dx, dy}, other, d);
}

int check(pos r, pos b){
	int ans = 0;
	if(r == pos{-1, -1}) ans += 2;
	if(b == pos{-1, -1}) ans += 1;
	if(ans == 2) res = true;
	return ans;
}

bool asks (int op, pos r, pos b){
	if(op == 0) return r.x >= b.x;
	if(op == 1) return r.x <= b.x;
	if(op == 2) return r.y >= b.y;
	if(op == 3) return r.y <= b.y;
}

void simulation(int cnt, pos r, pos b){
	if (res || cnt == 10) return;
	pos tr, tb;
	for (int i = 0; i < 4; i++){
		if(asks(i, r, b)) { tr = move(r, b, i); tb = move(b, tr, i); }
		else { tb = move(b, r, i); tr = move(r, tb, i); }
		if(!check(tr, tb)) simulation(cnt + 1, tr, tb);
	}
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++){
		string s;
		cin >> s;
		for (int j = 0; j < M; j++){
			v[i][j] = s[j] == '#'? 1 : 0;
			if(s[j] == 'R') R = {i, j};
			if(s[j] == 'B') B = {i, j};
			if(s[j] == 'O') O = {i, j};
		}
	}
	simulation(0, R, B);
	cout << res;
	return 0;
}