#ifndef RAYVECTOR
#define RAYVECTOR


template < typename T > class RayVector;

template < typename T > 
class RayVector
    {
        T x;
        T y;
        T z;
      public:
        RayVector (T a, T b, T c);
        RayVector ();
        void print_coordinates ();
        RayVector operator+ (RayVector another);
        RayVector operator- (RayVector another);
        T operator& (RayVector another);
        RayVector operator% (RayVector another);
        RayVector operator* (T number);
        bool operator== (RayVector another);
        double find_length ();
        RayVector get_unit_vector();
    };
 
typedef RayVector<double> DoubleVector;
typedef DoubleVector UnitVec;

#include "Vector.tpp"

#endif