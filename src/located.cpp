#include "located.h"

Located::Located(int x, int y)
{
	this->_x = x;
	this->_y = y;
}

Located::Located(const Located& loc)
{
	this->_x = loc._x;
	this->_y = loc._y;
}

 int Located::x() const
{
	return this->_x;
}
int Located::y() const
{
	return this->_y;
}

Located Located::getLocation() const
{
	return Located(this->_x, this->_y);
}

bool Located::isLocationEqual(const Located& loc1, const Located& loc2)
{
	return loc1._x == loc2._x && loc1._y == loc2._y;
}

bool Located::operator ==(const Located& loc2) const
{
	return this->_x == loc2._x && this->_y == loc2._y;
}

bool Located::operator !=(const Located& loc2) const
{
	return this->_x != loc2._x || this->_y != loc2._y;
}
