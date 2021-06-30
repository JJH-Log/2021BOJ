#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
using namespace std;

set<int> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	set<int>::iterator it;

	int i, G, P, X, cur, FLAG, cnt;
	cin >> G >> P;
	FLAG = 1;
	cnt = 0;
	for (i = 0; i <= G; i++) s.insert(i);
	for (i = 0; i < P; i++) {
		cin >> X;
		if (FLAG) {
			it = s.upper_bound(X);
			cur = (*--it);
			if (!cur) FLAG = 0;
			else cnt++, s.erase(cur);
		}
	}
	cout << cnt;
	return 0;
}
