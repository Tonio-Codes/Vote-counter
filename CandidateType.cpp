#include "CandidateType.h"

using namespace std;

CandidateType::CandidateType() : CharacterType()
{
	totalVotes = 0;
	numOfKingdoms = NUM_OF_KINGDOMS;
	kingdomVotes = new int[numOfKingdoms] {};
}

CandidateType::CandidateType(const CandidateType& otherCand) : 
	CharacterType(otherCand.getFirstName(), otherCand.getLastName(), otherCand.getId())
{
	totalVotes = otherCand.totalVotes;
	numOfKingdoms = otherCand.numOfKingdoms;
	kingdomVotes = new int[numOfKingdoms];

	for (int i = 0; i < numOfKingdoms; ++i)
	{
		kingdomVotes[i] = otherCand.kingdomVotes[i];
	}
}

CandidateType& CandidateType::operator=(const CandidateType& rhs)
{
	if (&rhs != this)
	{
		if (numOfKingdoms != rhs.numOfKingdoms)
		{
			delete[] kingdomVotes;
			kingdomVotes = new int[rhs.numOfKingdoms];
			numOfKingdoms = rhs.numOfKingdoms;
		}
		totalVotes = rhs.totalVotes;
		this->setCharacterInfo(rhs.getFirstName(), rhs.getLastName(), rhs.getId());
		for (int i = 0; i < numOfKingdoms; ++i)
		{
			kingdomVotes[i] = rhs.kingdomVotes[i];
		}
	}
	else
	{
		cerr << "attempted to assign to itself" << endl;
	}
	return *this;
}

void CandidateType::updateVotesByKingdom(int idx, int numVotes)
{
	totalVotes += numVotes - kingdomVotes[idx];
	kingdomVotes[idx] = numVotes;
}

int CandidateType::getTotalVotes() const
{
	return totalVotes;
}

int CandidateType::getVotesByKingdom(int idx) const
{
	return kingdomVotes[idx];
}

void CandidateType::printCandidateInfo() const
{
	printId();
	cout << " - " << getLastName() << ", " << getFirstName();
}

void CandidateType::printCandidateTotalVotes() const
{
	printName();
	cout << endl << " => Total Votes (all kingdoms): " << totalVotes;
}

bool CandidateType::operator==(int id) const
{
	return this->getId() == id;
}

CandidateType::~CandidateType()
{
	delete [] kingdomVotes;
	kingdomVotes = nullptr;
}