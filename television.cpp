#include<bits/stdc++.h>
using namespace std;
char niz[1000000];
long long durvo[4000000];
long long otg[1000000];
long long lazy[4000000];
long long posled[1000000];
void update(long long leftQ,long long rightQ,long long left,long long right,long long idx){
if(left>=leftQ and right<=rightQ){
    durvo[idx]*=-1;
    if(lazy[idx]==0){
        lazy[idx]=-1;
    }else{
    lazy[idx]*=-1;
    }
    for(int i=idx/2;i>=1;i/=2){
        durvo[i]=durvo[i*2]+durvo[i*2+1];
        if(lazy[i]!=0){
            durvo[i]*=lazy[i];
        }
    }
}else{
if(right<leftQ or left>rightQ){

}else{
update(leftQ,rightQ,left,(left+right)/2,idx*2);
update(leftQ,rightQ,(left+right)/2+1,right,idx*2+1);
}
}
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
long long n,q,l,broiel=1,nach=0,a=0,b=0;
cin>>n>>q;
cin>>niz;
l=strlen(niz);
for(int i=l-1;i>=0;i--){
    if(niz[i]=='o'){
            if(i==n-1){
        posled[i]=1;
            }else{
            posled[i]=posled[i+1]+1;
            }
    }
}

while(broiel<l){
    broiel*=2;
}
nach=broiel;
broiel*=2;
broiel--;
for(int i=broiel-nach+1;i<broiel-nach+1+l;i++){
    a=i-broiel+nach-1;
    if(niz[a]=='+'){
        durvo[i]=1;
    }else{
    if(niz[a]=='-'){
        durvo[i]=-1;
    }else{
    if(durvo[i-1]==1){
        durvo[i]=-1;
    }else{
        durvo[i]=1;
    }
    }
    }

}

for(int i=broiel-nach;i>=1;i--){

    durvo[i]=durvo[i*2]+durvo[i*2+1];
}
bool krai=false;
for(int i=0;i<q;i++){
cin>>a>>b;
if(niz[a-1]=='o'){

  update(a+posled[a-1]+broiel-nach,b+broiel-nach,broiel-nach+1,broiel,1);

}else{
update(a+broiel-nach,b+broiel-nach,broiel-nach+1,broiel,1);
}
if(b!=l){
    if(niz[b]=='o' and posled[a-1]<=b-a+1){
        update(b+broiel+1-nach,b+broiel+posled[b]-nach,broiel-nach+1,broiel,1);
    }
}
otg[i]=durvo[1]+1;
}
for(int i=0;i<q;i++){
   if(otg[i]==0){
    otg[i]=n;
   }else{
   if(otg[i]<0){
    otg[i]*=-1;
    otg[i]%=n;
    otg[i]=n-otg[i];
   }else{
   otg[i]%=n;
   if(otg[i]==0){
    otg[i]=n;
   }
   }
   }
   cout<<otg[i]<<"\n";
}
return 0;
}
