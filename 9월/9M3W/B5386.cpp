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


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, S, K, result;
	cin >> T;
	while (T--) {
		cin >> S >> K;
		if (K % 2) {
			if (S % 2) result = 1;
			else result = 0;
		}
		else {
			if (S % (K + 1) == K) result = K;
			else if ((S % (K + 1)) % 2) result = 1;
			else result = 0;
		}
		cout << result << '\n';
	}
	return 0;
}