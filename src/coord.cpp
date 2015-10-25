#include "coord.h"
#include "movable.h"

Coord::Coord(int x, int y, QObject* parent) : Movable(x,y,parent) {}

Coord Coord::sum(const Located& left, const Located& right)
{
	return Coord(left.x()+right.x(), left.y()+right.y());
}

Coord Coord::sub(const Located& left, const Located& right)
{
	return Coord(left.x()-right.x(), left.y()-right.y());
}

Coord Coord::operator+(const Located& right)
{
	return Coord(this->x()+right.x(), this->y()+right.y());
}

Coord Coord::operator-(const Located& right)
{
	return Coord(this->x()-right.x(), this->y()-right.y());
}
