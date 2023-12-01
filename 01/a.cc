#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()

template <typename T>
T nxt() {
  T x;
  cin >> x;
  return x;
}

int main() {
  string line;
  ll sum = 0;
  while (getline(cin, line)) {
    ll first = -1;
    ll last = -1;
    for (char c : line) {
      if (c < '0' || c > '9') continue;
      last = c - '0';
      if (first < 0) first = last;
    }
    sum += first * 10 + last;
  }
  cout << sum << endl;
}
