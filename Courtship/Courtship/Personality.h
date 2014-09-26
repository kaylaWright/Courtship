#ifndef _PERSONALITY_H_
#define _PERSONALITY_H_

#include <iostream>
#include <math.h>

class Personality
{
private:
	float m_baseFriendliness;

	//how strongly the personality reacts to situations. (multiplier)
	float m_reactiveness;
	//will factor in relationship with other personalities in 
	//larger shifts/changes. Insulting a 'friend' 
	float m_loyalty; 
protected: 
	//
public:
	//for random personalities.
	Personality();
	//for specific personalities
	//Personality();
	//destructor
	~Personality();
};

#endif