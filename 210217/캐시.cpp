#include <bits/stdc++.h>

 

using namespace std;

 

string lowercase(string str) {

    for (int i = 0; i < str.size(); i++) {

        if (str[i] >= 'A' && str[i] <= 'Z')

            str[i] += 32;

    }

 

    return str;

}

 

int solution(int cacheSize, vector<string> cities) {

    int answer = 0;

    deque<string> deq;

 

    if (cacheSize == 0)

        return cities.size() * 5;

 

    for (int i = 0; i < cities.size(); i++) {

        cities[i] = lowercase(cities[i]);

 

        bool check = false;

        for (deque<string>::iterator it = deq.begin(); it != deq.end(); it++) {

            if (cities[i].compare(*it) == 0) {

                deq.erase(it);

                deq.push_back(cities[i]);

                answer += 1;

                check = true;

                break;

            }

        }

 

        if (!check) {

            if (deq.size() == cacheSize)

                deq.pop_front();

            deq.push_back(cities[i]);

            answer += 5;

        }

    }

 

    return answer;

}