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


int f(int a, int b) {
	return (b - a) * (b - a + 1) / 2;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, S, N, Mb, mb, cnt;
	vector<int>::iterator it;
	cin >> S;
	v.resize(S, 0);
	for (i = 0; i < S; i++) cin >> v[i];
	sort(v.begin(), v.end());
	cin >> N;

	it = lower_bound(v.begin(), v.end(), N);
	if (v[it - v.begin()] == N) {
		cout << 0;
		return 0;
	}
	Mb = v[it - v.begin()] - 1;
	if (it - v.begin()) mb = v[it - v.begin() - 1] + 1;
	else mb = 1;
	cnt = 0;
	//cout << mb << ' ' << Mb << endl;
	cout << f(mb, Mb) - f(mb, N - 1) - f(N + 1, Mb);
	
	return 0;
}