#include <iostream>
#include <cmath>
using namespace std;

bool islog2int(int x) {
    if (x == 0) {
        return 0;
    }
    int a = 0;
    do {
        if (x == pow(2, a)) {
            return 1;
            break;
        }
        a++;
    } while (x >= pow(2, a));
    return 0;
}

int main() {
    string input;
    cin >> input;
    int len = log2(input.length()) + input.length() + 2;

    int data[30];
    for (int i = 0; i < 30; i++) {
        data[i] = 2;
    }
    int counti = 1, countj = 0, log2num = 0;
    for (int i = 1; i < len; i++) {
        if (islog2int(i)) {
            log2num++;
        } else {
            data[counti] = input[countj] - '0';
            countj++;
        }
        counti++;
    }
    
    string binary[len];
    for (int i = 1; i < len; i++) {
        if (data[i] == 1) {
            string ans;
            int a = i;
            for (int j = log2num - 1; j >= 0; j--) {
                if (a - pow(2, j) >= 0) {
                    ans += '1';
                    a -= pow(2, j);
                } else {
                    ans += '0';
                }
            } 
            binary[i] = ans;
        }
    }

    int ed = 0;
    string temp;
    for (int i = 1; i < len; i++) {
        if (data[i] == 1) {
            if (ed) {
                for (int j = 0; j < log2num; j++) {
                    if (binary[i][j] != temp[j]) {
                        temp[j] = '1';
                    } else {
                        temp[j] = '0';
                    }
                }
            } else {
                temp = binary[i];
            }
            ed = 1;            
        }
    }

    int counttemp = 0;
    for (int i = 1; i < len; i++) {
        if (data[i] == 2) {
            cout << temp[counttemp];
            counttemp++;
        } else {
            cout << data[i];
        }
    }
}
