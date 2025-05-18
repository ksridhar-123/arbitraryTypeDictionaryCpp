#pragma once

template <typename keyValType>
void GenericPtrWrapper::operator=(const keyValType& val)
{
	if (this->_ptr)
		delete this->_ptr;

	this->_ptr = new Specific<keyValType>(val);
}

template <typename keyType>
bool GenericPtrWrapper::isEqual(const keyType& key)
{
	Generic* tempKey = new Specific<keyType>(key);
	bool retVal = _ptr->isEqual(tempKey);
	delete tempKey;

	return retVal;
}