#pragma once

#include <string>
#include <iostream>

class ATarget;

class ASpell
{
protected:
	std::string name;
	std::string effects;

public:
	ASpell(){}
	ASpell(std::string name, std::string effects): name(name), effects(effects){}
	virtual ~ASpell(){}
	ASpell(ASpell const & other) { *this = other; }
	ASpell& operator=(ASpell const & other)
	{ this->name = other.name; this->effects = other.effects; return *this; }

	std::string const & getName() const { return name; }
	std::string const & getEffects() const { return effects; }

	virtual ASpell*	clone() const = 0;

	void	launch(ATarget const & target) const;
};
#include "ATarget.hpp"


