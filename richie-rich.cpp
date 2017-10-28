#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

char* richieRich(char* s, int n, int k){
    if(n==1) {
        if(k>=1)
            return "9";
        else return s;
    }
    int a,b;
    if(n%2==0) {
        b=n/2;
        a=b-1;
    } else {
        b=n/2+1;
        a=b-2;
        if(k==1 && s[b-1] < '9'){
            s[b-1] = '9';
            k--;
        }
    }
    int change[512000], x=0;
    for(; b<n && a>=0; b++, a--) {
        if(s[a]==s[b])
            continue;
        if(k<=0)
            break;
        if(s[a]>s[b]) {
            s[b]=s[a];
            change[x++]=a;
            k--;
        } else {
            s[a]=s[b];
            change[x++]=a;
            k--;
        }
    }
    x=x-1;
    if(b!=n)
        return "-1";
    int y=0;
    int w=x;
    while(k>1 && (n-y-1)>=y) {
        w=x;
        if(s[y]!='9') {
            s[y]=s[n-y-1]='9';
            if(y == n-y-1){
                while(w>=0 ){
                    if( change[w]==y) {
                        //k=k-1;
                        break;
                    } 
                    w--;
                }
                if(w<0)  k=k-1;
              
            }
            else {
                while(w>=0 ){
                    if(change[w]==y) {
                        k=k-1;
                        break;    
                    } 
                    w--;
                }
                if(w <0 )
                     k=k-2;
            }
        }
        y++;
    }
    while(k==1 && x>=0) {
        if(s[change[x]]!='9') {
            s[change[x]]='9';
            s[n-change[x]-1]='9';
            k--;
        }
        x--;
    }
    if(k>=1 && n%2!=0)
        s[n/2]='9';
    return s;
}

int main() {
    int n; 
    scanf("%i", &n);
    int k; 
    scanf("%i", &k);
    char* s = (char *)malloc(512000 * sizeof(char));
    scanf("%s", s);
    int result_size;
    char* result = richieRich(s, n, k);
    printf("%s\n", result);
    return 0;
}
