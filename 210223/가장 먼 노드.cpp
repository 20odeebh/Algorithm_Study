#include <string>
#include <vector>

using namespace std;
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
	
	vector<bool> b(n + 1);
    vector<vector<int>> a(n + 1), c;
    
    for (auto i : edge) {
        a[i[0]].push_back(i[1]);
        a[i[1]].push_back(i[0]);
    }
	
    c.push_back({ 1 });
    b[1] = true;
	
   while (true) {
       vector<int> v;
	   
       for (auto i : c.back())
           for (auto t : a[i])
		   
                if (!b[t]) {
                    v.push_back(t);
                    b[t] = true;
                }
				
       if(v.empty()) break;
       c.push_back(v);
   }
   
    return c.back().size();
}