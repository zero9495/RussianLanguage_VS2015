/*///////////////////////////////////////////////////////
                  ��������� ������
*////////////////////////////////////////////////////////
#pragma once
#include "MorphemicComposition.h"

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

bool Intersection(const OccurrenceMorpheme &a, const OccurrenceMorpheme &b) //������� �� ������������?
{
	return a.Intersection(b);
}

bool ConditionZeroEnding(const DictionaryMorpheme &a, const string c) //������� �������� ���������
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

bool ConditionSuffix(const string c, const OccurrenceMorpheme &a) //������� ��������
{
	//������� -�(��) �������� ������� �� ���������: ����������� ���-������, �����-������, 
	//���� �����, ����� �������� �������� ����� (�������, �������, �������, ��������, ��������)
	//
	//������� -�, -�, -� �������� ������� �� ��������� ������ �������� 
	//( ������, ������, ������������, �����, ��������, �����������, ���������, ������������).

	return a.ConditionSuffix(c);
}

bool EmptyBetweenSuffixAndEnding(const string c, const OccurrenceMorpheme &a, const OccurrenceMorpheme &b)
{
	return a.EmptyBetweenSuffixAndEnding(c, b);
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
				if (!ConditionZeroEnding(a, c)) //������� ��������� ������ ����� ���������� ������� � ������ ������
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
				if (this->ending.begin()->Size() == c.length()) //��������� �� ������ ���� ����� ����� �����
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
				if ((this->suffix.begin()->Size() == c.length()) //������� �� ������� ���� ������ ����� �����
					|| !(this->suffix.begin()->EmptyBetweenSuffixAndEnding(c, *(this->ending.begin())))
					|| !ConditionZeroEnding(a, c) //������� �������� ���������
					|| !ConditionSuffix(c, *(this->suffix.begin()))) //������� ��������
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
					|| !ConditionSuffix(c, *(this->suffix.begin()))) //������� ��������
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
				if ((this->prefix.begin()->Size() == c.length())//��������� �� ������ ���� ����� ����� �����
					|| !ConditionZeroEnding(a, c)) //������� �������� ���������
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
					|| !ConditionZeroEnding(a, c)
					|| !ConditionSuffix(c, *(this->suffix.begin()))) //������� ��������
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
					|| !ConditionSuffix(c, *(this->suffix.begin()))) //������� ��������
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
	}

	if (TempSuffix != 0)
	{
		a.PushBackSuffix(*TempSuffix);
	}

	if (TempPrefix != 0)
	{
		a.PushBackPrefix(*TempPrefix);
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
		os << endl << "������ ��������� ������." << endl;

		os << "���������: ";
		copy(a.prefix.begin(), a.prefix.end(), ostream_iterator<OccurrenceMorpheme>(os, " -> "));

		os << endl << "��������: ";
		copy(a.suffix.begin(), a.suffix.end(), ostream_iterator<OccurrenceMorpheme>(os, " -> "));

		os << endl << "���������: ";
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