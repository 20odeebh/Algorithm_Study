#include <iostream>

using namespace std;

int h, w, result, arr[501];

int main() {
	cin >> h >> w;
	
	for (int i = 1; i <= w; i++){
		cin >> arr[i];
	}
	
	for (int i = 1; i <= h; i++) {
		for (int j = 2; j <= w - 1; j++) {
			if (arr[j] >= i) continue;

			bool l = false, r = false;
			
			for (int k = j - 1; k >= 1; k--) {
				if (arr[k] >= i){
					l = true;
					break;
				}
			}
		
			for (int k = j + 1; k <= w; k++) {
				if (arr[k] >= i){
					r = true;
					break;
				}
			}

			if (l == true && r == true) result++;
		}
	}

	cout << result;
}
