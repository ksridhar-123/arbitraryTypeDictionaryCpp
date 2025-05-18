#pragma once

template <typename keyValType>
Specific<keyValType>::~Specific()
{}

template <typename keyValType>
Specific<keyValType>::Specific(keyValType var)
	: _var(var)
{}

template <typename keyValType>
Generic* Specific<keyValType>::makeCopy()
{
	return new Specific<keyValType>(this->_var);
}

template <typename keyValType>
bool Specific<keyValType>::isEqual(Generic* ptr)
{
	Specific<keyValType>* specificPtr = dynamic_cast<Specific<keyValType>*>(ptr);

	if (specificPtr)
	{
		if (this->_var == specificPtr->_var)
			return true;
		else
			return false;
	}

	else
		return false;
}

template <typename keyValType>
Generic* Specific<keyValType>::add(Generic* ptr)
{
	Specific<keyValType>* specificPtr = dynamic_cast<Specific<keyValType>*>(ptr);

	if (specificPtr)
	{
		keyValType newVar = this->_var + specificPtr->_var;
		return new Specific<keyValType>(newVar);
	}

	else
	{
		err::incompatibleTypes("+", typeid(keyValType).name());
		return nullptr;
	}
}

template <typename keyValType>
Generic* Specific<keyValType>::subtract(Generic* ptr)
{
	Specific<keyValType>* specificPtr = dynamic_cast<Specific<keyValType>*>(ptr);

	if (specificPtr)
	{
		keyValType newVar = this->_var - specificPtr->_var;
		return new Specific<keyValType>(newVar);
	}

	else
	{
		err::incompatibleTypes("-", typeid(keyValType).name());
		return nullptr;
	}
}

template <typename keyValType>
Generic* Specific<keyValType>::multiply(Generic* ptr)
{
	Specific<keyValType>* specificPtr = dynamic_cast<Specific<keyValType>*>(ptr);

	if (specificPtr)
	{
		keyValType newVar = this->_var * specificPtr->_var;
		return new Specific<keyValType>(newVar);
	}

	else
	{
		err::incompatibleTypes("*", typeid(keyValType).name());
		return nullptr;
	}
}

template <typename keyValType>
Generic* Specific<keyValType>::divide(Generic* ptr)
{
	Specific<keyValType>* specificPtr = dynamic_cast<Specific<keyValType>*>(ptr);

	if (specificPtr)
	{
		keyValType newVar = this->_var / specificPtr->_var;
		return new Specific<keyValType>(newVar);
	}

	else
	{
		err::incompatibleTypes("/", typeid(keyValType).name());
		return nullptr;
	}
}

template <typename keyValType>
void Specific<keyValType>::disp(std::ostream& out)
{
	out << _var;
}