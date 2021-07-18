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
#define INT_MIN -2147483647
#define INT_MAX 2147483647
//for (const auto& i : v) cout << i << ' ';
using namespace std;
using lld = long long;

vector<pair<int, int>> v;
int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, result;
	cin >> N;
	v.resize(N, { 0, 0 });
	for (i = 0; i < N; i++) {
		cin >> v[i].first;
		v[i].second = i;
	}
	
	sort(v.begin(), v.end());
	result = 1;
	for (i = 0; i < N; i++) result = max(result, v[i].second - i + 1);
	cout << result;

	return 0;
}