#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
void gaussianElimination(  vector<  vector<double>>& a,   vector<double>& b, int n,   vector<double>& x) {
    //прямой
    for (int k = 0; k < n; k++) {
        for (int i = k + 1; i < n; i++) {
            if (  abs(a[i][k]) >   abs(a[k][k])) {
                  swap(a[i], a[k]);
                  swap(b[i], b[k]);
            }
        }

        double A_Main = a[k][k];
        if (A_Main == 0) {
              cout << "Error" <<   endl;
            return;
        }

        for (int i = k; i < n; i++) {
            a[k][i] /= A_Main;

        }
        b[k] /= A_Main;


        for (int i = k + 1; i < n; i++) {
            double s = a[i][k];
            for (int j = k; j < n; j++) {
                a[i][j] -= s * a[k][j];
                 
            }
            b[i] -= s * b[k];
            
        }
    }
    //Обратный
    for (int k = n - 1; k >= 0; k--) {
        x[k] = b[k];
          
        for (int i = n - 1; i > k; i--) {
            x[k] -= a[k][i] * x[i];
              
        }
    }
}


  vector<double> calculateVectorF(  vector<  vector<double>>& a,   vector<double>& b,   vector<double>& x, int n) {
      vector<double> f(n);
    for (int i = 0; i < n; i++) {
        f[i] = -b[i];
        for (int j = 0; j < n; j++) {
            f[i] += a[i][j] * x[j];
        }
    }
    return f;
}

double calculateNorma(  vector<double>& f, int n) {
    double norma =   abs(f[0]);
    for (int i = 0; i < n; i++) {
        norma =   max(f[i], norma);
    }
    return norma;
}

int main() {
    int n = 3;
      vector<  vector<double>> a = {{8.64, 1.71, 5.42}, {-6.39, 4.25, 1.84}, {4.21, 7.92, -3.41}};
      vector<double> b = {10.21, 3.41, 12.29};
      vector<double> x(n);

    gaussianElimination(a, b, n, x);

      cout << "Solution (x): ";
    for (int i = 0; i < n; i++) {
          cout << x[i] << " ";
    }
      cout <<   endl;

      vector<double> f = calculateVectorF(a, b, x, n);
    
    double norma = calculateNorma(f, n);

      cout << "Norma: " << norma <<   endl;
    return 0;
}

