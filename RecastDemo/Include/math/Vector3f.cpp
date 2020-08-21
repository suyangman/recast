
#include "math/Vector3f.h"

#define FPFIXES 1

using namespace std;

const float		Vector3f::epsilon = 0.00001F;
const float		Vector3f::infinity = numeric_limits<float>::infinity ();
const Vector3f	Vector3f::infinityVec = Vector3f (numeric_limits<float>::infinity (), numeric_limits<float>::infinity (), numeric_limits<float>::infinity ());

const Vector3f	Vector3f::zero  = Vector3f (0, 0, 0);
const Vector3f	Vector3f::one  = Vector3f (1.0F, 1.0F, 1.0F);
const Vector3f	Vector3f::xAxis = Vector3f (1, 0, 0);
const Vector3f	Vector3f::yAxis = Vector3f (0, 1, 0);
const Vector3f	Vector3f::zAxis = Vector3f (0, 0, 1);
const Vector3f	Vector3f::left = Vector3f (-1, 0, 0);
const Vector3f	Vector3f::right = Vector3f (1, 0, 0);

#define k1OverSqrt2 float(0.7071067811865475244008443621048490)

