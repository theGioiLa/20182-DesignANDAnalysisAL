#include <iostream>
#include <vector>
#include <memory.h>
#define MAX_N 4005
#define MAX_K 805

int Cost[MAX_N][MAX_N]; // Cost[i][j]: Chi phi de xep j nguoi vao i hang dau tien (Output)
int U[MAX_N][MAX_N];    // U[i][j]: muc do ghet nhau cua nguoi i va nguoi j  (Input)
int D[MAX_N][MAX_N];    // D[i][j]: Chi phi de xep tu nguoi i den j vao mot hang
int B[MAX_N][MAX_N];    // Su dung trong tinh B
int n, k;               // So nguoi, so hang

/*bruteforce */

void computer_dissimilarity() { // Tinh D
    for (int d = 1; d < n; d++) {
        for (int i = 0; i < n - d; i++) {
            B[i][i+d] = B[i+1][i+d] + U[i][i+d];
            D[i][i+d] = D[i][i+d-1] + B[i][i+d];
        }
    }
}

int solve() {
    computer_dissimilarity();
    int tmp;
    for (int j = 0; j < n; j++) Cost[0][j] = D[0][j];
    for (int i = 1; i < k; i++) {   // Tinh hang C[i]
        for (int j = i+1; j < n; j++) {
           tmp = MAX_N; 
           for (int l = i; l <=j; l++) 
               tmp = std::min(tmp, Cost[i-1][l] + D[l+1][j]);
           Cost[i][j] = tmp;
        }
    }
    return Cost[k-1][n-1];
}

int main() {
    std::cin >> n >> k;
    for (int i = 0; i < n; i++)  {
        for (int j = 0; j < n; j++) {
            std::cin >> U[i][j];
        }
    }

    std::cout << solve();
    return EXIT_SUCCESS;
}
