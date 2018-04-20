#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

double V[105000];
ll T[105000];
ll A[105000];

void dfs(ll i,double x)
{
	
	ll index=lower_bound(V,V+i-1,x)-V;
				
	for(int t=index;t<=i;t++)
	{
					
		T[t]=T[t-1]+ceil((A[t]-A[t-1])/V[i]);
		V[t]=double(A[t]-A[t-1])/(T[t]-T[t-1]);
		if(V[t]<V[t-1])dfs(t,V[t]);

	}
}





int main()
{
	ll G;
	scanf("%lld",&G);
	
	for(int u=1;u<=G;u++)
	{
		ll n;
		memset(V,0,sizeof(V));
		memset(T,0,sizeof(T));
		memset(A,0,sizeof(A));
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)scanf("%lld",&A[i]);
		for(int i=1;i<=n;i++)
		{
			V[i]=A[i]-A[i-1];
			
			if(V[i]>=V[i-1])T[i]=T[i-1]+1;
			else dfs(i,V[i]);

		
			for(int i=0;i<=n;i++)
			{
				cout<<V[i]<<" ";
			}
			cout<<endl<<endl;
			
		}
		
		
		
		
		printf("Case #%d: %lld\n",u,T[n]);
		
		
		
	} 
	
}
