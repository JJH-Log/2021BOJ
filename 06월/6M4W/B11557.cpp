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
	
	string ts, ms;
	int t, T, i, tl, ml, N;
	cin >> T;
	for (t = 0; t < T; t++) {
		ms.clear();
		ml = -1;
		cin >> N;
		for (i = 0; i < N; i++) {
			cin >> ts >> tl;
			if (tl > ml) {
				ms = ts;
				ml = tl;
			}
		}
		cout << ms << '\n';
	}
	return 0;
}