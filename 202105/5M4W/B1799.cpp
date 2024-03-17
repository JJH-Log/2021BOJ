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

int N;

string mask(string s, int X) {
	string result;
	int x = X / N;
	int y = X % N;
	int d = 0;
	result = s;

	while (x + d < N) {
		if (y - d >= 0) result[(x + d) * N + (y - d)] = '0';
		if (y + d < N) result[(x + d) * N + (y + d)] = '0';
		d++;
	}
	return result;
}

int bishop(string s, int idx, int cnt) {
	int i, result;
	//cout << "idx : " << idx << " " << cnt << endl;

	result = cnt;
	for (i = idx; i < N * N; i++) {
		if (s[i] == '1') {
			//cout << temp << endl;
			result = max(result, bishop(mask(s, i), i + 1, cnt + 1));
		}
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, ra, rb;
	char c;
	string s;
	string a, b;
	cin >> N;
	a = ""; b = ""; s = "";
	for (i = 0; i < N * N; i++) {
		cin >> c;
		s += c;
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if ((i + j) % 2) {
				a += '0';
				b += s[i * N + j];
			}
			else {
				a += s[i * N + j];
				b += '0';
			}
		}
	}

	ra = bishop(a, 0, 0);
	rb = bishop(b, 1, 0);
	cout << ra + rb;
	return 0;
}
