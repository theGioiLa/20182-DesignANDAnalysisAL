#include <iostream>
#include <string>
#include <random>

char B[4000][4000];

int main() {
    int test;
    std::cin >> test;
    std::default_random_engine generator;

    int n, k;
    std::string out;

    if (test == 1) {
        std::uniform_int_distribution<int> dist_n(10, 50);
        n = dist_n(generator);
        k = n+1;

        out += std::to_string(n) + '_' + std::to_string(k) + ".i";
        freopen(out.c_str(), "w", stdout);
        
        std::cout << n << ' ' << k << '\n';
        std::uniform_int_distribution<int> dist_B(1, 9);
        
        for (auto i = 0; i < n; i++) {
            B[i][i] = 0;
            for (auto j = i+1; j < n; j++) {
                B[i][j] = dist_B(generator);
                B[j][i] = B[i][j];
            }
        }

        for (auto i = 0; i < n; i++) {
            for (auto j = 0; j < n; j++) std::cout << (int)B[i][j] << ' ';
            std::cout << '\n';
        }
    }

    if (test == 2) {
        for (auto t = 0; t < 5; t++) {
            std::uniform_int_distribution<int> dist_n(100, 500);
            n = dist_n(generator);

            std::uniform_int_distribution<int> dist_k(1, 20);
            k = dist_k(generator);

            out.clear();
            out += std::to_string(n) + '_' + std::to_string(k) + ".i";
            freopen(out.c_str(), "w", stdout);
            
            std::cout << n << ' ' << k << '\n';
            std::uniform_int_distribution<int> dist_B(1, 9);
            
            for (auto i = 0; i < n; i++) {
                B[i][i] = 0;
                for (auto j = i+1; j < n; j++) {
                    B[i][j] = dist_B(generator);
                    B[j][i] = B[i][j];
                }
            }

            for (auto i = 0; i < n; i++) {
                for (auto j = 0; j < n; j++) std::cout << (int)B[i][j] << ' ';
                std::cout << '\n';
            }
        }
    }

    if (test == 3) {
        for (auto t = 0; t < 5; t++) {
            std::uniform_int_distribution<int> dist_n(300, 500);
            n = dist_n(generator);

            std::uniform_int_distribution<int> dist_k(100, n/2);
            k = dist_k(generator);

            out.clear();
            out += std::to_string(n) + '_' + std::to_string(k) + ".i";
            freopen(out.c_str(), "w", stdout);
            
            std::cout << n << ' ' << k << '\n';
            std::uniform_int_distribution<int> dist_B(1, 9);
            
            for (auto i = 0; i < n; i++) {
                B[i][i] = 0;
                for (auto j = i+1; j < n; j++) {
                    B[i][j] = dist_B(generator);
                    B[j][i] = B[i][j];
                }
            }

            for (auto i = 0; i < n; i++) {
                for (auto j = 0; j < n; j++) std::cout << (int)B[i][j] << ' ';
                std::cout << '\n';
            }
        }
    }

    if (test == 4) {
        for (auto t = 0; t < 5; t++) {
            std::uniform_int_distribution<int> dist_n(1000, 2000);
            n = dist_n(generator);

            std::uniform_int_distribution<int> dist_k(1, 200);
            k = dist_k(generator);

            out.clear();
            out += std::to_string(n) + '_' + std::to_string(k) + ".i";
            freopen(out.c_str(), "w", stdout);
            
            std::cout << n << ' ' << k << '\n';
            std::uniform_int_distribution<int> dist_B(1, 9);
            
            for (auto i = 0; i < n; i++) {
                B[i][i] = 0;
                for (auto j = i+1; j < n; j++) {
                    B[i][j] = dist_B(generator);
                    B[j][i] = B[i][j];
                }
            }

            for (auto i = 0; i < n; i++) {
                for (auto j = 0; j < n; j++) std::cout << (int)B[i][j] << ' ';
                std::cout << '\n';
            }
        }
    }

    if (test == 5) {
        for (auto t = 0; t < 5; t++) {
            std::uniform_int_distribution<int> dist_n(2000, 3999);
            n = dist_n(generator);

            std::uniform_int_distribution<int> dist_k(200, 800);
            k = dist_k(generator);

            out.clear();
            out += std::to_string(n) + '_' + std::to_string(k) + ".i";
            freopen(out.c_str(), "w", stdout);
            
            std::cout << n << ' ' << k << '\n';
            std::uniform_int_distribution<int> dist_B(1, 9);
            
            for (auto i = 0; i < n; i++) {
                B[i][i] = 0;
                for (auto j = i+1; j < n; j++) {
                    B[i][j] = dist_B(generator);
                    B[j][i] = B[i][j];
                }
            }

            for (auto i = 0; i < n; i++) {
                for (auto j = 0; j < n; j++) std::cout << (int)B[i][j] << ' ';
                std::cout << '\n';
            }
        }
    }


    if (test == 6) {
        n = 4000;

        std::uniform_int_distribution<int> dist_k(1, 100);
        k = dist_k(generator);

        out.clear();
        out += std::to_string(n) + '_' + std::to_string(k) + ".i";
        freopen(out.c_str(), "w", stdout);
        
        std::cout << n << ' ' << k << '\n';
        std::uniform_int_distribution<int> dist_B(1, 9);
        
        for (auto i = 0; i < n; i++) {
            B[i][i] = 0;
            for (auto j = i+1; j < n; j++) {
                B[i][j] = dist_B(generator);
                B[j][i] = B[i][j];
            }
        }

        for (auto i = 0; i < n; i++) {
            for (auto j = 0; j < n; j++) std::cout << (int)B[i][j] << ' ';
            std::cout << '\n';
        }
    }

    if (test == 7) {
        n = 4000;

        std::uniform_int_distribution<int> dist_k(500, 800);
        k = dist_k(generator);

        out.clear();
        out += std::to_string(n) + '_' + std::to_string(k) + ".i";
        freopen(out.c_str(), "w", stdout);
        
        std::cout << n << ' ' << k << '\n';
        std::uniform_int_distribution<int> dist_B(1, 9);
        
        for (auto i = 0; i < n; i++) {
            B[i][i] = 0;
            for (auto j = i+1; j < n; j++) {
                B[i][j] = dist_B(generator);
                B[j][i] = B[i][j];
            }
        }

        for (auto i = 0; i < n; i++) {
            for (auto j = 0; j < n; j++) std::cout << (int)B[i][j] << ' ';
            std::cout << '\n';
        }
    }

    return 0;
}
