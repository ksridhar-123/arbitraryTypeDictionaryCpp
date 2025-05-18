#pragma once

#include <iostream>
#include "GenericPtrWrapper.h"

#ifdef DICTIONARYCLASS_EXPORTS
#define DICTIONARY_API __declspec(dllexport)
#else
#define DICTIONARY_API __declspec(dllimport)
#endif

class DICTIONARY_API Dictionary;

DICTIONARY_API std::ostream& operator<<(std::ostream&, const Dictionary&);

class DICTIONARY_API Dictionary
{
	struct DICTIONARY_API Node;

	Node* _head;
	Node* _tail;

	int _length;

	template <typename keyType>
	Node* findKey(const keyType&);

	friend DICTIONARY_API std::ostream& operator<<(std::ostream&, const Dictionary&);

	struct DICTIONARY_API Node
	{
		GenericPtrWrapper _keyWrapper;
		GenericPtrWrapper _valWrapper;

		Node* _next;

		Node();

		Node(const Node*);

		template <typename keyType, typename valType>
		Node(const keyType&, const valType&);

		~Node();

		template <typename keyType>
		void insertKey(const keyType&);
	};

public:

	template <typename keyType, typename valType>
	Dictionary(const keyType&, const valType&);

	Dictionary();

	Dictionary(const int&);

	Dictionary(const Dictionary&);

	template <typename keyType>
	GenericPtrWrapper& operator[](const keyType&);

	template <typename keyType, typename valType>
	void insert(const keyType&, const valType&);

	template <typename keyType>
	void del(const keyType&);

	Dictionary operator+(const Dictionary&);

	~Dictionary();
};

#include "DictionaryI.h"