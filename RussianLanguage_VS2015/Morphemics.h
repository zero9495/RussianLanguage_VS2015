/*///////////////////////////////////////////////////////
                       Морфемика
*////////////////////////////////////////////////////////
#pragma once
#include "MorphemicComposition.h"
//#include "DictionaryMorpheme.h"
using namespace std;

void FindAllOccurrences(list<OccurrenceMorpheme> &arr, const string c1, const string c2) //Найти все вхождения морфемы c1 в строку c2
{
	int l1 = c1.length();
	int l2 = c2.length();
	if (l1 > l2)
	{
		return;
	}

	OccurrenceMorpheme x;

	for (int i = 0; i < l2; i++)
	{
		if (c2[i] == c1[0])
		{
			x.Clear();
			//x.k.clear();

			for (int j = 0; j < l1; j++)
			{
				if (c1[j] != c2[i + j])
				{
					break;
				}

				x.PushBack(i + j);
				//x.k.push_back(i + j);

				if (j == l1 - 1)
				{
					arr.push_back(x);
				}
			}
		}
	}
}

list<OccurrenceMorpheme> FindSuffix(const list<string> &begin, const string c)
{
	list<OccurrenceMorpheme> arr;

	for (list<string>::const_iterator p = begin.begin(); p != begin.end(); p++)
	{
		FindAllOccurrences(arr, *p, c);
	}

	OccurrenceMorpheme x;
	x.PushBack(-1);
	//x.k.push_back(-1);
	arr.push_back(x);

	return arr;
}

void FindOccurrenceAtTheEnd(list<OccurrenceMorpheme> &arr, const string c1, const string c2) //Найти вхождение морфемы c1 в конец строки c2
{
	int l1 = c1.length();
	int l2 = c2.length();
	if (l1 > l2)
	{
		return;
	}

	OccurrenceMorpheme x;
	for (int i = 0; i < l1; i++)
	{
		if (c1[i] != c2[l2 - l1 + i])
		{
			return;
		}

		x.PushBack(l2 - l1 + i);
		//x.k.push_back(l2 - l1 + i);

		if (i == l1 - 1)
		{
			arr.push_back(x);
		}
	}
}

list<OccurrenceMorpheme> FindEnding(const list<string> &begin, const string c)
{
	list<OccurrenceMorpheme> arr;

	for (list<string>::const_iterator p = begin.begin(); p != begin.end(); p++)
	{
		FindOccurrenceAtTheEnd(arr, *p, c);
	}

	OccurrenceMorpheme x;
	x.PushBack(-1);
	//x.k.push_back(-1);
	arr.push_back(x);

	return arr;
}

void FindOccurrenceAtTheBegin(list<OccurrenceMorpheme> &arr, const string c1, const string c2) //Найти вхождение морфемы c1 в начало строки c2
{
	int l1 = c1.length();
	int l2 = c2.length();
	if (l1 > l2)
	{
		return;
	}

	OccurrenceMorpheme x;

	if (c1[0] == c2[0])
	{
		for (int i = 0; i < l1; i++)
		{
			if (c1[i] != c2[i])
			{
				return;
			}
			x.PushBack(i);
			//x.k.push_back(i);
		}
	}
	else
	{
		return;
	}
	arr.push_back(x);
}

list<OccurrenceMorpheme> FindPrefix(const list<string> &begin, const string c)
{
	list<OccurrenceMorpheme> arr;

	for (list<string>::const_iterator p = begin.begin(); p != begin.end(); p++)
	{
		FindOccurrenceAtTheBegin(arr, *p, c);
	}

	OccurrenceMorpheme x;
	x.PushBack(-1);
	//x.k.push_back(-1);
	arr.push_back(x);

	return arr;
}

/*oid AddMorphemicComposition(list<MorphemicComposition> &d, const OccurrenceMorpheme* TempEnding,
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
}*/

list<MorphemicComposition>* FindAllPossibleMorphemicComposition(const DictionaryMorpheme &a, const string c)
{
	list<MorphemicComposition>* d;
	MorphemicComposition b;

	list<OccurrenceMorpheme>* AllFoundPrefixes = 0;
	*AllFoundPrefixes = FindPrefix(a.GetPrefix(), c); //Все возможные приставки
	b.PushBackPrefix(*AllFoundPrefixes);
	delete[] AllFoundPrefixes;

	list<OccurrenceMorpheme>* AllFoundSuffixes = 0;
	*AllFoundSuffixes = FindSuffix(a.GetSuffix(), c); //Все возможные суффиксы
	b.PushBackSuffix(*AllFoundSuffixes);
	delete[] AllFoundSuffixes;

	list<OccurrenceMorpheme>* AllFoundEndings = 0;
	*AllFoundEndings = FindEnding(a.GetEnding(), c); //Все возможные окончания
	b.PushBackEnding(*AllFoundEndings);
	delete[] AllFoundEndings;

	//b.prefix = FindPrefix(a.prefix, c); //Все возможные приставки
	//b.suffix = FindSuffix(a.suffix, c); //Все возможные суффиксы
	//b.ending = FindEnding(a.ending, c); //Все возможные окончания

	ofstream fout("output.txt", ios::app);

	b.TurnDetailedOutputOn();
	fout << b;
	b.TurnDetailedOutputOff();

	/*fout <<endl << "Списки возможных морфем." << endl;

	fout << "Приставки: ";
	copy(b.prefix.begin(), b.prefix.end(), ostream_iterator<OccurrenceMorpheme>(fout, " -> "));

	fout << endl << "Суффиксы: ";
	copy(b.suffix.begin(), b.suffix.end(), ostream_iterator<OccurrenceMorpheme>(fout, " -> "));

	fout << endl << "Окончания: ";
	copy(b.ending.begin(), b.ending.end(), ostream_iterator<OccurrenceMorpheme>(fout, " -> "));
	fout << endl << endl;*/

	fout.close();

	d = b.FindAllPossibleMorphemicComposition(c);

	/*if (b.ending.size() == 0)
	{
		if (b.suffix.size() == 0)
		{
			if (b.prefix.size() == 0)
			{
				//(0,0,0)
				AddMorphemicComposition(d, 0, 0, 0);
			}
			else
			{
				//(0,0,1)
				for (list<OccurrenceMorpheme>::iterator p = b.prefix.begin(); p != b.prefix.end(); p++)
				{
					AddMorphemicComposition(d, 0, 0, &(*p));
				}
			}
		}
		else
		{
			for (list<OccurrenceMorpheme>::iterator s = b.suffix.begin(); s != b.suffix.end(); s++)
			{
				if (b.prefix.size() == 0)
				{
					//(0,1,0)
					AddMorphemicComposition(d, 0, &(*s), 0);
				}
				else
				{
					//(0,1,1)
					for (list<OccurrenceMorpheme>::iterator p = b.prefix.begin(); p != b.prefix.end(); p++)
					{
						AddMorphemicComposition(d, 0, &(*s), &(*p));
					}
				}
			}
		}
	}
	else
	{
		for (list<OccurrenceMorpheme>::iterator e = b.ending.begin(); e != b.ending.end(); e++)
		{
			if (b.suffix.size() == 0)
			{
				if (b.prefix.size() == 0)
				{
					//(1,0,0)
					AddMorphemicComposition(d, &(*e), 0, 0);
				}
				else
				{
					//(1,0,1)
					for (list<OccurrenceMorpheme>::iterator p = b.prefix.begin(); p != b.prefix.end(); p++)
					{
						AddMorphemicComposition(d, &(*e), 0, &(*p));
					}
				}
			}
			else
			{
				for (list<OccurrenceMorpheme>::iterator s = b.suffix.begin(); s != b.suffix.end(); s++)
				{
					if (b.prefix.size() == 0)
					{
						//(1,1,0)
						AddMorphemicComposition(d, &(*e), &(*s), 0);
					}
					else
					{
						//(1,1,1)
						for (list<OccurrenceMorpheme>::iterator p = b.prefix.begin(); p != b.prefix.end(); p++)
						{
							AddMorphemicComposition(d, &(*e), &(*s), &(*p));
						}
					}
				}
			}
		}
	}*/

	return d;
}