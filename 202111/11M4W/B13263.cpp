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
#include <bitset>
#include <cassert>
#include <sstream>
#define MOD 1000000009
#define BOUND 10000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;

//Reference : https://justicehui.github.io/hard-algorithm/2019/01/25/CHT/

int a[100000], b[100000], fx[100000]; // f : Convex Hull 에 포함되는 함수
lld dp[100000];
double px[100000]; //교점
int N, sidx; //stack idx

double x_inter(int idx1, int idx2) {
	return ((double)dp[idx2] - dp[idx1]) / ((double)b[idx1] - b[idx2]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> a[i];
	for (int i = 0; i < N; i++) cin >> b[i];
	//fx[0] = dp[0] = px[0] = 0;
	sidx = 1;
	for (int i = 1; i < N; i++) {
		int idx = upper_bound(px, px + sidx, a[i]) - px;
		dp[i] = (lld)b[fx[idx - 1]] * a[i] + dp[fx[idx - 1]];
		while (px[sidx - 1] >= x_inter(fx[sidx - 1], i)) px[--sidx] = fx[sidx] = 0;
		px[sidx] = x_inter(fx[sidx - 1], i);
		fx[sidx] = i;
		sidx++;
	}
	cout << dp[N - 1];
	return 0;
}
