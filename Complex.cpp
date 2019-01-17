//
// Created by Maya on 10/01/2019.
//
#include "MtmMat.h"
#include <iostream>
using namespace MtmMath;

#include "Complex.h"
// Constructor with two arguments
Complex::Complex(double r=0, double i=0)
{
    re = r;
    im = i;
}

Complex::Complex(const Complex& a)
{
    re = a.re;
    im = a.im;
}

Complex& operator=(const Complex& a)
{
    if (&a != this)
    {
        this->re = a.re;
        this->im = a.im;
    }
    return *this;
}

