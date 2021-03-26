#include <bits/stdc++.h>
 
using namespace std;
 
int main(void){
    int S;
    string N;
    
    cin >> S >> N;
     
    char one_store[23][12];
    char two_store[23][12];
    char three_store[23][12];
    char four_store[23][12];
    char five_store[23][12];
    char six_store[23][12];
    char seven_store[23][12];
    char eight_store[23][12];
    char nine_store[23][12];
    char zero_store[23][12];
    
    for(int i = 0; i < 23; i++){
        for(int j = 0; j < 12; j++){
            zero_store[i][j] = ' ';
            one_store[i][j] = ' ';
            two_store[i][j] = ' ';
            three_store[i][j] = ' ';
            four_store[i][j] = ' ';
            five_store[i][j] = ' ';
            six_store[i][j] = ' ';
            seven_store[i][j] = ' ';
            eight_store[i][j] = ' ';
            nine_store[i][j] = ' ';
        }
    }
 
    for(int i = 0; i < 2 * S + 3; i++){
        if(i % (S + 1) == 0){
            if(i / (S + 1) != 1){
                for(int j = 1; j <= S; j++){
                    zero_store[i][j] = '-';
                }
            }
        } 
        else{
            zero_store[i][0] = '|';
            zero_store[i][S + 1] = '|';
        } 
    }
 
    for(int i = 0; i < 2 * S + 3; i++){
        if(i % (S + 1) != 0){
            one_store[i][S + 1] = '|';
        } 
    }
 
    for(int i = 0; i < 2 * S + 3; i++){
        if(i % (S + 1) == 0){
            for(int j = 1; j <= S; j++){
                two_store[i][j] = '-';
            }
        } 
        else{
            if(i / (S + 1) == 0){
                two_store[i][S + 1] = '|';
            }
            else{
                two_store[i][0] = '|';
            }
        } 
    }
 
    for(int i = 0; i < 2 * S + 3; i++){
        if(i % (S + 1) == 0 ){
            for(int j = 1; j <= S; j++){
                three_store[i][j] = '-';
            }
        } 
        else{
            three_store[i][S + 1] = '|';
        } 
    }
 
    for(int i = 0; i < 2 * S + 3; i++){
        if(i % (S + 1) == 0 ){
            if(i / (S + 1) == 1){
                for(int j = 1; j <= S; j++){
                    four_store[i][j] = '-';
                }
            }
        } 
        else{
            if(i / (S + 1) == 0){
                four_store[i][0] = '|';
                four_store[i][S + 1] = '|';
            }
            else{
                four_store[i][S + 1] = '|';
            }
        } 
    }
 
    for(int i = 0; i < 2 * S + 3; i++){
        if(i % (S + 1) == 0 ){
            for(int j = 1; j <= S; j++){
                five_store[i][j] = '-';
            }
        } 
        else{
            if(i / (S + 1) == 0){
                five_store[i][0] = '|';
            }
            else{
                five_store[i][S + 1] = '|';
            }
        } 
    }
 
    for(int i = 0; i < 2 * S + 3; i++){
        if(i % (S + 1) == 0 ){
            for(int j = 1; j <= S; j++){
                six_store[i][j] = '-';
            }
        } 
        else{
            if(i / (S + 1) == 0){
                six_store[i][0] = '|';
            }
            else{
                six_store[i][0] = '|';
                six_store[i][S + 1] = '|';
            }
        } 
    }
 
    for(int i = 0; i < 2 * S + 3; i++){
        if(i % (S + 1) == 0 ){
            if(i / (S + 1) == 0){
                for(int j = 1; j <= S; j++){
                    seven_store[i][j] = '-';
                }
            }
        } 
        else{
            seven_store[i][S + 1] = '|';
        } 
    }
 
    for(int i = 0; i < 2 * S + 3; i++){
        if(i % (S + 1) == 0 ){
            for(int j = 1; j <= S; j++){
                eight_store[i][j] = '-';
            }
        } 
        else{
            eight_store[i][0] = '|';
            eight_store[i][S + 1] = '|';
        } 
    }
 
    for(int i = 0; i < 2 * S + 3; i++){
        if(i % (S + 1) == 0 ){
            for(int j = 1; j <= S; j++){
                nine_store[i][j] = '-';
            }
        } 
        else{
            if(i / (S + 1) == 0){
                nine_store[i][0] = '|';
                nine_store[i][S + 1] = '|';
            }
            else{
                nine_store[i][S + 1] = '|';
            }
        } 
    }
 
    vector<int> num_store;
    for(int i = 0; i < N.size(); i++){
        num_store.push_back(N[i] - '0');
    }
 
    for(int i = 0; i < 2 * S + 3; i++){
        for(int j = 0; j < num_store.size(); j++){
            if(num_store[j] == 0){
                for(int j = 0; j < S + 2; j++){
                    cout << zero_store[i][j];
                }
            }
            else if(num_store[j] == 1){
                for(int j = 0; j < S + 2; j++){
                    cout << one_store[i][j];
                }
            }
            else if(num_store[j] == 2){
                for(int j = 0; j < S + 2; j++){
                    cout << two_store[i][j];
                }
            }
            else if(num_store[j] == 3){
                for(int j = 0; j < S + 2; j++){
                    cout << three_store[i][j];
                }
            }
            else if(num_store[j] == 4){
                for(int j = 0; j < S + 2; j++){
                    cout << four_store[i][j];
                }
            }
            else if(num_store[j] == 5){
                for(int j = 0; j < S + 2; j++){
                    cout << five_store[i][j];
                }
            }
            else if(num_store[j] == 6){
                for(int j = 0; j < S + 2; j++){
                    cout << six_store[i][j];
                }
            }
            else if(num_store[j] == 7){
                for(int j = 0; j < S + 2; j++){
                    cout << seven_store[i][j];
                }
            }
            else if(num_store[j] == 8){
                for(int j = 0; j < S + 2; j++){
                    cout << eight_store[i][j];
                }
            }
            else if(num_store[j] == 9){
                for(int j = 0; j < S + 2; j++){
                    cout << nine_store[i][j];
                }
            }
 
            if(j == num_store.size() -1){
                cout << "\n";
            }
            else{
                cout << " ";
            }          
        }       
    }
}
