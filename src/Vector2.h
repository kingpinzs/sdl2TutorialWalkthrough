#include <math.h>
class Vector2 
{
public:
	
	Vector2();
	Vector2(float x, float y);
	
	bool operator==(const Vector2& v) const;
	bool equals(const Vector2& v) const;
	bool operator!=(const Vector2& v) const;
	
	Vector2& operator+=(const Vector2& v);
	Vector2& operator-=(const Vector2& v);
	Vector2 operator+(const Vector2& v) const;
	Vector2 operator-(const Vector2& v) const;
	
	Vector2& operator*=(float scalar);
	Vector2& operator*(float scalar);
	Vector2& operator/=(float scalar);
	Vector2& operator/(float scalar);
	
	void normalize();
	
	float getX() const {return mX;}
	float getY() const {return mY;}
	
	void setX(float x) {mX = x;}
	void setY(float y) {mY = y;}
	void set(float x, float y);
	

	float length();
	Vector2 zero();
	Vector2 down();
	Vector2 left();
	Vector2 one();
	Vector2 right();
	Vector2 up();
	
private:
	float mX; 
	float mY;
};