#ifndef CHARACTERTYPE_H
#define CHARACTERTYPE_H

#include <iostream>
#include <string>

class CharacterType
{
public:
	// Default constructor
	CharacterType() : id{ 0 } {};
  	// Overloaded constructor
	CharacterType(const std::string& fName, const std::string& lName, int newId)
		: firstName{ fName }, lastName{ lName }, id{ newId } {};
		
	
	void setCharacterInfo(const std::string& fName, const std::string& lName, int newId);
		
	
	std::string getFirstName() const;
	
	std::string getLastName() const;

	
	int getId() const;


	void printName() const;
	
	void printCharacterInfo() const;

	void printId() const;

	
	~CharacterType();

private:
	std::string firstName;	
	std::string lastName;	
	int id;					
};

#endif 

