nclude <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//#include <iostream>
int max(int a,int b){
    if(a<b)     return b;
    return a;
}
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int *v=(int *)calloc(n,sizeof(int));
        for(int i=0;i<n;i++){
            scanf("%d",v+i);
        }
        int **arr=(int **)calloc(2,sizeof(int*));
        arr[0]=(int *)calloc(n-1,sizeof(int));
        arr[1]=(int*)calloc(n-1,sizeof(int));   
        arr[0][0]=abs(v[0]-1);
        arr[1][0]=max(abs(v[1]-1),abs(v[1]-v[0]));
        //printf("%d %d ",arr[0][0],arr[1][0]);
        for(int i=1;i<n-1;i++){
            arr[0][i]=max(arr[0][i-1],abs(v[i]-1)+arr[1][i-1]);
            arr[1][i]=max(arr[0][i-1]+abs(v[i+1]-1),arr[1][i-1]+abs(v[i]-v[i+1]));
           // printf("%d %d_%d ",arr[0][i],arr[1][i],v[i+1]);
        }
        printf("%d\n",max(arr[0][n-2],arr[1][n-2]));
       
    }
    /*int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            
        }
        
        
        
        
        
        
    }*/
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}

