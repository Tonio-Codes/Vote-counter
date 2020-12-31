#include "CandidateList.h"
#include <list>
#include <algorithm>

using namespace std;

CandidateList::CandidateList()
{

}

void CandidateList::addCandidate(const CandidateType& cand)
{
	candidates.push_back(cand);
}

int CandidateList::getWinner() const
{
	list<CandidateType>::const_iterator iter = candidates.cbegin();
	list<CandidateType>::const_iterator end = candidates.cend();
	int winnerId = iter->getId();
	int winnerVotes = iter->getTotalVotes();

	while (iter != end)
	{
		if (iter->getTotalVotes() > winnerVotes)
		{
			winnerId = iter->getId();
			winnerVotes = iter->getTotalVotes();
		}
		++iter;
	}
	return winnerId;
}

bool CandidateList::isEmpty() const
{
	return (candidates.empty());
}

bool CandidateList::searchCandidate(int id) const
{
	list<CandidateType>::const_iterator iter = candidates.cbegin();
	return searchCandidate(id, iter);
}

void CandidateList::printCandidateName(int id) const
{
	list<CandidateType>::const_iterator iter = candidates.cbegin();
	if (searchCandidate(id, iter))
	{
		iter->printName();
	}
}

void CandidateList::printAllCandidates() const
{
	list<CandidateType>::const_iterator iter = candidates.cbegin();
	list<CandidateType>::const_iterator end = candidates.cend();
	while (iter != end)
	{
		iter->printCandidateInfo();
		cout << endl;
		++iter;
	}
}

void CandidateList::printKingdomVotes(int id, int idx) const
{
	
	list<CandidateType>::const_iterator iter = candidates.cbegin();
	if (searchCandidate(id, iter))
	{
		if (iter->getVotesByKingdom(idx) < 10)
		{
			cout << setw(6) << "* " << setw(2) << iter->getVotesByKingdom(idx) << "( => )" << KINGDOMS[idx];
			cout << endl;
		}
		else
		{
			cout << setw(6) << "* " << iter->getVotesByKingdom(idx) << "( => )" << KINGDOMS[idx];
			cout << endl;
		}
	}
}

void CandidateList::printCandidateTotalVotes(int id) const
{
	list<CandidateType>::const_iterator iter = candidates.cbegin();
	if (searchCandidate(id, iter))
	{
		cout << setfill(' ') << setw(20) << "=> Total Votes: " << iter->getTotalVotes();
	}
}

void CandidateList::printFinalResults() const
{
	list<CandidateType>::const_iterator iter = candidates.cbegin();
	list<CandidateType>::const_iterator winner = candidates.cbegin();
	printHeader();

	int highestVotes = getWinner();
	int position = 0;
	
	for (auto iter2 = candidates.cbegin(); iter2 != candidates.cend(); ++iter2)
	{
		while (iter != candidates.cend())
		{
			if (iter->getTotalVotes() > winner->getTotalVotes() && iter->getTotalVotes() < highestVotes)
			{
				winner = iter;
			}
			else if (winner->getTotalVotes() >= highestVotes)
			{
				++winner;
			}
			++iter;
		}
		++position;
		printCandidate(winner, position);

		highestVotes = winner->getTotalVotes();
		winner = candidates.cbegin();
		iter = candidates.cbegin();
	}

}

int CandidateList::getTheBiggestLoser() const
{
	list<CandidateType>::const_iterator iter = candidates.cbegin();
	list<CandidateType>::const_iterator end = candidates.cend();
	int loserId = iter->getId();
	int losersVotes = iter->getTotalVotes();

	while (iter != end)
	{
		if (iter->getTotalVotes() < losersVotes)
		{
			loserId = iter->getId();
			losersVotes = iter->getTotalVotes();
		}
		++iter;
	}
	return loserId;
}

CandidateList::~CandidateList()
{
	
}

bool CandidateList::searchCandidate(int id, list<CandidateType>::const_iterator& iter) const
{
	iter = find(iter, candidates.cend(), id);
	if (iter != candidates.cend())
	{
		return true;
	}
	else
	{
		cerr << setw(26) <<"=> Id not in the list.";
		return false;
	}
}

void CandidateList::printHeader() const
{
	cout << "************ FINAL RESULTS ************\n\n"
		<< "LAST           FIRST     TOTAL    POS\n"
		<< "NAME           NAME      VOTES      #\n"
		<< "_______________________________________\n\n";
}

void CandidateList::printCandidate(list<CandidateType>::const_iterator iter, int pos) const
{
	cout << setw(15) << left << iter->getLastName() << setw(12) << iter->getFirstName() << setw(3)
		<< iter->getTotalVotes() << setw(7) << right << pos << endl;
	
	if (pos % 5 == 0)
	{
		cout << "---------------------------------------\n";
	}
}

