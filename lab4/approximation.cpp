#include "approximation.h"
#include <cmath>

#define M 2

// double* approx(double* X, double* Y, int n){
//     double** a = new double*[n];
//     double* b = new double[n];

//     for(int i = 0; i < n; i++){
//         a[i] = new double[n];

//         for(int j = i; j < n; j++){
//             a[i][j] = pow(X[i], j);
//         }
//         b[i] = pow(X[i], i+1)*Y[i];
//     }

//     double* solutions = new double[n];
//     gauss(a, b, solutions, n);


//     for(int i = 0; i < n; i++){
//         delete[] a[i];
//     }
//     delete[] a;
//     delete[] b;
//     return solutions;
// }

double* approx(double* X, double* Y, int n){
    double** a = new double*[M];
    for(int i = 0; i < M; i++){
        a[i] = new double[M];
        for(int j = 0; j < M; j++){
            double sumx = 0;
            for(int xind = 0; xind < n; xind++){
                sumx += pow(X[xind], i+j);
            }
            a[i][j] = sumx;
        }
    }

    double* b = new double[M];

    for(int i = 0; i < M; i++){
        double sumxy = 0;
        for(int j = 0; j < M; j++){
            sumxy += Y[j]*pow(X[j], i);
        }
        b[i] = sumxy;
    }

    double *solutions = new double[M];

    gauss(a, b, solutions, M);
    return solutions;
}

double* approx_wrapped(double* X, double* Y, int n){
    for(int i = 0; i < n; i++){
        Y[i] = log(Y[i]);
    }
    
    double* solutions = approx(X, Y, n);
    return solutions;
}