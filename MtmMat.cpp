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

using std::size_t;

using namespace MtmMath;

template <class T>
<T>
MtmMat::MtmMat(Dimensions dim_t, const T& val=T())
{
    if (dim_t.getCol() <= 0 || dim_t.getRow() <= 0)
    {
        m == NULL;
        rows = 0;
        cols = 0;
        return;
    }
    m = new T*[dim_t.getRow()];
    for(int i = 0; i < dim_t.getRow(); i++)
    {
        m[i] = new T [dim_t.getCol()];
    }
    for(int i = 0; i < dim_t.getRow(); i++)
    {
        for(int j = 0; j < dim_t.getCol(); j++)
        {
            m[i][j] = val;
        }
    }
    rows = dim_t.getRow();
    cols = dim_t.getCol();

}

template <class T>
<T>
MtmMat::MtmMat(const MtmMat& mat)
{
    if (mat.m==NULL)
    {
        m == NULL;
        rows = 0;
        cols = 0;
        return;
    }
    m = new T*[mat.rows];
    for(int i = 0; i < mat.rows; i++)
    {
        m[i] = new T [mat.cols];
    }
    for(int i = 0; i < mat.rows; i++)
    {
        for(int j = 0; j < mat.cols; j++)
        {
            m[i][j] = mat.m[mat.rows][mat.cols];
        }
    }
    rows = mat.rows;
    cols = mat.cols;

}
MtmMat::~MtmMat()
{
    if (m!= NULL)
    {
        for (int i = 0 ; i< rows; i++)
        {
            delete[] m[i];
        }
        delete[] m;
    }
}
MtmMat& operator=(const MtmMat& mat)
{
    if (&mat != this)
    {
        this->~MtmMat();
        this->MtmMat(mat);
    }
    return *this;
}


MtmMat operator[](const MtmMat& a);
/*
static int calcMinLinIndex(int linIndex, int rows, int cols){
    for (int i = 0 ; i < rows ; i++){
        {
            for (int j = 0 ; j < cols ; j++){
                if (linIndex == (i + j*rows))
                {
                    return rows;
                }
            }
        }
    }
    return -1;
}
*/
using MtmExceptions::ChangeMatFail
template <class T>
<T>
void MtmMat::reshape(Dimensions newDim)
{
    if (typeid(this) != typeid(MtmMat))
    {
        throw ChangeMatFail();
    }
    if (newDim.getCol() <= 0 || newDim.getRow() <= 0)
    {
        return void();
    }
    if (newDim.getRow()*newDim.getCol() != rows*cols)
    {
        return void();
    }
    T** newMat = new T*[newDim.getRow()];
    //int linIndex = 0;
    //int curRow = 0;
    for(int i = 0; i < newDim.getRow(); i++)
    {
        newMat[i] = new T [newDim.getCol()];
    }
    /*
   for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            linIndex = (i + j*rows);
            curRow = calcMinLinIndex(linIndex,newDim.getRow(),newDim.getCol());
            newMat[curRow][(linIndex-curRow)/newDim.getRow()] = m[i][j];
        }
    }
    */
    for (int i= 0; i< rows*cols; i++)
    {
        *(newMat+(i)) = *(m+(i));
    }
    for (int i = 0 ; i< rows; i++)
    {
        delete[] m[i];
    }
    delete[] m;
    *m = *newMat;
}
