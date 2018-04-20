#include <bits/stdc++.h>
using namespace std;

const int maxN = 101010;

int n;
long long tme[maxN];
long long a[maxN];
double sp[maxN];

void update(int pos, int k) {
	sp[pos] /= k;
	if (sp[pos] < sp[pos-1]) {
		int k = ceil(sp[pos-1]/sp[pos]);
		update(pos-1, k);
	}
}

int main()
{
	int T; scanf("%d", &T);
	for (int t=1; t<=T; ++t) {
		scanf("%d", &n);
		
		a[0] = 0, sp[0] = 0;
		for (int i=1; i<=n; ++i) {
			scanf("%lld", &a[i]);
			sp[i] = a[i]-a[i-1];
			tme[i] = 1;
		}
		
		for (int i=2; i<=n; ++i) {
			if (sp[i] < sp[i-1]) {
				int k = ceil(sp[i-1]/sp[i]);
				update(i-1, k);
			}
		}
		
		long long ans = 0;
		for (int i=1; i<=n; ++i) {
			ans += tme[i];
		}
		printf("Case %d: %lld\n", t, ans);
	}
}
