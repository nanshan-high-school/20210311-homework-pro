#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
using namespace std;

int main() {
	string data;
	cin >> data;
	int num[data.length()];
	for(int i = 0; i < data.length(); i++) {
		num[i] = data[i] - '0';
	}
	int a;
	for(int i = 0; pow(2,i) <= data.length(); i++) {
		a = i + 1;
	}

	int board[a + data.length()];
	for(int i = 0; i < a + data.length(); i++) {
		board[i] = -1;
	}
	for(int i = 0; pow(2,i) <= data.length(); i++) {
		int t = pow(2,i);
		board[t - 1] = 2;
	}

	for(int i = 0; i < data.length(); i++) {
		int j = 0;
		while(1){
			if(board[j] == -1) {
				board[j] = num[i];
				break; 
			}
			j++;
		} 
	}

	vector<int> binary;
	for(int i = 0; i <  a + data.length(); i++) {
		if(board[i] == 1) {
			binary.push_back(i + 1);
		}
	}
	int temp = 0;
	for(int i = 0; i < binary.size(); i++) {
		temp = temp xor binary[i];
	}
	stack<int> res;
	while(temp != 0) {
		res.push(temp % 2);
		temp /= 2; 
	}
	if(a + data.length() > pow(2,res.size())) {
		while(a + data.length() > pow(2,res.size())) {
			res.push(0);
		}
	}

	for(int i = 0; i <  a + data.length(); i++) {
		if (board[i] == 2) {
			cout << res.top();
			res.pop();	
		} else {
			cout << board[i];
		}
	
	}
}
