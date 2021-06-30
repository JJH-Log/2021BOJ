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
#define MOD 1000000007
//for (const auto& i : v) cout << i << ' ';
using namespace std;
using lld = long long;

vector<int> v;
vector<int> w;

int check(int A, int B) {
	int a, b;
	a = (A & (1 << 5)) >> 5;
	b = (B & (1 << 1)) >> 1;
	if (a ^ b) return 1;
	return 0;
}

int roll(int X, int dir) {
	int temp;
	if (dir == 1) {
		temp = X & 1;
		X = X >> 1;
		X += (temp << 7);
	}
	else if (dir == -1){
		temp = X & (1 << 7);
		X = X << 1;
		if (temp) {
			X -= (1 << 8);
			X += 1;
		}
	}
	return X;
}

void action(int idx, int dir) {
	w[idx] = dir;
	if (idx != 0 && w[idx - 1] == 0 && check(v[idx - 1], v[idx])) action(idx - 1, (-1) * dir);
	if (idx != 3 && w[idx + 1] == 0 && check(v[idx], v[idx + 1])) action(idx + 1, (-1) * dir);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, temp, K, x, y;
	int result;
	string s;
	w.resize(4, 0);
	for (i = 0; i < 4; i++) {
		cin >> s;
		temp = 0;
		for (j = 0; j < 8; j++) {
			if (s[j] == '1') temp += (1 << (7 - j));
		}
		v.push_back(temp);
	}
	cin >> K;
	for (i = 0; i < K; i++) {
		for (j = 0; j < 4; j++) w[j] = 0;
		cin >> x >> y;
		action(x - 1, y);
		for (j = 0; j < 4; j++) v[j] = roll(v[j], w[j]);
	}
	result = 0;
	for (i = 0; i < 4; i++) {
		if(v[i] & (1 << 7)) result += 1 << i;
	}

	cout << result;
	return 0;
}