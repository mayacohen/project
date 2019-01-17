#ifndef EX3_MTMVEC_H
#define EX3_MTMVEC_H

#include <vector>
#include "MtmExceptions.h"
#include "Auxilaries.h"
#include "Complex.h"

using std::size_t;

namespace MtmMath {
    template <typename T>
    class MtmVec {
    private:
        bool isRow;
        size_t size;
        T* v;
    public:
        /*
         * Vector constructor, m is the number of elements in it and val is the initial value for the matrix elements
         */
        MtmVec(size_t m, const T& val=T());
        MtmVec(const MtmVec&);
        ~MtmVec();
        MtmVec& operator=(const MtmVec&);


        /*
         * Function that get function object f and uses it's () operator on each element in the vectors.
         * It outputs the function object's * operator after iterating on all the vector's elements
         */
        template <typename Func>
        T vecFunc(Func& f) const;

        const T& operator[](int index) const ;
        T& operator[](int index);
        /*
         * Resizes a vector to dimension dim, new elements gets the value val.
         * Notice vector cannot transpose through this method.
         */
        void resize(Dimensions dim, const T& val=T());

        /*
         * Performs transpose operation on matrix
         */
        void transpose();
    };
}

#endif //EX3_MTMVEC_H
