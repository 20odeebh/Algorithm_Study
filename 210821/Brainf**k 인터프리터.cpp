#include <bits/stdc++.h>

using namespace std;

const int DATA_MAX = 1e5 + 100;

int main(){
	int T;
	cin >> T;

	for (int t = 0; t < T; t++){
		int m, c, si;
		cin >> m >> c >> si;

		string program, input;
		cin >> program >> input;

		int datas[DATA_MAX] = { 0, };
		map<int, int> loopPair;

		vector<int> v;

		for (int i = 0; i < program.length(); i++)
		{
			if (program[i] == '['){
				v.push_back(i);
			}
			else if (program[i] == ']')
			{
				int temp = v.size() - 1;
				loopPair[v[temp]] = i;
				loopPair[i] = v[temp];
				v.pop_back();
			}
		}

		int idx = 0, programIdx = 0, inputIdx = 0, loopStartIdx = 987654321;
		bool isTerminated = true;

		for (int i = 0; i < program.length(); i++){
			switch (program[i]){
			case '+':
				datas[idx] = (datas[idx] + 1) % 256;
				break;
				
			case '-':
				datas[idx] = (datas[idx] + 256 - 1) % 256;
				break;
	
			case '>':
				idx = (idx + 1) % m;
				break;
			
			case '<':
				idx = (idx + m - 1) % m;
				break;
						
			case ']':
				if (datas[idx]){
					i = loopPair[i];
				}
				break;
			case '[':
				if (datas[idx] == 0){
					i = loopPair[i];
				}
				break;
			
			case '.':
				break;
				
			case ',':
				datas[idx] = (inputIdx == si) ? 256 - 1 : (int)input[inputIdx++];
				break;
			}

			if (++programIdx > 5 * 1e7){
				loopStartIdx = min(loopStartIdx, i);
			}

			if (programIdx > 5 * 1e7 * 2){
				isTerminated = false;
				break;
			}
		}

		if (isTerminated == false){
			cout << "Loops " << loopStartIdx << " " << loopPair[loopStartIdx] << "\n";
		}
		else{
			cout << "Terminates\n";
		}
	}
}
