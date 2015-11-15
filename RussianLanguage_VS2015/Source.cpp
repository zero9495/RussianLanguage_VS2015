/*///////////////////////////////////////////////////////////////

08.11.2015 - 2931 строк

*////////////////////////////////////////////////////////////////

#pragma once
#include <Windows.h>
#include "Morphology.h"
using namespace std;

class PartOfSpeech //Часть речи
{
public:
	PartOfSpeech(Noun a);
	PartOfSpeech(Adjective a);

	string name;

	union
	{
		Noun* noun;
		Adjective* adjective;
	};
};

PartOfSpeech::PartOfSpeech(Noun a)
{
	name = "Существительное";
	noun = new Noun(a);
}

PartOfSpeech::PartOfSpeech(Adjective a)
{
	name = "Прилагательное";
	adjective = new Adjective(a);
}

class Word //Слово
{
public:
	Word(const string c);

	static DictionaryMorpheme DictMorph; //Словарь морфем
	string c; //Само слово
	list<MorphemicComposition> MorphComp; //Список морфемных составов

	list<PartOfSpeech> PartOfSpeechList; //Список возможных частей речи
};

DictionaryMorpheme Word::DictMorph = ReadDictionaryMorphemeFiles();

list<PartOfSpeech> CreatePartOfSpeechList(list<Noun> &NounList, list<Adjective> &AdjectiveList)
{
	list<PartOfSpeech> PartOfSpeechList;

	for (list<Noun>::iterator p = NounList.begin(); p != NounList.end(); p++)
	{
		PartOfSpeech t(*p);
		PartOfSpeechList.push_back(t);
	}

	for (list<Adjective>::iterator p = AdjectiveList.begin(); p != AdjectiveList.end(); p++)
	{
		PartOfSpeech t(*p);
		PartOfSpeechList.push_back(t);
	}

	return PartOfSpeechList;
}

Word::Word(const string str)
{
	c = str;

	MorphComp = FindAllPossibleMorphemicComposition(DictMorph, c);
	SpellControl(DictMorph, c, MorphComp);

	list<Noun> NounList = AddNoun(MorphComp, c); //Возможные существительные
	list<Adjective> AdjectiveList = AddAdjective(MorphComp, c); //Возможные прилагательные

	PartOfSpeechList = CreatePartOfSpeechList(NounList, AdjectiveList);
}

/*
class SchemeWordCombination //Схема словосочетания
{
public:
	//string MainWord; //главное слово
	//string DependentWord; //зависимое слово

	PartOfSpeech MainWord; //главное слово
	PartOfSpeech DependentWord; //зависимое слово

	string TypeOfConnection; //Тип подчинительной связи (согласование, управление, примыкание)
	string TypeByMainWord; //Тип словосочетания по характеру главного слова (глагольное, именное, наречное)
	string TypeByQuestion; //Тип по вопросу (определительное, объектное, обстоятельственное)
	string TypeByConposition; //Тип по составу (простое, сложное, комбинированное)
	string TypeByDegreeOfRelatedness; //Тип по степени связанности компонентов (свободные, несвободные, устойчивые выражения
									  //и фразеологизмы
};

class  WordCombination //Словосочетание
{
public:
	list<Word> WordComb; //Само словосочетание

	list<SchemeWordCombination> SchemeWordComb; //Схемы словосочетания
};



list<SchemeWordCombination> SyntacticAnalysis(list<Word> WordComb) //Синтаксический анализ
{
	list<SchemeWordCombination> SchemeWordCombList;
	vector<Word> v;

	int i = 0;
	for (list<Word>::iterator p = WordComb.begin(); p != WordComb.end(); p++)
	{
		v[i] = *p;
		i++;
	}

	if (v.size() == 2)
	{
		for (list<PartOfSpeech>::iterator p0 = v[0].PartOfSpeechList.begin(); p0 != v[0].PartOfSpeechList.end(); p0++)
		{
			for (list<PartOfSpeech>::iterator p1 = v[1].PartOfSpeechList.begin(); p1 != v[1].PartOfSpeechList.end(); p1++)
			{
				SchemeWordCombination t;
				t.MainWord = *p0;
				t.DependentWord = *p1;
				SchemeWordCombList.push_back(t);

				t.MainWord = *p1;
				t.DependentWord = *p0;
				SchemeWordCombList.push_back(t);
			}
		}
	}

	return SchemeWordCombList;
}*/

int main()
{
	//Настройка поддержки русского языка
	//SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	//SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода

	setlocale(LC_ALL, "RUS");
	//wcout.imbue(locale(".866"));

	ofstream fout1("output.txt");
	fout1.close();

	/*int item1 = -1;
	list<string>* t = 0;
	char* str = 0;

	while (item1)
	{
		cout << endl;*/

		PrintDictionaryMorpheme(Word::DictMorph);

		/*cout << "1) Добавить морфему в словарь\n";
		cout << "2) Удалить морфему из словаря\n";
		cout << "3) Разобрать слово по составу\n";
		cout << "0) Выход\n";
		cout << "Пункт: ";
		cin >> item1;
		cin.ignore();

		t = 0;
		delete[] str;

		switch (item1)
		{
		case 1: //Добавить морфему в словарь
		{
			strcpy_s(str, sizeof(str), "Добавить");
		}
		case 2: //Удалить морфему из словаря
		{
			if (item1 == 2)
			{
				strcpy_s(str, sizeof(str), "Удалить");
			}

			int item = -1;

			cout << endl;
			cout << "1) " << str << " приставку\n";
			cout << "2) " << str << " суффикс\n";
			cout << "3) " << str << " окончание\n";
			cout << "4) " << str << " букву перед нулевым окончанием\n";
			cout << "0) Выход\n";
			cout << "Пункт: ";
			cin >> item;
			cin.ignore();

			char c[256];
			cout << "c=";
			cin.getline(c, 256);
			string x;
			x = c;

			switch (item)
			{
			case 1:
			{
				t = &(Word::DictMorph.prefix);
				break;
			}
			case 2:
			{
				t = &(Word::DictMorph.suffix);
				break;
			}
			case 3:
			{
				t = &(Word::DictMorph.ending);
				break;
			}
			case 4:
			{
				t = &(Word::DictMorph.LettersBeforeZeroEnding);
			}
			}

			if (item1 == 1)
			{
				t->push_back(x);
				break;
			}
			t->remove(x);
			break;
		}
		case 3: //Разобрать слово по составу
		{*/

		//_DEBUG_ERROR("Hello!!!");
			char c[256];
		
			ifstream fin("input.txt");
			ofstream fout("output.txt", ios::app);
			
			fin >> c;
			fout << endl << "Слово: " << c << endl;
			Word* word = new Word(c);			

			while (fin >> c)
			{
				fout << endl << endl << "Слово: " << c << endl;
				delete word;
				word = new Word(c);
			}
			
			delete word;
			fin.close();			
			/*break;
		}
		}
		cout << endl;
	}*/

	SaveDictionaryMorphemeFiles(Word::DictMorph);
}