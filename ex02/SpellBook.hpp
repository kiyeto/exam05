#pragma once
#include <vector>
#include <string>
#include "ASpell.hpp"

class SpellBook
{
private:
	std::vector<ASpell*> spells;

	SpellBook(SpellBook const & other);
	SpellBook& operator=(SpellBook const & other);
public:
	SpellBook(){}
	~SpellBook()
	{
		std::vector<ASpell*>::iterator b = spells.begin();
		std::vector<ASpell*>::iterator e = spells.end();
		for (; b != e; b++)
			delete *b;
		spells.clear();
	}

	void	learnSpell(ASpell *sp)
	{
		std::vector<ASpell*>::iterator b = spells.begin();
		std::vector<ASpell*>::iterator e = spells.end();
		if (sp)
		{
			for (; b != e ; b++)
			{
				if ((*b)->getName() == sp->getName())
					return ;
			}
			spells.push_back(sp);
		}
	}

	void	forgetSpell(std::string const & sp_name)
	{
		std::vector<ASpell*>::iterator b = spells.begin();
		std::vector<ASpell*>::iterator e = spells.end();
		for (; b != e; b++)
		{
			if ((*b)->getName() == sp_name)
			{
				delete *b;
				spells.erase(b);
				return ;
			}
		}
	}

	ASpell* createSpell(std::string const & sp_name)
	{
		std::vector<ASpell*>::iterator b = spells.begin();
		std::vector<ASpell*>::iterator e = spells.end();
		for (; b != e; b++)
		{
			if ((*b)->getName() == sp_name)
				return *b;
		}
		return (NULL);
	}
};