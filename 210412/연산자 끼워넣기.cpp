#include <iostream>
#include <algorithm>

using namespace std;

int N, number[12], Operator[4], maxResult = -1000000001, minResult = 1000000001;

void dfs(int plus, int minus, int multiply, int divide, int cnt, int sum){
        if (cnt == N){
                 maxResult = max(maxResult, sum);
                 minResult = min(minResult, sum);
        }

        if (plus > 0) dfs(plus - 1, minus, multiply, divide, cnt + 1, sum + number[cnt]);

        if (minus > 0) dfs(plus, minus - 1, multiply, divide, cnt + 1, sum - number[cnt]);

        if (multiply > 0) dfs(plus, minus, multiply - 1, divide, cnt + 1, sum * number[cnt]);

        if (divide > 0) dfs(plus, minus, multiply, divide - 1, cnt + 1, sum / number[cnt]);
}

int main(){
        cin >> N;

        for (int i = 0; i < N; i++){
			  cin >> number[i];
		    }

        for (int i = 0; i < 4; i++){
            cin >> Operator[i];
		    }
 
        dfs(Operator[0], Operator[1], Operator[2], Operator[3], 1, number[0]);

        cout << maxResult << "\n" << minResult << "\n";
}
