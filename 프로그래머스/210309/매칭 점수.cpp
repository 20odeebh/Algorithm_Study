#include <bits/stdc++.h>
using namespace std;
//좌홍님 소스로 공부
bool wordChange(char c) {
	return c == '\'' || !isalpha(c);
}

bool comp(pair<double, int> a, pair<double, int> b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first > b.first;
}
int solution(string word, vector<string> pages) {
	transform(word.begin(), word.end(), word.begin(), ::tolower);
	map<string, int> urlName;
	vector<vector<string>> links;
	vector<int> basicScore;
	vector<pair<double, int>> matchScore;

	for (int i = 0; i < pages.size(); i++) {
		transform(pages[i].begin(), pages[i].end(), pages[i].begin(), ::tolower);

		string content = "<meta property=\"og:url\" content=\"https://";
		int contentPos = pages[i].find(content);
		int contentStart = contentPos + content.size();
		int contentEnd = pages[i].substr(contentStart).find("\"/>");
		urlName[pages[i].substr(contentStart, contentEnd)] = i + 1;
		//주소 코드
		//cout<<contentStart<<' '<<contentEnd<<'\n';
		//cout<<pages[i].substr(contentStart, contentEnd)<<'\n';

		int bodyStartIdx = pages[i].find("<body>");
		int bodyEndIdx = pages[i].find("</body>");
		string bodyPage = pages[i].substr(bodyStartIdx, bodyEndIdx - bodyStartIdx);

		vector<string> link;
		string href = "<a href=\"https://";
		int hrefPos = bodyPage.find(href);
		//외부 링크 세는 갯수
		while (hrefPos != std::string::npos)
		{
			int hrefStart = hrefPos + href.size();
			int hrefEnd = bodyPage.substr(hrefStart).find("\">");
			link.push_back(bodyPage.substr(hrefStart, hrefEnd));
			hrefPos = bodyPage.find(href, hrefStart + hrefEnd);
		}

		links.push_back(link);
		replace_if(bodyPage.begin(), bodyPage.end(), wordChange, ' ');
		int score = 0;
		//??
		istringstream iss(bodyPage);
		//cout<<bodyPage<<'\n';
		string token;
		while (getline(iss, token, ' ')) {
			if (word.compare(token) == 0)
				score++;
		}
		basicScore.push_back(score);
	}

	for (int i = 0; i < links.size(); i++) {
		matchScore.push_back(make_pair(basicScore[i], i));
	}

	for (int i = 0; i < links.size(); i++) {
		int linkSize = links[i].size();
		for (int j = 0; j < linkSize; j++) {
			if (urlName[links[i][j]] != 0) {
				matchScore[urlName[links[i][j]] - 1].first += (double)basicScore[i] / (double)linkSize;
			}
		}

	}

	sort(matchScore.begin(), matchScore.end(), comp);
	return matchScore[0].second;
}