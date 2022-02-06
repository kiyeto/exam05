#pragma once

#include <string>
#include <iostream>

#include "ASpell.hpp"

class ATarget
{
private:
	std::string type;

public:
	ATarget(){}
	ATarget(std::string type):type(type){}
	virtual ~ATarget(){}
	ATarget(ATarget const & other){ *this = other; }
	ATarget& operator=(ATarget const & other)
	{ this->type = other.type; return *this; }

	std::string const & getType() const { return type;}

	virtual ATarget* clone() const = 0;

	void	getHitBySpell(const ASpell & spell) const
	{ std::cout << type << " has been " << spell.getEffects() << "!" << std::endl; }
};