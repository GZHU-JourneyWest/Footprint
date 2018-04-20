#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll sn(string a)
{
	ll sum=0;
	for(int i=0;i<a.length();i++)
	{
		sum=10*sum+(a[i]-48);
	}
	return sum;
}

int main()
{
	ll T;
	scanf("%lld",&T);
	string s;
	for(int u=1;u<=T;u++)
	{
		cin>>s;
		string s1=s.substr(0,s.length()-3);
		string sk=s.substr(s.length()-3);
		string s2=s1.substr(0,1);
		string s2_=s1.substr(1);
		string s3=s1.substr(0,s1.length()-1);
		string s3_=s1.substr(s1.length()-1,1);
		

		
		ll num1,num2,num3,num4;
		ll numx=sn(s2)+sn(s2_);
		ll numy=sn(s3)+sn(s3_);
		num1=max(numx,numy);
		num2=sk[0]-48;
		num3=sk[1]-48;
		num4=sk[2]-48;
		
		ll x=num2*num3/num4;
		ll ans=num1-x;
		printf("Case #%d: %lld\n",u,ans);
		
		
		
	} 
	
}