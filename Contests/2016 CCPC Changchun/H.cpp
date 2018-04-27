#include <bits/stdc++.h>
using namespace std;

const int maxN = 1000100;

int num[maxN], tmp[maxN];
int pre[maxN];

int n, m, p, ans;
vector<vector<int>> bucket; 

void prepare()
{
	fill(pre, pre+maxN, -1);
	for (int i=1, j=-1; i<m; ++i) {
		while (j>=0 && tmp[i]!=tmp[j+1]) j=pre[j];
		if (tmp[i] == tmp[j+1]) ++j;
		pre[i] = j;
	} 
}

void kmp()
{
	prepare();
	for (int b=0; b<p; ++b) {
		for (int i=0, j=-1; i<int(bucket[b].size()); ++i)
		{
			while (j>=0 && bucket[b][i]!=tmp[j+1]) j=pre[j];
			if (bucket[b][i]==tmp[j+1]) ++j;
			if (j+1==m) {
				++ans; j=pre[j];
			}
		}
	}
}

int main()
{
	int t; scanf("%d", &t);
	for (int kase=1; kase<=t; ++kase)
	{
		scanf("%d%d%d", &n, &m, &p);
		
		ans = 0;
		bucket.resize(p);
		for (int i=0; i<p; ++i) {
			bucket[i].clear();
		}
		
		for (int i=0; i<n; ++i) {
			scanf("%d", &num[i]);
			bucket[i%p].push_back(num[i]);
		} 
		for (int j=0; j<m; ++j) {
			scanf("%d", &tmp[j]);
		}
		kmp();
		
		printf("Case #%d: %d\n", kase, ans);
	}
}
