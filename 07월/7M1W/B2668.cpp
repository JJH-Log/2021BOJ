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

vector<int> v;
vector<int> w; //for check
int result;

int trace(int X) {
	int next, FLAG;
	next = v[X];
	if (w[next] == 3 || w[next] == 4) {
		w[X] = 3;
		return 0;
	}
	if (w[X] == 2) return 1;
	w[next]++;
	FLAG = trace(next);
	if (FLAG && w[X] != 2) result++, w[X] = 4;
	else if (FLAG) result++, w[X] = 4, FLAG = 0;
	else w[X] = 3;
	return FLAG;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, N;
	cin >> N;
	v.resize(N, 0);
	w.resize(N, 0);
	for (i = 0; i < N; i++) cin >> v[i], v[i]--;
	for (i = 0; i < N; i++) {
		if (!w[i]) w[i] = 1, trace(i);
	}
	cout << result << '\n';
	for (i = 0; i < N; i++) {
		if (w[i] == 4) cout << i + 1 << '\n';
	}
	return 0;
}