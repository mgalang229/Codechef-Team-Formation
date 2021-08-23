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
		string s, t;
		cin >> s >> t;
		int both = 0;
		int eng = 0;
		int prog = 0;
		int rem = 0;
		// count the number of students based on the subjects they know
		for (int i = 0; i < n; i++) {
			if (s[i] == '1' && t[i] == '1') {
				both++;
			} else if (s[i] == '1') {
				prog++;
			} else if (t[i] == '1') {
				eng++;
			} else {
				rem++;
			}
		}
		// find the number of pairs that can be created from programming and english students
		int ans = min(prog, eng);
		// calculate the remaining students without a pair
		rem += (max(prog, eng) - min(prog, eng));
		// check if students that know both subjects are greater than or equal to the remaining
		if (both >= rem) {
			// if yes, then combine them together and divide it by 2 to get the number of pairs
			ans += (both + rem) / 2;
		} else {
			// otherwise, simply add the value of 'both' to 'ans' (since it is the minimum)
			ans += both;
		}
		cout << ans << '\n';
	}
	return 0;
}
