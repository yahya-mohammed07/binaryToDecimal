#ifndef __MAGIC_H__
#define __MAGIC_H__

#include <cstdint>

namespace math
{
    /**
    * @brief This lamda swaps two integer values
    * @param first var from the user
    * @param second var you want to swap a with
    * @file magic.h
    */
    auto swap = [] (auto &first, auto &second) -> void
    {std::int64_t temp = first; first = second; second = temp;};
    /**
    * @namespace for pow functions
    */
    namespace pow
    {
        /**
        * @brief This template func returns the power of a number
        * @note give the type of the template
        * @param base the user enters the base
        * @param power the user enters the power
        * @file magic.h
        */
        template <typename T> 
        T powInt (const T &base,const std::uint64_t &power)
        {
            std::int64_t result = 1;
            if (power != 0)
            {
                result = base * (powInt(base, power - 1));
            }
            return result;
        }
        /**
        * @brief This template func returns the power of a number
        * @note give the type of the template
        * @param base the user enters the base
        * @param power the user enters the power as negative number
        * @file magic.h
        */
        template<typename T> 
        T powFloat(const T &base, std::int64_t power)
        {
            long double result = 1;
            if (power != 0)
            {
                result = (1.0 / base) * (powFloat(base, power + 1));
            }
            return result;
        }
    }
    /**
    * @brief This lamda reverse a given number
    * @param n the number needed to be reversed,
    * @file magic.h
    */
    auto reverse = [] (auto n) -> std::int64_t
    {
        std::int64_t result = 0;
        while (true)
        {
            result = result * 10 + n % 10;
            n /= 10;
            if (n == 0) break;
        }
        return result;
    };
}
/**
* @namespace sort contains sorting algorithms
*/
namespace sort
{
    /**
    * @brief This func sorts int value as ascending or deascending orders
    * @note put <int*> for static arrays and <std::vector<int>&> for vectors
    * @param arr to take an array from the user
    * @param size the user gives the size of the array
    * @param order as bool put value true for ascending or flase for deascending
    * @file magic.h
    */
    template<typename T> 
    void bubble(T arr, const std::uint64_t &size, const bool &order)
    {
        for (long i = 0; i < size; i++)
        {
            bool swapped = false;
            if (order == true)
            {
                for (long j = 0; j < (size - 1 - i); j++)
                {
                    if (arr[j] > arr[j + 1])
                    {
                        math::swap(arr[j], arr[j + 1]);
                        swapped = true;
                    }
                }
            }
            else
            {
                for (long j = 0; j < (size - 1 - i); j++)
                {
                    if (arr[j] < arr[j + 1])
                    {
                        math::swap(arr[j], arr[j + 1]);
                        swapped = true;
                    }
                }
            }
            if (swapped == false) break;
        }
    }
    /**
    * @brief This func sorts int value as ascending or deascending orders
    * @note put <int*> for static arrays and <std::vector<int>&> for vectors
    * @param arr to take an array from the user
    * @param size the user gives the size of the array
    * @param order as bool put value true for ascending or flase for deascending
    * @file magic.h
    */
    template<typename T> 
    void selection(T arr, const std::uint64_t &size, const bool &order)
    {
        for (long i = 0; i < size - 1; i++)
        {
            int minIndex = i;
            int minValue = arr[i];
            if (order == true)
            {
                for (long j = i + 1; j < size; j++)
                {
                    if (minValue > arr[j])
                    {
                        minIndex = j;
                        minValue = arr[j];
                        math::swap(arr[i], arr[minIndex]);
                    }
                }
            }
            else
            {
                for (long j = i + 1; j < size; j++)
                {
                    if (minValue < arr[j])
                    {
                        minIndex = j;
                        minValue = arr[j];
                        math::swap(arr[i], arr[minIndex]);
                    }
                }
            }
        }
    }
    /**
    * @brief This func sorts int value as ascending or deascending orders
    * @note put <int*> for static arrays and <std::vector<int>&> for vectors
    * @param arr to take an array from the user
    * @param size the user gives the size of the array
    * @param order as bool put value true for ascending or flase for deascending
    * @file magic.h
    */
    template<typename T> 
    void insertion(T arr, const std::uint64_t &size, const bool &order)
    {
        for (long i = 1; i < size; i++)
        {
            long j = i;
            if (order == true)
            {
                while (j > 0 && arr[j - 1] > arr[j])
                {
                    math::swap(arr[j], arr[j - 1]);
                    j -= 1;
                }
            }
            else
            {
                while (j > 0 && arr[j - 1] < arr[j])
                {
                    math::swap(arr[j], arr[j - 1]);
                    j -= 1;
                }
            }
        }
    }
}
/**
* @namespace for searching algorithms
*/
namespace search
{
    /**
    * @brief This func seaches recursively for a number in a given array
    * @note put <int*> for static arrays and <std::vector<int>&> for vectors
    * @param arr to take an array from the user
    * @param target the user give the number to look for
    * @param first always put 0
    * @param last the user gives size - 1,
    * returns -1 if not found
    * @file magic.h
    */
    template<typename T> 
    int binary(T arr, const long &target, int first, std::uint64_t last)
    {
        long mid = 0;
        mid = (first + last) / 2;
        if (last >= first)
        {
            if (arr[mid] == target)
            {
                return mid;
            }
            else if (target > arr[mid])
            {
                return binary(arr, target, first + 1, last);
            }
            else
            {
                return binary(arr, target, first, last - 1);
            }
        }
        return -1;
    }
    /**
    * @brief This func seaches recursively for a number in a given array
    * @note put <int*> for static arrays and <std::vector<int>&> for vectors
    * @param arr to take an array from the user
    * @param target the user give the number to look for
    * @param start always put 0
    * @param size the user gives size - 1,
    * returns -1 if not found
    * @file magic.h
    */
    template<typename T>
    int linear(T arr, const std::uint32_t &target, int start, const std::uint64_t size)
    {
        if (start > size)
        {
            return -1;
        }
        else if (arr[start] == target)
        {
            return start;
        }
        return linear(arr, target, start + 1, size);
    }
}
#endif // __MAGIC_H__