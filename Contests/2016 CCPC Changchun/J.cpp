#include<bits/stdc++.h>
using namespace std;

char num[2][10100];
char ans[55][10100]; int cnt;

void Minus(char *a, char *b, char *rslt)
{
	int alen = strlen(a);
	int blen = strlen(b);
	int borrow = 0;
	
	int len = 0;
	for (int i=0, j=0; i<alen||j<blen||borrow; ++i, ++j)
	{
		int lhs = i<alen ? a[i]-'0' : 0;
		int rhs = j<blen ? b[i]-'0' : 0;
		int ret = lhs-rhs+borrow;
		borrow = 0;
		if (ret<0) {
			ret += 10, borrow = -1;
		}
		rslt[len++] = ret+'0';
	}
	rslt[len] = 0;
	--len;
	while (len>0 && rslt[len] == '0') rslt[len--] = 0;
}

void solve()
{
	char *cur = num[cnt&1];
	
	int len = strlen(cur);
	if (len == 1 && cur[0] == '0') return;
	if (len > 1) {
		if (cur[len-1] == '1') {
			for (int i=0; i<len-1; ++i) ans[cnt][i] = '9';
		}
		else {
			ans[cnt][0] = cur[len-1]-1;
			for (int i=1; i<len-1; ++i) ans[cnt][i] = '9';
			ans[cnt][len-1] = cur[len-1]-1;
		}
		Minus(num[cnt&1], ans[cnt], num[~cnt&1]);
	}
	else {
		ans[cnt][0] = cur[0];
		++cnt; return;
	}
	
	++cnt;
	solve();
}

int main()
{
	int t; scanf("%d", &t);
	for (int kase=1; kase<=t; ++kase)
	{
		cnt = 0; 
		memset(ans, 0, sizeof(ans));
		memset(num, 0, sizeof(num));
		
		scanf("%s", num[0]);
		reverse(num[0], num[0]+strlen(num[0]));
		solve();
		
		printf("Case #%d:\n", kase);
		printf("%d\n", cnt);
		for (int i=0; i<cnt; ++i) {
			int len = strlen(ans[i]);
			for (int j=len-1; j>=0; --j) {
				putchar(ans[i][j]);
			}
			putchar('\n');
		}
	}
} 
