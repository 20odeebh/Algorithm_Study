#include <iostream>

using namespace std;

long long m[100];

int main(){
    int N;
    cin >> N;
    m[0] =1; 
    m[1] = 1;
 
    for (int i = 2; i < N; i++)
        m[i] = m[i - 1] + m[i - 2];
    
    cout << m[N-1] << endl;
}
