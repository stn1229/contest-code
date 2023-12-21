#include<bits/stdc++.h>
using namespace std;
int main(){
    int s;

    //freopen("in.txt","r",stdin);
    while(cin>>s){
        vector<vector<int> >v(s,vector<int>(s));
        for(int i=0;i<s;++i)
            for(int j=0;j<s;++j)
                cin>>v[i][j];
        //for(int i=0;i<s;++i,cout<<endl)for(int j=0;j<s;++j)cout<<v[i][j]<<' ';cout<<endl;
        int maxi=0;
        for(int i=0;i<s;++i){
            for(int j=0;j<s;++j){
                maxi=max(maxi,v[i][j]);
                if(i==0&&j==0)continue;
                if(i==0)v[i][j]+=v[i][j-1];
                else if(j==0)v[i][j]+=v[i-1][j];
                else {
                    v[i][j] += v[i-1][j]+v[i][j-1]-v[i-1][j-1];
                }
            }
        }
        //for(int i=0;i<s;++i,cout<<endl)for(int j=0;j<s;++j)cout<<v[i][j]<<' ';cout<<endl;
        for(int i=0;i<s;++i)for(int j=0;j<s;++j)
        for(int o=0;o<=i;++o)for(int p=0;p<=j;++p){
            if(o==i||p==j)maxi=max(maxi,v[i][j]-v[o][p]);
            maxi=max(maxi,v[i][j]-v[o][j]-v[i][p]+v[o][p]);
        }
        cout<<maxi<<endl;
    }
}
