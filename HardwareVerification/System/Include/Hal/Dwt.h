/*
 * Dwt.h
 *
 *  Created on: 1 Jun 2019
 *      Author: yuri
 */

#ifndef HAL_DWT_H
#define HAL_DWT_H

#include <cstdint>
#include "HalCommon.h"

namespace Hal
{

class Dwt
{
public:
	Dwt();
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// @brief	Delay at HAL level in microsecond.
	///
	/// @param	us	Time is microseconds.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static void DelayMicrosecond(uint32_t us);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// @brief	Delay at HAL level in milliseconds.
	///
	/// @param	ms	The milliseconds.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static void DelayMilliseconds(uint32_t ms);
};
} // namespace Hal

#endif