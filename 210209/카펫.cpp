#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    for(int h=3;;h++){
        if( (brown + yellow) % h) continue;        
        int w = (brown + yellow)/h;
        if(yellow == (w-2)*(h-2)){
            answer.push_back(w);
            answer.push_back(h);
            break;
        }
    }
    return answer;
}