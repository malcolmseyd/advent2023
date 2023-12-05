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
    ll left;
    ll len;
    while (ss >> left >> len) {
      state_.push_back({left, left + len});
    }
    // discard first two useless lines
    getline(cin, line);
    getline(cin, line);
  }

  auto solve() {
    init();
    for (auto num : state_) {
      DEBUG("({},{}) ", num.first, num.second);
    }
    DEBUG("\n");

    while (!cin.eof()) {
      transition_all();
      for (auto num : state_) {
        DEBUG("({},{}) ", num.first, num.second);
      }
      DEBUG("\n");
    }

    ll ans = numeric_limits<ll>::max();
    for (auto num : state_) {
      ans = min(ans, num.first);
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
        break;
      };
      ll dst, src, len;
      stringstream(line) >> dst >> src >> len;
      map_.push_back({dst, src, len});
    }
    sort(all(map_), [](tuple<ll, ll, ll> a, tuple<ll, ll, ll> b) {
      return get<1>(a) < get<1>(b);
    });
    DEBUG("MAP:\n");
    ll last = 0;
    for (auto t : map_) {
      auto [dst, src, len] = t;
      char marker = ' ';
      if (last == src) {
        marker = '>';
      }
      DEBUG("{} [{},{})\n", marker, src, src + len);
      last = src + len;
    }
  }

  void transition_all() {
    read_map();
    vector<pair<ll, ll>> new_state;
    new_state.reserve(state_.size());
    for (auto old : state_) {
      transition(old, new_state);
    }
    state_.swap(new_state);
  }

  void transition(pair<ll, ll> old, vector<pair<ll, ll>>& new_state) {
    DEBUG("\n");
    auto [left, right] = old;
    for (auto entry : map_) {
      if (!(left < right)) return;

      auto [dst, src, len] = entry;
      ll rangeleft = src;
      ll rangeright = src + len;

      DEBUG("try ({},{}) [{},{})\n", left, right, rangeleft, rangeright);

      ll shift = dst - src;
      if (right < rangeleft || left > rangeright) {
        DEBUG("skipping\n");
        continue;
      }

      if (left < rangeleft) {
        DEBUG("copy ({},{})\n", left, rangeleft);
        new_state.push_back({left, rangeleft});
      }
      DEBUG("shift ({},{})\n", max(left, rangeleft) + shift,
            min(right, rangeright) + shift);
      new_state.push_back(
          {max(left, rangeleft) + shift, min(right, rangeright) + shift});
      left = rangeright;
    }
    DEBUG("copy ({},{})\n", left, right);
    new_state.push_back({left, right});
  }

  vector<pair<ll, ll>> state_;
  vector<tuple<ll, ll, ll>> map_;
};

int main() { cout << Solution().solve() << endl; }
