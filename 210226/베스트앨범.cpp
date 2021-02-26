#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;
typedef struct Node {
	string genre;
	int play;
	int uniqueNum;
};
map<string, int> music;
bool cmp(Node& n1, Node& n2)
{
	if (music[n1.genre] == music[n2.genre]) {
		if (n1.play == n2.play) {
			return n1.uniqueNum < n2.uniqueNum;
		}
		else {
			return n1.play > n2.play;
		}
	}
	else {
		return music[n1.genre] > music[n2.genre];
	}
}
vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	vector<Node> v;
	for (int i = 0; i < plays.size(); i++) {
		music[genres[i]] += plays[i];
		Node n;
		n.genre = genres[i];
		n.play = plays[i];
		n.uniqueNum = i;
		v.push_back(n);
	}
	sort(v.begin(), v.end(), cmp);
	map<string, int> best;
	for (const auto& i : v) {
		if (best[i.genre] < 2) {
			best[i.genre]++;
			answer.push_back(i.uniqueNum);
		}
	}
	return answer;
}