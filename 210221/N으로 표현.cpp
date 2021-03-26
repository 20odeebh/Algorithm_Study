#include <bits/stdc++.h>

using namespace std;

int solution(int N, int number) {
	
	int answer = 0;
	int base = 0;

	unordered_set<int> numbers[8];

	for (int i = 0; i < 8; i++) { 
		base = 10 * base + 1; 
		numbers[i].insert(base * N); 
	}

	for (int i = 1; i < 8; i++) {
		for (int j = 0; j < i; j++) {
			for (auto op1 : numbers[j]) {
				for (auto op2 : numbers[i - j - 1]) {
					numbers[i].insert(op1 + op2); 
					numbers[i].insert(op1 - op2); 
					numbers[i].insert(op1 * op2); 
					if (op2 != 0) { numbers[i].insert(op1 / op2); } 
				}
			}
		}
		if (numbers[i].count(number) > 0) { answer = i + 1; break; }
	}
	return answer;
}