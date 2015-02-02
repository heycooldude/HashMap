#pragma once
#include "Interfaces05.h"
class HashNode
{
public:
	HashNode();
	~HashNode();
	int key;
	CompositeKey k;
	HashNode * node;
};

