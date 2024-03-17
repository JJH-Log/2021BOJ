#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <set>
#include <cassert>
#include <bitset>
#include <sstream>
#include <cmath>
#define MOD 10007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;

int state[262144];
struct pos { int x, y; };
struct board { pos k, r1, r2; };
pos dRook[4] = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
pos dKing[8] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };

bool isSame(pos a, pos b) { return ((a.x == b.x) && (a.y == b.y)); }
int getNumStr(string s) { return (s[1] - '1') * 8 + s[0] - 'a'; }
int getNumPos(pos a) { return a.x * 8 + a.y; };
bool inRange(pos a) { return a.x >= 0 && a.x < 8 && a.y >= 0 && a.y < 8; }

bool isRookEnable(pos k, pos r1, pos r2) {
	if (r1.x == r2.x || r1.y == r2.y) return true;
	for (int i = 0; i < 8; i++) {
		pos nk = { k.x + dKing[i].x, k.y + dKing[i].y };
		if(inRange(nk) && (isSame(nk, r1) || isSame(nk, r2))) return false;
	}
	return true;
}

bool isCheckMate(pos k, pos r1, pos r2) {
	if (k.x == r1.x || k.x == r2.x || k.y == r1.y || k.y == r2.y) return true;
	return false;
}

bool isKingEnable(pos k, pos r1, pos r2) {
	if (k.x == r1.x || k.x == r2.x || k.y == r1.y || k.y == r2.y) return false;
	return true;
}

int encodeStr(string k, string r1, string r2) {
	return ((getNumStr(k) << 12) | (getNumStr(r1) << 6) | getNumStr(r2));
}

int encodePos(pos k, pos r1, pos r2) {
	return ((getNumPos(k) << 12) | (getNumPos(r1) << 6) | getNumPos(r2));
}

pos getPos(int N) {
	return { N / 8, N % 8 };
}

string getStr(pos X) {
	string ans = "";
	ans += (char)(X.y + 'a');
	ans += (char)(X.x + '1');
	return  ans;
}

board decode(int code) {
	board res;
	res.r2 = getPos(code % 64);
	res.r1 = getPos((code >> 6) % 64);
	res.k = getPos((code >> 12) % 64);
	return res;
}

queue<int> q1, q2;

void findImpossibleState() {
	for (int i = 0; i < 64; i++) {
		for (int j = 0; j < 64; j++) {
			for (int k = 0; k < 64; k++) {
				board now = { getPos(i), getPos(j), getPos(k) };
				if(now.k.x == now.r1.x || now.k.y == now.r1.y || now.k.x == now.r2.x || now.k.y == now.r2.y || (now.r1.x == now.r2.x && now.r1.y == now.r2.y)) state[encodePos(now.k, now.r1, now.r2)] = -1;
			}
		}
	}
}

void findCheckmateState() {
	board now;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			for (int k = 0; k < 8; k++) {
				if (abs(i - j) >= 2 && (j != k) && abs(i - k) >= 2) {
					for (int p = 1; p <= 7; p++) {
						state[encodePos({ 0, i }, { 1, j }, { p, k })] = 1;
						state[encodePos({ 0, i }, { p, k }, { 1, j })] = 1;
						state[encodePos({ i, 0 }, { j, 1 }, { k, p })] = 1;
						state[encodePos({ i, 0 }, { k, p }, { j, 1 })] = 1;
					}
					for (int p = 6; p >= 0; p--) {
						state[encodePos({ 7, i }, { 6, j }, { p, k })] = 1;
						state[encodePos({ 7, i }, { p, k }, { 6, j })] = 1;
						state[encodePos({ i, 7 }, { k, p }, { j, 6 })] = 1;
						state[encodePos({ i, 7 }, { j, 6 }, { k, p })] = 1;
					}
				}
			}
		}
	}
}

void fillQueue() {
	for (int i = 0; i < 262144; i++) {
		if (!state[i]) {
			state[i] = 1e9;
			q1.push(i);
		}
	}
}

void searchState(int turn) {
	//cout << "TURN = " << turn << ", " << q1.size() << '\n';
	//board now = decode(q1.front());
	//cout << getStr(now.k) << ' ' << getStr(now.r1) << ' ' << getStr(now.r2) << endl;
	//if (turn == 6) return;
	int tar = 143084, tt = 3;
	if (q1.empty()) return;
	while (!q1.empty()) {
		board now = decode(q1.front());
		//if(q1.front() == tar && turn == tt) cout << getStr(now.k) << ' ' << getStr(now.r1) << ' ' << getStr(now.r2) << endl;
		bool FLAG = true;
		for (int ri = 0; ri < 4; ri++) {
			for (int j = 1; j <= 7; j++) {
				pos nr1 = { now.r1.x + dRook[ri].x * j, now.r1.y + dRook[ri].y * j };
				if (isSame(nr1, now.r2)) break;
				if (inRange(nr1) && isRookEnable(now.k, nr1, now.r2)) {
					//if (q1.front() == tar && turn == tt) cout << getStr(now.k) << ' ' << getStr(nr1) << ' ' << getStr(now.r2) << endl;
					int worstCase = -1;
					for (int ki = 0; ki < 8; ki++) {
						pos nk = { now.k.x + dKing[ki].x, now.k.y + dKing[ki].y };
						if (inRange(nk) && isKingEnable(nk, nr1, now.r2)) {
							worstCase = max(worstCase, state[encodePos(nk, nr1, now.r2)]);
							//if (q1.front() == tar && turn == tt) cout << "KING's pos : " << state[encodePos(nk, nr1, now.r2)] << ' ' << getStr(nk) << ' ' << getStr(nr1) << ' ' << getStr(now.r2) << endl;
						}
					}
					if (worstCase == turn) {
						state[encodePos(now.k, now.r1, now.r2)] = turn + 1;
						FLAG = false;
					}
				}
			}
		}
		for (int ri = 0; ri < 4; ri++) {
			for (int j = 1; j <= 7; j++) {
				pos nr2 = { now.r2.x + dRook[ri].x * j, now.r2.y + dRook[ri].y * j };
				if (isSame(now.r1, nr2)) break;
				if (inRange(nr2) && isRookEnable(now.k, now.r1, nr2)) {
					int worstCase = -1;
					for (int ki = 0; ki < 8; ki++) {
						pos nk = { now.k.x + dKing[ki].x, now.k.y + dKing[ki].y };
						if (inRange(nk) && isKingEnable(nk, now.r1, nr2)) {
							worstCase = max(worstCase, state[encodePos(nk, now.r1, nr2)]);
						}
					}
					if (worstCase == turn) {
						state[encodePos(now.k, now.r1, now.r2)] = turn + 1;
						FLAG = false;
					}
				}
			}
		}
		if (FLAG) q2.push(q1.front());
		q1.pop();
	}
	swap(q1, q2);
	searchState(turn + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	findImpossibleState();
	findCheckmateState();
	fillQueue();
	searchState(1);
	
	int T;
	string p1, p2, p3;
	cin >> T;
	while (T--) {
		cin >> p1 >> p2 >> p3;
		int now = encodeStr(p1, p2, p3);
		cout << state[now] << '\n';
	}

	return 0;
}
