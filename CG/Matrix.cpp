#include "Matrix.h"
#include <assert.h>
#include <cmath>
#include <string>

inline
Mat3x3::Mat3x3(bool bSetToIdentity) {
	if (bSetToIdentity) SetIdentity();
	else memset(afSingle, 0, 9 * sizeof(float));
}

inline
Mat3x3::Mat3x3(const float afInit[9])
{
	memcpy(afSingle, afInit, 9 * sizeof(float));
}

inline
Mat3x3::Mat3x3(const Vec3& vRight, const Vec3& vOut, const Vec3& vUp)
{
	afSingle[0] = vRight.x;
	afSingle[3] = vRight.y;
	afSingle[6] = vRight.z;

	afSingle[1] = vOut.x;
	afSingle[4] = vOut.y;
	afSingle[7] = vOut.z;

	afSingle[2] = vUp.x;
	afSingle[5] = vUp.y;
	afSingle[8] = vUp.z;
}

inline
Mat3x3::Mat3x3(const Mat3x3 &vIn)
{
	memcpy(afSingle, vIn.afSingle, 9 * sizeof(float));
}

inline
Mat3x3 Mat3x3::operator*(const Mat3x3& vIn) const
{
	Mat3x3 cTmp;

	for (int i = 0; i < 3; ++i)
	{
		cTmp.afRowCol[i][0] = afRowCol[i][0] * vIn.afRowCol[0][0] +
			afRowCol[i][1] * vIn.afRowCol[1][0] +
			afRowCol[i][2] * vIn.afRowCol[2][0];
		cTmp.afRowCol[i][1] = afRowCol[i][0] * vIn.afRowCol[0][1] +
			afRowCol[i][1] * vIn.afRowCol[1][1] +
			afRowCol[i][2] * vIn.afRowCol[2][1];
		cTmp.afRowCol[i][2] = afRowCol[i][0] * vIn.afRowCol[0][2] +
			afRowCol[i][1] * vIn.afRowCol[1][2] +
			afRowCol[i][2] * vIn.afRowCol[2][2];
	}

	return cTmp;
}

inline
Vec3 Mat3x3::operator*(const Vec3& vIn) const
{
	return Vec3(afRowCol[0][0] * vIn.x + afRowCol[0][1] * vIn.y + afRowCol[0][2] * vIn.z,
		afRowCol[1][0] * vIn.x + afRowCol[1][1] * vIn.y + afRowCol[1][2] * vIn.z,
		afRowCol[2][0] * vIn.x + afRowCol[2][1] * vIn.y + afRowCol[2][2] * vIn.z);
}


inline
bool Mat3x3::operator==(const Mat3x3& vIn) const
{
	return (memcmp(afSingle, vIn.afSingle, 9 * sizeof(float)) == 0);
}


inline 
bool Mat3x3::operator!=(const Mat3x3& vIn) const
{
	return (memcmp(afSingle, vIn.afSingle, 9 * sizeof(float)) != 0);
}

inline
void Mat3x3::SetIdentity(void)
{
	memset(afSingle, 0, 9 * sizeof(float));
	afSingle[0] = afSingle[4] = afSingle[8] = 1.0f;					
}

inline
void Mat3x3::Set(const float afValue[9])
{
	memcpy(afSingle, afValue, 9 * sizeof(float));
}

inline
void Mat3x3::RotateX(float fRadians)
{
	Mat3x3 mRotate;

	float fCosine = cosf(fRadians);
	float fSine = sinf(fRadians);

	mRotate.afRowCol[1][1] = fCosine;
	mRotate.afRowCol[1][2] = fSine;
	mRotate.afRowCol[2][1] = -fSine;
	mRotate.afRowCol[2][2] = fCosine;

	// this function can be further optimized by hardcoding
	// the multiplication here and removing terms with 0.0 multipliers
	*this = mRotate * *this;
}

inline
void Mat3x3::RotateY(float fRadians)
{
	Mat3x3 mRotate;

	float fCosine = cosf(fRadians);
	float fSine = sinf(fRadians);

	mRotate.afRowCol[0][0] = fCosine;
	mRotate.afRowCol[0][2] = -fSine;
	mRotate.afRowCol[2][0] = fSine;
	mRotate.afRowCol[2][2] = fCosine;

	// this function can be further optimized by hardcoding
	// the multiplication here and removing terms with 0.0 multipliers
	*this = mRotate * *this;
}

inline
void Mat3x3::RotateZ(float fRadians)
{
	Mat3x3 mRotate;

	float fCosine = cosf(fRadians);
	float fSine = sinf(fRadians);

	mRotate.afRowCol[0][0] = fCosine;
	mRotate.afRowCol[1][0] = -fSine;
	mRotate.afRowCol[0][1] = fSine;
	mRotate.afRowCol[1][1] = fCosine;

	// this function can be further optimized by hardcoding
	// the multiplication here and removing terms with 0.0 multipliers
	*this = mRotate * *this;
}

inline
void Mat3x3::RotateArbitrary(const Vec3& vAxis, float fRadians)
{
	float s = sinf(fRadians);
	float c = cosf(fRadians);
	float t = 1.0f - c;

	Vec3 vNormalizedAxis(vAxis);
	vNormalizedAxis.Normalize( );
	const float& x = vNormalizedAxis.x;
	const float& y = vNormalizedAxis.y;
	const float& z = vNormalizedAxis.z;

	Mat3x3 mRotate;
	mRotate.afRowCol[0][0] = t * x * x + c;
	mRotate.afRowCol[0][1] = t * x * y + s * z;
	mRotate.afRowCol[0][2] = t * x * z - s * y;
	mRotate.afRowCol[1][0] = t * x * y - s * z;
	mRotate.afRowCol[1][1] = t * y * y + c;
	mRotate.afRowCol[1][2] = t * y * z + s * x;
	mRotate.afRowCol[2][0] = t * x * z + s * y;
	mRotate.afRowCol[2][1] = t * y * z - s * x;
	mRotate.afRowCol[2][2] = t * z * z + c;

	*this = mRotate * *this;
}

inline
void Mat3x3::Scale(float x, float y, float z)
{
	afSingle[0] *= x;
	afSingle[1] *= x;
	afSingle[2] *= x;
	afSingle[3] *= y;
	afSingle[4] *= y;
	afSingle[5] *= y;
	afSingle[6] *= z;
	afSingle[7] *= z;
	afSingle[8] *= z;
}

inline
void Mat3x3::Scale(const Vec3& vScalar)
{
	Scale(vScalar.x, vScalar.y, vScalar.z);
}
