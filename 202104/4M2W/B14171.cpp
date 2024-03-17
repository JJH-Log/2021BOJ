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


vector<vector<int>> v;

int cumsum(int N) {
	if (N <= 1) return 0;
	int result = 0;
	for (int i = 0; i < N; i++) {
		result += i;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, x, y;
	string s1, s2;
	v.resize(26 * 26, vector<int>(26 * 26, 0));

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s1 >> s2;
		x = int(s1[0] - 'A') * 26 + int(s1[1] - 'A');
		y = int(s2[0] - 'A') * 26 + int(s2[1] - 'A');
		v[x][y]++;
	}

	int result = 0;
	for (int i = 0; i < v.size(); i++) {
		for (int j = i + 1; j < v.size(); j++) {
			result += v[i][j] * v[j][i];
		}
	}
	for (int i = 0; i < v.size(); i++) result += cumsum(v[i][i]);
	cout << result;

}
