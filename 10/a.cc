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

constexpr array<pair<ll, ll>, 8> deltas({});

using Point = pair<ll, ll>;
template <size_t N>
using Points = array<pair<ll, ll>, N>;

struct Solution {
  Point move(ll x, ll y) {
    switch (grid_[y][x]) {
      // case 'S':
      //   for (auto [dx, dy] : Points<8>({
      //            {-1, 0},
      //            {0, 1},
      //            {0, -1},
      //            {1, 0},
      //        })) {
      //     if (y + dy < 0 || y + dy >= grid_.size() || x + dx < 0 ||
      //         x + dx >= grid_[0].size())
      //       continue;
      //     if (grid_[y + dy][x + dx] != '.') {
      //       return {x + dx, y + dy};
      //     }
      //   }
      //   break;
      case '-':
        for (auto [dx, dy] : Points<2>({{-1, 0}, {1, 0}})) {
          if (Point{x + dx, y + dy} != prev_) {
            return {x + dx, y + dy};
          }
        }
        break;
      case '|':
        for (auto [dx, dy] : Points<2>({{0, -1}, {0, 1}})) {
          if (Point{x + dx, y + dy} != prev_) {
            return {x + dx, y + dy};
          }
        }
        break;
      case 'L':
        for (auto [dx, dy] : Points<2>({{0, -1}, {1, 0}})) {
          if (Point{x + dx, y + dy} != prev_) {
            return {x + dx, y + dy};
          }
        }
        break;
      case 'J':
        for (auto [dx, dy] : Points<2>({{0, -1}, {-1, 0}})) {
          if (Point{x + dx, y + dy} != prev_) {
            return {x + dx, y + dy};
          }
        }
        break;
      case '7':
        for (auto [dx, dy] : Points<2>({{0, 1}, {-1, 0}})) {
          if (Point{x + dx, y + dy} != prev_) {
            return {x + dx, y + dy};
          }
        }
        break;
      case 'F':
        for (auto [dx, dy] : Points<2>({{0, 1}, {1, 0}})) {
          if (Point{x + dx, y + dy} != prev_) {
            return {x + dx, y + dy};
          }
        }
        break;
      case '.':
        assert(false);
      default:
        assert(false);
    }
    assert(false);
  }

  Solution() {
    string line;
    while (getline(cin, line)) {
      grid_.push_back(line);
    }
    for (ll row = 0; row < grid_.size(); row++) {
      auto& s = grid_[row];
      for (ll col = 0; col < s.size(); col++) {
        if (s[col] == 'S') {
          start_ = {col, row};
        }
      }
    }
  }

  auto solve() {
    Point curr = start_;
    auto [sx, sy] = start_;
    ll ans = 0;
    for (auto [dx, dy] : Points<4>({{-1, 0}, {1, 0}, {0, -1}, {0, 1}})) {
      if (sy + dy < 0 || sy + dy >= grid_.size() || sx + dx < 0 ||
          sx + dx >= grid_[0].size())
        continue;
      char c = grid_[sy + dy][sx + dx];
      if (dx == -1 && !(c == '-' || c == 'L' || c == 'F')) continue;
      if (dx == 1 && !(c == '-' || c == 'J' || c == '7')) continue;
      if (dy == -1 && !(c == '|' || c == '7' || c == 'F')) continue;
      if (dy == 1 && !(c == '|' || c == 'J' || c == 'L')) continue;
      ll i = 1;
      prev_ = start_;
      curr = {start_.first + dx, start_.second + dy};
      while (curr != start_) {
        auto [x, y] = curr;
        // DEBUG("{} {}\n", x, y);
        curr = move(x, y);
        prev_ = {x, y};
        i += 1;
      }
      // DEBUG("{}\n\n", i);
      ans = max(ans, i / 2);
    }

    return ans;
  }

  vector<string> grid_;
  Point start_;
  Point prev_ = {-1, -1};
};

int main() { cout << Solution().solve() << endl; }
