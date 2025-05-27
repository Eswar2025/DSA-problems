#include <iostream>

using namespace std;

int maxi(int arr[],int k){
    int m=0,x=1;
    for(int i=1;i<k;i++){
        m=0;
        for(int j=0;j<i;j++){
            if(arr[j]>=arr[i]){
                m++;
            }
        }
        if(m==i){
            x++;
        }
    }
   return x;
}
int main()  {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int x=0;x<n;x++){
            cin>>a[x];
        }
        
        cout<<maxi(a,n)<<endl;
    }
    return 0;  
} 