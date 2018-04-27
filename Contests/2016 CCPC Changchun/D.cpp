#include<bits/stdc++.h>

using namespace std;

int main()
{
	int a[20]={0,0,0,1,1,2,3,3,4,5,6,7,7,8,9,10,11,12,13,14};
	int T,i,k;
	scanf("%d",&T);
	for(i=1;i<=T;++i)
	{
		scanf("%d",&k);
		printf("Case #%d: %d\n",i,a[k-1]); 
	} 
}
