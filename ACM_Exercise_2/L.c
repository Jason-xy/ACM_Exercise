#include<iostream>
using namespace std;
int main(){
    int T;
    cin>>T;
    while (T--){
        int n,F;
        cin>>n>>F;
        int sum=0;
        for(int i=n;i>1;i--){
            sum=sum+(2*i-1)*(n-i+1);
        }
        int last;
        if(sum+n>F) cout<<"-1"<<endl;
        else{
            last=F-sum;
            for(int i=1;i<n;i++){
            	cout<<i<<" ";
			}        
            cout<<last<<endl;
        }
    }
    return 0;
}