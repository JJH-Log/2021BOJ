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

vector<int> v;
multiset<int> ms;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int i, N, M, temp, FLAG, t;
	multiset<int>::iterator it;
	cin >> N;
	v.resize(N);
	for (i = 0; i < N; i++) cin >> v[i];
	cin >> M;
	for (i = 0; i < M; i++) {
		cin >> temp;
		ms.insert(temp);
	}
	t = 0; FLAG = 0;
	while (true) {
		for (i = 0; i < N; i++) {
			it = ms.upper_bound(v[i]);
			if (it != ms.begin()) FLAG = 1, ms.erase(--it);
		}
		if (!FLAG) break;
		FLAG = 0, t++;
	}
	if (!ms.size()) cout << t;
	else cout << -1;
	return 0;
}