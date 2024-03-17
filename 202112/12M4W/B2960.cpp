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

int N, K;
bool v[1001];

int find() {
	for (int i = 2; i <= 1000; i++) if (!v[i]) return i;
	return 0;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int now, cnt = 0;
	cin >> N >> K;
	while (now = find()) {
		for (int i = now; i <= N; i += now) {
			if (!v[i]) {
				v[i] = true, cnt++;
				if (cnt == K) {
					cout << i;
					return 0;
				}
			}
		}
	}

	return 0;
}
