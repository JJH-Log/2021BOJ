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
#define MOD 1000000007
//for (const auto& i : v) cout << i << ' ';
using namespace std;
using lld = long long;

vector<lld> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	lld S;
	cin >> S;
	S *= 2;
	for (lld i = 1; i <= 100000; i++) v.push_back(i * (i + 1));
	if (S == 2) cout << 1;
	else cout << upper_bound(v.begin(), v.end(), S) - v.begin();
	return 0;
}