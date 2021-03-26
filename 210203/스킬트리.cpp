#include <string>
#include <vector>

using namespace std;
//지금 문자가 문자열의 몇 번째와 일치하는 지 리턴 일치하는 게 없으면 -1 리턴
int cmp(char a, string b){
    for(int i=0;i<b.size();i++){
        if(a == b[i]) return i;
    }
    return -1;
}

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
        
    for(int j=0;j<skill_trees.size();j++){
        int pre = -1;
         for(int i=0;i<skill_trees[j].size();i++){
            int result=cmp(skill_trees[j][i],skill);
			//일치하는 게 없거나 전의 문자보다 
            if(result == -1 || pre+1 == result){
                if(result != -1) pre=result;
            }
            else{
                answer++;
                break;
            }            
        }
    }
   
    return skill_trees.size()-answer;
}