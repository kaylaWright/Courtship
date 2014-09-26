#ifndef _PERSON_H_
#define _PERSON_H_

#include <iostream>
#include <vector>

#include "Personality.h"
#include "Relationship.h"

class Person
{
private:
protected:
public:
	//name of the person.
	std::string m_name;
	//the person's personality; can be random or fixed.
	Personality *m_personality;
	//a list of relationships based off the characters present. 
	//Vector<*Relationship> m_relationships;
};

#endif