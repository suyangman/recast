#include "math/Quaternion.h"

/*
Quaternionf Slerp(const Quaternionf& a, const Quaternionf& b, float time)
{
	#if DEBUGMODE
	float debugLengthA = Magnitude (a);
	float debugLengthB = Magnitude (b);
	#endif
	// ====================================================
	// AART - Advanced Animation and Rendering Techniques
	// ====================================================

	float cosom = a.x*b.x + a.y*b.y + a.z*b.z + a.w*b.w;

	if ( (1 + cosom) > std::numeric_limits<float>::epsilon() )
	{
		float sp;
		float sq;

		if ( (1 - cosom) > std::numeric_limits<float>::epsilon() )
		{
			double omega = acos(cosom);
			double sinom = 1.0 / sin(omega);

			sp = (sin((1 - time) * omega) * sinom);
			sq = (sin(time * omega) * sinom);
		}
		else
		{
			sp = 1 - time;
			sq = time;
		}

		Quaternionf res = Quaternionf (
			a.x*sp + b.x*sq,
			a.y*sp + b.y*sq,
			a.z*sp + b.z*sq,
			a.w*sp + b.w*sq);
		AssertIf (!CompareApproximately (SqrMagnitude (res), 1.0F) &&
					  CompareApproximately (SqrMagnitude (b), 1.0) &&
					  CompareApproximately (SqrMagnitude (a), 1.0));
		return res;
	}
	else
	{
		float halfpi = pi / 2;
		float sp = sin((1 - time) * halfpi);
		float sq = sin(time * halfpi);

		Quaternionf res = Quaternionf (
			a.x*sp - a.y*sq,
			a.y*sp + a.x*sq,
			a.z*sp - a.w*sq,
			a.z);

		AssertIf (!CompareApproximately (SqrMagnitude (res), 1.0F) &&
					  CompareApproximately (SqrMagnitude (b), 1.0) &&
					  CompareApproximately (SqrMagnitude (a), 1.0));
		return res;
	}
}
*/

