#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#define ll long long

bool cmp(std::pair<ll, ll> p1, std::pair<ll, ll> p2) {
    return p1.first >= p2.first;
}
int main() {
    int test;
    std::string out;
    ll n, x, y;
    std::cin >>  test;
    std::default_random_engine generator;

    if (test == 1) {
        std::uniform_int_distribution<int> distribution(1, 10e6);
        n = 5000;
        out += std::to_string(n) + ".i";
        freopen(out.c_str(), "w", stdout);
        std::cout << n << '\n';

        y = distribution(generator);
        for (auto i = 0; i < n; i++) {
            x = distribution(generator);
            std::cout << x << ' ' <<  y << '\n';
        }
    }

    if (test == 2) {
        n = 20;
        out += std::to_string(n) + ".i";
        freopen(out.c_str(), "w", stdout);
        std::cout << n << '\n';

        std::uniform_int_distribution<int> distribution(1, 10e4);
        x = distribution(generator);
        y = distribution(generator);

        for (auto i = 0; i < n; i++) std::cout << x << ' ' << y << '\n';
    }

    if (test == 3) {
        n = 30000;
        out += std::to_string(n) + ".i";
        freopen(out.c_str(), "w", stdout);
        std::cout << n << '\n';

        std::vector<std::pair<ll, ll>> a(n);
        std::uniform_int_distribution<int> distribution(1, 10e6);
        for (auto i = 0; i < n; i++) {
            x = distribution(generator);
            y = distribution(generator);
            a[0] = {x, y}; 
        }

        std::sort(a.begin(), a.end(), cmp);
        for (auto i: a) std::cout << i.first << ' ' << i.second << '\n';
    }

    if (test == 4) {
        std::uniform_int_distribution<int> distribution1(3000, 5000);
        for (int i = 0; i < 5; i++) {
            std::uniform_int_distribution<int> distribution(1, 10e6);
            n = distribution1(generator);
            out.clear();
            out += std::to_string(n) + ".i";
            freopen(out.c_str(), "w", stdout);
            std::cout << n << '\n';
            for (auto j = 0; j < n; j++) {
                x = distribution(generator);
                y = distribution(generator);
                std::cout << x << ' ' << y << '\n';
            }
        }
    }

    if (test == 5) {
        std::uniform_int_distribution<int> distribution1(6000, 10000);
        for (int i = 0; i < 5; i++) {
            std::uniform_int_distribution<int> distribution(1, 10e6);
            n = distribution1(generator);
            out.clear();
            out += std::to_string(n) + ".i";
            freopen(out.c_str(), "w", stdout);
            std::cout << n << '\n';
            for (auto j = 0; j < n; j++) {
                x = distribution(generator);
                y = distribution(generator);
                std::cout << x << ' ' << y << '\n';
            }
        }
    }

    if (test == 6) {
        std::uniform_int_distribution<int> distribution1(10000, 29999);
        for (int i = 0; i < 10; i++) {
            std::uniform_int_distribution<int> distribution(1, 10e6);
            n = distribution1(generator);
            out.clear();
            out += std::to_string(n) + ".i";
            freopen(out.c_str(), "w", stdout);
            std::cout << n << '\n';
            for (auto j = 0; j < n; j++) {
                x = distribution(generator);
                y = distribution(generator);
                std::cout << x << ' ' << y << '\n';
            }
        }
    }

    return 0;
}
