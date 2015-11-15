/*///////////////////////////////////////////////////////
                   Морфемный состав
*////////////////////////////////////////////////////////
#pragma once
#include "OccurrenceMorpheme.h"
#include "DictionaryMorpheme.h"
#include <iterator>
#include <list>
using namespace std;

class MorphemicComposition //Морфемный состав
{
public:
	MorphemicComposition();
	~MorphemicComposition();

	void TurnDetailedOutputOn();
	void TurnDetailedOutputOff();

	void Clear();
	bool SpellControl(const DictionaryMorpheme &a, const string& c) const; //Контроль орфографии

	void PushBackEnding(const OccurrenceMorpheme& a);
	void PushBackEnding(const list<OccurrenceMorpheme>& a);

	void PushBackSuffix(const OccurrenceMorpheme& a);
	void PushBackSuffix(const list<OccurrenceMorpheme>& a);

	void PushBackPrefix(const OccurrenceMorpheme& a);
	void PushBackPrefix(const list<OccurrenceMorpheme>& a);

	list<MorphemicComposition>* FindAllPossibleMorphemicComposition(const string& c) const;

	friend ostream& operator<<(ostream& os, const MorphemicComposition& a);

private:
	list<OccurrenceMorpheme> ending;
	list<OccurrenceMorpheme> suffix;
	list<OccurrenceMorpheme> prefix;

	bool detailedOutput; // Подробный вывод
};

MorphemicComposition::MorphemicComposition()
{
	detailedOutput = false;
}

MorphemicComposition::~MorphemicComposition()
{
	Clear();
}

void MorphemicComposition::Clear()
{
	ending.clear();
	suffix.clear();
	prefix.clear();
}

bool Intersection(const OccurrenceMorpheme &a, const OccurrenceMorpheme &b) //Морфемы не пересекаются?
{
	return a.Intersection(b);

	/*for (int i = 0; i < (int)a.k.size(); i++)
	{
	for (int j = 0; j < (int)b.k.size(); j++)
	{
	if (a.k[i] == b.k[j])
	{
	return false;
	}
	}
	}*/
	return true;
}

bool ConditionZeroEnding(const DictionaryMorpheme &a, const string c) //Условие нулевого окончания
{
	list<string> ending = a.GetLettersBeforeZeroEnding();

	string str;
	char c1 = c[c.length() - 1];
	char c2[2];
	c2[0] = c1;
	c2[1] = NULL;
	str = c2;
	for (list<string>::const_iterator p = ending.begin(); p != ending.end(); p++)
	{
		if (*p == c2)
		{
			return true;
		}
	}
	return false;
}

bool ConditionSuffix(const string c, const OccurrenceMorpheme &a) //Условие суффикса
{
	//Суффикс -е(ть) образует глаголы со значением: становиться кем-нибудь, каким-нибудь, 
	//быть таким, каким называет исходное слово (стареть, звереть, темнеть, богатеть, хорошеть)
	//
	//Суффикс -а, -о, -е образует наречия со значением оценки действия 
	//( певуче, сильно, стремительно, снова, умоляюще, растроганно, смягчающе, взволнованно).

	return a.ConditionSuffix(c);

	/*if (a.k.size() == 1)
	{
	int k = a.k[0];
	if (c[k] == 'е')
	{
	int leng = c.length();

	if (k == leng - 1)
	{
	return true;
	}
	else
	{
	if ((leng >= k + 3) && (c[k + 1] == 'т') && (c[k + 2] == 'ь'))
	{
	return true;
	}
	return false;
	}
	}
	}
	return true;*/
}

bool EmptyBetweenSuffixAndEnding(const string c, const OccurrenceMorpheme &a, const OccurrenceMorpheme &b)
{
	return a.EmptyBetweenSuffixAndEnding(c, b);

	/*if (b.k[0] == -1)
	{
	if (c.length() == a.k[a.k.size() - 1] + 1)
	{
	return true;
	}
	return false;
	}

	if (a.k[a.k.size() - 1] + 1 == b.k[0])
	{
	return true;
	}
	return false;*/
}

bool MorphemicComposition::SpellControl(const DictionaryMorpheme &a, const string& c) const
{
	if (this->prefix.begin()->IsEmpty())
	{
		if (this->suffix.begin()->IsEmpty())
		{
			if (this->ending.begin()->IsEmpty())
			{
				//(0,0,0)
				if (!ConditionZeroEnding(a, c)) //Нулевое окончание бывает перед согласными буквами и мягким знаком
				{
					return false;
				}
				else
				{
					return true;
				}
			}
			else
			{
				//(0,0,1)
				if (this->ending.begin()->Size() == c.length()) //Окончание не должно быть равно всему слову
				{
					return false;
				}
				else
				{
					return true;
				}
			}
		}
		else
		{
			if (this->ending.begin()->IsEmpty())
			{
				//(0,1,0)	
				if ((this->suffix.begin()->Size() == c.length()) //Суффикс не должнен быть равнен всему слову
					|| !(this->suffix.begin()->EmptyBetweenSuffixAndEnding(c, *(this->ending.begin())))
					//|| !EmptyBetweenSuffixAndEnding(a, c, *(this->suffix.begin()), *(this->ending.begin()))
					|| !ConditionZeroEnding(a, c) //Условие нулевого окончания
					|| !ConditionSuffix(c, *(this->suffix.begin()))) //Условие суффикса
				{
					return false;
				}
				else
				{
					return true;
				}
			}
			else
			{
				//(0,1,1)
				if (!Intersection(*(this->suffix.begin()), *(this->ending.begin()))
					|| !(this->suffix.begin()->EmptyBetweenSuffixAndEnding(c, *(this->ending.begin())))
					//|| !EmptyBetweenSuffixAndEnding(a, c, *(this->suffix.begin()), *(this->ending.begin()))
					|| !ConditionSuffix(c, *(this->suffix.begin()))) //Условие суффикса
				{
					return false;
				}
				else
				{
					return true;
				}
			}
		}
	}
	else
	{
		if (this->suffix.begin()->IsEmpty())
		{
			if (this->ending.begin()->IsEmpty())
			{
				//(1,0,0)
				if ((this->prefix.begin()->Size() == c.length())//Приставка не должна быть равна всему слову
					|| !ConditionZeroEnding(a, c)) //Условие нулевого окончания
				{
					return false;
				}
				else
				{
					return true;
				}
			}
			else
			{
				//(1,0,1)
				if (!Intersection(*(this->prefix.begin()), *(this->ending.begin())))
				{
					return false;
				}
				else
				{
					return true;
				}
			}
		}
		else
		{
			if (this->ending.begin()->IsEmpty)
			{
				//(1,1,0)
				if (!Intersection(*(this->suffix.begin()), *(this->prefix.begin()))
					|| !(this->suffix.begin()->EmptyBetweenSuffixAndEnding(c, *(this->ending.begin())))
					//|| !EmptyBetweenSuffixAndEnding(a, c, *(this->suffix.begin()), *(this->ending.begin()))
					|| !ConditionZeroEnding(a, c)
					|| !ConditionSuffix(c, *(this->suffix.begin()))) //Условие суффикса
				{
					return false;
				}
				else
				{
					return true;
				}
			}
			else
			{
				//(1,1,1)
				if (!Intersection(*(this->prefix.begin()), *(this->suffix.begin()))
					|| !Intersection(*(this->prefix.begin()), *(this->ending.begin()))
					|| !Intersection(*(this->suffix.begin()), *(this->ending.begin()))
					|| !(this->suffix.begin()->EmptyBetweenSuffixAndEnding(c, *(this->ending.begin())))
					//|| !EmptyBetweenSuffixAndEnding(a, c, *(this->suffix.begin()), *(this->ending.begin()))
					|| !ConditionSuffix(c, *(this->suffix.begin()))) //Условие суффикса
				{
					return false;
				}
				else
				{
					return true;
				}
			}
		}
	}
}

void AddMorphemicComposition(list<MorphemicComposition> &d, const OccurrenceMorpheme* TempEnding,
	const OccurrenceMorpheme* TempSuffix, const OccurrenceMorpheme* TempPrefix)
{
	MorphemicComposition a;

	if (TempEnding != 0)
	{
		a.PushBackEnding(*TempEnding);
		//a.ending.push_back(*TempEnding);
	}

	if (TempSuffix != 0)
	{
		a.PushBackSuffix(*TempSuffix);
		//a.suffix.push_back(*TempSuffix);
	}

	if (TempPrefix != 0)
	{
		a.PushBackPrefix(*TempPrefix);
		//a.prefix.push_back(*TempPrefix);
	}

	d.push_back(a);
}

list<MorphemicComposition>* MorphemicComposition::FindAllPossibleMorphemicComposition(const string& c) const
{
	list<MorphemicComposition>* d;

	if (this->ending.size() == 0)
	{
		if (this->suffix.size() == 0)
		{
			if (this->prefix.size() == 0)
			{
				//(0,0,0)
				AddMorphemicComposition(*d, 0, 0, 0);
			}
			else
			{
				//(0,0,1)
				for (list<OccurrenceMorpheme>::const_iterator p = this->prefix.begin(); p != this->prefix.end(); p++)
				{
					AddMorphemicComposition(*d, 0, 0, &(*p));
				}
			}
		}
		else
		{
			for (list<OccurrenceMorpheme>::const_iterator s = this->suffix.begin(); s != this->suffix.end(); s++)
			{
				if (this->prefix.size() == 0)
				{
					//(0,1,0)
					AddMorphemicComposition(*d, 0, &(*s), 0);
				}
				else
				{
					//(0,1,1)
					for (list<OccurrenceMorpheme>::const_iterator p = this->prefix.begin(); p != this->prefix.end(); p++)
					{
						AddMorphemicComposition(*d, 0, &(*s), &(*p));
					}
				}
			}
		}
	}
	else
	{
		for (list<OccurrenceMorpheme>::const_iterator e = this->ending.begin(); e != this->ending.end(); e++)
		{
			if (this->suffix.size() == 0)
			{
				if (this->prefix.size() == 0)
				{
					//(1,0,0)
					AddMorphemicComposition(*d, &(*e), 0, 0);
				}
				else
				{
					//(1,0,1)
					for (list<OccurrenceMorpheme>::const_iterator p = this->prefix.begin(); p != this->prefix.end(); p++)
					{
						AddMorphemicComposition(*d, &(*e), 0, &(*p));
					}
				}
			}
			else
			{
				for (list<OccurrenceMorpheme>::const_iterator s = this->suffix.begin(); s != this->suffix.end(); s++)
				{
					if (this->prefix.size() == 0)
					{
						//(1,1,0)
						AddMorphemicComposition(*d, &(*e), &(*s), 0);
					}
					else
					{
						//(1,1,1)
						for (list<OccurrenceMorpheme>::const_iterator p = this->prefix.begin(); p != this->prefix.end(); p++)
						{
							AddMorphemicComposition(*d, &(*e), &(*s), &(*p));
						}
					}
				}
			}
		}
	}

	return d;
}

ostream& operator<<(ostream& os, const MorphemicComposition &a)
{
	if (a.detailedOutput)
	{
		os << endl << "Списки возможных морфем." << endl;

		os << "Приставки: ";
		copy(a.prefix.begin(), a.prefix.end(), ostream_iterator<OccurrenceMorpheme>(os, " -> "));

		os << endl << "Суффиксы: ";
		copy(a.suffix.begin(), a.suffix.end(), ostream_iterator<OccurrenceMorpheme>(os, " -> "));

		os << endl << "Окончания: ";
		copy(a.ending.begin(), a.ending.end(), ostream_iterator<OccurrenceMorpheme>(os, " -> "));
		os << endl << endl;
	}
	else
	{
		os << "(";
		copy(a.prefix.begin(), a.prefix.end(), ostream_iterator<OccurrenceMorpheme>(os, " "));
		os << ",";
		copy(a.suffix.begin(), a.suffix.end(), ostream_iterator<OccurrenceMorpheme>(os, " "));
		os << ",";
		copy(a.ending.begin(), a.ending.end(), ostream_iterator<OccurrenceMorpheme>(os, " "));
	}

	return os;
}