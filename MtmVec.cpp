//
// Created by Maya on 10/01/2019.
//
#include <vector>
#include "MtmMat.h"
#include <iostream>
#include "MtmExceptions.h"
#include "Auxilaries.h"
#include "MtmVec.h"
#include <MtmExceptions.h>
#include "Complex.h"

using std::size_t;

using namespace MtmMath;

template <class T>
MtmVec::MtmVec(size_t m, const T& val=T())
{
    if (m <= 0 )
    {
        v == NULL;
        size = 0;
        return;
    }
    v = new T*[m];
    for(int i = 0; i < m; i++)
    {
        v[i] = val;
    }
    size = m;
    isRow = false;
}

template <class T>
MtmVec::MtmVec(const MtmVec& vec)
{
    if (vec.v==NULL)
    {
        *v == NULL;
        size = 0;
        return;
    }
    size = vec.size;
    isRow = vec.isRow;
    v = new T*[vec.size];
    for(int i = 0; i < size; i++)
    {
        v[i] = vec.v[i];
    }
}

MtmVec::~MtmVec()
{
    delete[] v;
}

MtmVec::MtmVec& operator=(const MtmVec& vec)
{
    if (&vec != this)
    {
        this->~MtmVec();
        this->MtmVec(vec);
    }
    return *this;
}

template<class T>
template<class Func>
T MtmVec<T>::vecFunc(Func &f) const
{
    T vec =  new T*[size];
    for (int i=0; i<size; i++)
    {
        vec[i] = f(v[i]);
    }
    return vec;
}

template<class T>
T &MtmVec<T>::operator[](int index)
{
    return v[index];
}

template<class T>
const T &MtmVec<T>::operator[](int index) const
{
    return v[index];
}

template<typename T>
void MtmVec<T>::transpose()
{
    isRow = (!isRow);
}
