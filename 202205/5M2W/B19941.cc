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
#include <regex>
#define MOD 1000000007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N, K, res;
bool ate[20000];
string s;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K >> s;
	for (int i = 0; i < N; i++) {
		if (s[i] == 'H') continue;
		bool FLAG = false;
		for (int j = -K; !FLAG && j <= K; j++) {
			if (0 <= i + j && i + j < N && s[i + j] == 'H' && !ate[i + j]) {
				ate[i + j] = FLAG = true;
			}
		}
		res += FLAG;
	}
	cout << res;

	return 0;
}