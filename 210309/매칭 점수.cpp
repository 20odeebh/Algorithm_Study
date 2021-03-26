#include <bits/stdc++.h>

using namespace std;

char ifUpperSwapLower(char c) {
	return 'A' <= c && c <= 'Z' ? c - 'A' + 'a' : c;
}

int solution(string word, vector<string> pages) {
	
	for (int i = 0; i < word.size(); i++) {
		word[i] = ifUpperSwapLower(word[i]);
	}

	int N = pages.size();
	unordered_map<string, int> linkAndWebIndexMap; 
	vector<pair<int, vector<string>>> web(N, { 0, vector<string>() });
	for (int i = 0; i < N; i++) {
		string html = pages[i];
		int j = 0;		

		string nowLink = "";
		int ind = 0;
		while (nowLink == "") {
			
			ind = html.find("<meta") + 5;
			int last = html.substr(ind).find(">");
			html = html.substr(ind);
			ind = html.find("https://");
            
			if (last < ind)
				continue;
            
			while (html[ind] != '\"') {
				nowLink += html[ind++];
			}
			linkAndWebIndexMap[nowLink] = i;
		}

		int startBodyInd = html.find("<body>") + 6;
		int lastBodyInd = html.find("</body>");

		string tmp = "";
		bool nowInBracket = false;
		for (int j = startBodyInd; j < lastBodyInd; j++) {
			char nowC = ifUpperSwapLower(html[j]);
			if (nowInBracket) {
				if (nowC == '>')
					nowInBracket = false;
			} else if (nowC == ' ' || !('a'<=nowC && nowC <= 'z')) {
				if(tmp != "" && tmp == word)
					web[i].first++; 
				tmp = "";
				if (nowC == '<')
					nowInBracket = true;
			}
			else {
				tmp += nowC;
			}
		}
		if (tmp != "" && tmp == word)
			web[i].first++; 

		tmp = html.substr(startBodyInd);
		ind = tmp.find("<a href");
		while (ind != string::npos) {
			tmp = tmp.substr(ind + 7);
			tmp = tmp.substr(tmp.find("https://"));
			web[i].second.push_back(tmp.substr(0, tmp.find("\"")));
			ind = tmp.find("<a href");
		}
	}
	
	vector<double> matchingScore(N, 0);
	for (int i=0;i<N;i++) {
		matchingScore[i] += web[i].first;
		double linkScore = 0;
		if (web[i].second.size() != 0)
			linkScore = (double)web[i].first / (double)web[i].second.size();
		for (int j = 0; j < web[i].second.size(); j++) {
			if(linkAndWebIndexMap.find(web[i].second[j])!=linkAndWebIndexMap.end()){
			int linkInd = linkAndWebIndexMap[web[i].second[j]];
			matchingScore[linkInd] += linkScore;
			}
		}
	}

	int answer = 0;
	for (int i = 0; i < N; i++) {
		if(matchingScore[answer] < matchingScore[i]){
			answer = i;
		}
	}

	return answer;
}