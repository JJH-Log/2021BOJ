#include <iostream>
#include <vector>
#include <string> //substr
#include <map>
#include <queue>
#include <stack>
#include <utility>  //pair
#include <algorithm> //sort, reverse
#include <math.h> // sqrt
#include <set>
#include <cassert>
#define MOD 1000000007
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

vector<vector<int>> v;
int R, C, pipe;


bool connection(int x, int y) {
    v[x][y] = pipe;
    if (y == C - 1) return true;
    for (int i = -1; i < 2; i++) {
        int dx = x + i;
        int dy = y + 1;
        if (dx >= 0 && dx < R && v[dx][dy] == 0 && connection(dx, dy)) return true;
    }
    return false;
}

void print() {
    cout << endl;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (v[i][j] == 0) cout << '.';
            else if (v[i][j] == -1) cout << 'x';
            else cout << v[i][j];
        }
        cout << endl;
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int i, j;
    string s;
    cin >> R >> C;
    v.resize(R, vector<int>(C, 0));
    for (i = 0; i < R; i++) {
        cin >> s;
        for (j = 0; j < C; j++) if(s[j] == 'x') v[i][j] = -1;
    }
    pipe = 1;
    for (i = 0; i < R; i++) {
        //print();
        if (v[i][0] == 0 && connection(i, 0)) pipe++;
    }
    cout << pipe - 1;

    return 0;
}