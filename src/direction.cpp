#include "direction.h"
#include <QDebug>


Direction::Direction(int coefficientX, int coefficientY)
{

    _coefficientX = qBound(-1, coefficientX, 1);
    _coefficientY = qBound(-1,coefficientY, 1);
}

Direction::Direction(const Direction& dir)
{
    _coefficientX = dir._coefficientX;
    _coefficientY = dir._coefficientY;
}

int Direction::coefficientX() const
{
    return _coefficientX;
}

int Direction::coefficientY() const
{
    return _coefficientY;
}

int Direction::getDirectionAngle() const
{
	if (Direction::equal(*this, Direction::UP))
		return 0;
	else if (Direction::equal(*this, Direction::UP_RIGHT))
		return 1;
	else if (Direction::equal(*this, Direction::RIGHT))
		return 2;
	else if (Direction::equal(*this, Direction::DOWN_RIGHT))
		return 3;
	else if (Direction::equal(*this, Direction::DOWN))
		return 4;
	else if (Direction::equal(*this, Direction::DOWN_LEFT))
		return 5;
	else if (Direction::equal(*this, Direction::LEFT))
		return 6;
	else if (Direction::equal(*this, Direction::UP_LEFT))
		return 7;
	return 0;
}

Direction Direction::getDirectionOpposite() const
{
    return Direction(-_coefficientX, -_coefficientY);
}

Direction Direction::getDirectionRotated(int angle) const
{
	if (Direction::equal(Direction::NONE, *this)) return Direction::NONE;
	Direction dir = Direction::NONE;
    dir.setDirection(getDirectionAngle() + angle);
	return dir;
}

void Direction::setDirection(const Direction& dir)
{
    _coefficientX = dir._coefficientX;
    _coefficientY = dir._coefficientY;
}

void Direction::setDirection(const int coefficientX, const int coefficientY)
{
    _coefficientX = qBound(-1, coefficientX, 1);
    _coefficientY = qBound(-1,coefficientY, 1);
}

void Direction::setDirection(int angle)
{
	//simply and positivity angle
	angle %= 8;
	if (angle < 0) angle = 8+angle;
	switch (angle) {
		case 0:
            setDirection(Direction::UP);
			return;
		case 1:
            setDirection(Direction::UP_RIGHT);
			return;
		case 2:
            setDirection(Direction::RIGHT);
			return;
		case 3:
            setDirection(Direction::DOWN_RIGHT);
			return;
		case 4:
            setDirection(Direction::DOWN);
			return;
		case 5:
            setDirection(Direction::DOWN_LEFT);
			return;
		case 6:
            setDirection(Direction::LEFT);
			return;
		case 7:
            setDirection(Direction::UP_LEFT);
			return;
	}
}

void Direction::setCoefficientX(const int coefficientX)
{
    _coefficientX = qBound(-1,coefficientX,1);
}

void Direction::setCoefficientY(const int coefficientY)
{
    _coefficientY = qBound(-1,coefficientY,1);
}

Direction Direction::sum(const Direction& dir1, const Direction& dir2)
{
	return Direction(dir1._coefficientX + dir2._coefficientX, dir1._coefficientY + dir2._coefficientY);
}

Direction Direction::sum(const int coeX1, const int coeY1, const int coeX2, const int coeY2)
{
	return Direction(coeX1+coeX2, coeY1+coeY2);
}

Direction Direction::sub(const Direction& dir1, const Direction& dir2)
{
	return Direction(dir1._coefficientX - dir2._coefficientX, dir1._coefficientY - dir2._coefficientY);
}

Direction Direction::sub(const int coeX1, const int coeY1, const int coeX2, const int coeY2)
{
	return Direction(coeX1-coeX2, coeY1-coeY2);
}

bool Direction::equal(const Direction& dir1, const Direction& dir2)
{
	return dir1._coefficientX == dir2._coefficientX && dir1._coefficientY == dir2._coefficientY;
}

Direction Direction::operator+(const Direction& dir2)
{
    return Direction(_coefficientX + dir2._coefficientX, _coefficientY + dir2._coefficientY);
}

Direction Direction::operator-(const Direction& dir2)
{
    return Direction(_coefficientX - dir2._coefficientX, _coefficientY - dir2._coefficientY);
}

bool Direction::operator==(const Direction& dir2)
{
    return _coefficientX == dir2._coefficientX && _coefficientY == dir2._coefficientY;
}

bool Direction::operator!=(const Direction& dir2)
{
    return _coefficientX != dir2._coefficientX || _coefficientY != dir2._coefficientY;
}

Direction Direction::operator<<(int times)
{
    return getDirectionRotated(-times);
}

Direction Direction::operator>>(int times)
{
    return getDirectionRotated(times);
}

const Direction Direction::NONE = Direction(0, 0);
const Direction Direction::UP = Direction(0, -1);
const Direction Direction::UP_RIGHT = Direction(1, -1);
const Direction Direction::RIGHT = Direction(1, 0);
const Direction Direction::DOWN_RIGHT = Direction(1, 1);
const Direction Direction::DOWN = Direction(0, 1);
const Direction Direction::DOWN_LEFT = Direction(-1, 1);
const Direction Direction::LEFT  = Direction(-1, 0);
const Direction Direction::UP_LEFT = Direction(-1, -1);
