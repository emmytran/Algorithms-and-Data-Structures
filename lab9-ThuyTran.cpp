#include <iostream>
#include <bits/stdc++.h>

void print_opt_parens(std::vector<std::vector<int>> &s,int i, int j, char& name) {
    if (i == j) {
        std::cout << name;
        name++;
        return;
    }
    
    std::cout << "(";
    print_opt_parens(s, i, s[i][j], name);
    print_opt_parens(s, s[i][j] + 1, j, name);
    std::cout << ")";
}

void matrix_chain(int p[], int n){
    int m[n][n];
    std::vector<std::vector<int>> s (n, std::vector<int>(n, 0));
    int j, q;
    for(int i = 1; i <= n; i++) {
        m[i][i]=0;
    }

    for(int l = 2; l <= n; l++) {
        for (int i = 1 ; i <= n-l + 1; i++) {
            j = i + l - 1;
            m[i][j] = INT_MAX;
            for(int k = i; k <= j - 1; k++) {
                q = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                    
                }
            }
        }
    }
    
    std::cout << "Optimal Parenthesization is: ";
    char name = 'A';

    print_opt_parens(s, 1, n, name);
    std::cout << std::endl;
    std::cout << "Optimal Cost is: " << m[1][n] << std::endl;
}

int main() {
    int p[] = {4, 10, 3, 12, 20, 7};
    int n = (sizeof(p) / sizeof(p[0])) - 1;
    matrix_chain(p, n);
    
    return 0;
}
