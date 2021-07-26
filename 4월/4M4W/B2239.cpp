#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility> 
#include <string>
#include <stack>
#include <map>
using namespace std;

vector<vector<int>> v;  //sudoku vector
vector<vector<int>> c; //for checking / 0 - col / 00 - row / 000 - group
int FLAG;
void ans(int target) {
	int x, y, i, j;
	x = target / 9;
	y = target % 9;
	if (target == 81) {
		for (i = 0; i < 9; i++) {
			for (j = 0; j < 9; j++) cout << v[i][j];
			if(i != 8) cout << endl;
		}
		FLAG = 0;
	}
	else if (v[x][y] == 0) {
		for (i = 0; i < 9; i++) {
			if (!(c[x][i] & 1) && !(c[y][i] & 2) && !(c[y / 3 + x / 3 * 3][i] & 4) && FLAG) {
				//if(target < 10) cout << x << ' ' << y << ' ' << y / 3 + x / 3 * 3 << ' ' << i + 1<< ' ' << c[x][i] << ' ' << c[y][i] << ' ' << (c[y % 3 + x / 3 * 3][i] & 4) << endl;
				c[x][i] += 1;
				c[y][i] += 2;
				c[y / 3 + x / 3 * 3][i] += 4;
				v[x][y] = i + 1;
				ans(target + 1);
				c[x][i] -= 1;
				c[y][i] -= 2;
				c[y / 3 + x / 3 * 3][i] -= 4;
				v[x][y] = 0;
			}
		}
	}
	else ans(target + 1);

}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	v.resize(9, vector<int>(9, 0));
	c.resize(9, vector<int>(9, 0));
	int i, j;
	for (i = 0; i < 9; i++) {
		cin >> s;
		for (j = 0; j < 9; j++) {
			v[i][j] = s[j] - '0';
			if (v[i][j] != 0) {
				c[i][v[i][j] - 1] += 1; //col
				c[j][v[i][j] - 1] += 2; //row
				c[j / 3 + i / 3 * 3][v[i][j] - 1] += 4;
			}
		}
	}
	FLAG = 1;
	ans(0);
	return 0;
}

