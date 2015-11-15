/*///////////////////////////////////////////////////////
                     Морфология
*////////////////////////////////////////////////////////
#pragma once
#include "AddNounByEnding.h"
#include "AddAdjectiveByEnding.h"
#include "Spelling.h"
using namespace std;

void AddNounByEnding(list<Noun> &NounList, const string& c, const OccurrenceMorpheme &a)
{

	if (a.Size() == 1)
	{
		if (a.IsEmpty)
		{
			AddNounByEndingNULL(NounList);
			return;
		}
		switch (c[a.k[0]])
		{
		case 'а':
		{
			AddNounByEndingA(NounList);
			break;
		}
		case 'я':
		{
			AddNounByEndingYA(NounList);
			break;
		}
		case 'ы':
		{
			AddNounByEndingYI(NounList);
			break;
		}
		case 'и':
		{
			AddNounByEndingI(NounList);
			break;
		}
		case 'е':
		{
			AddNounByEndingE(NounList);
			break;
		}
		case 'у':
		{
			AddNounByEndingU(NounList);
			break;
		}
		case 'ю':
		{
			AddNounByEndingYU(NounList);
			break;
		}
		case 'о':
		{
			AddNounByEndingO(NounList);
			break;
		}
		}
	}
	if (a.k.size() == 2)
	{
		switch (c[a.k[0]])
		{
		case 'о':
		{
			switch (c[a.k[1]])
			{
			case 'й':
			{
				AddNounByEndingOYandEY(NounList);
				break;
			}
			case 'м':
			{
				AddNounByEndingOMandEM(NounList);
				break;
			}
			}
		}
		case 'е':
		{
			switch (c[a.k[1]])
			{
			case 'й':
			{
				AddNounByEndingOYandEY(NounList);
				break;
			}
			case 'м':
			{
				AddNounByEndingOMandEM(NounList);
				break;
			}
			}
		}
		}
	}
}

list<Noun> AddNoun(const list<MorphemicComposition> MorphComp, const string c)
{
	list<Noun> NounList;

	for (list<MorphemicComposition>::const_iterator p = MorphComp.begin(); p != MorphComp.end(); p++)
	{
		AddNounByEnding(NounList, c, *(p->ending.begin()));
	}

	return NounList;
}

void AddAdjectiveByEnding(list<Adjective> &AdjectiveList, const string c, const OccurrenceMorpheme &a)
{
	if (a.k.size() == 1)
	{
		if (a.k[0] == -1)
		{
			AddAdjectiveByEndingNULL(AdjectiveList);
			return;
		}
		switch (c[a.k[0]])
		{
		case 'а':
		{
			AddAdjectiveByEndingA(AdjectiveList);
		}
		case 'о':
		{
			AddAdjectiveByEndingOandE(AdjectiveList);
		}
		case 'е':
		{
			AddAdjectiveByEndingOandE(AdjectiveList);
		}
		case 'у':
		{
			AddAdjectiveByEndingUandYU(AdjectiveList);
		}
		case 'ю':
		{
			AddAdjectiveByEndingUandYU(AdjectiveList);
		}
		case 'ы':
		{
			AddAdjectiveByEndingYIandI(AdjectiveList);
		}
		case 'и':
		{
			AddAdjectiveByEndingYIandI(AdjectiveList);
		}
		}
	}

	if (a.k.size() == 2)
	{
		switch (c[a.k[0]])
		{
		case 'ы':
		{
			switch (c[a.k[1]])
			{
			case 'й':
			{
				AddAdjectiveByEndingYIYandIY(AdjectiveList);
			}
			case 'м':
			{
				AddAdjectiveByEndingYUMandIM(AdjectiveList);
			}
			case 'х':
			{
				AddAdjectiveByEndingYIHandIH(AdjectiveList);
			}
			}
		}
		case 'и':
		{
			switch (c[a.k[1]])
			{
			case 'й':
			{
				AddAdjectiveByEndingYIYandIY(AdjectiveList);
			}
			case 'м':
			{
				AddAdjectiveByEndingYUMandIM(AdjectiveList);
			}
			case 'х':
			{
				AddAdjectiveByEndingYIHandIH(AdjectiveList);
			}
			}
		}
		case 'о':
		{
			switch (c[a.k[1]])
			{
			case 'й':
			{
				AddAdjectiveByEndingOY(AdjectiveList);
			}
			case 'е':
			{
				AddAdjectiveByEndingOEandEE(AdjectiveList);
			}
			case 'м':
			{
				AddAdjectiveByEndingOMandEM(AdjectiveList);
			}
			case 'ю':
			{
				AddAdjectiveByEndingOYUandEYU(AdjectiveList);
			}
			}
		}
		case 'е':
		{
			switch (c[a.k[1]])
			{
			case 'е':
			{
				AddAdjectiveByEndingOEandEE(AdjectiveList);
			}
			case 'м':
			{
				AddAdjectiveByEndingOMandEM(AdjectiveList);
			}
			case 'й':
			{
				AddAdjectiveByEndingEY(AdjectiveList);
			}
			case 'ю':
			{
				AddAdjectiveByEndingOYUandEYU(AdjectiveList);
			}
			}
		}
		case 'у':
		{
			switch (c[a.k[1]])
			{
			case 'ю':
			{
				AddAdjectiveByEndingUYUandYUYU(AdjectiveList);
			}
			}
		}
		case 'ю':
		{
			switch (c[a.k[1]])
			{
			case 'ю':
			{
				AddAdjectiveByEndingUYUandYUYU(AdjectiveList);
			}
			}
		}
		}
	}

	if (a.k.size() == 3)
	{
		switch (c[a.k[0]])
		{
		case 'о':
		{
			switch (c[a.k[1]])
			{
			case 'г':
			{
				switch (c[a.k[2]])
				{
				case 'о':
				{
					AddAdjectiveByEndingOGOandEGO(AdjectiveList);
				}
				}
			}
			case 'м':
			{
				switch (c[a.k[2]])
				{
				case 'у':
				{
					AddAdjectiveByEndingOMUandEMU(AdjectiveList);
				}
				}
			}
			}
		}
		case 'е':
		{
			switch (c[a.k[1]])
			{
			case 'г':
			{
				switch (c[a.k[2]])
				{
				case 'о':
				{
					AddAdjectiveByEndingOGOandEGO(AdjectiveList);
				}
				}
			}
			case 'м':
			{
				switch (c[a.k[2]])
				{
				case 'у':
				{
					AddAdjectiveByEndingOMUandEMU(AdjectiveList);
				}
				}
			}
			}
		}
		case 'ы':
		{
			switch (c[a.k[1]])
			{
			case 'м':
			{
				switch (c[a.k[2]])
				{
				case 'и':
				{
					AddAdjectiveByEndingYIMIandIMI(AdjectiveList);
				}
				}
			}
			}
		}
		case 'и':
		{
			switch (c[a.k[1]])
			{
			case 'м':
			{
				switch (c[a.k[2]])
				{
				case 'и':
				{
					AddAdjectiveByEndingYIMIandIMI(AdjectiveList);
				}
				}
			}
			}
		}
		}
	}
}

list<Adjective> AddAdjective(const list<MorphemicComposition> MorphComp, const string c)
{
	list<Adjective> AdjectiveList;

	for (list<MorphemicComposition>::const_iterator p = MorphComp.begin(); p != MorphComp.end(); p++)
	{
		AddAdjectiveByEnding(AdjectiveList, c, *(p->ending.begin()));
	}

	return AdjectiveList;
}