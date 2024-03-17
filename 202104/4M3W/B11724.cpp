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

vector<int> v;
vector<bool> ans;
int vfind(int target) {
	if (v[target] == target) return target;
	else return vfind(v[target]);
}

void vunion(int x, int y) {
	if (x > y) v[x] = y;
	else v[y] = x;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, N, M, x, y;
	cin >> N >> M;
	v.resize(N + 1, 0);
	ans.resize(N + 1, false);

	for (i = 0; i < M; i++) {
		cin >> x >> y;
		if (v[x] == 0) v[x] = x;
		if (v[y] == 0) v[y] = y;
		x = vfind(x);
		y = vfind(y);
		vunion(x, y);
	}

	int result = 0;
	for (i = 1; i <= N; i++) {
		if (v[i] == 0) result++;
		else {
			x = vfind(i);
			if (!ans[x]) {
				ans[x] = true;
				result++;
			}
		}
	}
	cout << result;
	return 0;
}
