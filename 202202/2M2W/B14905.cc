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
using namespace std;
using lld = long long;
using pii = pair<int, int>;

vector<int> p;
int p3[1000][3];
int tmp[3];

void backTracking(int cnt, int total) {
	if (cnt == 3) {
		if (!p3[total][0]) {
			p3[total][0] = tmp[0];
			p3[total][1] = tmp[1];
			p3[total][2] = tmp[2];
		}
		return;
	}
	for (int i = 0; i < p.size() && (total + p[i]) < 1000; i++) {
		tmp[cnt] = p[i];
		backTracking(cnt + 1, total + p[i]);
	}
}

bool isPrime(int X) {
	for (int i = 0; p[i] * p[i] <= X; i++) {
		if (X % p[i] == 0) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	p.push_back(2);
	for (int i = 3; i <= 10007; i += 2) if (isPrime(i)) p.push_back(i);
	backTracking(0, 0);
	int N;
	for (int i = 6; i < 1000; i++) if (!p3[i][0]) cout << i << endl;

	while (true) {
		cin >> N;
		if (cin.eof()) break;
		if (N < 8) cout << "Impossible.\n";
		else {
			for (int i = 6; i < 1000; i++) {
				if (isPrime(N - i)) {
					cout << N - i << ' ' << p3[i][0] << ' ' << p3[i][1] << ' ' << p3[i][2] << '\n';
					break;
				}
			}
		}
	}


	return 0;
}
