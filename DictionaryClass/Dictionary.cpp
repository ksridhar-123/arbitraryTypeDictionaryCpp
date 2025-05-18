#include "Dictionary.h"

using namespace std;

Dictionary::Node::Node()
	: _keyWrapper(nullptr),
	_valWrapper(nullptr),
	_next(nullptr)
{}

Dictionary::Node::Node(const Node* node)
	: _keyWrapper(node->_keyWrapper),
	_valWrapper(node->_valWrapper),
	_next(nullptr)
{}

Dictionary::Node::~Node()
{}

Dictionary::Dictionary()
	: _head(nullptr),
	_tail(nullptr),
	_length(0)
{}

Dictionary::Dictionary(const int& length)
	: _head(nullptr),
	_tail(nullptr),
	_length(length)
{
	Node* prev = nullptr;

	for (int i = 0; i < this->_length; i++)
	{
		Node* tempNode = new Node;

		if (i)
			prev->_next = tempNode;

		else
			this->_head = tempNode;

		prev = tempNode;
	}

	this->_tail = prev;
}

Dictionary::Dictionary(const Dictionary& dict)
	: _head(nullptr),
	_tail(nullptr),
	_length(dict._length)
{
	Node* prev = nullptr;
	Node* dictNode = dict._head;

	for (int i = 0; i < this->_length; i++)
	{
		Node* tempNode = new Node(dictNode);

		if (i)
			prev->_next = tempNode;

		else
			this->_head = tempNode;

		prev = tempNode;

		dictNode = dictNode->_next;
	}

	this->_tail = prev;
}

Dictionary::~Dictionary()
{
	Node* tempNode = this->_head->_next;

	while (tempNode)
	{
		this->_head->_next = tempNode->_next;
		delete tempNode;
		tempNode = this->_head->_next;
	}

	delete this->_head;
}

Dictionary Dictionary::operator+(const Dictionary& dict)
{
	Dictionary tempDict(this->_length + dict._length);

	Node* tempNode1 = this->_head;
	Node* tempNode2 = tempDict._head;

	while (tempNode1)
	{
		tempNode2->_keyWrapper = tempNode1->_keyWrapper;
		tempNode2->_valWrapper = tempNode1->_valWrapper;

		tempNode1 = tempNode1->_next;
		tempNode2 = tempNode2->_next;
	}

	tempNode1 = dict._head;

	while (tempNode1)
	{
		tempNode2->_keyWrapper = tempNode1->_keyWrapper;
		tempNode2->_valWrapper = tempNode1->_valWrapper;

		tempNode1 = tempNode1->_next;
		tempNode2 = tempNode2->_next;
	}

	return tempDict;
}

ostream& operator<<(std::ostream& out, const Dictionary& dict)
{
	Dictionary::Node* tempNode = dict._head;

	out << "KEY\tVALUE" << endl;

	while (tempNode)
	{
		out << tempNode->_keyWrapper << "\t" << tempNode->_valWrapper << endl;

		tempNode = tempNode->_next;
	}

	return out;
}