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

vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, N, S, P, r1;
	cin >> N >> S >> P;
	if (!N) {
		cout << 1;
		return 0;
	}
	else {
		v.resize(P + 1, -1);
		for (i = 0; i < N; i++) {
			cin >> v[P];
			sort(v.begin(), v.end(), greater<int>());
		}
		r1 = P;
		for (i = 0; i < P; i++) {
			if (r1 == P && v[i] == S) r1 = i;
			if (v[i] < S) {
				if (r1 != P) cout << r1 + 1;
				else cout << i + 1;
				return 0;
			}
		}
		cout << -1;
	}
	return 0;
}