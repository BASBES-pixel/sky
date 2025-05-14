#ifndef TRUE_VEC_H
#define TRUE_VEC_H
#include <iostream> 
#include <cmath>
class CVec{
	private:
		double x, y, z;

	public:
		CVec(const CVec& _CV ): x(_CV.x),y(_CV.y), z(_CV.z){}
		CVec(const double  _x, const double _y,const double _z): x(_x),y(_y), z(_z){}
		CVec(): x(0), y(0), z(0){}
		CVec operator=(const CVec& _CV){ x = _CV.x; y = _CV.y; z = _CV.z; return *this;}
		CVec operator-(const CVec& _CV){ return {x - _CV.x, y - _CV.y, z - _CV.z};}
		CVec operator+(const CVec& _CV){ return {x + _CV.x, y + _CV.y, z + _CV.z};}
		CVec operator-=(const CVec& _CV){ x -= _CV.x; y -= _CV.y; z -= _CV.z; return *this;}
		CVec operator+=(const CVec& _CV){ x += _CV.x; y += _CV.y; z += _CV.z; return *this;}
		double getx()const{ return x;}
		double gety()const{ return y;}
		double getz()const{ return z;}
		CVec dot(const double a){ return {x*a, y*a, z*a};}
		double len()const{ return pow((x*x) + (y*y) + (z*z),0.5);}
		CVec nVec()const
		{
			double length = len();
			if(length == 0)
			{
				return CVec(0,0,0);
			}
			return CVec(x / length, y/length, z/length);
		}
		auto operator<=>(const CVec& other) const = default;
};

inline std::ostream& operator << ( std::ostream& os, const CVec& _CV)
{
	os<<_CV.getx()<<","<<_CV.gety()<<","<<_CV.getz();
	return os;
}
#endif
