#include <iostream>
#include <cstdlib>
#include <cstdio>
#define MAX_N 4005
#define MAX_K 805
#define INFTY 100000000

int Cost[MAX_K][MAX_N]; // Cost[i][j]: Chi phi de xep j nguoi vao i hang dau tien (Output)
int A[MAX_N][MAX_N];    // A[i][j]: muc do ghet nhau cua nguoi i va nguoi j  (Input)
int D[MAX_N][MAX_N];    // D[i][j]: Chi phi de xep tu nguoi i den j vao mot hang
int B[MAX_N][MAX_N];    // Su dung trong tinh B
int n, k;               // So nguoi, so hang

/*bruteforce */

void computer_dissimilarity() { // Tinh D
    for (int d = 1; d < n; d++) {
        for (int i = 0; i < n - d; i++) {
            B[i][i+d] = B[i+1][i+d] + A[i][i+d];
            D[i][i+d] = D[i][i+d-1] + B[i][i+d];
        }
    }
}

// Tinh toan C[i][j] va R[i][j] biet R[i][j] nam trong khoang left right
int find_Rij(int i, int j, int left, int right) {
    int temp = INFTY;
    int p;
    for (int l = left; l <= right; l++) {
        if (temp > Cost[i-1][l-1] + D[l][j]) {
            temp = Cost[i-1][l-1] + D[l][j];
            p = l;
        }
    }

    Cost[i][j] = temp;

    return p;
}

// Tinh C[i, x], C[i, x+1], ..., C[i][y] biet cac diem chia toi uu nam trong khoang left, right
void dac_dynamic(int i, int x, int y, int left, int right) {
    if (y < x) return;
    else if (y == x) {
        find_Rij(i, x, left, right);
    } else {
        int m = (x + y) / 2;
        int R = find_Rij(i, m, left, right);
        dac_dynamic(i, x, m-1, left, R);
        dac_dynamic(i, m+1, y, R, right);
    }
}

int solve() {
    computer_dissimilarity();

    for (int j = 0; j < n; j++) {
        Cost[0][j] = D[0][j];
    }

    for (int i = 1; i < k; i++) {
        int R = find_Rij(i, n-1, i, n-1);
        dac_dynamic(i, i+1, n-2, i, R);
    }
    return Cost[k-1][n-1];
}

int main() {
    std::cin >> n >> k;
	char c;
	for(int i = 0 ; i < n; i++){
		for(int j = 0; j < n ; j ++){
			c = getchar();
			while(c < '0' || c > '9')
			     c = getchar();
			A[i][j] = c - '0';
		}
	}

    std::cout << solve();
    return EXIT_SUCCESS;
}
