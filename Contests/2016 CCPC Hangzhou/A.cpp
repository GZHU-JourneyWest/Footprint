#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
	ll T;
	scanf("%lld",&T);
	for(int u=1;u<=T;u++)
	{
		queue<ll> Q;
		ll n,k,a;
		ll asum=0,ans=0;
		scanf("%lld%lld",&n,&k);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a);
			Q.push(a);
			asum+=a;
		}
		printf("Case #%d: ",u);
		if(asum%k!=0)printf("-1\n");
		else
		{
			ll pjs=asum/k,top;
			ll sum=0;
			ll k=0;
			while(!Q.empty())
			{
				top=Q.front();
				Q.pop();
				sum+=top;
				if(sum%pjs==0)
				{
					ans+=sum/pjs-1;
					ans+=k;
					k=0;
					sum=0;
				}
				else k++;
			}
			
			
			
			
			printf("%lld\n",ans);
			
			
		}
	}
	
	
} 