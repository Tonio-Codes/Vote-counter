#ifndef CANDIDATETYPE_H
#define CANDIDATETYPE_H

#include "CharacterType.h"

const int NUM_OF_KINGDOMS = 7;	// this is the capacity of the array
const std::string KINGDOMS[] = {
	"The North",
	"The Vale",
	"The Stormlands",
	"The Reach",
	"The Westerlands",
	"The Iron Islands",
	"Dorne" 
};

class CandidateType	: public CharacterType
{
public:
	// Default constructor
	CandidateType();
	// Copy constructor
	CandidateType(const CandidateType& otherCand);

	// Copy assignment operator
	CandidateType& operator=(const CandidateType& rhs);

	void updateVotesByKingdom(int idx, int numVotes);

	
	int getTotalVotes() const;

	int getVotesByKingdom(int idx) const;

	void printCandidateInfo() const;

	void printCandidateTotalVotes() const;
	

	bool operator==(int id) const;

	~CandidateType();
	
private:
	int totalVotes;
	int numOfKingdoms;
	int *kingdomVotes;
};

#endif
