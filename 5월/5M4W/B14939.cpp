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

vector<int> v;
int result, ans;

pair<int, int> seed(int X) {
	int i, u, m;
	u = v[0];
	m = v[1];
	for (i = 0; i < 10; i++) {
		if (X & (1 << i)) {
			ans++;
			if (i == 0) u ^= 3, m ^= 1;
			else if (i == 9) u ^= 768, m ^= 512;
			else {
				u ^= ((1 << (i - 1)) + (1 << i) + (1 << (i + 1)));
				m ^= (1 << i);
			}
		}
	}
	return { u, m };
}

pair<int, int> roll(pair<int, int> w, int cnt) {
	if (cnt == 10) return w;
	pair<int, int> result;
	int i, u, m, d;
	u = w.first; m = w.second; d = v[cnt];
	for (i = 0; i < 10; i++) {
		if (u & (1 << i)) {
			ans++;
			if (i == 0) u ^= 1, m ^= 3, d ^= 1;
			else if (i == 9) u ^= 512, m ^= 768, d ^= 512;
			else {
				u ^= (1 << i);
				m ^= ((1 << (i - 1)) + (1 << i) + (1 << (i + 1)));
				d ^= (1 << i);
			}
		}
	}
	return roll({ m, d }, cnt + 1);
}

int check(pair<int, int> w) {
	int i, m, d;
	m = w.first; d = w.second;
	for (i = 0; i < 10; i++) {
		if (m & (1 << i)) {
			ans++;
			if (i == 0) m ^= 1, d ^= 3;
			else if (i == 9) m ^= 512, d ^= 768;
			else {
				m ^= (1 << i);
				d ^= ((1 << (i - 1)) + (1 << i) + (1 << (i + 1)));
			}
		}
	}
	return ((!m) && (!d));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j;
	pair<int, int> temp;
	string s;
	v.resize(10, 0);
	for (i = 0; i < 10; i++) {
		cin >> s;
		for (j = 0; j < 10; j++) {
			if (s[j] == 'O') v[i] += (1 << j);
		}
	}
	result = 100;
	for (i = 0; i < 1024; i++) {
		ans = 0;
		temp = roll(seed(i), 2);
		if (check(temp)) result = min(result, ans);
	}
	cout << result;
	return 0;
}
