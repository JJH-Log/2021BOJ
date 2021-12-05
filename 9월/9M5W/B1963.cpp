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

#define MOD 1000000007
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

bool w[10000];
int v[10000];
queue<int> q;

bool isPrime(int X) {
	for (int i = 3; i <= sqrt(X); i += 2) {
		if (X % i == 0) return false;
	}
	return true;
}

int getNext(int X, int d, int div) {
	int dv = 1;
	for (int i = 0; i < div; i++) dv *= 10;
	int Y = ((X / dv) % 10) * dv;
	return X - Y + d * dv;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, T, now, next;
	cin >> T;

	for (int i = 1001; i < 10000; i += 2) if (isPrime(i)) w[i] = 1;

	while (T--) {
		cin >> N >> M;
		v[N] = 1;
		q.push(N);
		while (!q.empty()) {
			now = q.front();
			q.pop();
			if (!v[M]) {
				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 10; j++) {
						if (i + j) { // 첫 자리 0오는걸 방지
							next = getNext(now, j, i);
							if (w[next] && !v[next]) {
								v[next] = v[now] + 1;
								q.push(next);
							}
						}
					}
				}
			}
		}
		if (v[M]) cout << v[M] - 1 << '\n';
		else cout << "Impossible\n";
		fill(v, v + 10000, 0);
	}
	

	return 0;
}