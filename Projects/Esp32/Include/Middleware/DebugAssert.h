#pragma once

#include "ErrorList.h"
#include <cstdint>
#include <cstdarg>

#ifndef __ASSERT_FUNC
#ifdef __ASSERT_FUNCTION
#define __ASSERT_FUNC __ASSERT_FUNCTION /* used in glibc assert.h */
#else
#define __ASSERT_FUNC "??"
#endif
#endif

#ifndef NDEBUG
#define DEBUG
#endif

#ifdef DEBUG
/**
 * @brief Test the result, if different prints the error and breaks in an assert
 * @param function					The function the check the result
 * @param result					The result expected
 */
#define DebugAssert(function, result)                                     \
	do                                                                    \
	{                                                                     \
		int __err_rc = (int)function;                                     \
		if (__err_rc != result)                                           \
		{                                                                 \
			Middleware::DebugAssert::Assert(__err_rc, __FILE__, __LINE__, \
											__ASSERT_FUNC, #function);    \
		}                                                                 \
	} while (0)

/**
 * @brief Test the result, if different prints the error
 * @param function					The function the check the result
 * @param result					The result expected
 */
#define DebugAssertWithoutAbort(function, result) ({                                 \
	esp_err_t __err_rc = (int)function;                                              \
	if (__err_rc != result)                                                          \
	{                                                                                \
		Middleware::DebugAssert::AssertWithoutBreaking(__err_rc, __FILE__, __LINE__, \
													   __ASSERT_FUNC, #function);    \
	}                                                                                \
	__err_rc;                                                                        \
})
#else
#define DebugAssert(function) function
#define DebugAssertWithoutAbort(x) function
#endif

namespace Middleware
{

class DebugAssert
{
public:

	void Assert();

public:
	static void Assert(int rc, const char *file, int line, const char *function, const char *expression);
	static void AssertWithoutBreaking(int rc, const char *file, int line, const char *function, const char *expression);

private:
	static void abort();
	static const char *GetErrorName(int code);
};

} // namespace Middleware