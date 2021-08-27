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
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

vector<int> v; //prefix Sum

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, i;
	int result = -1e9;
	int pSum1, pSum2;
	cin >> N >> M;
	v.resize(N, 0);
	cin >> v[0];
	for (i = 1; i < M; i++) {
		cin >> v[i], v[i] += v[i - 1];
	}
	pSum1 = v[M - 1]; pSum2 = 0;
	result = max(result, pSum1 - pSum2); //M = N Case
	for (i = M; i < N; i++) {
		cin >> v[i];
		pSum1 += v[i];
		pSum2 = min(pSum2, v[i - M]);
		result = max(result, pSum1 - pSum2);
		v[i] += v[i - 1];
	}
	cout << max(result, 0); //Zero pick Case
	return 0;
}