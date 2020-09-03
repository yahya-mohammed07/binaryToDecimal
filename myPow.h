#ifndef __MYPOW_H__
#define __MYPOW_H__

// pow for unsigned long long integers
unsigned long long powull(const std::size_t & base, unsigned long long power)
{
    unsigned long long result = 1;
    if (power != 0)
    {
        result = base * (powull(base, power - 1));
    }
    return result;
}
// pow for long long integers
long long powll(const long long & base, long long power)
{
    long long result = 1;
    if (power != 0)
    {
        result = base * (powll(base, power - 1));
    }
    return result;
}
// pow for integers
int powInt(const int & base, int power)
{
    int result = 1;
    if (power != 0)
    {
        result = base * (powInt(base, power - 1));
    }
    return result;
}
// pow for floats
float powFloat(const long long & base, long long power)
{
    float result = 1;
    if (power != 0)
    {
        result = (1.0 / base) * (powFloat(base, power + 1));
    }
    return result;
}
// pow for doubles
double powDouble(const long long & base, long long power)
{
    double result = 1;
    if (power != 0)
    {
        result = (1.0 / base) * (powDouble(base, power + 1));
    }
    return result;
}
// pow for long doubles
long double powLd(const long long & base, long long power)
{
    long double result = 1;
    if (power != 0)
    {
        result = (1.0 / base) * (powLd(base, power + 1));
    }
    return result;
}

#endif // __MYPOW_H__