#pragma once

#include <iostream>
#include <iomanip>

#ifdef TYPECLASS_EXPORTS
#define TYPE_API __declspec(dllexport)
#else
#define TYPE_API __declspec(dllimport)
#endif

class Generic
{
public:

	TYPE_API Generic();

	virtual Generic* makeCopy() = 0;

	virtual bool isEqual(Generic*) = 0;

	virtual Generic* add(Generic*) = 0;

	virtual Generic* subtract(Generic*) = 0;

	virtual Generic* multiply(Generic*) = 0;

	virtual Generic* divide(Generic*) = 0;

	virtual void disp(std::ostream&) = 0;

	TYPE_API virtual ~Generic();
};