#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
#include <stack>
//for (const auto& i : v) cout << i << ' ';
using namespace std;

vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	v.resize(10, 0);
	int i, j, T;
	cin >> s;
	for (i = 0; i < s.size(); i++) v[s[i] - '0']++;
	T = 0;
	for (i = 1; i < 10; i++) T += i * v[i];

	if (v[0] && !(T % 3)) {
		for (i = 9; i >= 0; i--) {
			for (j = 0; j < v[i]; j++) cout << i;
		}
	}
	else cout << -1;
	
	return 0;
}