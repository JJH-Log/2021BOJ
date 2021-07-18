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
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXLEN 10000000
//for (const auto& i : v) cout << i << ' ';
using namespace std;
using lld = long long;

vector<int> v;
vector<int> w;
int N, K;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	lld result;
	string s;
	cin >> N >> K;
	v.resize(N, 0);
	w.resize(20, 0);
	int len;
	for (int i = 0; i < K; i++) {
		cin >> s;
		len = s.size() - 1;
		v[i] = len;
		w[len]++;
	}
	result = 0;
	for (int i = 0; i < N; i++) {
		if (i + K < N) {
			cin >> s;
			len = s.size() - 1;
			v[i + K] = len;
			w[len]++;
		}
		if (i - K > 0) w[v[i - K - 1]]--;
		result = result + w[v[i]] - 1;
	}
	cout << result / 2;
	return 0;
}