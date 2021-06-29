#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility> 
#include <string>
using namespace std;

vector<char> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	int i;
	bool ans;
	while (true) {
		ans = true;
		v.clear();
		getline(cin, s);
		if (s == ".") break;
		for (i = 0; i < s.size(); i++) {
			if ((s[i] == '(') || (s[i] == '[')) v.push_back(s[i]);
			if (s[i] == ')') {
				if (!v.size()) ans = false;
				else {
					if (v.back() != '(') ans = false;
					else v.pop_back();
				}
			}
			if (s[i] == ']') {
				if (!v.size()) ans = false;
				else {
					if (v.back() != '[') ans = false;
					else v.pop_back();
				}
			}
		}
		if (v.size()) ans = false;
		if (ans == true) cout << "yes\n";
		else cout << "no\n";
	}
}

