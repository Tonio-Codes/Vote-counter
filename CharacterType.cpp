#include "CharacterType.h"

using namespace std;

void CharacterType::setCharacterInfo(const string& fName, const string& lName, int newId)
{
	firstName = fName;
	lastName = lName;
	id = newId;
}

string CharacterType::getFirstName() const
{
	return firstName;
}

string CharacterType::getLastName() const
{
	return lastName;
}

int CharacterType::getId() const
{
	return id;
}

void CharacterType:: printName() const
{
	cout << lastName << ", " << firstName;
}

void CharacterType::printCharacterInfo() const
{
	printId();
	cout << " " << firstName << " " << lastName;
}

void CharacterType::printId() const
{
	cout << "ID: " << id;
}

CharacterType::~CharacterType()
{

}
