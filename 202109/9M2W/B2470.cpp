#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string> //substr
#include <map>
#include <queue>
#include <stack>
#include <utility>  //pair
#include <algorithm> //sort, reverse
#include <math.h> // sqrt
#include <set>
#include <cassert>
#define MOD 1000000007
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

vector<int> v;
int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int ir, jr;
	int i, j;
	cin >> N;
	v.resize(N, 0);
	for (i = 0; i < N; i++) cin >> v[i];
	sort(v.begin(), v.end());
	i = 0, ir = 0, jr = N - 1, j = N - 1;
	while (i != j) {
		if (abs(v[i] + v[j]) < abs(v[ir] + v[jr])) ir = i, jr = j;
		if (v[i] + v[j] < 0) i++;
		else j--;
	}
	cout << v[ir] << ' ' << v[jr];
	return 0;
}