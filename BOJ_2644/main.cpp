#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

int n;
int p, q;
int m;

map<int, vi> adj;

int solve() {
	auto visit = vb(n + 1, false);

	auto st = stack<pii>{};
	st.push({ p, 0 });

	auto ret = -1;
	while (!st.empty()) {
		auto [f, d] = st.top();
		st.pop();

		if (f == q) {
			ret = d;
			break;
		}

		visit[f] = true;

		for (const auto& y : adj[f]) {
			if (visit[y]) {
				continue;
			}

			st.push({ y, d + 1 });
		}
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> n;
	for (auto i = 1; i <= n; ++i) {
		adj[i] = vi{};
	}

	cin >> p >> q;

	cin >> m;
	while (0 < (m--)) {
		int a, b;
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	const auto ans = solve();
	cout << ans;

	return 0;
}