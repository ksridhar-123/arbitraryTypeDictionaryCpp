#pragma once

#include "Generic.h"
#include "Specific.h"

#ifdef GENERICPTRWRAPPERCLASS_EXPORTS
#define GENERICPTRWRAPPER_API __declspec(dllexport)
#else
#define GENERICPTRWRAPPER_API __declspec(dllimport)
#endif

class GENERICPTRWRAPPER_API GenericPtrWrapper;

GENERICPTRWRAPPER_API std::ostream& operator<<(std::ostream&, const GenericPtrWrapper&);

class GENERICPTRWRAPPER_API GenericPtrWrapper
{
	Generic* _ptr;

	friend GENERICPTRWRAPPER_API std::ostream& operator<<(std::ostream&, const GenericPtrWrapper&);

public:

	GenericPtrWrapper(Generic*);

	GenericPtrWrapper(const GenericPtrWrapper&);

	GenericPtrWrapper(GenericPtrWrapper&&) noexcept;

	Generic* operator->();

	void operator=(const GenericPtrWrapper&);

	void operator=(GenericPtrWrapper&&) noexcept;

	template <typename keyValType>
	void operator=(const keyValType&);

	GenericPtrWrapper operator+(const GenericPtrWrapper&);

	GenericPtrWrapper operator-(const GenericPtrWrapper&);

	GenericPtrWrapper operator*(const GenericPtrWrapper&);

	GenericPtrWrapper operator/(const GenericPtrWrapper&);

	template <typename keyType>
	bool isEqual(const keyType&);

	~GenericPtrWrapper();
};

#include "GenericPtrWrapperI.h"