#pragma once
class Vec3
{
public:
	Vec3() :x(0.0f), y(0.0f), z(0.0f) {};								// defaults to (0, 0, 0)
	Vec3(float _x, float _y, float _z) :x(_x), y(_y), z(_z) {};
	Vec3(const Vec3 &vIn) :x(vIn.x),y(vIn.y),z(vIn.z) {};
	Vec3(const Vec3 &&vIn) :x(vIn.x), y(vIn.y), z(vIn.z) {};
	Vec3			operator=(const Vec3& vIn) { x = vIn.x; y = vIn.y; z = vIn.z; }
	Vec3			operator=(const Vec3&& vIn) { x = vIn.x; y = vIn.y; z = vIn.z; }
	~Vec3() {};

	// operators
	float&			operator[](int nIndex);
	bool			operator<(const Vec3& vIn) const;
	bool			operator>(const Vec3& vIn) const;
	bool			operator==(const Vec3& vIn) const;
	bool			operator!=(const Vec3& vIn) const;
	Vec3			operator-(const Vec3& vIn) const;
	Vec3			operator-=(const Vec3& vIn);
	Vec3			operator+(const Vec3& vIn) const;
	Vec3			operator+=(const Vec3& vIn);
	Vec3			operator*(const Vec3& vIn) const;
	Vec3			operator*=(const Vec3& vIn);
	Vec3			operator/(const Vec3& vIn) const;
	Vec3			operator/=(const Vec3& vIn);
	Vec3			operator*(float fScalar) const;
	Vec3			operator*=(float fScalar);
	Vec3			operator/(float fDivisor) const;
	Vec3			operator/=(float fDivisor);
	Vec3			operator-(void) const;

	// utility
	void			Set(float x, float y, float z);

	// mathematical operators
	Vec3			Cross(const Vec3& vIn) const;
	float			Distance(const Vec3& vIn) const;
	float			DistanceSquared(const Vec3& vIn) const;
	float			Dot(const Vec3& vIn) const;
	float			Magnitude(void) const;
	float			MagnitudeSquared(void) const;
	Vec3			Normalize(void);
	void			Scale(float fScalar);

	float			x, y, z;
};