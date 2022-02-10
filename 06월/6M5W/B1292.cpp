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

	int i, j, A, B, cnt;
	v.resize(1000, 0);
	j = 1, cnt = 0;
	for (i = 0; i < 1000; i++) {
		v[i] = j;
		cnt++;
		if (j == cnt) cnt = 0, j++;
	}
	cin >> A >> B;
	A--, B--, cnt = 0;
	for (i = A; i <= B; i++) cnt += v[i];
	cout << cnt;
	return 0;
}