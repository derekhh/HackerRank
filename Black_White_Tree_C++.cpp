#include<bits/stdc++.h>
using namespace std ;

int visited[100009] , n ,point ,c , col1 , a[100009] , final_ans , present[100009] ; 
vector < int >adj[100009] , ans[2][100009] ; 

int dfs(int i , int col)
{
    if(visited[i])
    return  -1 ; 
    
    visited[i]= 1 ; 
    
    int tot =0 ; 
    
    for(int j =0 ;j<adj[i].size() ; j++)
    {
        int val = dfs(adj[i][j] , col) ; 
        
        if(val >0)
        {
            tot+=val ; 
           // cout<<adj[i][j]<<" "<<i<<" "<<val<<" "<<tot<<" "<<col<<"df\n" ;
            ans[col][i].push_back(adj[i][j]) ; 
        }
    }
    
    if(a[i] == col)
        tot++ ; 
    else
        tot-- ; 
    
    if(final_ans < tot)
    {
        final_ans = tot; 
        col1 = col ; 
        point = i ;  
    }
    return tot ; 
}

void dfs1(int i , int vis)
{
//	cout<<i<<"\n ";
c++ ;  
        present[i] = 1; 
    for(int j = 0 ; j<ans[col1][i].size() ; j++)
    {
        if(!present[ans[col1][i][j]])
        dfs1(ans[col1][i][j] , vis) ; 
    }
}
int main()
{
    cin>>n ; 
    
    for(int i = 1; i <=n ; i++)
        cin>>a[i] ; 
    
    for(int i =0 ; i<n-1; i++)
    {
        int u , v ; 
        cin>>u>>v ; 
        
        adj[u].push_back(v) ; 
        adj[v].push_back(u) ; 
    }
    
    int t = 0 ;
    dfs(1 , 0 ) ; 
    
    memset(visited , 0 , sizeof(visited));
    
    dfs(1 , 1) ;
   
    cout<<final_ans<<"\n" ; 
    
    c = 0; 
    
    dfs1(point , 0 ) ; 
    cout<<c<<"\n" ; 
    
    for(int i = 1; i <=n ; i++)
    if(present[i])
    cout<<i<<" ";
    
    return 0 ; 
}
