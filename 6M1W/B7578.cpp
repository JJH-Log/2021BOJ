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
#define MOD 10007
//for (const auto& i : v) cout << i << ' ';
using namespace std;
using lld = long long;

vector<int> v;
lld result;
int ar[1000001];
lld merge(int a, int b) {
	if (a == b) return 0;
	int i, l, r, mid;
	lld result;
	vector<int> temp;
	l = a; mid = (a + b + 1) / 2; r = mid;
	result = 0;
	result += merge(a, mid - 1);
	result += merge(mid, b);
	
	while (true) {
		if (l == mid || r == b + 1) break;
		if (v[l] < v[r]) temp.push_back(v[l]), l++;
		else temp.push_back(v[r]), r++, result += ((lld)mid - l);
	}
	while (true) {
		if (l == mid && r == b + 1) break;
		if (l == mid) temp.push_back(v[r]), r++;
		else temp.push_back(v[l]), l++;
	}
	for (i = a; i <= b; i++) v[i] = temp[i - a];
	return result;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, x, N;
	lld result;
	cin >> N;
	v.resize(N, 0);
	for (i = 0; i < N; i++) cin >> x, ar[x] = i;
	for (i = 0; i < N; i++) cin >> x, v[i] = ar[x];
	cout << merge(0, N - 1) << '\n';
	return 0;
}