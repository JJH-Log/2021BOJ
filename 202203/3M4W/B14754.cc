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
#define MOD 1000000007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N, M;
int v[1000][1000];
bool rm[1000][1000];
lld res;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cin >> v[i][j];
	}

	for (int i = 0; i < N; i++) {
		int tar = 0;
		for (int j = 0; j < M; j++) if (v[i][j] > v[i][tar]) tar = j;
		rm[i][tar] = 1;
	}
	for (int j = 0; j < M; j++) {
		int tar = 0;
		for (int i = 0; i < N; i++) if (v[i][j] > v[tar][j]) tar = i;
		rm[tar][j] = 1;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!rm[i][j]) res += v[i][j];
		}
	}
	cout << res;
	

	return 0;
}