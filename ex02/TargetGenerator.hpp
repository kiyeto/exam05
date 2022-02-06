#pragma once

#include "ATarget.hpp"
#include <string>
#include <vector>

class TargetGenerator
{
private:
	std::vector<ATarget*> targets;

	TargetGenerator(TargetGenerator const & other);
	TargetGenerator& operator=(TargetGenerator const & other);
public:
	TargetGenerator(){}
	~TargetGenerator()
	{
		std::vector<ATarget*>::iterator b = targets.begin();
		std::vector<ATarget*>::iterator e = targets.end();
		for (; b != e ; b++)
			delete (*b);
		targets.clear();
	}

	void learnTargetType(ATarget* target)
	{
		std::vector<ATarget*>::iterator b = targets.begin();
		std::vector<ATarget*>::iterator e = targets.end();
		if (target)
		{
			for (; b != e ; b++)
			{
				if ((*b)->getType() == target->getType())
					return ;
			}
			targets.push_back(target->clone());
		}
	}

	void	forgetTargetType(std::string const & type)
	{
		std::vector<ATarget*>::iterator b = targets.begin();
		std::vector<ATarget*>::iterator e = targets.end();
		for (; b != e; b++)
		{
			if ((*b)->getType() == type)
			{
				delete *b;
				targets.erase(b);
				return ;
			}
		}
	}

	ATarget* createTarget(std::string const & type)
	{
		std::vector<ATarget*>::iterator b = targets.begin();
		std::vector<ATarget*>::iterator e = targets.end();
		for (; b != e; b++)
		{
			if ((*b)->getType() == type)
				return (*b);
		}
		return (NULL);
	}
};