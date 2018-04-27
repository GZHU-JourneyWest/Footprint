#include<bits/stdc++.h>

using namespace std;

int main()
{
	int T,i,j;
	scanf("%d",&T);
	for(i=1;i<=T;++i)
	{
		int k,n,a,b,c;
		scanf("%d%d",&n,&k);
		if(k%2==0)
		{
			a=k;
			b=k*2;
			printf("Case #%d: ",i);
			printf("%d %d 1",a,b);
			for(j=n;j>=2;--j)
			{
				if(j!=a&&j!=b)printf(" %d",j);	
			}
			printf("\n");	
		}
		else if(k==1)
		{	
			printf("Case #%d: 1",i);
			for(j=2;j<=n;++j)
				printf(" %d",j);
			printf("\n");
		}
		else 
		{
			if((k-1)%3==0)a=k-1;
			else a=k+1;
			b=k;
			c=k*2;
			printf("Case #%d: ",i);
			printf("%d %d %d 1",a,b,c);
			for(j=n;j>=2;--j)
			{
				if(j!=a&&j!=b&&j!=c)printf(" %d",j);	
			}
			printf("\n"); 
		} 
	} 
}
