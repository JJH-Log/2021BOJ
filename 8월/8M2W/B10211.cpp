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
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, N, i, temp;
	int result, total;
	int FLAG, u;
	cin >> T;
	while (T--) {
		cin >> N;
		FLAG = true;
		result = total = 0;
		u = -1e9;
		for (i = 0; i < N; i++) {
			cin >> temp;
			total += temp;
			if (temp < 0) u = max(u, temp);
			else FLAG = false;
			if (total < 0) total = 0;
			result = max(result, total);
		}
		if (FLAG) cout << u << '\n';
		else cout << result << '\n';
	}
	return 0;
}