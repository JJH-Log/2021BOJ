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

vector<vector<int>> v;
int N;

int calculate(int x, int oper, int y) {
	if (oper == '+' - '0') return x + y;
	if (oper == '-' - '0') return x - y;
	if (oper == '*' - '0') return x * y;
}

void printState() {
	for (int j = 0; j < 2; j++) {
		for (int i = 0; i < (N + 1) / 2; i++) {
			cout << v[j][i] << ' ';
		}
		cout << endl;
	}
	return;
}

int backTracking(int idx) {
	int result = -2e9;
	for (int i = idx; i < (N / 2); i++) {
		vector<int> temp = { v[0][i], v[1][i], v[0][i + 1] };
		v[0][i] = calculate(v[0][i], v[1][i], v[0][i + 1]);
		v[1][i] = '*' - '0';
		v[0][i + 1] = 1;
		result = max(result, backTracking(i + 2));
		v[0][i] = temp[0];
		v[1][i] = temp[1];
		v[0][i + 1] = temp[2];
	}
	int ans = v[0][0];
	//printState();
	for (int i = 0; i < (N / 2); i++) ans = calculate(ans, v[1][i], v[0][i + 1]);
	//cout << "ans : " << ans << endl;
	return max(result, ans);
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	int i;
	string s;
	v.resize(2, vector<int>((N + 1) / 2, 0));
	cin >> s;
	for (i = 0; i < N; i++) v[i % 2][i / 2] = s[i] - '0';
	cout << backTracking(0);

	return 0;
}