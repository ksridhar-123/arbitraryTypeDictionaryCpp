#include "GenericPtrWrapper.h"

using namespace std;

GenericPtrWrapper::GenericPtrWrapper(Generic* ptr)
	: _ptr(ptr)
{}

GenericPtrWrapper::GenericPtrWrapper(const GenericPtrWrapper& ptrWrapper)
{
	this->_ptr = ptrWrapper._ptr->makeCopy();
}

GenericPtrWrapper::GenericPtrWrapper(GenericPtrWrapper&& ptrWrapper) noexcept
	:_ptr(ptrWrapper._ptr)
{
	ptrWrapper._ptr = nullptr;
}

Generic* GenericPtrWrapper::operator->()
{
	return _ptr;
}

GenericPtrWrapper::~GenericPtrWrapper()
{
	if (_ptr)
		delete _ptr;
}

void GenericPtrWrapper::operator=(const GenericPtrWrapper& ptrWrapper)
{
	if (this->_ptr)
		delete this->_ptr;

	this->_ptr = ptrWrapper._ptr->makeCopy();
}

void GenericPtrWrapper::operator=(GenericPtrWrapper&& ptrWrapper) noexcept
{
	if (this->_ptr)
		delete this->_ptr;

	this->_ptr = ptrWrapper._ptr;
	ptrWrapper._ptr = nullptr;
}

ostream& operator<<(ostream& out, const GenericPtrWrapper& ptrWrapper)
{
	ptrWrapper._ptr->disp(out);
	return out;
}

GenericPtrWrapper GenericPtrWrapper::operator+(const GenericPtrWrapper& ptrWrapper)
{
	Generic* ptr = this->_ptr->add(ptrWrapper._ptr);
	return GenericPtrWrapper(ptr);
}

GenericPtrWrapper GenericPtrWrapper::operator-(const GenericPtrWrapper& ptrWrapper)
{
	Generic* ptr = this->_ptr->subtract(ptrWrapper._ptr);
	return GenericPtrWrapper(ptr);
}

GenericPtrWrapper GenericPtrWrapper::operator*(const GenericPtrWrapper& ptrWrapper)
{
	Generic* ptr = this->_ptr->multiply(ptrWrapper._ptr);
	return GenericPtrWrapper(ptr);
}

GenericPtrWrapper GenericPtrWrapper::operator/(const GenericPtrWrapper& ptrWrapper)
{
	Generic* ptr = this->_ptr->divide(ptrWrapper._ptr);
	return GenericPtrWrapper(ptr);
}