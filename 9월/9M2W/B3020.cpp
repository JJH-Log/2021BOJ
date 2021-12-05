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

vector<int> vb, vt;
int N, H;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, t, result, now, cnt;
	cin >> N >> H;
	vb.resize(H, 0);
	vt.resize(H, 0);
	for (i = 0; i < N; i++) {
		cin >> t;
		if (i % 2) vt[H - t]++;
		else vb[t - 1]++;
	}
	result = (N + 1) / 2; now = (N + 1) / 2; cnt = 1;
	for (i = 1; i < H; i++) {
		now += vt[i] - vb[i - 1];
		if (result > now) result = now, cnt = 1;
		else if (result == now) cnt++;
	}
	cout << result << ' ' << cnt;
	
	return 0;
}