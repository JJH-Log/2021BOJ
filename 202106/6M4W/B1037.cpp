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
#define MOD 1000000007
//for (const auto& i : v) cout << i << ' ';
using namespace std;
using lld = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, t, m, M;
	m = 0, M = 0;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> t;
		if (!i) m = t, M = t;
		else {
			if (m > t) m = t;
			if (M < t) M = t;
		}
	}
	cout << M * m;
}