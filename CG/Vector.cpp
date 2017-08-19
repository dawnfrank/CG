#include "Vector.h"
#include <assert.h>
#include <cmath>



inline
float& Vec3::operator[](int nIndex) {
	if(nIndex==0)return *(&x);
	else if(nIndex == 1)return *(&y);
	else if(nIndex == 2)return *(&z);
	else assert(0 && "no Valid Vector Index");
}

inline
bool Vec3::operator<(const Vec3 & vIn) const
{
	if (x == vIn.x) {
		if (y == vIn.x) return z < vIn.z;
		else return y < vIn.y;
	}
	else return x < vIn.x;
}

inline
bool Vec3::operator>(const Vec3 & vIn) const
{
	if (x == vIn.x) {
		if (y == vIn.x) return z > vIn.z;
		else return y > vIn.y;
	}
	else return x > vIn.x;
}

inline
bool Vec3::operator==(const Vec3 & vIn) const
{
	return (x == vIn.x && y == vIn.y && z == vIn.z);
}

inline
bool Vec3::operator!=(const Vec3 & vIn) const
{
	return (x != vIn.x || y != vIn.y || z != vIn.z);
}

inline
Vec3 Vec3::operator-(const Vec3 & vIn) const
{
	return Vec3(x - vIn.x,y - vIn.y,z - vIn.z);
}

inline
Vec3 Vec3::operator-=(const Vec3 & vIn)
{
	x -= vIn.x;
	y -= vIn.y;
	z -= vIn.z;
	return *this;
}


inline
Vec3 Vec3::operator+(const Vec3 & vIn) const
{
	return Vec3(x + vIn.x, y + vIn.y, z + vIn.z);
}

inline
Vec3 Vec3::operator+=(const Vec3 & vIn)
{
	x += vIn.x;
	y += vIn.y;
	z += vIn.z;
	return *this;
}

inline
Vec3 Vec3::operator*(const Vec3 & vIn) const
{
	return Vec3(x * vIn.x, y * vIn.y, z * vIn.z);
}

inline
Vec3 Vec3::operator*=(const Vec3 & vIn)
{
	x *= vIn.x;
	y *= vIn.y;
	z *= vIn.z;
	return *this;
}

inline
Vec3 Vec3::operator/(const Vec3 & vIn) const
{
	return Vec3(x / vIn.x, y / vIn.y, z / vIn.z);
}

inline
Vec3 Vec3::operator/=(const Vec3 & vIn)
{
	x /= vIn.x;
	y /= vIn.y;
	z /= vIn.z;
	return *this;
}

inline
Vec3 Vec3::operator*(float fScaler) const
{
	return Vec3(x * fScaler, y * fScaler, z * fScaler);
}

inline
Vec3 Vec3::operator*=(float fScaler)
{
	x *= fScaler;
	y *= fScaler;
	z *= fScaler;
	return *this;
}

inline
Vec3 Vec3::operator/(float fScaler) const
{
	return Vec3(x / fScaler, y / fScaler, z / fScaler);
}

inline
Vec3 Vec3::operator/=(float fScaler)
{
	x /= fScaler;
	y /= fScaler;
	z /= fScaler;
	return *this;
}

inline
Vec3 Vec3::operator-() const
{
	return Vec3(-x, -y, -z);
}

inline
void Vec3::Set(float x,float y,float z)
{
	x = x;
	y = y;
	z = z;
}

inline 
Vec3 Vec3::Cross(const Vec3& vIn) const 
{
	return Vec3(y * vIn.z - z * vIn.y, z * vIn.x - x * vIn.z, x * vIn.y - y * vIn.x);
}

inline
float Vec3::Distance(const Vec3& vIn) const
{
	return ((*this - vIn).Magnitude());
}

inline
float Vec3::DistanceSquared(const Vec3& vIn) const
{
	return ((*this - vIn).MagnitudeSquared());
}

inline
float Vec3::Dot(const Vec3& vIn) const
{
	return (x * vIn.x + y * vIn.y + z * vIn.z);
}

inline
float Vec3::Magnitude() const
{
	return float(sqrt(x * x + y * y + z * z));
}

inline
float Vec3::MagnitudeSquared() const
{
	return (x * x + y * y + z * z);
}

inline
Vec3 Vec3::Normalize()
{
	float fMagnitude = Magnitude();
	if (fMagnitude > 0)
		Scale(1.0f / fMagnitude);
	return *this;
}

inline 
void Vec3::Scale(float fScalar) {
	x *= fScalar;
	y *= fScalar;
	z *= fScalar;
}
