#include <iostream>
#include <cmath>
#include <complex>
#include <time.h>
using namespace std;
double f(double x, double y){
    return y;
}
double g(double x, double y, double k, double m){
    return -k/m*x;
}
void runge_kutta(double &x, double &y, double t, double h, double k, double m){
double k1 = f(x,y);
double l1 = g(x,y,k,m);
double k2 = f(x+h/2,y+h/2*k1);
double l2 = g(x+h/2,y+h/2*l1,k,m);
double k3 = f(x+h/2,y+h/2*k2);
double l3 = g(x+h/2,y+h/2*l2,k,m);
double k4 = f(x+h,y+h*k3);
double l4 = g(x+h,y+h*l3,k,m);
x = x + h/6*(k1+2*k2+2*k3+k4);
y = y + h/6*(l1+2*l2+2*l3+l4);
}
int main(){
double m = 1; // mass in kg
double k = 100; // spring constant in N/m
double x0 = 0.0; // initial displacement in m
double v0 = 0; // initial velocity in m/s
double t0 = 0; // initial time in s
double tf = 10; // final time in s
double h = 0.01; // step size in s
double x = x0;
double y = v0;
cout << "t\tx\tv\n";
cout << t0 << "\t" << x << "\t" << y << "\n";
for (double t = t0 + h; t <= tf; t += h){
runge_kutta(x,y,t,h,k,m); 
cout << t << "\t" << x << "\t" << y << "\n"; 
}
return 0;
}
