#pragma once

template <typename keyType, typename valType>
Dictionary::Node::Node(const keyType& key, const valType& val)
	: _keyWrapper(new Specific<keyType>(key)),
	_valWrapper(new Specific<valType>(val)),
	_next(nullptr)
{}

template <typename keyType, typename valType>
Dictionary::Dictionary(const keyType& key, const valType& val)
{
	Node* tempNode = new Node(key, val);
	this->_head = tempNode;
	this->_tail = tempNode;

	this->_length = 1;
}

template <typename keyType>
void Dictionary::Node::insertKey(const keyType& key)
{
	_keyWrapper = key;
}

template <typename keyType>
Dictionary::Node* Dictionary::findKey(const keyType& key)
{
	Node* tempNode = this->_head;

	while (tempNode)
	{
		if (tempNode->_keyWrapper.isEqual(key))
			return tempNode;

		else
			tempNode = tempNode->_next;
	}

	return nullptr;
}

template <typename keyType>
GenericPtrWrapper& Dictionary::operator[](const keyType& key)
{
	if (Node* ptr = findKey(key))
		return ptr->_valWrapper;

	else
	{
		Node* tempNode = new Node;
		tempNode->insertKey(key);
		this->_tail->_next = tempNode;
		this->_tail = tempNode;
		this->_length++;
		return tempNode->_valWrapper;
	}
}

template <typename keyType, typename valType>
void Dictionary::insert(const keyType& key, const valType& val)
{
	Node* tempNode = new Node(key, val);
	this->_tail->_next = tempNode;
	this->_tail = tempNode;
	this->_length++;
}

template <typename keyType>
void Dictionary::del(const keyType& key)
{
	if (Node* ptr = findKey(key))
	{
		Node* tempNode = this->_head;
		while (tempNode->_next != ptr)
			tempNode = tempNode->_next;

		tempNode->_next = ptr->_next;

		if (ptr == this->_tail)
			this->_tail = tempNode;

		delete ptr;

		this->_length--;
	}

	else
		std::cout << "Cannot find the dictionary entry to delete!" << std::endl;
}