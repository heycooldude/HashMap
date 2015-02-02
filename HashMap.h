#pragma once
#include "Interfaces05.h"
#include "HashNode.h"
class HashMap:public IHashMap
{
public:
	HashMap();
	~HashMap();
	void insert(CompositeKey key, int value) ;
	 void remove(CompositeKey key) ;
	 bool containsKey(CompositeKey key) ;
	 int getValue(CompositeKey key) ;
	 int kthMinValue(int k) ;
	 int size();
	 std::vector<HashNode *> hash;
	 std::vector<CompositeKey> vec;
	 void sort();
	 HashNode * prev;
	 int siz;
};

