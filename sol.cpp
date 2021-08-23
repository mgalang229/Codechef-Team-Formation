#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		string t;
		cin >> t;
		// calculate the maximum number of groups that can be created
		int limit = n / 2;
		int both = 0;
		int p = 0;
		int e = 0;
		// count the number of students that know programming, english, or both
		for (int i = 0; i < n; i++) {
			if (s[i] == '1' && t[i] == '1') {
				both++;
			} else {
				p += (s[i] == '1');
				e += (t[i] == '1');
			}
		}
		// subtract the students who know either of the subjects from 'n' (remaining)
		n -= (both + p + e);
		// find the number of pairs that can created by combining programming and english students
		int ans = min(p, e);
		// subtract the value above from 'p' and 'e'
		p -= min(p, e);
		e -= min(p, e);
		// find the remaining number of students who doesn't have a pair
		int remaining = p + e + n;
		// find the number of pairs that can be created by combining the students that
		// know both programming and english, together with the remaining students
		ans += min(both, remaining);
		both -= min(both, remaining);
		remaining -= min(both, remaining);
		// find the minimum value between the calculated answer plus dividing 'both' by 2
		// (if there are remaining students) and the 'limit' calculated previously
		cout << min(ans + (both / 2), limit) << '\n';
	}
	return 0;
}
