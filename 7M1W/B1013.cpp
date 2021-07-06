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
#include <regex>
#define MOD 1000000000
//for (const auto& i : v) cout << i << ' ';
using namespace std;
using lld = long long;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	regex re("(100+1+|01)+");
	int t, T;
	string s;
	cin >> T;
	for (t = 0; t < T; t++) {
		cin >> s;
		if (regex_match(s, re)) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}