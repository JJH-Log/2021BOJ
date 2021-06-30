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
#define MOD 1000000007
using namespace std;

vector<vector<int>> v;
vector<vector<int>> R;

vector<vector<int>> conv(vector<vector<int>> A, vector<vector<int>> B) { //size = 8;
	int i, j, k;
	vector<vector<int>> result;
	result.resize(8, vector<int>(8, 0));
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			for (k = 0; k < 8; k++) {
				result[i][j] = ((long long)result[i][j] + ((long long)A[i][k] * B[k][j])) % MOD;
			}
		}
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	v.push_back({ 0,1,1,0,0,0,0,0 });
	v.push_back({ 1,0,1,1,0,0,0,0 });
	v.push_back({ 1,1,0,1,1,0,0,0 });
	v.push_back({ 0,1,1,0,1,1,0,0 });
	v.push_back({ 0,0,1,1,0,1,0,1 });
	v.push_back({ 0,0,0,1,1,0,1,0 });
	v.push_back({ 0,0,0,0,0,1,0,1 });
	v.push_back({ 0,0,0,0,1,0,1,0 });
	cin >> N;
	while (N) {
		if (N % 2) {
			if (!R.size()) R = v;
			else R = conv(R, v);
		}
		v = conv(v, v);
		N /= 2;
	}
	cout << R[0][0];
	return 0;
}