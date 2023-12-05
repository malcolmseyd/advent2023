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
  void init() {
    string line;
    getline(cin, line);
    line.erase(0, line.find(':') + 1);
    stringstream ss(line);
    ll num;
    while (ss >> num) {
      state_.push_back(num);
    }
    // discard first two useless lines
    getline(cin, line);
    getline(cin, line);
  }
  auto solve() {
    init();

    // for (auto num : state_) {
    //   DEBUG("{} ", num);
    // }
    // DEBUG("\n");

    while (!cin.eof()) {
      transition_all();
      // for (auto num : state_) {
      //   DEBUG("{} ", num);
      // }
      // DEBUG("\n");
    }

    ll ans = numeric_limits<ll>::max();
    for (auto num : state_) {
      ans = min(ans, num);
    }

    return ans;
  }
  void read_map() {
    map_.clear();
    string line;
    while (getline(cin, line)) {
      if (line.length() == 0) {
        // discard this and next useless line
        getline(cin, line);
        return;
      };
      ll dst, src, len;
      stringstream(line) >> dst >> src >> len;
      map_.push_back({dst, src, len});
    }
  }
  void transition_all() {
    read_map();
    vector<ll> new_state;
    new_state.reserve(state_.size());
    for (auto old : state_) {
      new_state.push_back(transition(old));
    }
    state_.swap(new_state);
  }
  ll transition(ll old) {
    for (auto entry : map_) {
      auto& [dst, src, len] = entry;
      if (old >= src && old < src + len) {
        return old - src + dst;
      }
    }
    return old;
  }
  vector<ll> state_;
  vector<tuple<ll, ll, ll>> map_;
};

int main() { cout << Solution().solve() << endl; }
