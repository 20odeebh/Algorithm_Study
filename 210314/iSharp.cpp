#include <bits/stdc++.h>

using namespace std;

string type,str,temp,val;
int main() {
   
    cin >> type;
    cin.ignore();
    
    getline(cin, str);
    
    for(int i = 0; i < str.size(); i++) {
        char c = str[i];
        if(c == ' ') continue;
        if(c == ',' || c == ';') {
            reverse(temp.begin(), temp.end());
            for(int j = 0; j < temp.size(); j++) {
                if(temp[j] == '[') {
                    temp[j] = ']';
                } else if(temp[j] == ']') {
                    temp[j] = '[';
                }
            }
            cout << type << temp << ' ' << val << ";\n";
            temp = "";
            val = "";
            continue;
        }

        if(isalpha(c)) {
            val += c;
        } else {
            temp += c;
        }
    }
}
