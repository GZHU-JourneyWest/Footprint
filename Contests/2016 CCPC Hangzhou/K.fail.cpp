#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e9+7;

vector<int> prime;
bool isprime[maxN];

void seive()
{
	memset(isprime, true, sizeof(isprime));
	isprime[0] = isprime[1] = false;
	for (int i=2; i<maxN; ++i) {
		if (isprime[i]) {
			prime.push_back(i);
		}
		for (int j=0; j<int(prime.size()) && i*prime[j]<maxN; ++j) {
			isprime[i*prime[j]] = false;
			if (i%prime[j] == 0) break;
		}
	}
}


int main()
{
	seive(); 
	
	for (int i=0; i<100; ++i) {
		cout << prime[i] << ' ';
	}
	cout << endl;
}
