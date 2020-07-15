#pragma once

typedef struct _tagResolution
{
	unsigned int width;
	unsigned int height;
}RESOLUTION, *PRESOLUTION;

typedef struct _tagPosition
{
	float x, y;

	/* 생성자 파트 */
	_tagPosition() :
		x(0.f),
		y(0.f) {}

	_tagPosition(float _x, float _y) :
		x(_x), y(_y) {}

	_tagPosition(const _tagPosition& pos)
	{
		x = pos.x;
		y = pos.y;
	}

	_tagPosition(const POINT& pt)
	{
		x = pt.x;
		y = pt.y;
	}

	/* 연산자 오버로딩 파트 */
	void operator=(const _tagPosition& rhs)
	{
		x = rhs.x;
		y = rhs.y;
	}

	void operator=(const POINT& pt)
	{
		x = pt.x;
		y = pt.y;
	}

	void operator=(float f[2])
	{
		x = f[0];
		y = f[1];
	}

	/* + */
	_tagPosition operator+(const _tagPosition& rhs)
	{
		_tagPosition tPos;
		tPos.x = this->x + rhs.x;
		tPos.y = this->y + rhs.y;
		return tPos;
	}

	_tagPosition operator+(const POINT& rhs)
	{
		_tagPosition tPos;
		tPos.x = this->x + rhs.x;
		tPos.y = this->y + rhs.y;
		return tPos;
	}

	_tagPosition operator+(float f[2])
	{
		_tagPosition tPos;
		tPos.x = this->x + f[0];
		tPos.y = this->y + f[1];
		return tPos;
	}

	_tagPosition operator+(float f)
	{
		_tagPosition tPos;
		tPos.x = this->x + f;
		tPos.y = this->y + f;
		return tPos;
	}

	/* - */
	_tagPosition operator-(const _tagPosition& rhs)
	{
		_tagPosition tPos;
		tPos.x = this->x - rhs.x;
		tPos.y = this->y - rhs.y;
		return tPos;
	}

	_tagPosition operator-(const POINT& rhs)
	{
		_tagPosition tPos;
		tPos.x = this->x - rhs.x;
		tPos.y = this->y - rhs.y;
		return tPos;
	}

	_tagPosition operator-(float f[2])
	{
		_tagPosition tPos;
		tPos.x = this->x - f[0];
		tPos.y = this->y - f[1];
		return tPos;
	}

	_tagPosition operator-(float f)
	{
		_tagPosition tPos;
		tPos.x = this->x - f;
		tPos.y = this->y - f;
		return tPos;
	}

	/* * */
	_tagPosition operator*(const _tagPosition& rhs)
	{
		_tagPosition tPos;
		tPos.x = this->x * rhs.x;
		tPos.y = this->y * rhs.y;
		return tPos;
	}

	_tagPosition operator*(const POINT& rhs)
	{
		_tagPosition tPos;
		tPos.x = this->x * rhs.x;
		tPos.y = this->y * rhs.y;
		return tPos;
	}

	_tagPosition operator*(float f[2])
	{
		_tagPosition tPos;
		tPos.x = this->x * f[0];
		tPos.y = this->y * f[1];
		return tPos;
	}

	_tagPosition operator*(float f)
	{
		_tagPosition tPos;
		tPos.x = this->x * f;
		tPos.y = this->y * f;
		return tPos;
	}

	/* / */
	_tagPosition operator/(const _tagPosition& rhs)
	{
		_tagPosition tPos;
		tPos.x = this->x / rhs.x;
		tPos.y = this->y / rhs.y;
		return tPos;
	}

	_tagPosition operator/(const POINT& rhs)
	{
		_tagPosition tPos;
		tPos.x = this->x / rhs.x;
		tPos.y = this->y / rhs.y;
		return tPos;
	}

	_tagPosition operator/(float f[2])
	{
		_tagPosition tPos;
		tPos.x = this->x / f[0];
		tPos.y = this->y / f[1];
		return tPos;
	}

	_tagPosition operator/(float f)
	{
		_tagPosition tPos;
		tPos.x = this->x / f;
		tPos.y = this->y / f;
		return tPos;
	}
}POSITION, *PPOSITION, _SIZE, *_PSIZE;