#ifndef ABMC_H
#define ABMC_H

extern float fabmc(float, float, float);
extern double dabmc(double, double, double);
extern long double ldabmc(long double, long double, long double);
extern _Decimal32 dfabmc(_Decimal32 a, _Decimal32 b, _Decimal32 c);
extern _Decimal64 ddabmc(_Decimal64 a, _Decimal64 b, _Decimal64 c);
extern _Decimal128 dlabmc(_Decimal128 a, _Decimal128 b, _Decimal128 c);
#endif
