#ifndef DIRECTION_H
#define DIRECTION_H
#include "src_global.h"

/**
 * @brief This class rappresent a one direction (up, down, ...)
 * @version 1.0
 * @since 1.0
 */
class SRCSHARED_EXPORT Direction
{
	public:

		/**
		 * @brief Create a new instance of direction
		 * @param coefficient X
		 * @param coefficient Y
		 */
		Direction(int coefficientX = 0, int coefficientY = 0);

		/**
		 * @brief Copy costructor of Direction
		 * @param dir
		 */
		Direction(const Direction& dir);

		/**
		 * @brief Return the coefficient of x
		 * @return The coefficient of x
		 */
		int getCoefficientX();
		/**
		 * @brief Return the coefficient of y
		 * @return The coefficient of y
		 */
		int getCoefficientY();

		/**
		 * @brief Direction NONE (0; 0)
		 */
		static Direction NONE;
		/**
		 * @brief Direction UP (0; -1)
		 */
		static Direction UP;
		/**
		 * @brief Direction UP_RIGHT (1; -1)
		 */
		static Direction UP_RIGHT;
		/**
		 * @brief Direction RIGHT (1; 0)
		 */
		static Direction RIGHT;
		/**
		 * @brief Direction DOWN_RIGHT (1; 1)
		 */
		static Direction DOWN_RIGHT;
		/**
		 * @brief Direction DOWN (0; 1)
		 */
		static Direction DOWN;
		/**
		 * @brief Direction DOWN_LEFT (-1; 1)
		 */
		static Direction DOWN_LEFT;
		/**
		 * @brief Direction LEFT (-1; 0)
		 */
		static Direction LEFT;
		/**
		 * @brief Direction UP_LEFT (-1; -1)
		 */
		static Direction UP_LEFT;

	protected:
		/**
		 * @brief Coefficient X of direction.
		 * * -1 to left
		 * * +1 to right
		 * * 0 no move
		 */
		short int coefficientX;
		/**
		 * @brief Coefficient Y of direction.
		 * * -1 to up
		 * * +1 to down
		 * * 0 no move
		 */
		short int coefficientY;

};

#endif // DIRECTION_H
