/*///////////////////////////////////////////////////////
              ¬хождение морфемы в слово
*////////////////////////////////////////////////////////
#pragma once
#include <iostream>
#include <vector>
using namespace std;

class OccurrenceMorpheme //¬хождение морфемы в слово
{
public:
	OccurrenceMorpheme();
	~OccurrenceMorpheme();

	void Clear();
	void PushBack(const int& numberFromOccurrence);
	bool IsEmpty() const;
	int GetSize() const;

	bool Intersection(const OccurrenceMorpheme &a) const;
	bool ConditionSuffix(const string& str) const;
	bool EmptyBetweenSuffixAndEnding(const string& str, const OccurrenceMorpheme &secondMorpheme) const;

	friend bool operator==(const OccurrenceMorpheme &a, const OccurrenceMorpheme &b);
	friend ostream& operator<<(ostream& out, const OccurrenceMorpheme &a);
	void operator=(const OccurrenceMorpheme &a);

private:
	vector<int> vect;
};

OccurrenceMorpheme::OccurrenceMorpheme()
{
}

OccurrenceMorpheme::~OccurrenceMorpheme()
{
}

void OccurrenceMorpheme::Clear()
{
	vect.clear();
}

void OccurrenceMorpheme::PushBack(const int& numberFromOccurrence)
{
	vect.push_back(numberFromOccurrence);
}

bool OccurrenceMorpheme::IsEmpty() const
{
	if (vect[0] == -1)
	{
		return true;
	}
	return false;
}

int OccurrenceMorpheme::GetSize() const
{
	return vect.size();
}

bool OccurrenceMorpheme::Intersection(const OccurrenceMorpheme &a) const
{
	for (int i = 0; i < (int)a.vect.size(); i++)
	{
		for (int j = 0; j < (int)vect.size(); j++)
		{
			if (a.vect[i] == vect[j])
			{
				return false;
			}
		}
	}
	return true;
}

bool OccurrenceMorpheme::ConditionSuffix(const string& str) const
{
	//—уффикс -е(ть) образует глаголы со значением: становитьс€ кем-нибудь, каким-нибудь, 
	//быть таким, каким называет исходное слово (стареть, звереть, темнеть, богатеть, хорошеть)
	//
	//—уффикс -а, -о, -е образует наречи€ со значением оценки действи€ 
	//( певуче, сильно, стремительно, снова, умол€юще, растроганно, см€гчающе, взволнованно).

	if (vect.size() == 1)
	{
		int firstNumberInOccurrence = vect[0];
		if (str[firstNumberInOccurrence] == 'е')
		{
			int leng = str.length();

			if (firstNumberInOccurrence == leng - 1)
			{
				return true;
			}
			else
			{
				if ((leng >= firstNumberInOccurrence + 3) && 
					(str[firstNumberInOccurrence + 1] == 'т') &&
					(str[firstNumberInOccurrence + 2] == 'ь'))
				{
					return true;
				}
				return false;
			}
		}
	}
	return true;
}

bool OccurrenceMorpheme::EmptyBetweenSuffixAndEnding(const string& str, const OccurrenceMorpheme &secondMorpheme) const
{
	if (secondMorpheme.vect[0] == -1)
	{
		if (str.length() == vect[vect.size() - 1] + 1)
		{
			return true;
		}
		return false;
	}

	if (vect[vect.size() - 1] + 1 == secondMorpheme.vect[0])
	{
		return true;
	}
	return false;
}

bool operator==(const OccurrenceMorpheme &a, const OccurrenceMorpheme &b)
{
	if (a.vect != b.vect)
	{
		return false;
	}
	return true;
}

ostream& operator<<(ostream& out, const OccurrenceMorpheme &a)
{
	for (int i = 0; i < (int)a.vect.size(); i++)
	{
		out << a.vect[i];
	}
	return out;
}

void OccurrenceMorpheme::operator = (const OccurrenceMorpheme &a)
{
	vect = a.vect;
}