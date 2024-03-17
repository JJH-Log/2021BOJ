#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
#define MOD 1000000000
//for (const auto& i : v) cout << i << ' ';
using namespace std;
using lld = long long;

int N, K;

int getUnderCnt(int X) {
	int result = 0;
	for (int i = 1; i <= N; i++) {
		result += min(X / i, N);
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int l, r, mid;
	cin >> N >> K;
	l = 1; r = K;
	while (l != r) {
		mid = (l + r) / 2;
		if (getUnderCnt(mid) < K) l = mid + 1;
		else r = mid;
	}
	cout << l;
	

	return 0;
}