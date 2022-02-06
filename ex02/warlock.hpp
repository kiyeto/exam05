#pragma once

#include <string>
#include <iostream>
#include <vector>
#include "ATarget.hpp"
#include "SpellBook.hpp"

class Warlock
{
private:
	std::string name;
	std::string	title;
	SpellBook	s_book;

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
		s_book.learnSpell(sp);
	}
	void	forgetSpell(std::string sp_name)
	{
		s_book.forgetSpell(sp_name);
	}

	void	launchSpell(std::string sp_name, ATarget & target)
	{
		ASpell* spell = s_book.createSpell(sp_name);
		if (spell)
			spell->launch(target);
	}
};