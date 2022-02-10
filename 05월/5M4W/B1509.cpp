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

string S;
vector<int> v;

int check(int i, int j) {
	string A = S.substr(i, j - i + 1);
	string B = A;
	reverse(B.begin(), B.end());
	if (A == B) return 1;
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, N;
	cin >> S;
	N = S.size();

	v.resize(N, 10000);

	v[0] = 1;
	for (i = 1; i < N; i++) {
		if (check(0, i)) v[i] = 1;
		else {
			for (j = 0; j  < i; j++) {
				if (check(j + 1, i)) v[i] = min(v[i], v[j] + 1);
			}
		}
	}
	cout << v[N - 1];
	return 0;
}
