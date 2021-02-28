#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
	vector<long long> v;

	for (int i = 0; i < n; i++) {
		if (v.size() < 3) v.push_back(i + 1);
		else v.push_back((v[i - 1] % 1234567) + (v[i - 2] % 1234567));
	}
	return (v.back()) % 1234567;
}