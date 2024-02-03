#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

//sieve
const int N=1e7+7;
bool mark[N+7];
vector<int>prime; // prime
vector<int>spf(N+7);//smallest prime factor

void sieve(){
    for(int i=4;i<=N;i+=2){
        mark[i]=true;
        spf[i]=2;
    }
    spf[2]=2;
    for(ll i=3;i*i<=N;i+=2){
        if(!mark[i]){
            spf[i]=i;
            for(ll j=i*i;j<=N;j+=(2*i)){
                if(mark[j]==0)spf[j]=i;
                mark[j]=true;
            }
        }
    }
    prime.pb(2);
    for(int i=3;i<=N;i+=2){
        if(!mark[i])prime.pb(i);
    }
}


//primeFact
vector<int>primeFact(ll x){
    vector<int>v;
    while(x>1){
        v.pb(spf[x]);
        x/=spf[x];
    }
    return v;
}



//binpow
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}



//binpow with mod
long long binpowM(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}



//Large Expo using Binary Multi (while the M or A is too big)
long long binpowM2(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)res = binMulti(res,a,m) % m;
        a = binMulti(a,a,m) % m;
        b >>= 1;
    }
    return res;
}

long long binMulti(long long a,long long b,long long M){
    long long res=0;
    while(b>0){
        if((b&1))res=(res+a)%M;
        a=(a+a)%M;
        b>>=1;
    }
    return res;
}


//Euler tottient function ETF
int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}


//gcd of vector
ll Vgcd(vector<ll>v){
    ll GCD=v[0];
    for(int i=1;i<v.size();i++){
        GCD=__gcd(GCD,v[i]);
    }
    return GCD;
}



int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    return 0;
}