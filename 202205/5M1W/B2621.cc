#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <cstring>
#include <string.h>
#include <math.h>
#include <set>
#include <cassert>
#include <bitset>
#include <sstream>
#include <cmath>
#include <random>
#include <numeric>
#define MOD 14579
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

struct card {
	char color;
	int num;
};
card v[5];

bool cmp_color(card x, card y) {
	if (x.color == y.color) return x.num < y.num;
	return x.color < y.color;
}

bool cmp_num(card x, card y) {
	if (x.num == y.num) return x.color < y.color;
	return x.num < y.num;
}

int isRule1() {
	sort(v, v + 5, cmp_num);
	char tar = v[0].color;
	int tnum = v[0].num;
	for (int i = 1; i < 5; i++) {
		if (v[i].color != tar) return -1;
		if (v[i].num != tnum + i) return -1;
	}
	return 900 + v[4].num;
}

int isRule2() {
	if ((v[0].num == v[1].num) && (v[1].num == v[2].num) && (v[2].num == v[3].num)) return 800 + v[1].num;
	if ((v[3].num == v[4].num) && (v[1].num == v[2].num) && (v[2].num == v[3].num)) return 800 + v[1].num;
	return -1;
}

int isRule3() {
	if ((v[0].num == v[1].num) && (v[1].num == v[2].num) && (v[3].num == v[4].num)) return 700 + v[0].num * 10 + v[3].num;
	if ((v[0].num == v[1].num) && (v[2].num == v[3].num) && (v[3].num == v[4].num)) return 700 + v[4].num * 10 + v[0].num;
	return -1;
}

int isRule4() {
	char tar = v[0].color;
	for (int i = 1; i < 5; i++) if (v[i].color != tar) return -1;
	return 600 + v[4].num;
}

int isRule5() {
	int tnum = v[0].num;
	for (int i = 1; i < 5; i++) if (v[i].num != tnum + i) return -1;
	return 500 + v[4].num;
}

int isRule6() {
	if ((v[0].num == v[1].num) && (v[1].num == v[2].num)) return 400 + v[0].num;
	if ((v[1].num == v[2].num) && (v[2].num == v[3].num)) return 400 + v[1].num;
	if ((v[2].num == v[3].num) && (v[3].num == v[4].num)) return 400 + v[2].num;
	return -1;
}

int isRule7() {
	if ((v[0].num == v[1].num) && (v[2].num == v[3].num)) return 300 + v[2].num * 10 + v[0].num;
	if ((v[0].num == v[1].num) && (v[3].num == v[4].num)) return 300 + v[3].num * 10 + v[0].num;
	if ((v[1].num == v[2].num) && (v[3].num == v[4].num)) return 300 + v[3].num * 10 + v[1].num;
	return -1;
}

int isRule8() {
	for (int i = 0; i < 4; i++) if (v[i].num == v[i + 1].num) return 200 + v[i].num;
	return -1;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 5; i++) cin >> v[i].color >> v[i].num;
	
	if (isRule1() != -1) cout << isRule1();
	else if (isRule2() != -1) cout << isRule2();
	else if (isRule3() != -1) cout << isRule3();
	else if (isRule4() != -1) cout << isRule4();
	else if (isRule5() != -1) cout << isRule5();
	else if (isRule6() != -1) cout << isRule6();
	else if (isRule7() != -1) cout << isRule7();
	else if (isRule8() != -1) cout << isRule8();
	else cout << 100 + v[4].num;

	return 0;
}
