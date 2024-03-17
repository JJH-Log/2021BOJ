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
#include <string.h>
#include <math.h>
#include <set>
#include <cassert>
#include <bitset>
#include <sstream>
#include <cmath>
#include <random>
#include <numeric>
#define MOD 998244353
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

lld tar[501], m[501], tmp[501];
string x, res, res2;
lld A, B;
int pt;
lld bound = 10000;

int _find(lld t[]) {
	for (int i = 500; i >= 0; i--) if (t[i]) return i;
}

void multiply() {
	for (int i = 0; i < 500; i++) tmp[i] = 0;
	int ptr1 = _find(tar);
	int ptr2 = _find(m);
	for (int i = 0; i <= ptr1; i++) {
		for (int j = 0; j <= ptr2; j++) {
			tmp[i + j] += tar[i] * m[j];
		}
	}
	for (int i = 0; i < 500; i++) {
		tmp[i + 1] += tmp[i] / bound;
		tmp[i] %= bound;
	}
	int ptr3 = _find(tmp);
	for (int i = 0; i <= ptr3; i++) m[i] = tmp[i];
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> x >> B;
	A = 0;
	for (int i = 0; i < x.size(); i++){
		if (x[i] != '.') {
			A *= 10;
			A += x[i] - '0';
		}
		else pt = x.size() - i - 1;
	}
	tar[0] = A;
	for (int i = 0; i < 500; i++) {
		tar[i + 1] = tar[i] / bound;
		tar[i] %= bound;
	}
	int ptr = _find(tar);
	for (int i = 0; i <= ptr; i++) m[i] = tar[i];
	for (int i = 1; i < B; i++) multiply();
	ptr = _find(m);
	for (int i = 0; i <= ptr; i++) {
		while (m[i]) {
			res += '0' + (m[i] % 10);
			m[i] /= 10;
		}
		if (i != ptr) while (res.size() != 4 * (i + 1)) res += '0';
	}
	while (res.size() <= pt * B) res += '0';
	res2 = res.substr(0, pt * B);
	res2 += '.';
	res2 += res.substr(pt * B);
	reverse(res2.begin(), res2.end());
	cout << res2;
	return 0;
}