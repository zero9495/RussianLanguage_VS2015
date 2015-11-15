#pragma once
#pragma once
#include "Adjective.h"
#include <list>
using namespace std;

bool IsIn(const list<Adjective> &AdjectiveList, const Adjective &t)
{
	for (list<Adjective>::const_iterator p = AdjectiveList.begin(); p != AdjectiveList.end(); p++)
	{
		if (*p == t)
		{
			return true;
		}
	}
	return false;
}

void MyPush(list<Adjective> &AdjectiveList, const Adjective &t)
{
	if (!IsIn(AdjectiveList, t))
	{
		AdjectiveList.push_back(t);
	}
}

string null;

void AddAdjectiveByEndingYIYandIY(list<Adjective> &AdjectiveList) //-ый, ий
{
	//мужской род, именительный падеж, ед.число
	Adjective* t1 = new Adjective("Мужской", "Единственное", "Именительный", null);
	MyPush(AdjectiveList, *t1);
	delete t1;

	//мужской род, винительный падеж, ед.число
	t1 = new Adjective("Мужской", "Единственное", "Винительный", null);
	MyPush(AdjectiveList, *t1);
	delete t1;
}

void AddAdjectiveByEndingOY(list<Adjective> &AdjectiveList) //-ой
{
	//-мужской род, именительный падеж, ед.число
	Adjective* t1 = new Adjective("Мужской", "Единственное", "Именительный", null);
	MyPush(AdjectiveList, *t1);
	delete t1;

	//- женский род, родительный падеж, ед.число
	t1 = new Adjective("Женский", "Единственное", "Родительный", null);
	MyPush(AdjectiveList, *t1);
	delete t1;

	//- женский род, родительный падеж, ед.число, притяжательное
	t1 = new Adjective("Женский", "Единственное", "Родительный", "Притяжательное");
	MyPush(AdjectiveList, *t1);
	delete t1;

	//- женский род, дательный падеж, ед.число
	t1 = new Adjective("Женский", "Единственное", "Дательный", null);
	MyPush(AdjectiveList, *t1);
	delete t1;

	//- женский род, дательный падеж, ед.число, притяжательное
	t1 = new Adjective("Женский", "Единственное", "Дательный", "Притяжательное");
	MyPush(AdjectiveList, *t1);
	delete t1;

	//- женский род, творительный падеж, ед.число
	t1 = new Adjective("Женский", "Единственное", "Творительный", null);
	MyPush(AdjectiveList, *t1);
	delete t1;

	//- женский род, творительный падеж, ед.число, притяжательное
	t1 = new Adjective("Женский", "Единственное", "Творительный", "Притяжтаельное");
	MyPush(AdjectiveList, *t1);
	delete t1;

	//- женский род, предложный падеж, ед.число
	t1 = new Adjective("Женский", "Единственное", "Предложный", null);
	MyPush(AdjectiveList, *t1);
	delete t1;

	//- женский род, предложный падеж, ед.число, притяжательное
	t1 = new Adjective("Женский", "Единственное", "Предложный", "Притяжательное");
	MyPush(AdjectiveList, *t1);
	delete t1;
}

void AddAdjectiveByEndingOEandEE(list<Adjective> &AdjectiveList) //-ое, -ее
{
	//- средний род, именительный падеж, ед.число
	Adjective* t1 = new Adjective("Средний", "Единственное", "Именительный", null);
	MyPush(AdjectiveList, *t1);
	delete t1;
}

void AddAdjectiveByEndingOGOandEGO(list<Adjective> &AdjectiveList) //-ого, -его
{
	//- мужской род, родительный падеж, ед.число
	Adjective* t1 = new Adjective("Мужской", "Единственное", "Родительный", null);
	MyPush(AdjectiveList, *t1);
	delete t1;

	//-мужской род, родительный падеж, ед.число, притяжательное
	t1 = new Adjective("Мужской", "Единственное", "Родительный", "Притяжаетльное");
	MyPush(AdjectiveList, *t1);
	delete t1;

	//- средний род, родительный падеж, ед.число
	t1 = new Adjective("Средний", "Единственное", "Родительный", null);
	MyPush(AdjectiveList, *t1);
	delete t1;

	//- средний род, родительный падеж, ед.число, притяжательное
	t1 = new Adjective("Средний", "Единственное", "Родительный", "Притяжаетльное");
	MyPush(AdjectiveList, *t1);
	delete t1;
}

void AddAdjectiveByEndingOMUandEMU(list<Adjective> &AdjectiveList) //-ому, -ему
{
	//-мужской род, дательный падеж, ед.число
	Adjective* t1 = new Adjective("Мужской", "Единственное", "Дательный", null);
	MyPush(AdjectiveList, *t1);
	delete t1;

	//- мужской род, дательный падеж, ед.число, притяжательное
	t1 = new Adjective("Мужской", "Единственное", "Дательный", "Притяжательное");
	MyPush(AdjectiveList, *t1);
	delete t1;

	//- средний род, дательный падеж, ед.число
	t1 = new Adjective("Средний", "Единственное", "Дательный", null);
	MyPush(AdjectiveList, *t1);
	delete t1;

	//- средний род, дательный падеж, ед.число, притяжательное
	t1 = new Adjective("Средний", "Единственное", "Дательный", "Притяжательное");
	MyPush(AdjectiveList, *t1);
	delete t1;
}

void AddAdjectiveByEndingYUMandIM(list<Adjective> &AdjectiveList) //-ым, им
{
	//-мужской род, творительный падеж, ед.число
	Adjective* t1 = new Adjective("Мужской", "Единственное", "Творительный", null);
	MyPush(AdjectiveList, *t1);
	delete t1;

	//- мужской род, творительный падеж, ед.число, притяжательное
	t1 = new Adjective("Мужской", "Единственное", "Творительный", "Притяжательное");
	MyPush(AdjectiveList, *t1);
	delete t1;

	//- средний род, творительный падеж, ед.число
	t1 = new Adjective("Средний", "Единственное", "Творительный", null);
	MyPush(AdjectiveList, *t1);
	delete t1;

	//- средний род, творительный падеж, ед.число, притяжательное
	t1 = new Adjective("Средний", "Единственное", "Творительный", "Притяжательное");
	MyPush(AdjectiveList, *t1);
	delete t1;

	//- дательный падеж, мн.число, притяжательное
	t1 = new Adjective(null, "Множественное", "Дательный", "Притяжательное");
	MyPush(AdjectiveList, *t1);
	delete t1;
}

void AddAdjectiveByEndingOMandEM(list<Adjective> &AdjectiveList) //-ом, -ем
{
	//-мужской род, предложный падеж, ед.число
	Adjective* t1 = new Adjective("Мужской", "Единственное", "Предложный", null);
	MyPush(AdjectiveList, *t1);
	delete t1;

	//- мужской род, предложный падеж, ед.число, притяжательное
	t1 = new Adjective("Мужской", "Единственное", "Предложный", "Притяжательное");
	MyPush(AdjectiveList, *t1);
	delete t1;

	//- средний род, предложный падеж, ед.число
	t1 = new Adjective("Средний", "Единственное", "Предложный", null);
	MyPush(AdjectiveList, *t1);
	delete t1;

	//- средний род, предложный падеж, ед.число, притяжательное
	t1 = new Adjective("Средний", "Единственное", "Предложный", "Притяжательное");
	MyPush(AdjectiveList, *t1);
	delete t1;
}

void AddAdjectiveByEndingEY(list<Adjective> &AdjectiveList) //-ей
{
	//-женский род, родительный падеж, ед.число
	Adjective* t1 = new Adjective("Женский", "Единственное", "Родительный", null);
	MyPush(AdjectiveList, *t1);
	delete t1;

	//- женский род, родительный падеж, ед.число, притяжательное
	t1 = new Adjective("Женский", "Единственное", "Родительный", "Притяжательное");
	MyPush(AdjectiveList, *t1);
	delete t1;

	//- женский род, дательный падеж, ед.число
	t1 = new Adjective("Женский", "Единственное", "Дательный", null);
	MyPush(AdjectiveList, *t1);
	delete t1;

	//- женский род, дательный падеж, ед.число, притяжательное
	t1 = new Adjective("Женский", "Единственное", "Дательный", "Притяжательное");
	MyPush(AdjectiveList, *t1);
	delete t1;

	//- женский род, творительный падеж, ед.число
	t1 = new Adjective("Женский", "Единственное", "Творительный", null);
	MyPush(AdjectiveList, *t1);
	delete t1;

	//- женский род, творительный падеж, ед.число, притяжательное
	t1 = new Adjective("Женский", "Единственное", "Творительный", "Притяжательное");
	MyPush(AdjectiveList, *t1);
	delete t1;

	//- женский род, предложный падеж, ед.число
	t1 = new Adjective("Женский", "Единственное", "Предложный", null);
	MyPush(AdjectiveList, *t1);
	delete t1;

	//- женский род, предложный падеж, ед.число, притяжательное
	t1 = new Adjective("Женский", "Единственное", "Предложный", "Притяжательное");
	MyPush(AdjectiveList, *t1);
	delete t1;
}

void AddAdjectiveByEndingOYUandEYU(list<Adjective> &AdjectiveList) //-ою, -ею
{
	//-женский род, творительный падеж, ед.число
	Adjective* t1 = new Adjective("Женский", "Единственное", "Творительный", null);
	MyPush(AdjectiveList, *t1);
	delete t1;
}

void AddAdjectiveByEndingUYUandYUYU(list<Adjective> &AdjectiveList) //-ую, -юю
{
	//-женский род, винительный падеж, ед.число
	Adjective* t1 = new Adjective("Женский", "Единственное", "Винительный", null);
	MyPush(AdjectiveList, *t1);
	delete t1;
}

void AddAdjectiveByEndingNULL(list<Adjective> &AdjectiveList) // нулевое
{
	//-мужской род, именительный падеж, ед.число, притяжательное
	Adjective* t1 = new Adjective("Мужской", "Единственное", "Именительный", "Притяжательное");
	MyPush(AdjectiveList, *t1);
	delete t1;
}

void AddAdjectiveByEndingA(list<Adjective> &AdjectiveList) // -а
{
	//-женский род, именительный падеж, ед.число, притяжательное
	Adjective* t1 = new Adjective("Женский", "Единственное", "Именительный", "Притяжательное");
	MyPush(AdjectiveList, *t1);
	delete t1;
}

void AddAdjectiveByEndingOandE(list<Adjective> &AdjectiveList) // -о, -е
{
	//-средний род, именительный падеж, ед.число, притяжательное
	Adjective* t1 = new Adjective("Средний", "Единственное", "Именительный", "Притяжательное");
	MyPush(AdjectiveList, *t1);
	delete t1;
}

void AddAdjectiveByEndingUandYU(list<Adjective> &AdjectiveList) // -у, -ю
{
	//-женский род, винительный падеж, ед.число, притяжательное
	Adjective* t1 = new Adjective("Женский", "Единственное", "Винительный", "Притяжательное");
	MyPush(AdjectiveList, *t1);
	delete t1;
}

void AddAdjectiveByEndingYIandI(list<Adjective> &AdjectiveList) // -ы, -и
{
	//-именительный падеж, мн.число, притяжательное
	Adjective* t1 = new Adjective(null, "Множественное", "Именительный", "Притяжательное");
	MyPush(AdjectiveList, *t1);
	delete t1;
}

void AddAdjectiveByEndingYIHandIH(list<Adjective> &AdjectiveList) // -ых, -их
{
	//-родительный падеж, мн.число, притяжательное
	Adjective* t1 = new Adjective(null, "Множественное", "Родительный", "Притяжательное");
	MyPush(AdjectiveList, *t1);
	delete t1;

	//-предложный падеж, мн.число, притяжательное
	t1 = new Adjective(null, "Множественное", "Предложный", "Притяжательное");
	MyPush(AdjectiveList, *t1);
	delete t1;
}

void AddAdjectiveByEndingYIMIandIMI(list<Adjective> &AdjectiveList) // -ыми, -ими
{
	//-творительный падеж, мн.число, притяжательное
	Adjective* t1 = new Adjective(null, "Множественное", "Творительный", "Притяжательное");
	MyPush(AdjectiveList, *t1);
	delete t1;
}