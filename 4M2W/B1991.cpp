#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

map<char, pair<char, char>> m;

queue<pair<char, char>> q;

int preOrder(char root, char left, char right) {
    cout << root;
    if (left != '.') preOrder(left, m[left].first, m[left].second);
    if (right != '.') preOrder(right, m[right].first, m[right].second);
    return 0;
}

int inOrder(char root, char left, char right) {
    if (left != '.') inOrder(left, m[left].first, m[left].second);
    cout << root;
    if (right != '.') inOrder(right, m[right].first, m[right].second);
    return 0;
}

int postOrder(char root, char left, char right) {
    if (left != '.') postOrder(left, m[left].first, m[left].second);
    if (right != '.') postOrder(right, m[right].first, m[right].second);
    cout << root;
    return 0;
}

int main() {
    int i, N;
    char t1, t2, t3;
    cin >> N;

    for (i = 0; i < N; i++) {
        cin >> t1 >> t2 >> t3;
        m[t1] = make_pair(t2, t3);
    }
    
    preOrder('A', m['A'].first, m['A'].second);
    cout << endl;
    inOrder('A', m['A'].first, m['A'].second);
    cout << endl;
    postOrder('A', m['A'].first, m['A'].second);
    cout << endl;
    return 0;
}

