#include "HashMap.h"
#include "HashNode.h"

HashMap::HashMap()
{
	//node = NULL;
	for (int i = 0; i < 15; i++){

		hash.push_back(NULL);
	}
}


HashMap::~HashMap()
{
}

void HashMap::insert(CompositeKey key, int value){
	vec.push_back(key);
	int haskeyvalue = key.key3 % 15;
	HashNode * cur=new HashNode();
	cur->key=value;
	cur->k = key;
	
	if (hash[haskeyvalue] == NULL)
	{
		hash[haskeyvalue] = cur;
		siz++;
	}
	else{
		HashNode * temp;	
		temp=hash[haskeyvalue];
		while (temp->node != NULL){
			temp = temp->node;
		}
		temp->node = cur;
		siz++;
	}

}
void HashMap::remove(CompositeKey key){
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] == key){
			for (int j = i; j < vec.size()-1; j++){
				vec[j] = vec[j+1 ];
			}

			vec.pop_back();
			break;
		}
	}
	int haskeyvalue = key.key3 % 15;
	HashNode * cur = hash[haskeyvalue];
	//cur->k = key;
	HashNode * temp = hash[haskeyvalue];
	//if (temp != NULL){
		if (temp == NULL)
		{
			return;
		}
		else {
			if (temp->k == key){
				hash[haskeyvalue] = hash[haskeyvalue]->node;
				siz--;
			}
			else
			{
				HashNode * prev = new HashNode();
				
				while (cur != NULL){
					
					if (cur->k == key){
						prev->node = cur->node;
						siz--;
						break;
						//delete cur;
					}
					prev = cur;
						cur = cur->node;
					
				}

			}
		}
		//temp = temp->node;
	//}
}
bool HashMap::containsKey(CompositeKey key){
	int haskeyvalue = key.key3 % 15;
	HashNode * cur=hash[haskeyvalue];
	while (cur != NULL){
		if (cur->k == key)
			return true;
		else
			cur = cur->node;
	}
	return false;
}
int HashMap::getValue(CompositeKey key){ 
	int haskeyvalue = key.key3 % 15;
	HashNode * cur = hash[haskeyvalue];
	while (cur != NULL){
		if (cur->k == key)
			return cur->key;
		else
			cur = cur->node;
	}
	//return cur->key;
}
int HashMap::kthMinValue(int k){  
	sort();
	//int haskeyvalue = key.key3 % 15;
	return getValue(vec[k]);
}
void HashMap::sort(){
	int i,j;
	CompositeKey key;
	for (j = 1; j < vec.size(); j++)    // Start with 1 (not 0)
	{
		key = vec[j];
		for (i = j - 1; (i >= 0) && (key<vec[i]  ); i--)   // Smaller values move up
		{
			vec[i + 1] = vec[i];
		}
		vec[i + 1] = key;    //Put key into its proper location
	}
	

}
int HashMap::size(){ return siz; }
