#include <iostream>
#include <cmath>
#include <stack>
#include <cstring>


using namespace std;

int main() {
	string num;
	cin >> num;

	int a = 0, b = 0;
	for (int i = 0; num[i] != '\0'; i++) a++;
	for (int i = 0; pow(2, i) <= a; i++) b++;

	int data[a + b];
	memset(data, 0, sizeof(data));

	int c = 0, p = 0;
	for (int i = 0; i < a + b; i++) {
		if (i + 1 == pow(2, p)) {
			p++;
			continue;
		} else {
			data[i] = num[c] - '0';
			c++;
		}
	}

	int q = 0;
	int binary[a][b];
	int result[b];

	memset(binary, 0, sizeof(binary));

	for (int i = 0; i < a + b; i++) {
		int x = i + 1;
		if (data[i] == 1) {
			for (int j = b - 1; j >= 0; j--) {
				binary[q][j] = x % 2;
				x /= 2;
			}

			q++;
		}
	}

	for (int i = 0, j = 1; i < q; i++, j++) {
		for (int h = 0; h < b; h++) {
			if (binary[i][h] != binary[j][h]) {
				result[b - h - 1] = 1;
			} else result[b - h - 1] = 0;
		}
	}
	
	for (int i = 0, x = 0; i < a + b; i++) {
		if (i + 1 == pow(2, x)) {
			data[i] = result[x];
			x++;
		} else continue;
	}

	for (int i = 0; i < a + b; i++) cout << data[i];
}
