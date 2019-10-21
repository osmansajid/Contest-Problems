#include<bits/stdc++.h>
using namespace std;
#define mod  10007

long long mulmod(long long a, long long b, long long c) {
    long long x = 0, y = a % c;
    while (b > 0) {
        if (b % 2 == 1){
            x = (x + y) % c;
        }
        y = (y * 2) % c;
        b /= 2;
    }
    return x % c;
}

struct MAT
{
	 long long r,c;
	 long long a[4][4];
	 MAT(long long a,long long b){
	 	r = a;
	 	c = b;
	 }
     void init(long long temp[]){
     	for(long long i = 0 ; i<r*c ; i++){
     		a[i/c][i%c] = temp[i];
     	}
     }
     long long get(int x,int y){
        return a[x][y];
     }
     void print(){
          for(long long i = 0 ; i< r ; i++){
          	 for(long long j = 0; j < c ; j++){
          	 	 cout << a[i][j] << ' ';
          	 }
          	 cout << endl;
          }
     }
     MAT operator*(MAT b){
     	 MAT sum(r,b.c);
     	 long long temp[r*b.c];
     	 memset(temp,0,sizeof temp);
     	 sum.init(temp);
     	 for(long long i = 0 ; i< r ; i++){   // row 1st mat
     	 	 for(long long j = 0 ; j< b.c ; j++){  // col 2nd mat
                   for(long long k=0; k<c ;k++){   // col 1st matss
                   	  sum.a[i][j] += mulmod(a[i][k],b.a[k][j],mod);
                      if(sum.a[i][j] >= mod) sum.a[i][j] = sum.a[i][j]%mod;
                   }
     	 	 }
     	 }
     	 return sum;

     }
};

MAT pow(MAT b , long long p){
    if(p == 0 || p == 1)
      return b;
    if(p&1){
        return b*pow(b,p-1);
    }
    else{
        MAT temp = pow(b,p/2);
        return temp*temp;
    }

}

long long fun(long long nth,long long x,long long y,long long z){
    if(nth<=2) return 0;//base condition
    MAT a(4,4);//coefficient matrix
    MAT a2(4,1);//recursive relation matrix
    long long tmp[16];
    tmp[0]=x;
    tmp[1]=0;
    tmp[2]=y;
    tmp[3]=1;
    tmp[4]=1;
    tmp[5]=0;
    tmp[6]=0;
    tmp[7]=0;
    tmp[8]=0;
    tmp[9]=1;
    tmp[10]=0;
    tmp[11]=0;
    tmp[12]=0;
    tmp[13]=0;
    tmp[14]=0;
    tmp[15]=1;
    a.init(tmp);
    long long tmp2[4];
    tmp2[0]=0;
    tmp2[1]=0;
    tmp2[2]=0;
    tmp2[3]=z;
    a2.init(tmp2);
    MAT ans=pow(a,nth-2)*a2;
    //ans.print();
    return ans.get(0,0)%mod;
}

int main()
{
    int t,tc=0;
    scanf("%d",&t);
    long long n,x,y,z;
    while(t--){
        scanf("%lld%lld%lld%lld",&n,&x,&y,&z);
        printf("Case %d: %d\n",++tc,fun(n,x,y,z));
    }
}

