#include <iostream>

using namespace std;

int MaxNum(int *a,int n){
    int b=0,maxN=0;
    for(int i=0;i<n;i++){
        if(b<=0)
            b=a[i];
        else
            b+=a[i];

        if(b>maxN){
            maxN=b;
        }
    }
    return maxN;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int m=MaxNum(a,n); 
    cout<<m;
    return 0;
}
