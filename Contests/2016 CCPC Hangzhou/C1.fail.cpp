#include<bits/stdc++.h>

using namespace std;

int main()
{
	int T,i,j,k;
	scanf("%d",&T);
	for(i=1;i<=T;++i)
	{
		int n,a0=0,a;
		double speed=0;
		int ans=0;
		scanf("%d",&n);
		for(j=1;j<=n;++j)
		{
				scanf("%d",&a);
				if(j==1)speed=a;
				if(a-a0>=speed){
					if(j==n){
						ans++;
						continue;
					}
					double temp=a-a0;
					k=temp/speed;
					speed=temp/k;
					a0=a;
					ans+=k; 
				} 
				else
				{
					double temp=a-a0;
					k=speed/temp; 
					speed=a-a0;
					ans=ans*k+1;
					a0=a;	
				} 
		}
		printf("Case #%d: %d\n",i,ans);
	}
}
