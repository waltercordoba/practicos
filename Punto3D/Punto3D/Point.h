#pragma once
namespace Cpp_math
{
	class Point
	{
	public:
		Point() : mX(0.0f), mY(0.0f), mZ(0.0f) {}
		Point(const float x, const float y, const float z);
		Point(const Point& p);
		Point getAddition(const Point& p);
		Point getSubtraction(const Point & p);
		const Point& add(const Point& p);
		const Point & subtract(const Point & p);
		float distance(const Point& p);
		float getmX() { return mX; }
		float getmY() { return mY; }
		float getmZ() { return mZ; }
		void setmX(const float _mX) { mX = _mX; }
		void setmY(const float _mY) { mY = _mY; }
		void setmZ(const float _mZ) { mZ = _mZ; }
		void operator=(const Point p);
		~Point();
	private:
		float mX;
		float mY;
		float mZ;

	};
}
