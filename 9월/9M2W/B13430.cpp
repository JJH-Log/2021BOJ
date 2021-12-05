#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string> //substr
#include <map>
#include <queue>
#include <stack>
#include <utility>  //pair
#include <algorithm> //sort, reverse
#include <math.h> // sqrt
#include <set>
#include <cassert>
#define MOD 1000000007
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

vector<lld> v;
queue<int> q;
lld N, K;

void push_frag(int X) {
	for (int i = 2; i <= X; i++) {
		while (X % i == 0 && X > 1) {
			q.push(i);
			X /= i;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	lld result;
	int i, j, A, B, now;
	cin >> K >> N;
	A = N + K;
	B = min(N - 1, K + 1);
	v.resize(B, 0);
	for (i = 0; i < B; i++) v[i] = A - i;
	for (i = 1; i <= B; i++) push_frag(i);
	while (!q.empty()) {
		now = q.front();
		q.pop();
		for (i = 0; i < B; i++) {
			if (v[i] % now == 0) {
				v[i] /= now;
				break;
			}
		}
	}
	result = 1;
	for (i = 0; i < B; i++) result = (result * v[i]) % MOD;
	cout << result;
	return 0;
}