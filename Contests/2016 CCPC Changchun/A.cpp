#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



string  sb(string a,string b)
{
	string zero(a.length()-b.length(),'0');
	b=zero+b;

	ll sumk=0;
	string c="";
	for(int i=a.length()-1;i>=0;i--)
	{
		sumk=a[i]-b[i]+sumk;
		c=char((sumk+10)%10+48)+c;
		if(sumk<0)sumk=-1;
		else sumk=0;
	
	}

	string sum="";
	bool flag=0;
	for(int i=0;i<c.length();i++)
	{
		
		
		if(c[i]!='0')flag=1;
		if(flag!=0)sum=sum+c[i];
	}
	
	if(sum=="")sum="0";
	return sum;
}
bool pd(string a)
{
	for(int i=0;i<a.length()/2;i++)
	{
		if(a[a.length()-1-i]!=a[i])return 0;
	}
	return 1;
	
	
}
string hw(string a)
{
	string b="";
	for(int i=0;i<a.length()/2;i++)
	{
		
		a[a.length()-1-i]=a[i];
		
	}
	return a;
	
}




vector<string> V;
int main()
{
	
	
	ll T,l;
	string a,b,c;
	scanf("%lld",&T);
	
	
	
	


	
	for(int u=1;u<=T;u++)
	{
		
		V.clear();
		
		cin>>a;
		l=a.length();
		
		
		
		
		while(pd(a)==0)
		{
			
			//if(a.length()%2==0)
		//	{
			//	string zero(a.length()/2-1,'0');
			//	b="1"+zero;
			//}
			
		//	else 
			//{
			//	string zero(a.length()/2,'0');
			//	b="1"+zero;
		//	}
			
			if(a.length()==2)
			{
				if(a[0]=='1')
				{
					
					b="1";
				}
				else
				{
					string zero(a.length()/2,'0');
					b="1"+zero;
					
				}
			}
			else
			{
				string zero(a.length()/2,'0');
				b="1"+zero;
			}
			
			
			
			c=sb(a,b);
			c=hw(c);
			
			V.push_back(c);
			c=sb(a,c);
			a=c;
		}
		V.push_back(a);
		printf("Case #%d:\n%u\n",u,V.size());
		for(int i=0;i<V.size();i++)
		{
			cout<<V[i]<<endl;
		}
		
		
		
		
	
		
		
		
		
	}
	
	
}
