/*
 * LICENCE
 * copyright 2014 ~ ****
 * Some rights reserved.
 * Author: HUFANGYUAN
 * Released under CC BY-NC
*/
#ifndef MAT3_H
#define MAT3_H
#include <cmath>
#include "Vec3.h"

template <typename real>
class Mat3
{
typedef Vec3<real> vec;
public:
    Mat3(const Mat3& m) : x(m.x), y(m.y), z(m.z)
    {}
    Mat3(const vec& _x = 0, const vec& _y = 0, const vec& _z = 0) : x(_x), y(_y), z(_z)
    {}
    ~Mat3()
    {}

    inline const Mat3 operator+ (const Mat3& m) const
    {
        return Mat3(x+m.x, y+m.y, z+m.z);
    }

    inline const Mat3 operator- (const Mat3& m) const
    {
        return Mat3(x-m.x, y-m.y, z-m.z);
    }

    inline void operator+= (const Mat3& m)
    {
        x += m.x;   y += m.y;   z += m.z;
    }
    inline void operator-= (const vec& m)
    {
        x -= m.x;   y -= m.y;   z -= m.z;
    }

    inline const Mat3 operator* (const real& s) const
    {
        return Mat3(s*x, s*y, s*z);
    }

    inline const Mat3 operator* (const Mat3& m) const //right multiplation
    {
        Mat3 ret;
        ret.x = vec( x.x*m.x.x + x.y*m.y.x + x.z*m.z.x, x.x*m.x.y + x.y*m.y.y + x.z*m.z.y, x.x*m.x.z + x.y*m.y.z + x.z*m.z.z );
        ret.y = vec( y.x*m.x.x + y.y*m.y.x + y.z*m.z.x, y.x*m.x.y + y.y*m.y.y + y.z*m.z.y, y.x*m.x.z + y.y*m.y.z + y.z*m.z.z );
        ret.z = vec( z.x*m.x.x + z.y*m.y.x + z.z*m.z.x, z.x*m.x.y + z.y*m.y.y + z.z*m.z.y, z.x*m.x.z + z.y*m.y.z + z.z*m.z.z );
        return ret;
    }

    inline const vec operator* (const vec& v) const //right multiplation
    {
        return vec(x*v, y*v, z*v);
    }

    inline Mat3 trans()
    {
        x.y = y.x;  x.z = z.x;
        y.z = z.y;
        return *this;
    }
/*
    inline real mag2() const
    {
        return (x*x + y*y + z*z);
    }

    inline real mag() const
    {
        return sqrt(mag2());
    }
*/
public:
    vec x, y, z;
};

template <typename real>
inline const Mat3<real> operator* (const real& s, const Mat3<real>& m)
{
    return Mat3<real>(s*m.x, s*m.y, s*m.z);
}

#endif // MAT3_H
