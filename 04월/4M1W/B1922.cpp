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

typedef struct NW {
    int a;
    int b;
    int d;
    NW(int x, int y, int z) :
        a(x), b(y), d(z) {}
    NW() :
        a(0), b(0), d(0) {}
}net;

bool compare(net x, net y) {
    if (x.d == y.d) {
        if (x.a == y.a) {
            return x.b < y.b;
        }
        else return x.a < y.a;
    }
    return x.d < y.d;
}


vector<net> v;
vector<int> c;

int changeConnection(int x, int y) {
    int temp = 0;
    for (int i = 0; i < c.size(); i++) {
        if (c[i] == x) {
            c[i] = y;
            if (y == 1) temp++;
        }
    }
    return temp;
}

int main() {
    int i, N, M;
    int result, temp;
    int connection;
    cin >> N;
    cin >> M;
    v.resize(M, net(0,0,0));
    c.resize(N + 1, 1001);

    for (i = 0; i < M; i++) scanf("%d %d %d", &v[i].a, &v[i].b, &v[i].d);
    sort(v.begin(), v.end(), compare);

    connection = 0;
    result = 0;
    i = 0;

    while ((connection != N) && (i < M)) {
        if (v[i].a != v[i].b) {
            if ((c[v[i].a] == 1001) && (c[v[i].b] == 1001)) {
                temp = min(v[i].a, v[i].b);
                c[v[i].a] = c[v[i].b] = temp;
                if (temp == 1) connection += 2;
            }
            else {
                if (c[v[i].a] == 1001) {
                    c[v[i].a] = c[v[i].b];
                    if(v[i].a < c[v[i].b]) connection += changeConnection(c[v[i].b], v[i].a);
                    else if (c[v[i].b] == 1) connection++;
                }
                else if (c[v[i].b] == 1001) {
                    c[v[i].b] = c[v[i].a];
                    if (v[i].b < c[v[i].a]) connection += changeConnection(c[v[i].a], v[i].b);
                    else if (c[v[i].a] == 1) connection++;
                }
                else {
                    if (c[v[i].a] > c[v[i].b]) connection += changeConnection(c[v[i].a], c[v[i].b]);
                    else if (c[v[i].a] < c[v[i].b]) connection += changeConnection(c[v[i].b], c[v[i].a]);
                    else result -= v[i].d;
                }
            }
            result += v[i].d;
        }
        i++;
    }
    cout << result;
}

