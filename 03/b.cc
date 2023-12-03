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

struct Solution {
  Solution() : gears({}){};
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
    curr = 0;
    ll sum = 0;
    for (ll row = 0; row < rows; row++) {
      ll len = 0;
      bool near_sym = false;
      ll num = 0;
      for (ll col = 0; col < cols; col++) {
        char c = lines[row][col];
        if (c < '0' || c > '9') {
          if (len > 0) {
            numbers.push_back(num);
            curr += 1;
          }
          num = 0;
          len = 0;
          continue;
        }
        num *= 10;
        num += c - '0';
        len += 1;
        adj_gear(row, col);
      }
      // if (len > 0) cout << num << endl;
      if (len > 0) {
        numbers.push_back(num);
        curr += 1;
      }
    }
    for (auto& gear : gears) {
      // cout << format("({},{}) = ", gear.first.first, gear.first.second);
      auto& nums = gear.second;
      if (nums.size() == 2) {
        ll prod = 1;
        for (auto num : nums) {
          // cout << format("{} ", num);
          prod *= numbers[num];
        }
        sum += prod;
      }
      // cout << endl;
    }
    return sum;
  }

  void adj_gear(ll row, ll col) {
    for (ll i = row - 1; i <= row + 1; i++) {
      for (ll j = col - 1; j <= col + 1; j++) {
        if (inside(i, j) && lines[i][j] == '*') {
          if (gears.count({i, j}) == 0) {
            gears[{i, j}] = {curr};
          } else {
            gears[{i, j}].insert(curr);
          }
          return;
        }
      }
    }
  }

  bool inside(ll row, ll col) {
    if (row < 0) return false;
    if (row >= rows) return false;
    if (col < 0) return false;
    if (col >= cols) return false;
    return true;
  }

  vector<string> lines;
  map<pair<ll, ll>, set<ll>> gears;
  vector<ll> numbers;
  ll rows;
  ll cols;
  ll curr;
};

int main() { cout << Solution().solve() << endl; }
