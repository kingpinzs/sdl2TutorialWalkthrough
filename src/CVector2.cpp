#include "Vector2.h"

Vector2::Vector2() : mX(0), mY(0)
{ }
Vector2::Vector2(float x, float y) : mX(x), mY(y)
{ }
Vector2 Vector2::zero() {
	mX = 0;
	mY = 0;
	return *this;
}
Vector2 Vector2::down() {
	mX = 0;
	mY = -1;
	return *this;
}
Vector2 Vector2::left(){
	mX = -1;
	mY = 0;
	return *this;
}
Vector2 Vector2::one() {
	mX = 1;
	mY = 1;
	return *this;
}
Vector2 Vector2::right() {
	mX = 1;
	mY = 0;
	return *this;
}
Vector2 Vector2::up() {
    mX = 0;
	mY = 1;
	return *this;
}
void Vector2::set(float x, float y) {
	mX = x; 
	mY = y;
}

bool Vector2::operator==(const Vector2& v) const{
	return ((mX == v.getX()) && (mY == v.getY()));
}

bool Vector2::equals(const Vector2& v) const{
	return ((mX == v.getX()) && (mY == v.getY()));
}

bool Vector2::operator!=(const Vector2& v) const {
	return ((mX != v.getX()) || (mY != v.getY()));
}

Vector2& Vector2::operator+=(const Vector2& v) {
	mX += v.getX();
	mY += v.getY();
	
	return *this;
}

Vector2 Vector2::operator+(const Vector2& v) const {
	
	Vector2 temp(*this);
	temp += v;
	return temp;
}

Vector2& Vector2::operator*=(float scalar) {
	mX *= scalar;
	mY *= scalar;
	
	return *this;
}

Vector2& Vector2::operator*(float scalar) {
	
	Vector2 temp(*this);
	temp *= scalar;
	
	return temp;
}

Vector2& Vector2::operator-=(const Vector2& v) {
	mX -= v.getX();
	mY -= v.getY();
	
	return *this;
}

Vector2 Vector2::operator-(const Vector2& v) const {
	
	Vector2 temp(*this);
	temp -= v;
	return temp;
}

Vector2& Vector2::operator/=(float scalar) {
	mX /= scalar;
	mY /= scalar;
	
	return *this;
}

Vector2& Vector2::operator/(float scalar) {
	
	Vector2 temp(*this);
	temp /= scalar;
	return temp;
}

float Vector2::length() {
	return sqrt((mX*mX) + (mY*mY));
}

void Vector2::normalize() {
	float len = length();
	if (len > 0) {
		(*this) *= 1/1;
	}
}