#include <string>
#include <vector>

using namespace std;

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	int key_size = key.size();
    int lock_size = lock.size();
    
    
    int arr_lock[20][20] = {};
    for(int i=0; i<lock_size; i++){
        for(int j=0; j<lock_size; j++){
            arr_lock[i][j] = lock[i][j];
        }
    }
    int arr_key[20][20] = {};
    for(int i=0; i<key_size; i++){
        for(int j=0; j<key_size; j++){
            arr_key[i][j] = key[i][j];
        }
    }
    
    for(int j=0; j<=3; j++){
        if(j != 0){
            for(int a =0; a<key_size; a++){
                for(int b=0; b <key_size; b++){
                    arr_key[b][key_size-1-a] = key[a][b];
                }
            }
            for(int a=0; a<key_size; a++){
                for(int b=0; b<key_size; b++){
                    key[a][b] = arr_key[a][b];
                }
            }
        }
            
        for(int s_i= -key_size+1; s_i<lock_size; s_i++){
            for(int s_j= -key_size+1 ; s_j<lock_size; s_j++){
                    
                int arr[20][20] = {0,};
                for(int a=0; a<lock_size; a++){
                    for(int b=0; b<lock_size; b++){
                        arr[a][b] = lock[a][b];
                    }
                }
       
                for(int a=0; a<key_size; a++){
                    for(int b=0; b<key_size; b++){
                        if(a+s_i>=0&&a+s_i<20&&b+s_j>=0&&b+s_j<20){
                            arr[a+s_i][b+s_j] += key[a][b];
                        }
                    }
                }
      
                int check=1;
                for(int a=0; a<lock_size; a++){
                    for(int b=0; b<lock_size; b++){
                        check = check*arr[a][b];
                    }
                }
                if(check==1){ return true; }
            }
        }
    }
    return false;
}