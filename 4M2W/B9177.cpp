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

string s1;
string s2;
string s3;
int l1, l2, l3;

bool isMixed(int p1, int p2, int p3) {
	bool temp = false;
	if (p1 != l1) {
		if (s1[p1] == s3[p3]) temp = temp | isMixed(p1 + 1, p2, p3 + 1);
	}
	if ((!temp) && (p2 != l2)) {
		if (s2[p2] == s3[p3]) temp = temp | isMixed(p1, p2 + 1, p3 + 1);
	}
	if (p1 + p2 == l3) temp = true;
	return temp;
}


bool tokenCheck() {
	int i;
	vector<int> a, b;
	a.resize(52, 0);
	b.resize(52, 0);
	for (i = 0; i < l1; i++) {
		if ((s1[i] >= 'a') && (s1[i] <= 'z')) a[int(s1[i] - 'a')]++;
		if ((s1[i] >= 'A') && (s1[i] <= 'Z')) a[int(s1[i] - 'A' + 26)]++;
	}
	for (i = 0; i < l2; i++) {
		if ((s2[i] >= 'a') && (s2[i] <= 'z')) a[int(s2[i] - 'a')]++;
		if ((s2[i] >= 'A') && (s2[i] <= 'Z')) a[int(s2[i] - 'A' + 26)]++;
	}
	for (i = 0; i < l3; i++) {
		if ((s3[i] >= 'a') && (s3[i] <= 'z')) b[int(s3[i] - 'a')]++;
		if ((s3[i] >= 'A') && (s3[i] <= 'Z')) b[int(s3[i] - 'A' + 26)]++;
	}
	for (i = 0; i < 52; i++) {
		if (a[i] != b[i]) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, T;
	cin >> T;
	for (i = 0; i < T; i++) {
		cin >> s1 >> s2 >> s3;
		l1 = s1.size();
		l2 = s2.size();
		l3 = s3.size();

		if (tokenCheck()) {
			if (isMixed(0, 0, 0)) cout << "Data set " << i + 1 << ": yes\n";
			else cout << "Data set " << i + 1 << ": no\n";
		}
		else cout << "Data set " << i + 1 << ": no\n";
	}
}

