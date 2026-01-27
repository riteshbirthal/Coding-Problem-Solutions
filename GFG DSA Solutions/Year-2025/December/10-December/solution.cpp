#include <iostream>
#include <stdio.h>
#include <algorithm>

int main() {
	int t,n;
	scanf("%d",&t);
	while(t--){
	    scanf("%d",&n);
	    int ar[n],c=0,d=0,p=1;
	    for(int i=0;i<n;i++)scanf("%d",&ar[i]);
	    std::sort(ar,ar+n);
	    for(int i=0;i<n;i++){
	        if(ar[i]!=(i+p) && !d){
	            if(ar[i+1]==i+p){
	                p=0;
	                continue;
	            }
	            d=i+p;
	        }
	        if(ar[i]==ar[i+1] && !c)c=ar[i];
	        if(c && d) break;
	    }
	    printf("%d %d\n",c,d);
	}
	return 0;
}
