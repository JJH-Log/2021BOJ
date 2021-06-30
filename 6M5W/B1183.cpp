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

	int i, N, a, b, tar;
	cin >> N;
	v.resize(N, 0);
	for (i = 0; i < N; i++) {
		cin >> a >> b;
		v[i] = a - b;
	}
	if (N % 2 == 1) {
		cout << 1;
		return 0;
	}
	sort(v.begin(), v.end());
	tar = N / 2;
	cout << v[tar] - v[tar - 1] + 1;
	return 0;
}