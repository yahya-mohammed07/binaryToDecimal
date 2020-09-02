#ifndef __MYPOW_H__
#define __MYPOW_H__

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
double powFloat(const int & base, int power)
{
    double result = 1;
    if (power != 0)
    {
        result = (1.0 / base) * (powFloat(base, power + 1));
    }
    return result;
}

#endif // __MYPOW_H__