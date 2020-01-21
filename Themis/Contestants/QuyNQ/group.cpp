#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

#define X first
#define Y second 
#define left first
#define right second 
#define ll long long
#define INF 10e10
#define MAX_N 300005

typedef std::pair<ll, ll> Line;
typedef std::pair<ll, ll> Interval;

ll n; // so luong nhom
std::pair<ll, ll> A[MAX_N]; // A - input
std::vector<std::pair<ll, ll> > B;// B - input da sx va loai bo du thua

ll C[MAX_N]; // Ham chi phi

Interval I[MAX_N]; // Mang Interval
ll ALine[MAX_N];   // Luu chi so duong thang ung voi tung interval i
// ll APoint[MAX_N];   // Luu chi so cua interval ung voi diem truy van x_i

std::stack<ll> S; // Luu chi so duong thang co ich

ll find_intersectX(ll lineId1, ll lineId2) { // (d_i): y = y_{i+1} * x + c[i]
    ll deltaC = C[lineId2] - C[lineId1];
    ll deltaY = B[lineId2+1].Y - B[lineId1+1].Y;
    return -deltaC/deltaY;
}

ll fast_dynamic() {
    ll size = B.size();
    C[0] = B[0].X * B[0].Y;
    S.push(0);

    ll m = 0; // Chi so cua interval ben phai nhat
    I[0] = {-INF, INF};
    // APoint[0] = 0; 
    ALine[0] = 0;

    ll prev_interval = 0; // APoint[0] = 0;
    ll l, d;
    ll xp; // giao diem cua 2 duong thang
    
    for (ll i = 1; i < size; i++) {
        // tim interval I_l ung voi diem query x_{i-1}
        l = prev_interval - 1;
        while (1)  {
            l++;
            if (I[l].left <= B[i].X && B[i].X <= I[l].right) break;
        }

        d = ALine[l];
        C[i] = std::min(B[0].Y * B[i].X, B[d+1].Y * B[i].X + C[d]);
        if (i == size-1) break;

        d = S.top(); // Lay duong thang tren dinh S
        if (B[i+1].Y == B[d+1].Y) { // Xy ly TH 2 duong thang song song
            if (C[i] < C[d]) { // Kiem tra duong thang d_i va d
                S.pop();
                if (S.empty()) { // TH d_1 // d_0
                    S.push(i);
                    continue;
                }

                d = S.top();
            } else {
                // Gan interval ung voi x_i
                // APoint[i] = l;
                prev_interval = l;
                continue;
            }
        }

        xp = find_intersectX(d, i);
        while (xp <= I[m].left) {
            S.pop();
            m--;
            d = S.top();
            xp = find_intersectX(d, i);
        }

        S.push(i);
        I[m].right = xp;
        I[m+1] = {xp, INF};
        if (l < m) { // l khong phai la interval bi thay the 
            // APoint[i] = l;
            prev_interval = l;
        } else {
            if (I[m].left <= B[i].X && B[i].X <= I[m].right) {
                // APoint[i] = m;
                prev_interval = m;
            } else {
                // APoint[i] = m+1;
                prev_interval = m+1;
            }
        }

        ALine[m+1] = i; // Gan interval m+1 voi d_i
        m++;
    }

    return C[size-1];
}

int main() {
    std::cin >> n;
    for (ll i = 0; i < n; i++) std::cin >> A[i].X >> A[i].Y;
    std::sort(A, A+n);


    for (ll i = 0; i < n; i++) {
        while (!B.empty() && B.back().Y <= A[i].Y) B.pop_back(); 
        B.push_back(A[i]);
    }

    std::cout << fast_dynamic();
    return 0;
}
