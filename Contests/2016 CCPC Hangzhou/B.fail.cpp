#include <bits/stdc++.h>
using namespace std;
using LL = long long;

template<typename T = int>
inline T read() {
	T val = 0, sign = 1; char ch;
	for (ch=getchar(); ch<'0'||ch>'9'; ch=getchar()) 
		if (ch == '-') sign = -1;
	for (; ch>='0' && ch<='9'; ch=getchar())
		val = val*10+ch-'0';
	return sign*val;
}

const int maxN = 1010;

int n;
int pre[maxN];
int x[maxN], y[maxN], c[maxN]; LL r[maxN];
queue<int> que[maxN];
bool bang[maxN][maxN];

void init()
{
	iota(pre, pre+n+1, 0);
}

int find(int x) {
	return x==pre[x] ? x : pre[x]=find(pre[x]);
}

void merge(int a, int b, int cost) // Merge b into a, cost c
{
	a = find(a), b = find(b);
	if (a == b) return;
	pre[b] = a, c[a] = cost;
}

int main()
{
	int T; T = read();
	for (int t=1; t<=T; ++t) {
		n = read(); init();
		
		for (int i=1; i<=n; ++i) {
			x[i] = read(); y[i] = read();
			r[i] = read(); c[i] = read();
			r[i] *= r[i];
		}
		
		for (int i=1; i<=n; ++i) {
			for (int j=i+1; j<=n; ++j) {
				LL dis = (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
				if (dis <= r[i]) {
					bang[i][j] = true; que[i].push(j); 
				}
				if (dis <= r[j]) {
					bang[j][i] = true; que[j].push(i);
				}
			}
		}
		
		for (int i=1; i<=n; ++i) {
			while (que[i].size()) {
				int cur = que[i].front(); que[i].pop();
				if (bang[cur][i]) {
					merge(i, cur, min(c[find(i)], c[find(cur)]));
				}
				else {
					if (find(cur) == cur) {
						merge(i, cur, c[find(i)]);
					}
				}
			}
		}
		
		LL cost = 0;
		for (int i=1; i<=n; ++i) {
			if (find(i) == i) cost += c[i];
		}
		
		printf("Case #%d: %lld\n", t, cost);
	}
}
