#ifndef CANDIDATELIST_H
#define CANDIDATELIST_H

#include "CandidateType.h"


#include <iostream>
#include <string>
#include <iomanip>
#include <list>
#include <algorithm>

class CandidateList
{
public:
	// Default constructor
	CandidateList();

	void addCandidate(const CandidateType& cand);

	int getWinner() const;

	bool isEmpty() const;
	
	bool searchCandidate(int id) const;
	
	void printCandidateName(int id) const;
	
	void printAllCandidates() const;
	
	void printKingdomVotes(int id, int idx) const;
	
	void printCandidateTotalVotes(int id) const;

	void printFinalResults() const;

	int getTheBiggestLoser() const;

	// Destructor
	~CandidateList();

	private:
	bool searchCandidate(int id, std::list<CandidateType>::const_iterator& iter) const;

	void printHeader() const;
	
	void printCandidate(std::list<CandidateType>::const_iterator iter, int pos) const;
	
	std::list<CandidateType> candidates;
};

#endif
