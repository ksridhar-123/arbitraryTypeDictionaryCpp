#include "Specific.h"

Generic* Specific<std::string>::subtract(Generic* ptr)
{
	Specific<std::string>* specificPtr = dynamic_cast<Specific<std::string>*>(ptr);

	if (specificPtr)
	{
		err::noSuchOp("-", "string");
		return nullptr;
	}

	else
	{
		err::incompatibleTypes("-", "string");
		return nullptr;
	}
}

Generic* Specific<std::string>::multiply(Generic* ptr)
{
	Specific<std::string>* specificPtr = dynamic_cast<Specific<std::string>*>(ptr);

	if (specificPtr)
	{
		err::noSuchOp("*", "string");
		return nullptr;
	}

	else
	{
		err::incompatibleTypes("*", "string");
		return nullptr;
	}
}

Generic* Specific<char>::multiply(Generic* ptr)
{
	Specific<std::string>* specificPtr = dynamic_cast<Specific<std::string>*>(ptr);

	if (specificPtr)
	{
		err::noSuchOp("*", "char");
		return nullptr;
	}

	else
	{
		err::incompatibleTypes("*", "char");
		return nullptr;
	}
}

Generic* Specific<std::string>::divide(Generic* ptr)
{
	Specific<std::string>* specificPtr = dynamic_cast<Specific<std::string>*>(ptr);

	if (specificPtr)
	{
		err::noSuchOp("/", "string");
		return nullptr;
	}

	else
	{
		err::incompatibleTypes("/", "string");
		return nullptr;
	}
}

Generic* Specific<char>::divide(Generic* ptr)
{
	Specific<std::string>* specificPtr = dynamic_cast<Specific<std::string>*>(ptr);

	if (specificPtr)
	{
		err::noSuchOp("/", "char");
		return nullptr;
	}

	else
	{
		err::incompatibleTypes("/", "char");
		return nullptr;
	}
}