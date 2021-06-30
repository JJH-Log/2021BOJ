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
	
	int i, FLAG, state;
	string s;
	cin >> s;
	state = 0;
	FLAG = 1;
	for (i = 0; i < s.size(); i++) {
		if (state == 0) {
			if (s[i] == 'p') state = 1;
			else if (s[i] == 'k') state = 2;
			else if (s[i] == 'c') state = 3;
			else FLAG = 0;
		}
		else if (state == 1) {
			if (s[i] == 'i') state = 0;
			else FLAG = 0;
		}
		else if (state == 2) {
			if (s[i] == 'a') state = 0;
			else FLAG = 0;
		}
		else if (state == 3) {
			if (s[i] == 'h') state = 4;
			else FLAG = 0;
		}
		else if (state == 4) {
			if (s[i] == 'u') state = 0;
			else FLAG = 0;
		}
	}
	if (state) FLAG = 0;
	if (FLAG) cout << "YES";
	else cout << "NO";

	return 0;
}