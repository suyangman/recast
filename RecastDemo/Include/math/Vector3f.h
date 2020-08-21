#pragma once

#include <algorithm>
//#include "cppcore/common/CommonDef.h"
//#include "cppcore/math/FloatConversion.h"
//#include "cppcore/containers/array.h"

#ifndef M_PI
#define M_PI 3.1415926
#endif

class Vector3f
{
	public:

	float x, y, z;

	Vector3f () : x(0.f), y(0.f), z(0.f) {}
	Vector3f (float inX, float inY, float inZ)	{ x = inX; y = inY; z = inZ; }
	explicit Vector3f (const float* array)	{ x = array[0]; y = array[1]; z = array[2]; }
	void Set (float inX, float inY, float inZ)	{ x = inX; y = inY; z = inZ; }
	void Set (const float* array)	{ x = array[0]; y = array[1]; z = array[2]; }

	float* GetPtr ()								{ return &x; }
	const float* GetPtr ()const						{ return &x; }

	//float& operator[] (int i)						{ DebugAssertIf (i < 0 || i > 2); return (&x)[i]; }
	//const float& operator[] (int i)const			{ DebugAssertIf (i < 0 || i > 2); return (&x)[i]; }

	//bool operator == (const Vector3f& v)const		{ return FLOAT_IS_ZERO(x-v.x) && FLOAT_IS_ZERO(y-v.y) && FLOAT_IS_ZERO(z-v.z); }
	//bool operator != (const Vector3f& v)const		{ return !FLOAT_IS_ZERO(x-v.x) || !FLOAT_IS_ZERO(y-v.y) || !FLOAT_IS_ZERO(z-v.z); }

	Vector3f& operator += (const Vector3f& inV)		{ x += inV.x; y += inV.y; z += inV.z; return *this; }
	Vector3f& operator -= (const Vector3f& inV)		{ x -= inV.x; y -= inV.y; z -= inV.z; return *this; }
	Vector3f& operator *= (float s)					{ x *= s; y *= s; z *= s; return *this; }
	Vector3f& operator /= (float s);

	Vector3f operator - () const					{ return Vector3f (-x, -y, -z); }

	Vector3f& Scale (const Vector3f& inV)			{ x *= inV.x; y *= inV.y; z *= inV.z; return *this;}

	static const float		epsilon;
	static const float		infinity;
	static const Vector3f	infinityVec;
	static const Vector3f	zero;
	static const Vector3f	one;
	static const Vector3f	xAxis;
	static const Vector3f	yAxis;
	static const Vector3f	zAxis;
    static const Vector3f	left;
    static const Vector3f	right;
};

inline Vector3f Scale(const Vector3f& lhs, const Vector3f& rhs) { return Vector3f(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z); }