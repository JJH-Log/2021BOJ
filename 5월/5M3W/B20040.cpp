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

int find(int target) {
	if (v[target] == target) return target;
	else return find(v[target]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, N, M, x, y, result, FLAG;
	cin >> N >> M;
	v.resize(N, 0);
	result = 0;
	FLAG = 1;
	for (i = 0; i < N; i++) v[i] = i;
	for (i = 0; i < M; i++) {
		cin >> x >> y;
		x = find(x);
		y = find(y);
		if (x == y && FLAG) {
			result = i + 1;
			FLAG = 0;
		}
		if (x < y) v[y] = x;
		else v[x] = y;
	}
	cout << result;
	return 0;
}