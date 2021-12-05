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
#include <sstream>
#define MOD 1000000009
#define BOUND 10000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;

int N, K;
int v[9][9];
int r[3][20];
bool lock[9];
bool result;
int used[3];

int isWin(int score) {
	if (score % (K + 1) == K) return 0;
	if ((score / (K + 1)) % (K + 1) == K) return 1;
	if ((score / ((K + 1) * (K + 1))) % (K + 1) == K) return 2;
	return -1;
}

int kmulti(int num) {
	if (num == 0) return 1;
	if (num == 1) return K + 1;
	return (K + 1) * (K + 1);
}

void solve(int user_1, int user_2, int score) { //지우 : 0 경희 : 1 민호 : 2
	if (result) return;
	int check = isWin(score);
	if (check >= 0) {
		if (!check) result = true;
		return;
	}
	if (user_1 != 0 && user_2 != 0) {
		int ans = v[r[user_1][used[user_1]]][r[user_2][used[user_2]]];
		used[user_1]++, used[user_2]++;
		if (ans == 2 || (ans == 1 && user_1 == 2)) solve(user_1, 0, score + kmulti(user_1));
		else solve(user_2, 0, score + kmulti(user_2));
		used[user_1]--, used[user_2]--;
	}
	else if (user_1 == 0) {
		for (int i = 0; i < N; i++) {
			if (lock[i]) continue;
			int ans = v[i][r[user_2][used[user_2]]];
			lock[i] = true, used[user_2]++;
			if (ans == 2) solve(0, 3 - user_2, score + 1);
			else solve(user_2, 3 - user_2, score + kmulti(user_2));
			lock[i] = false, used[user_2]--;
		}
	}
	else {
		for (int i = 0; i < N; i++) {
			if (lock[i]) continue;
			int ans = v[i][r[user_1][used[user_1]]];
			lock[i] = true, used[user_1]++;
			if (ans == 2) solve(0, 3 - user_1, score + 1); 
			else solve(user_1, 3 - user_1, score + kmulti(user_1));
			lock[i] = false; used[user_1]--;
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> v[i][j];
	}
	for (int i = 0; i < 20; i++) cin >> r[1][i], r[1][i]--;
	for (int i = 0; i < 20; i++) cin >> r[2][i], r[2][i]--;
	for (int i = 0; i < N; i++) lock[i] = false;
	for (int i = 0; i < 3; i++) used[i] = 0;
	result = false;
	
	solve(0, 1, 0);
	cout << result;
	
	return 0;
}
