#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <math.h>
#include <set>
#include <cassert>
#include <sstream>
#define MOD 1000000
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

int v[7], lock[10];
int target, deg;
bool result;

void check() {
	int hello = v[0] * 10000 + v[2] * 1000 + v[4] * 110 + v[3];
	int world = v[1] * 10000 + v[3] * 1000 + v[5] * 100 + v[4] * 10 + v[6];
	if (hello + world == target && !result) {
		cout << "  " << hello << '\n' << "+ " << world << "\n-------\n";
		for (int i = 0; i < (7 - deg); i++) cout << ' ';
		cout << target;
		result = true;
	}
}

void backTracking(int cnt) {
	if (cnt == 7) check();
	for (int i = 0; i <= 9; i++) {
		if (!lock[i]) {
			if (i != 0 || cnt > 1) {
				lock[i] = 1;
				v[cnt] = i;
				backTracking(cnt + 1);
				lock[i] = 0;
			}
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> target;
	int t = target;
	deg = 0;
	while (t) {
		deg++;
		t /= 10;
	}
	backTracking(0);
	if (!result) cout << "No Answer";
	
	return 0;
}