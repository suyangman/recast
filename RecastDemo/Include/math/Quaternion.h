#ifndef QUATERNION_H
#define QUATERNION_H

#include "math/Vector3f.h"
//#include "cppcore/math/FloatConversion.h"
#include <algorithm>
#include <vector>

class Quaternionf
{
public:
	float x, y, z, w;

	Quaternionf () { *this = identity(); }
	Quaternionf (float inX, float inY, float inZ, float inW);
	explicit Quaternionf (const float* array)	{ x = array[0]; y = array[1]; z = array[2]; w = array[3]; }

	// methods

	const float* GetPtr ()const				{ return &x; }
	float* GetPtr ()								{ return &x; }

	const float& operator [] (int i)const	{ return GetPtr ()[i]; }
	float& operator [] (int i)					{ return GetPtr ()[i]; }

	void Set (const float* array)	{ x = array[0]; y = array[1]; z = array[2]; w = array[3]; }

	Quaternionf&	operator += (const Quaternionf&  aQuat);
	Quaternionf&	operator -= (const Quaternionf&  aQuat);
	Quaternionf&	operator *= (const float     	aScalar);
	Quaternionf&	operator *= (const Quaternionf& 	aQuat);

	friend Quaternionf operator + (const Quaternionf& lhs, const Quaternionf& rhs)
	{
		Quaternionf q (lhs);
		return q += rhs;
	}

	friend Quaternionf	operator - (const Quaternionf& lhs, const Quaternionf& rhs)
	{
		Quaternionf t (lhs);
		return t -= rhs;
	}

	Quaternionf operator - () const
	{
		return Quaternionf(-x, -y, -z, -w);
	}

	Quaternionf	operator * (const float s) const
	{
		return Quaternionf (x*s, y*s, z*s, w*s);
	}

	friend Quaternionf	operator * (const float s, const Quaternionf& q)
	{
		Quaternionf t (q);
		return t *= s;
	}

	inline friend Quaternionf operator * (const Quaternionf& lhs, const Quaternionf& rhs)
	{
		return Quaternionf (
				lhs.w*rhs.x + lhs.x*rhs.w + lhs.y*rhs.z - lhs.z*rhs.y,
				lhs.w*rhs.y + lhs.y*rhs.w + lhs.z*rhs.x - lhs.x*rhs.z,
				lhs.w*rhs.z + lhs.z*rhs.w + lhs.x*rhs.y - lhs.y*rhs.x,
				lhs.w*rhs.w - lhs.x*rhs.x - lhs.y*rhs.y - lhs.z*rhs.z);
	}

	static Quaternionf identity () { return Quaternionf (0.0F, 0.0F, 0.0F, 1.0F); }
};

inline Quaternionf::Quaternionf(float inX, float inY, float inZ, float inW)
{
	x = inX;
	y = inY;
	z = inZ;
	w = inW;
}

inline Quaternionf& Quaternionf::operator+= (const Quaternionf& aQuat)
{
	x += aQuat.x;
	y += aQuat.y;
	z += aQuat.z;
	w += aQuat.w;
	return *this;
}

inline Quaternionf& Quaternionf::operator-= (const Quaternionf& aQuat)
{
	x -= aQuat.x;
	y -= aQuat.y;
	z -= aQuat.z;
	w -= aQuat.w;
	return *this;
}

inline Quaternionf& Quaternionf::operator *= (float aScalar)
{
	x *= aScalar;
	y *= aScalar;
	z *= aScalar;
	w *= aScalar;
	return *this;
}


inline Quaternionf& Quaternionf::operator *= (const Quaternionf& rhs)
{
	float tempx = w * rhs.x + x * rhs.w + y * rhs.z - z * rhs.y;
	float tempy = w * rhs.y + y * rhs.w + z * rhs.x - x * rhs.z;
	float tempz = w * rhs.z + z * rhs.w + x * rhs.y - y * rhs.x;
	float tempw = w * rhs.w - x * rhs.x - y * rhs.y - z * rhs.z;
	x = tempx; y = tempy; z = tempz; w = tempw;
	return *this;
}

inline Vector3f RotateVectorByQuat(const Quaternionf& lhs, const Vector3f& rhs)
{
	//	Matrix3x3f m;
	//	QuaternionToMatrix (lhs, &m);
	//	Vector3f restest = m.MultiplyVector3 (rhs);
	float x = lhs.x * 2.0F;
	float y = lhs.y * 2.0F;
	float z = lhs.z * 2.0F;
	float xx = lhs.x * x;
	float yy = lhs.y * y;
	float zz = lhs.z * z;
	float xy = lhs.x * y;
	float xz = lhs.x * z;
	float yz = lhs.y * z;
	float wx = lhs.w * x;
	float wy = lhs.w * y;
	float wz = lhs.w * z;

	Vector3f res;
	res.x = (1.0f - (yy + zz)) * rhs.x + (xy - wz) * rhs.y + (xz + wy) * rhs.z;
	res.y = (xy + wz) * rhs.x + (1.0f - (xx + zz)) * rhs.y + (yz - wx) * rhs.z;
	res.z = (xz - wy) * rhs.x + (yz + wx) * rhs.y + (1.0f - (xx + yy)) * rhs.z;

	//	AssertIf (!CompareApproximately (restest, res));
	return res;
}

#endif
