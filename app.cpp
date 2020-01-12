#include "stdafx.h"
#include "math.h"
#include "conio.h"
#include "iostream"
#include "fstream"
const double eps = 1e-5;
typedef double vec[2];
using namespace std;
ofstream fout1("Result I.txt");
ofstream fout2("Result II.txt");
double fnw1(double x, double y) {
return((2 * y*(sin(x + y) + *x - ) - (x*x + y*y - 1)*cos(x+y)) / (2 *
y*(cos(x + y) + ) - 2 * x*cos(x + y)));
}
double fnw2(double x, double y) {
return((-2*x*(sin(x + y) + *x - ) + (cos(x + y) + )*(x*x + y*y -
1)) / (2 * y*(cos(x + y) + ) - 2 * x*cos(x + y)));
}
double f11(double x, double y) {
return (sin(x+y)+ *x- );
}
double f22(double x, double y) {
return (x*x+y*y-1);
}
double f1(double x, double y) {
return (cos(x+ )- *y- );
}
double f2(double x, double y) {
return (x+sin(y- )- );
}
double x1(double x, double y) {
return ( + sin( - y));
}
double y1(double x, double y) {
return (- / + cos(x + ) / );
}
double norm(vec ar) {
return (sqrt(ar[0] * ar[0] + ar[1] * ar[1]));
}
void iter(double xf, double yf, double fx(double, double), double fy(double, double),
double f1(double, double), double f2(double, double)) {
vec xkp, xk, dif, fn;
int it = 0;
xk[0] = xf;

xk[1] = yf;
fn[0] = f1(xk[0], xk[1]);
fn[1] = f2(xk[0], xk[1]);
fout1 << "(x" << it << ",y" << it << ") = (" << xk[0] << "," << xk[1] << ")" <<
endl;
fout1 << "(f1(x" << it << ",y" << it << "),f2(x" << it << ",y" << it << ")) = ("
<< fn[0] << "," << fn[1] << ")" << endl;
fout1 << "||F|| = " << norm(fn) << endl << endl;
xkp[0] = fx(xk[0],xk[1]);
xkp[1] = fy(xk[0],xk[1]);
dif[0] = xkp[0] - xk[0];
dif[1] = xkp[1] - xk[1];
fn[0] = f1(xkp[0], xkp[1]);
fn[1] = f2(xkp[0], xkp[1]);
++it;
fout1 << "(x" << it << ",y" << it << ") = (" << xkp[0] << "," << xkp[1] << ")" <<
endl;
fout1 << "(f1(x" << it << ",y" << it << "),f2(x" << it << ",y" << it << ")) = ("
<< fn[0] << "," << fn[1] << ")" << endl;
fout1 << "||F|| = " << norm(fn) << endl << endl;
while ((norm(dif) > eps)||(norm(fn) > eps )) {
++it;
xk[0] = xkp[0];
xk[1] = xkp[1];
xkp[0] = fx(xk[0], xk[1]);
xkp[1] = fy(xk[0], xk[1]);
dif[0] = xkp[0] - xk[0];
dif[1] = xkp[1] - xk[1];
fn[0] = f1(xkp[0], xkp[1]);
fn[1] = f2(xkp[0], xkp[1]);
fout1 << "(x" << it << ",y" << it << ") = (" << xkp[0] << "," << xkp[1] <<

")" << endl;

fout1 << "(f1(x" << it << ",y" << it << "),f2(x" << it << ",y" << it << "))

= (" << fn[0] << "," << fn[1] << ")" << endl;

fout1 << "||F|| = " << norm(fn) << endl << endl;
}
cout << "Answer : (" << xkp[0] << "," << xkp[1] << ")" << endl << endl;
fout1 << "Answer : (" << xkp[0] << "," << xkp[1] << ")" << endl;
}
void newton(double xf, double yf, double fnw1(double, double), double fnw2(double,
double), double f11(double, double), double f22(double, double)) {
vec xkp, xk, dif, fn;
int it = 0;
xk[0] = xf;
xk[1] = yf;
fn[0] = f11(xk[0], xk[1]);
fn[1] = f22(xk[0], xk[1]);
fout2 << "(x" << it << ",y" << it << ") = (" << xk[0] << "," << xk[1] << ")" <<
endl;
fout2 << "(f1(x" << it << ",y" << it << "),f2(x" << it << ",y" << it << ")) = ("
<< fn[0] << "," << fn[1] << ")" << endl;
fout2 << "||F|| = " << norm(fn) << endl << endl;
xkp[0] = xk[0] - fnw1(xk[0], xk[1]);
xkp[1] = xk[1] - fnw2(xk[0], xk[1]);
dif[0] = xkp[0] - xk[0];
dif[1] = xkp[1] - xk[1];
fn[0] = f1(xkp[0], xkp[1]);
fn[1] = f2(xkp[0], xkp[1]);
++it;
fout2 << "(x" << it << ",y" << it << ") = (" << xkp[0] << "," << xkp[1] << ")" <<
endl;
fout2 << "(f1(x" << it << ",y" << it << "),f2(x" << it << ",y" << it << ")) = ("
<< fn[0] << "," << fn[1] << ")" << endl;
fout2 << "||F|| = " << norm(fn) << endl << endl;

fout2 << "fnw1" << fnw1(xk[0], xk[1]) << "fnw2" << fnw2(xk[0], xk[1]) << endl;
while ((norm(dif) > eps) || (norm(fn) > eps)) {
++it;
xk[0] = xkp[0];
xk[1] = xkp[1];
xkp[0] = xk[0] - fnw1(xk[0], xk[1]);
xkp[1] = xk[1] - fnw2(xk[0], xk[1]);
dif[0] = xkp[0] - xk[0];
dif[1] = xkp[1] - xk[1];
fn[0] = f11(xkp[0], xkp[1]);
fn[1] = f22(xkp[0], xkp[1]);
fout2 << "(x" << it << ",y" << it << ") = (" << xkp[0] << "," << xkp[1] <<

")" << endl;

fout2 << "(f1(x" << it << ",y" << it << "),f2(x" << it << ",y" << it << "))

= (" << fn[0] << "," << fn[1] << ")" << endl;

fout2 << "||F|| = " << norm(fn) << endl << endl;
}
cout << "Answer : (" << xkp[0] << "," << xkp[1] << ")" << endl << endl;
fout2 << "Answer : (" << xkp[0] << "," << xkp[1] << ")" << endl;
}
int main()
{
double xc1, yc1, xc2, yc2;
cout << "I. Input the closest dot " << endl;
cout << "x = ";
cin >> xc1;
cout << endl;
cout << "y = ";
cin >> yc1;
cout << endl;
iter(xc1,yc1,x1,y1,f1,f2);
cout << "II. Input the closest dot " << endl;
cout << "x = ";
cin >> xc2;
cout << endl;
cout << "y = ";
cin >> yc2;
cout << endl;
newton(xc2, yc2, fnw1, fnw2, f11, f22);
fout1.close();
fout2.close();
_getch();
return 0;
}