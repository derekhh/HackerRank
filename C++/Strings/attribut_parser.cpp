#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <deque>
#include <sstream>
#include <stdio.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,q;
    char ch;
    map <string,string> mp;
    scanf("%d %d\n",&n,&q);
    string s,s1,s2,s3;
    stringstream ss,ss1;
    deque<string> dq;
    while(n--){
        getline(cin,s);
        ss<<s.substr(1,s.size()-2)<<" tumera - were ";
        ss>>s1;
        //cout<<s1<<endl;
        if(s1[0]=='/'){
            
            dq.pop_back();
        }
        else{
           // cout<<"AG.....";
           dq.push_back(s1);
            for(int i=0;i<dq.size()-1;i++)
            {
                   ss1<<dq[i]<<".";
            }
            ss1<<dq[dq.size()-1];
            //cout<<ss1.str()<<"\n";
           // cout<<"...."+s1+"....";
           while(1)
           {
                ss>>s2>>ch>>s3;
               if(ch=='-')  break;
                mp.insert(make_pair(ss1.str()+"~"+s2,s3));
               //cout<<ss1.str()+"~"+s2<<" "<<s3<<endl;
           } 
        }
        ss.str("");
        ss.clear();
        ss1.str("");
        ss1.clear();
    }
    for(int i=0;i<dq.size();i++){
        cout<<dq[i]<<".";
    }
    map<string,string>::iterator iter;
    /*for(iter=mp.begin();iter!=mp.end();iter++){
        cout<<iter->first<<endl;
    }*/
    while(q--){
        string str2;
        //getline(cin)
        cin>>str2;
        if(mp.find(str2)!=mp.end()){
            string t=mp.find(str2)->second;
            cout<<(mp.find(str2)->second).substr(1,t.size()-2)<<endl;
        }
        else{
            cout<<"Not Found!"<<endl;
        }
    }
    //cout<<ss.str();
    return 0;
}
