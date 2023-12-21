#include "bits/stdc++.h"
using namespace std;
bool sss(pair<char,int>a,pair<char,int>b){
    if(a.second < b.second)
        return false;
    else if(a.second > b.second)
        return true;
    else {
        return a.first < b.first;
    }
    return true;
}

int main(){
    //freopen("in.txt","r",stdin);
    int kase;cin>>kase;
    for(int oo=0;oo<kase;++oo){
        int x,y;cin>>x>>y;
        vector<vector<char> >data(x+2,vector<char>(y+2));
        vector<vector<int> >value(x+2,vector<int>(y+2));

        for(int i=1;i<=x;++i){
            for(int j=1;j<=y;++j){
                cin>>data[i][j];
            }
        }
        int tmp=0;
        for(int i=1;i<=x;++i){
            for(int j=1;j<=y;++j){
                int mini=0x3f3f3f3f;
                bool fin=false;
                if(data[i][j]==data[i-1][j]&&data[i-1][j]!=0){fin=true;mini=min(value[i-1][j],mini);}
                if(data[i][j]==data[i][j-1]&&data[i][j-1]!=0){fin=true;mini=min(value[i][j-1],mini);}
                if(fin)value[i][j]=mini;
                else value[i][j]=++tmp;
            }
        }
        for(int i=x;i>0;--i){
            for(int j=y;j>0;--j){
                bool fin=false;
                int mini=0x3f3f3f3f;
                if(data[i][j]==data[i-1][j]&&data[i-1][j]!=0){fin=true;mini=min(value[i-1][j],mini);}
                if(data[i][j]==data[i][j-1]&&data[i][j-1]!=0){fin=true;mini=min(value[i][j-1],mini);}
                if(data[i][j]==data[i+1][j]&&data[i+1][j]!=0){fin=true;mini=min(value[i+1][j],mini);}
                if(data[i][j]==data[i][j+1]&&data[i][j+1]!=0){fin=true;mini=min(value[i][j+1],mini);}
                if(fin)value[i][j]=mini;
            }
        }
        for(int i=1;i<=x;++i){
            for(int j=1;j<=y;++j){
                bool fin=false;
                int mini=0x3f3f3f3f;
                if(data[i][j]==data[i-1][j]&&data[i-1][j]!=0){fin=true;mini=min(value[i-1][j],mini);}
                if(data[i][j]==data[i][j-1]&&data[i][j-1]!=0){fin=true;mini=min(value[i][j-1],mini);}
                if(data[i][j]==data[i+1][j]&&data[i+1][j]!=0){fin=true;mini=min(value[i+1][j],mini);}
                if(data[i][j]==data[i][j+1]&&data[i][j+1]!=0){fin=true;mini=min(value[i][j+1],mini);}
                if(fin)value[i][j]=mini;
            }
        }
        /*for(int i=1;i<=x;++i,cout<<endl){
            for(int j=1;j<=y;++j){
                cout<<value[i][j]<<' ';
            }
        }*/
        map<char,int>cou;
        set<int> fined;
        for(int i=1;i<=x;++i){
            for(int j=1;j<=y;++j){
                if(fined.find(value[i][j])==fined.end()){cou[data[i][j]]++;fined.insert(value[i][j]);}
            }
        }
        vector<pair<char,int> >ans;
        for(map<char,int>::iterator p=cou.begin();p!=cou.end();p++){
            ans.push_back(pair<char,int>(p->first,p->second));
        }
        sort(ans.begin(),ans.end(),sss);

        cout<<"World #"<<oo+1<<endl;
        for(int i=0;i<ans.size();++i){
            cout<<ans[i].first<<": "<<ans[i].second<<endl;
        }
    }
}
