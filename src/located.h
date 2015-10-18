#ifndef LOCATED_H
#define LOCATED_H

#include "src_global.h"

/**
 * @brief This class is the base class of any non-movable objects
 *		  and it can rappresent a fixed position in 2D space
 * @author amreo
 * @version 0.1
 * @since 0.1
 */
class SRCSHARED_EXPORT Located
{

	public:
		/**
		 * @brief Create a new instance of fixed position
		 * @param Coordinate x
		 * @param Coordinate y
		 */
		Located(int x = 0, int y = 0);

		/**
		 * @brief Create a new instance of fixed position from located object
		 * @param Located object
		 */
		Located(const Located& loc);

		/**
		 * @brief Return the X coordinate
		 * @return X coordinate
		 */
		int x() const;
		/**
		 * @brief Return the Y coordinate
		 * @return Y coordinate
		 */
		int y() const;
		/**
		 * @brief Return the location of this object
		 * @return Location of this object
		 */
		Located getLocation();

	protected:
		/**
		 * @brief Coordinate x
		 */
		int _x;
		/**
		 * @brief Coordinate y
		 */
		int _y;
};

#endif // LOCATED_H
