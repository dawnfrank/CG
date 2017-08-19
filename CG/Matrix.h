#pragma once
#include "Vector.h"

class Mat3x3{
public:
	Mat3x3(bool bSetToIdentity = true);
	Mat3x3(const float afInit[9]);
	Mat3x3(const Vec3& vRight, const Vec3& vOut, const Vec3& vUp);
	Mat3x3(const Mat3x3 &vIn);

	// operators
	Mat3x3			operator*(const Mat3x3& vIn) const;
	Vec3			operator*(const Vec3& vIn) const;
	bool			operator==(const Mat3x3& vIn) const;
	bool			operator!=(const Mat3x3& vIn) const;

	// utility
	void			SetIdentity(void);
	void			Set(const float afValue[9]);

	// mathematical operations
	void			RotateX(float fRadians);
	void			RotateY(float fRadians);
	void			RotateZ(float fRadians);
	void			RotateArbitrary(const Vec3& vAxis, float fRadius);
	void			Scale(float x, float y, float z);
	void			Scale(const Vec3& vScalar);

	union
	{
		float	afSingle[9];
		float	afRowCol[3][3];

		// afSingle[0] = mafRowCol[0][0]
		// afSingle[1] = mafRowCol[0][1]
		// afSingle[2] = mafRowCol[0][2]
		// afSingle[3] = mafRowCol[1][0]
		// afSingle[4] = mafRowCol[1][1]
		// afSingle[5] = mafRowCol[1][2]
		// afSingle[6] = mafRowCol[2][0]
		// afSingle[7] = mafRowCol[2][1]
		// afSingle[8] = mafRowCol[2][2]
	};
};