#pragma once

#include <string>
#include <iostream>
#include <vector>
#include "ATarget.hpp"

class Warlock
{
private:
	std::string name;
	std::string	title;
	std::vector<ASpell*> spells;

	Warlock();
	Warlock(Warlock const &other);
	Warlock& operator=(Warlock const & other);
public:
	~Warlock(){ std::cout << name << ": My job here is done!" << std::endl; }
	Warlock(std::string const & name, std::string const & title):name(name), title(title)
	{ std::cout << name << ": This looks like another boring day." << std::endl; }

	std::string const & getName() const
	{ return name; }

	std::string const & getTitle() const
	{ return title; }

	void	setTitle(std::string const & title)
	{ this->title = title; }

	void introduce() const 
	{ std::cout << name << ": I am " << name << ", " << title << "!" << std::endl; }

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
	void	forgetSpell(std::string sp_name)
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

	void	launchSpell(std::string sp_name, ATarget & target)
	{
		std::vector<ASpell*>::iterator b = spells.begin();
		std::vector<ASpell*>::iterator e = spells.end();
		for (; b != e; b++)
		{
			if ((*b)->getName() == sp_name)
			{
				(*b)->launch(target);
				return ;
			}
		}
	}
};