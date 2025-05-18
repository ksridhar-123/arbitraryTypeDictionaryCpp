#pragma once

#include <iostream>
#include "Generic.h"

namespace err
{
	TYPE_API void incompatibleTypes(std::string, std::string);

	TYPE_API void noSuchOp(std::string, std::string);
}