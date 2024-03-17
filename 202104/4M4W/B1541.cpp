#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility> 
#include <string>
#include <stack>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s, temp;
	int i, a, b, FLAG;
	a = 0;
	b = 0;
	FLAG = 0;
	cin >> s;
	for (i = 0; i < s.size(); i++) {
		if (s[i] == '-') {
			if (FLAG) b += stoi(temp);
			else a += stoi(temp);
			temp.clear();
			FLAG = 1;
		}
		else if (s[i] == '+') {
			if (FLAG) b += stoi(temp);
			else a += stoi(temp);
			temp.clear();
		}
		else {
			if (!temp.size()) temp = s[i];
			else temp += s[i];
		}
	}
	if (FLAG) b += stoi(temp);
	else a += stoi(temp);
	//cout << a << endl << b << endl;
	cout << a - b;

	return 0;
}

