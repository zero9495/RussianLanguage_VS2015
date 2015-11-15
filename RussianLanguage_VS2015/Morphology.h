/*///////////////////////////////////////////////////////
                     ����������
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
		case '�':
		{
			AddNounByEndingA(NounList);
			break;
		}
		case '�':
		{
			AddNounByEndingYA(NounList);
			break;
		}
		case '�':
		{
			AddNounByEndingYI(NounList);
			break;
		}
		case '�':
		{
			AddNounByEndingI(NounList);
			break;
		}
		case '�':
		{
			AddNounByEndingE(NounList);
			break;
		}
		case '�':
		{
			AddNounByEndingU(NounList);
			break;
		}
		case '�':
		{
			AddNounByEndingYU(NounList);
			break;
		}
		case '�':
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
		case '�':
		{
			switch (c[a.k[1]])
			{
			case '�':
			{
				AddNounByEndingOYandEY(NounList);
				break;
			}
			case '�':
			{
				AddNounByEndingOMandEM(NounList);
				break;
			}
			}
		}
		case '�':
		{
			switch (c[a.k[1]])
			{
			case '�':
			{
				AddNounByEndingOYandEY(NounList);
				break;
			}
			case '�':
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
		case '�':
		{
			AddAdjectiveByEndingA(AdjectiveList);
		}
		case '�':
		{
			AddAdjectiveByEndingOandE(AdjectiveList);
		}
		case '�':
		{
			AddAdjectiveByEndingOandE(AdjectiveList);
		}
		case '�':
		{
			AddAdjectiveByEndingUandYU(AdjectiveList);
		}
		case '�':
		{
			AddAdjectiveByEndingUandYU(AdjectiveList);
		}
		case '�':
		{
			AddAdjectiveByEndingYIandI(AdjectiveList);
		}
		case '�':
		{
			AddAdjectiveByEndingYIandI(AdjectiveList);
		}
		}
	}

	if (a.k.size() == 2)
	{
		switch (c[a.k[0]])
		{
		case '�':
		{
			switch (c[a.k[1]])
			{
			case '�':
			{
				AddAdjectiveByEndingYIYandIY(AdjectiveList);
			}
			case '�':
			{
				AddAdjectiveByEndingYUMandIM(AdjectiveList);
			}
			case '�':
			{
				AddAdjectiveByEndingYIHandIH(AdjectiveList);
			}
			}
		}
		case '�':
		{
			switch (c[a.k[1]])
			{
			case '�':
			{
				AddAdjectiveByEndingYIYandIY(AdjectiveList);
			}
			case '�':
			{
				AddAdjectiveByEndingYUMandIM(AdjectiveList);
			}
			case '�':
			{
				AddAdjectiveByEndingYIHandIH(AdjectiveList);
			}
			}
		}
		case '�':
		{
			switch (c[a.k[1]])
			{
			case '�':
			{
				AddAdjectiveByEndingOY(AdjectiveList);
			}
			case '�':
			{
				AddAdjectiveByEndingOEandEE(AdjectiveList);
			}
			case '�':
			{
				AddAdjectiveByEndingOMandEM(AdjectiveList);
			}
			case '�':
			{
				AddAdjectiveByEndingOYUandEYU(AdjectiveList);
			}
			}
		}
		case '�':
		{
			switch (c[a.k[1]])
			{
			case '�':
			{
				AddAdjectiveByEndingOEandEE(AdjectiveList);
			}
			case '�':
			{
				AddAdjectiveByEndingOMandEM(AdjectiveList);
			}
			case '�':
			{
				AddAdjectiveByEndingEY(AdjectiveList);
			}
			case '�':
			{
				AddAdjectiveByEndingOYUandEYU(AdjectiveList);
			}
			}
		}
		case '�':
		{
			switch (c[a.k[1]])
			{
			case '�':
			{
				AddAdjectiveByEndingUYUandYUYU(AdjectiveList);
			}
			}
		}
		case '�':
		{
			switch (c[a.k[1]])
			{
			case '�':
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
		case '�':
		{
			switch (c[a.k[1]])
			{
			case '�':
			{
				switch (c[a.k[2]])
				{
				case '�':
				{
					AddAdjectiveByEndingOGOandEGO(AdjectiveList);
				}
				}
			}
			case '�':
			{
				switch (c[a.k[2]])
				{
				case '�':
				{
					AddAdjectiveByEndingOMUandEMU(AdjectiveList);
				}
				}
			}
			}
		}
		case '�':
		{
			switch (c[a.k[1]])
			{
			case '�':
			{
				switch (c[a.k[2]])
				{
				case '�':
				{
					AddAdjectiveByEndingOGOandEGO(AdjectiveList);
				}
				}
			}
			case '�':
			{
				switch (c[a.k[2]])
				{
				case '�':
				{
					AddAdjectiveByEndingOMUandEMU(AdjectiveList);
				}
				}
			}
			}
		}
		case '�':
		{
			switch (c[a.k[1]])
			{
			case '�':
			{
				switch (c[a.k[2]])
				{
				case '�':
				{
					AddAdjectiveByEndingYIMIandIMI(AdjectiveList);
				}
				}
			}
			}
		}
		case '�':
		{
			switch (c[a.k[1]])
			{
			case '�':
			{
				switch (c[a.k[2]])
				{
				case '�':
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