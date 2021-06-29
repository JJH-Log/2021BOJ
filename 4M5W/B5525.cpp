#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility> 
#include <string>
#include <stack>
#include <map>
#include <set>
//for (const auto& i : v) cout << i << ' ';
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	int i, N, L, t, n, iL, result;
	cin >> N >> L;
	cin >> s;
	t = 0; iL = 0; result = 0;
	for (i = 0; i < L; i++) {
		if (s[i] == 'I') n = 1;
		else n = 0;
		if (n == t) {
			if (iL - N > 0) result += iL - N;
			iL = 0;
		}
		t = n;
		if (t) iL++;
	}
	if (iL - N > 0) result += iL - N;
	cout << result;
	return 0;
}