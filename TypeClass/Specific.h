#pragma once

#include "Generic.h"
#include "ErrorFuncs.h"

template <typename keyValType>
class Specific
	: public Generic
{
	keyValType _var;

public:

	Specific(keyValType var);

	virtual Generic* makeCopy() override;

	virtual bool isEqual(Generic*) override;

	virtual Generic* add(Generic*) override;

	virtual Generic* subtract(Generic*) override;

	virtual Generic* multiply(Generic*) override;

	virtual Generic* divide(Generic*) override;

	virtual void disp(std::ostream&) override;

	virtual ~Specific() override;
};

#include "SpecificI.h"

template TYPE_API Generic* Specific<std::string>::subtract(Generic* ptr);

template TYPE_API Generic* Specific<std::string>::multiply(Generic* ptr);

template TYPE_API Generic* Specific<char>::multiply(Generic* ptr);

template TYPE_API Generic* Specific<std::string>::divide(Generic* ptr);

template TYPE_API Generic* Specific<char>::divide(Generic* ptr);