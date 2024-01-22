#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
typedef long long ll;

ifstream fin("socdist.in");
ofstream fout("socdist.out");

ll n, m, lo, hi, grass[200005];

bool works(ll d) {
	ll pre = grass[0], mn = 1e18;
	for (int i = 0; i < n - 1; i++) {
		int nxt = lower_bound(grass, grass + 2 * m, pre + d) - grass;
		if (nxt >= 2 * m) return 0;
		if (nxt % 2) pre += d;
		else pre = grass[nxt];
	}
	return 1;
}

int main() {
	fin >> n >> m;
	for (int i = 0; i < m; i++)
		fin >> grass[2 * i] >> grass[2 * i + 1];
	sort(grass, grass + 2 * m);
	hi = (grass[2 * m - 1] - grass[0]) / (n - 1);
	while (lo <= hi) {
		ll mid = (lo + hi + 1) / 2;
		if (works(mid)) {
			if (lo == mid) break;
			lo = mid;
		}
		else hi = mid - 1;
	}
	fout << lo << endl;
}