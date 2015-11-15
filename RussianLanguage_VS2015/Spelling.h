/*///////////////////////////////////////////////////////
                     Орфография
*////////////////////////////////////////////////////////
#pragma once
#include "Morphemics.h"

using namespace std;

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
	}
	return true;*/
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

void PrintListMorphemicComposition(const list<MorphemicComposition> &a)
{
	ofstream fout("output.txt", ios::app);

	fout << "Морфемные разборы после контроля орфографии." << endl;

	int i = 0;
	for (list<MorphemicComposition>::const_iterator p = a.begin(); p != a.end(); p++)
	{
		fout << "a[" << i << "]=";
		fout << (*p);
		i++;
	}

	fout.close();
}

void SpellControl(const DictionaryMorpheme &a, const string c, list<MorphemicComposition> &d) //Контроль орфографии
{
	//ofstream fout("output.txt", ios::app);

 /*fout << "\nПриставки: ";
 copy(b.prefix.begin(), b.prefix.end(), ostream_iterator<OccurrenceMorpheme>(std::cout, " -> "));
 std::cout << "\nСуффиксы: ";
 copy(b.suffix.begin(), b.suffix.end(), ostream_iterator<OccurrenceMorpheme>(std::cout, " -> "));
 std::cout << "\nОкончания: ";
 copy(b.ending.begin(), b.ending.end(), ostream_iterator<OccurrenceMorpheme>(std::cout, " -> "));
 std::cout << "\n\n";*/

	//fout << "Все вожможные морфемные разборы." << endl;

	list<MorphemicComposition>::iterator p = d.begin();
	int i = 0;

	while (p != d.end())
	{
		//fout << "d[" << i << "]=";
		//fout << (*p);

		if (!(p->SpellControl(a, c)))
		{
			p = d.erase(p);
		}
		else
		{
			p++;
		}

		/*if (p->prefix.begin()->k[0] == -1)
		{
			if (p->suffix.begin()->k[0] == -1)
			{
				if (p->ending.begin()->k[0] == -1)
				{
					//(0,0,0)
					if (!ConditionZeroEnding(a, c)) //Нулевое окончание бывает перед согласными буквами и мягким знаком
					{
						p = d.erase(p);
					}
					else
					{
						p++;
					}
				}
				else
				{
					//(0,0,1)
					if (p->ending.begin()->k.size() == c.length()) //Окончание не должно быть равно всему слову
					{
						p = d.erase(p);
					}
					else
					{
						p++;
					}
				}
			}
			else
			{
				if (p->ending.begin()->k[0] == -1)
				{
					//(0,1,0)	
					if ((p->suffix.begin()->k.size() == c.length()) //Суффикс не должнен быть равнен всему слову
						|| !EmptyBetweenSuffixAndEnding(a, c, *(p->suffix.begin()), *(p->ending.begin()))
						|| !ConditionZeroEnding(a, c) //Условие нулевого окончания
						|| !ConditionSuffix(c, *(p->suffix.begin()))) //Условие суффикса
					{
						p = d.erase(p);
					}
					else
					{
						p++;
					}
				}
				else
				{
					//(0,1,1)
					if (!Intersection(*(p->suffix.begin()), *(p->ending.begin()))
						|| !EmptyBetweenSuffixAndEnding(a, c, *(p->suffix.begin()), *(p->ending.begin()))
						|| !ConditionSuffix(c, *(p->suffix.begin()))) //Условие суффикса
					{
						p = d.erase(p);
					}
					else
					{
						p++;
					}
				}
			}
		}
		else
		{
			if (p->suffix.begin()->k[0] == -1)
			{
				if (p->ending.begin()->k[0] == -1)
				{
					//(1,0,0)
					if ((p->prefix.begin()->k.size() == c.length())//Приставка не должна быть равна всему слову
						|| !ConditionZeroEnding(a, c)) //Условие нулевого окончания
					{
						p = d.erase(p);
					}
					else
					{
						p++;
					}
				}
				else
				{
					//(1,0,1)
					if (!Intersection(*(p->prefix.begin()), *(p->ending.begin())))
					{
						p = d.erase(p);
					}
					else
					{
						p++;
					}
				}
			}
			else
			{
				if (p->ending.begin()->k[0] == -1)
				{
					//(1,1,0)
					if (!Intersection(*(p->suffix.begin()), *(p->prefix.begin()))
						|| !EmptyBetweenSuffixAndEnding(a, c, *(p->suffix.begin()), *(p->ending.begin()))
						|| !ConditionZeroEnding(a, c)
						|| !ConditionSuffix(c, *(p->suffix.begin()))) //Условие суффикса
					{
						p = d.erase(p);
					}
					else
					{
						p++;
					}
				}
				else
				{
					//(1,1,1)
					if (!Intersection(*(p->prefix.begin()), *(p->suffix.begin()))
						|| !Intersection(*(p->prefix.begin()), *(p->ending.begin()))
						|| !Intersection(*(p->suffix.begin()), *(p->ending.begin()))
						|| !EmptyBetweenSuffixAndEnding(a, c, *(p->suffix.begin()), *(p->ending.begin()))
						|| !ConditionSuffix(c, *(p->suffix.begin()))) //Условие суффикса
					{
						p = d.erase(p);
					}
					else
					{
						p++;
					}
				}
			}
		}*/
		i++;
	}
	//fout << endl;

	//fout.close();

	PrintListMorphemicComposition(d);
}