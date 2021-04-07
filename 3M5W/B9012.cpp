#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
using namespace std;


int main() {
	int c, i, T, count;
	string s;
	cin >> T;
	bool flag;
	for (c = 0; c < T; c++) {
		cin >> s;
		count = 0;
		flag = true;
		for (i = 0; i < s.length(); i++) {
			if (s[i] == '(') count++;
			if (s[i] == ')') count--;
			if (count < 0) flag = false;
		}
		if (count != 0) flag = false;
		if (flag) printf("YES\n");
		else printf("NO\n");
	}
}