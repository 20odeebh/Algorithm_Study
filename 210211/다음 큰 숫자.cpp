#include <string>
#include <vector>

using namespace std;

int count(int n){
    int cnt=0;
    while(n){
        if(n%2) cnt++;
        n/=2;
    }
    return cnt;
}

int solution(int n) {
    int answer = 0;
    
    int cnt = count(n);
    
    for(int i=n+1;;i++){
        if(count(i) == cnt) return i;
    }

}
