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
#define MOD 1000000007
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

vector<lld> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	v.push_back(5);
	v.push_back(13);
	int M, idx, N = 1;
	string key = "Messi Gimossi";
	while (v[N] <= MAXINT) {
		v.push_back(v[N] + v[N - 1] + 1);
		N++;
	}
	cin >> M;
	while (M > 13) {
		idx = lower_bound(v.begin(), v.end(), M) - v.begin();
		if (v[idx - 1] + 1 == M) {
			cout << "Messi Messi Gimossi";
			return 0;
		}
		M -= v[idx - 1] + 1;
	}
	if (M == 6) cout << "Messi Messi Gimossi";
	else cout << key[M - 1];
	
	return 0;
}