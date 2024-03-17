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

bool isPrime(int X) {
	for (int i = 2; i <= sqrt(X); i++) {
		if (X % i == 0) return false;
	}
	return true;
}


int getReverse(int X) {
	int result = 0;
	while (X) {
		result *= 10;
		result += X % 10;
		X /= 10;
	}
	return result;
}

int getNumber(int deg, int center, int now) {
	if (deg == 1) return now;
	int d = 1;
	for (int i = 0; i < deg / 2; i++) d *= 10;
	if (deg % 2) return now * d * 10 + center * d + getReverse(now);
	else return now * d + getReverse(now);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int trace[5] = { 9, 99, 999, 9999, 99999 };
	int idx = 0;

	int deg = 3, center = 0, now = 1;
	int A, B, X;
	cin >> A >> B;
	if (A <= 5 && 5 <= B) cout << 5 << '\n';
	if (A <= 7 && 7 <= B) cout << 7 << '\n';
	if (A <= 11 && 11 <= B) cout << 11 << '\n';

	while (true) {
		X = getNumber(deg, center, now);
		if (X > B) break;
		if (isPrime(X) && X >= A) cout << X << '\n';
		center = (center + 1) % 10;
		if (center % 10 == 0) now++;
		if (trace[idx] < now) deg += 2, idx++;
	}
	cout << -1;
	return 0;
}