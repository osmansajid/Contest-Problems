#include<bits/stdc++.h>
using namespace std;

unsigned long long mulmod(unsigned long long a, unsigned long long b, unsigned long long c){
	unsigned long long x = 0,y = a%c;

	while(b>0){
		if(b&1) x = (x+y)%c;
		y = (y<<1)%c;
		b >>= 1;
	}

	return x;
}

unsigned long long pow(unsigned long long a, unsigned long long b, unsigned long long c){
	unsigned long long x = 1, y = a;

	while(b>0){
		if(b&1) x = mulmod(x,y,c);
		y = mulmod(y,y,c);
		b >>= 1;
	}

	return x;
}

bool miller_rabin(unsigned long long p, int it){
	if(p<2) return false;
	if(p==2) return true;
	if((p&1)==0) return false;

	unsigned long long s = p-1;
	while(s%2==0) s >>= 1;

	while(it--){
		unsigned long long a = rand()%(p-1)+1,temp = s;
		unsigned long long mod = pow(a,temp,p);

		if(mod==-1 || mod==1) continue;

		while(temp!=p-1 && mod!=p-1){
			mod = mulmod(mod,mod,p);
			temp <<= 1;
		}

		if(mod!=p-1) return false;
	}

	return true;
}

int main()
{
    long long n;
    cin>>n;
    if(n%2==0){
        if(n==2|| n==4) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    else{
        if(miller_rabin(n,18)){
            cout<<"NO"<<endl;
        }
        else cout<<"YES"<<endl;
    }
}
