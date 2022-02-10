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
#define MOD 1000000009
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, A, B, cnt;
	cin >> N >> A >> B;
	cnt = 0;
	while (((A + 1) / 2) != ((B + 1) / 2)) {
		cnt++;
		A = (A + 1) / 2;
		B = (B + 1) / 2;
	}
	cout << cnt + 1;

	return 0;
}
