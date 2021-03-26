#include <string>
using namespace std;
 
int solution(string name) {
    int answer = 0;
    string init = "";
    for(int i=0; i<name.size(); i++) init += "A";
 
    int cur = 0;
    while(name != init) {
        int left = 0, right = 0, minStep = name.size(), minIdx = 0;
        for(int i=0; i<name.size(); i++) {
            if(name[i] == init[i]) continue;
 
            if(cur > i) {
                right = name.size() - cur + i;
                left = cur - i;
                
            } else {
                right = i - cur;
                left = cur + name.size() - i;
                
            }
 
            if(left < minStep || right < minStep) {
                minStep = min(left, right);
                minIdx = i;
            }
        }
 
        cur = minIdx;
        answer += minStep;
        answer += min(name[cur] - 'A', 'Z' - name[cur] + 1);
        init[cur] = name[cur];
    }
 
    return answer;
}
