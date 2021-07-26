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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string s;
	int i, step;

	getline(cin, s);
	step = 0;
	for (i = 0; i < s.size(); i++) {
		if (step == 0) { if (s[i] == 'U') step++; }
		else if (step == 1) { if (s[i] == 'C') step++; }
		else if (step == 2) { if (s[i] == 'P') step++; }
		else if (step == 3) { if (s[i] == 'C') step++; }
	}
	if (step == 4) cout << "I love UCPC";
	else cout << "I hate UCPC";
	return 0;
}