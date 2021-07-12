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
//for (const auto& i : v) cout << i << ' ';
using namespace std;
using lld = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int pcnt;
	string s;
	cin >> s;
	pcnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'A') {
			if (pcnt >= 2 && i != s.size() - 1 && s[i + 1] == 'P') pcnt -= 2;
			else {
				cout << "NP";
				return 0;
			}
		}
		else pcnt += 1;
	}
	if (pcnt == 1) cout << "PPAP";
	else cout << "NP";
	return 0;
}