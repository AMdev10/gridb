#include "diagonaldistancefunction.h"
#include <QtMath>

float DiagonalDistanceFunction::operator()(int x1, int y1, int x2, int y2) const
{
	//dX = |x1-x2|
	//dY = |y1-y2|
	//d = max(dX, dY)
	return qMax(qAbs(x1-x2), qAbs(y1-y2));
}
