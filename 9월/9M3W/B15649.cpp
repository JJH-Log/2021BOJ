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
#include <sstream>
#define MOD 1000000007
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

vector<bool> lock;
vector<int> v;
int N, M;

void backTracking(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) cout << v[i] + 1 << ' ';
		cout << '\n';
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!lock[i]) {
			lock[i] = true;
			v[cnt] = i;
			backTracking(cnt + 1);
			lock[i] = false;
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	v.resize(M, 0);
	lock.resize(M, 0);
	backTracking(0);

	return 0;
}