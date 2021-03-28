#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int N;
struct Node {
	string str;
	int len;
};
bool cmp(Node& n1, Node& n2)
{
	return n1.len < n2.len;
}
int main()
{
	cin >> N;
	Node n;
	vector<Node> v;
	for (int i = 0; i < N; i++) {
		cin >> n.str;
		n.len = n.str.length();
		v.push_back(n);
	}
	sort(v.begin(), v.end(), cmp);
	int answer = N;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (v[j].str.find(v[i].str) == 0) {
				answer--;
				break;
			}
		}
	}
	printf("%d\n", answer);
	return 0;
}