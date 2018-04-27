#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int maxN = 1010;

bool vis[maxN];
LL ans[maxN];

void down(int i)
{
	for (; i; i -= i&(-i)) {
		vis[i] = !vis[i];
	}
}

LL cal(int a, int b)
{
	memset(vis, 0, sizeof(vis));
	down(a); if (a!=b) down(b);
	
	int ans = 0;
	for (int i=max(a, b); i; --i) {
		if (vis[i]) ++ans; 
 	}
 	return ans;
} 

string bin(int x)
{
	string str;
	while (x) {
		str.push_back(x&1 ? '1' : '0');
		x >>= 1;
	}
	reverse(str.begin(), str.end());
	return str;
}

int main()
{
	ans[1] = 1;
	for (int i=2; i<100; ++i) {
		ans[i] = ans[i-1];
		for (int j=1; j<=i; ++j) {
			ans[i] += cal(j, i);
		}
		cout << i << ' ' << bin(i) << ' ' << ans[i] << ' ' << bin(ans[i]) << endl;
		// cout << i << ' ' << ans[i] << ' ' << ans[i]-ans[i-1] << endl;
	}
}
