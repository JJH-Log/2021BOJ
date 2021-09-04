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

struct status {
    int A, D, H;
    void absorb(status opp) {
        A += opp.A;
        D += opp.D;
        H += opp.H;
    }
    void absorb_multiple(status opp, int k) {
        A = (A + ((lld)opp.A * k % MOD)) % MOD;
        D = (D + ((lld)opp.D * k % MOD)) % MOD;
        H = (H + ((lld)opp.H * k % MOD)) % MOD;
    }
    void modulo() {
        A = A % MOD;
        D = D % MOD;
        H = H % MOD;
    }
};

int encode(status X) { return (X.H - 1) * 300 + (X.D - 1) * 100 + X.A - 1; }

int nextVal(int now, int pp, int aa, int modulo) {
    int result = 1;
    while (pp) {
        if (pp % 2) result = (result * now) % modulo;
        pp /= 2;
        now = (now * now) % modulo;
    }
    return (result + aa) % modulo + 1;
}

vector<int> getMobHash(int mapSize, int X, int Xp, int Xa) {
    vector<int> result;
    result.resize(mapSize, 0);
    int now, cnt, ans;
    now = X, cnt = 1;
    while (!result[now - 1]) {
        ans = nextVal(now, Xp, Xa, mapSize);
        result[now - 1] = ans;
        now = ans;
    }
    return result;
}

bool isAbleDefeat(status A, status B) {
    while (A.H > 0 && B.H > 0) {
        B.H -= max(A.A - B.D, 1);
        A.H -= max(B.A - A.D, 1);
    }
    if (B.H > 0) return false;
    return true;
}

vector<int> M;
vector<int> Ma, Md, Mh;
int N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int Ap, Aa, Dp, Da, Hp, Ha;
    int now, cnt, ans, i;
    status X, Y;
    cin >> N >> X.A >> X.D >> X.H >> Y.A >> Y.D >> Y.H;
    cin >> Ap >> Aa >> Dp >> Da >> Hp >> Ha;
    M.resize(300000, 0);
    Ma = getMobHash(100, Y.A, Ap, Aa);
    Md = getMobHash(3, Y.D, Dp, Da);
    Mh = getMobHash(1000, Y.H, Hp, Ha);

    for (i = 1; i <= N; i++) {
        M[encode(Y)] = i;
        if (!isAbleDefeat(X, Y)) {
            cout << -1;
            return 0;
        }
        X.absorb(Y);
        Y = {Ma[Y.A - 1], Md[Y.D - 1], Mh[Y.H - 1]};
        if (M[encode(Y)]) break;
    }
    X.modulo();
    if (i != N + 1) {
        int cycle = i - M[encode(Y)] + 1;
        int left = N - i;
        int p, q;
        p = left / cycle;
        q = left % cycle;
        for (i = 1; i <= cycle; i++) {
            if (i <= q) X.absorb_multiple(Y, p + 1);
            else X.absorb_multiple(Y, p);
            Y = { Ma[Y.A - 1], Md[Y.D - 1], Mh[Y.H - 1] };
        }
    }
    cout << X.A << ' ' << X.D << ' ' << X.H;
    return 0;
}