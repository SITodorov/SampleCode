#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxN=100001;
bool vis[maxN];
pair<ll,pair<ll,ll> > edges[maxN];
ll links[maxN],sizeLinks[maxN];
ll Rfind(ll a){
    while(a!=links[a])a=links[a];

    return a;
}
ll VUnion(ll a,ll b){
   a=Rfind(a);
   b=Rfind(b);
   if(sizeLinks[a]<sizeLinks[b])swap(a,b);
    sizeLinks[a]+=sizeLinks[b];
    links[b]=a;
}
bool sameSet(ll a,ll b){
    return (Rfind(a)==Rfind(b));
}
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
ll n,m,a,b,c;
ll lengthSum=0,visCount=0;
cin>>n>>m;
for(int i=0;i<m;i++){
    cin>>a>>b>>c;
    lengthSum+=c;
    edges[i]={c,{a,b}};
}
for(int i=1;i<=n;i++){
    links[i]=i;
    sizeLinks[i]=1;
}
sort(edges,edges+m);
for(int i=0;i<m;i++){
   c=edges[i].first;
    a=edges[i].second.first;
    b=edges[i].second.second;

    if(sameSet(a,b)==false){
            if(vis[a]==false){
                vis[a]=true;
                visCount++;
            }
            if(vis[b]==false){
                vis[b]=true;
                visCount++;
            }
        VUnion(a,b);

        lengthSum-=c;
    }
}
if(visCount<n)lengthSum=-1;
cout<<lengthSum<<"\n";
return 0;
}
/*
4 5
1 2 4
1 3 3
2 4 6
1 4 3
3 4 1
ans:9
*/
