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

bool is_sym(char c) { return (c < '0' || c > '9') && c != '.'; }

struct Solution {
  void read() {
    string line;
    while (getline(cin, line)) {
      lines.push_back(line);
    }
    rows = lines.size();
    cols = lines[0].size();
  }
  ll solve() {
    read();
    sum = 0;
    for (ll row = 0; row < rows; row++) {
      ll len = 0;
      bool near_sym = false;
      ll num = 0;
      for (ll col = 0; col < cols; col++) {
        char c = lines[row][col];
        if (c < '0' || c > '9') {
          // if (len > 0) cout << num << endl;
          if (len > 0 && near_sym) {
            sum += num;
          }
          num = 0;
          len = 0;
          near_sym = false;
          continue;
        }
        num *= 10;
        num += c - '0';
        len += 1;
        if (adj_sym(row, col)) {
          // cout << format("near sym: {} {}\n", row, col);
          near_sym = true;
        }
      }
      // if (len > 0) cout << num << endl;
      if (len > 0 && near_sym) {
        sum += num;
      }
    }
    return sum;
  }
  bool adj_sym(ll row, ll col) {
    for (ll i = row - 1; i <= row + 1; i++) {
      for (ll j = col - 1; j <= col + 1; j++) {
        if (inside(i, j) && is_sym(lines[i][j])) {
          return true;
        }
      }
    }
    return false;
  }

  bool inside(ll row, ll col) {
    if (row < 0) return false;
    if (row >= rows) return false;
    if (col < 0) return false;
    if (col >= cols) return false;
    return true;
  }

  vector<string> lines;
  ll rows;
  ll cols;
  ll sum;
};

int main() { cout << Solution().solve() << endl; }
