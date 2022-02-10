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

vector<vector<lld>> convMatrix(vector<vector<lld>> X, vector<vector<lld>> Y) { //predict as same size
    lld vSize = X.size();
    vector<vector<lld>> R;
    R.resize(vSize, vector<lld>(vSize, 0));
    int i, j, k;
    for (i = 0; i < vSize; i++) {
        for (j = 0; j < vSize; j++) {
            for (k = 0; k < vSize; k++) R[i][j] = ((lld)R[i][j] + ((lld)X[i][k] * Y[k][j])) % MOD;
        }
    }
    return R;
}

vector<vector<lld>> subMatrix(vector<vector<lld>> X, vector<vector<lld>> Y) { //predict as same size
    lld vSize = X.size();
    vector<vector<lld>> R;
    R.resize(vSize, vector<lld>(vSize, 0));
    int i, j;
    for (i = 0; i < vSize; i++) {
        for (j = 0; j < vSize; j++) {
            R[i][j] = ((lld)X[i][j] - Y[i][j] + MOD) % MOD;
        }
    }
    return R;
}

lld powNum(lld X, lld N) {
    lld R = 1;
    while (N) {
        if (N % 2) R = ((lld)R * X) % MOD;
        X = ((lld)X * X) % MOD;
        N /= 2;
    }
    return R;
}

vector<vector<lld>> powMatrix(vector<vector<lld>> X, lld N) {
    lld vSize = X.size();
    int i, j;
    vector<vector<lld>> R;
    R.resize(vSize, vector<lld>(vSize, 0));
    for (i = 0; i < vSize; i++) R[i][i] = 1;
    while (N) {
        if (N % 2) R = convMatrix(R, X);
        X = convMatrix(X, X);
        N /= 2;
    }
    return R;
}

vector<vector<lld>> v;
vector<vector<lld>> e;
vector<vector<lld>> ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    lld a1, a2;
    lld N;
    cin >> N;
    /*
    짝수번째 피보나치 수열의 합 : An = (E + X2 + X4..Xn-2)A1 (mod by p)
    (E - X2)An = (E + X2 + X4..Xn-2)(E - X2)A1 (mod by p)
    (E - X2)An = (E - Xn)A1 
    가장 위의 원소만 확인하면 된다는 점을 활용한다.
   
    */
    if (N % 2) N--;
    v = { {1, 1}, {1, 0} };
    e = { {1, 0}, {0, 1} };
    ans = subMatrix(e, powMatrix(v, N));
    a1 = ans[0][0];
    ans = subMatrix(e, powMatrix(v, 2));
    a2 = ans[0][0];
    cout << ((lld)a1 * powNum(a2, MOD - 2)) % MOD;
    
    return 0;
}