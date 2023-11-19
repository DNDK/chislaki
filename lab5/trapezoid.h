#pragma once

double trapezoid(double a, double b, int n, double (*F)(double));
double trapezoid_wrapped(double a, double b, int n, double (*F)(double), double eps = 1e-6);
