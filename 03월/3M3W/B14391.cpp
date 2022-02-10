
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector <int>> v;

int make_number(int x1, int y1, int x2, int y2) {
	int i;
	int temp = 0;
	if ((x1 == x2) && (y1 == y2)) return v[x1][y1];
	if (x1 == x2) {
		for (i = y1; i <= y2; i++) {
			temp = temp * 10 + v[x1][i];
		}
	}
	if (y1 == y2) {
		for (i = x1; i <= x2; i++) {
			temp = temp * 10 + v[i][y1];
		}
	}
	return temp;
}
int get_max(int x1, int y1, int x2, int y2) {
	int result = -1;
	int x_res = -1;
	int y_res = -1;
	if ((x1 == x2) && (y1 == y2)) return v[x1][y1];
	if ((x1 == x2) || (y1 == y2)) result = make_number(x1, y1, x2, y2);
	if (x1 != x2) x_res = max(make_number(x1, y1, x1, y2) + get_max(x1 + 1, y1, x2, y2), make_number(x2, y1, x2, y2) + get_max(x1, y1, x2 - 1, y2));
	if (y1 != y2) y_res = max(make_number(x1, y1, x2, y1) + get_max(x1, y1 + 1, x2, y2), make_number(x1, y2, x2, y2) + get_max(x1, y1, x2, y2 - 1));
	result = max(result, x_res);
	result = max(result, y_res);
	return result;
}

int main() {
	int i, j, N, M;
	string temp;

	cin >> N >> M;

	v.resize(N, vector<int>(M, 0));

	for (i = 0; i < N; i++) {
		cin >> temp;
		for (j = 0; j < M; j++) {
			v[i][j] = temp[j] - '0';
		}
	}
	cout << get_max(0, 0, N-1, M-1);

	return 0;
}

//make_number에서도 길이 1x1 예외 처리를 해줘야함 (안그러면 중복 연산)
//토지 경작 문제와 비슷한 재귀함수