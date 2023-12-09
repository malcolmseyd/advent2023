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

#ifndef NDEBUG
#define DEBUG(args...) (cout << format(args))
#else
#define DEBUG(...) 0
#endif

struct Solution {
  auto solve() {
    ll ans = 0;
    string line;
    vector<vector<ll>> histories;
    histories.push_back({});
    while (getline(cin, line)) {
      stringstream ss(line);
      ll in_num;
      while (ss >> in_num) {
        histories[0].push_back(in_num);
      }

      ll i = 1;
      while (true) {
        if (i >= histories.size()) {
          histories.push_back({});
        }
        bool all_zero = true;
        for (ll j = 0; j < histories[i - 1].size() - 1; j++) {
          ll diff = histories[i - 1][j + 1] - histories[i - 1][j];
          if (diff != 0) all_zero = false;
          histories[i].push_back(diff);
        }
        if (all_zero) break;
        i++;
      }

      histories[i].push_back(0);
      while (i > 0) {
        auto& v = histories[i - 1];
        ll d = *(histories[i].end() - 1);
        histories[i - 1].push_back(*(histories[i - 1].end() - 1) + d);
        i--;
      }

      // DEBUG("final = {}\n", *(histories[0].end() - 1));
      ans += *(histories[0].end() - 1);

      for (auto& v : histories) {
        // DEBUG("[ ");
        // for (auto& e : v) {
        //   DEBUG("{} ", e);
        // }
        // DEBUG("]\n");
        v.clear();
      }
      // DEBUG("\n");
    }
    return ans;
  }
};

int main() { cout << Solution().solve() << endl; }
