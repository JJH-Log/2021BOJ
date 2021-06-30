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
	
	v.resize(11, -1);
	int x, y, i, N, result;
	cin >> N;
	result = 0;
	for (i = 0; i < N; i++) {
		cin >> x >> y;
		if (v[x] == -1) v[x] = y;
		else {
			if (v[x] ^ y) result++, v[x] = y;
		}
	}
	cout << result;
	return 0;
}