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

string A, B;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int ans = 100;
	cin >> A >> B;
	for (int i = 0; i < B.size() - A.size() + 1; i++) {
		int cnt = 0;
		for (int j = 0; j < A.size(); j++) if (B[j + i] != A[j]) cnt++;
		ans = min(cnt, ans);
	}
	cout << ans;
	
	return 0;
}
