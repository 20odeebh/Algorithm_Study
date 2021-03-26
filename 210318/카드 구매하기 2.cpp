#include <vector>
#include <iostream>

using namespace std;
int n;

int main(){
    
    cin>>n;
    vector<int> a(n+1);
    
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    
    vector<int> b(n+1);
    for(int i=1; i<=n; i++){
        b[i]=-1;  
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            if (b[i]==-1 || b[i]>b[i-j]+a[j]){
                b[i]=b[i-j]+a[j];
            }
        }
    }
    cout<<b[n]<<"\n";
}
