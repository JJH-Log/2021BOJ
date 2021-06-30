#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
//for (const auto& i : v) cout << i << ' ';
using namespace std;
using lld = long long;

set<int> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int i, t, N;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> t;
		s.insert(t);
	}
	for (auto it : s) cout << it << ' ';
	return 0;
}