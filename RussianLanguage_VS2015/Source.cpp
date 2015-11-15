/*///////////////////////////////////////////////////////////////

08.11.2015 - 2931 �����

*////////////////////////////////////////////////////////////////

#pragma once
#include <Windows.h>
#include "Morphology.h"
using namespace std;

class PartOfSpeech //����� ����
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
	name = "���������������";
	noun = new Noun(a);
}

PartOfSpeech::PartOfSpeech(Adjective a)
{
	name = "��������������";
	adjective = new Adjective(a);
}

class Word //�����
{
public:
	Word(const string c);

	static DictionaryMorpheme DictMorph; //������� ������
	string c; //���� �����
	list<MorphemicComposition> MorphComp; //������ ��������� ��������

	list<PartOfSpeech> PartOfSpeechList; //������ ��������� ������ ����
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

	list<Noun> NounList = AddNoun(MorphComp, c); //��������� ���������������
	list<Adjective> AdjectiveList = AddAdjective(MorphComp, c); //��������� ��������������

	PartOfSpeechList = CreatePartOfSpeechList(NounList, AdjectiveList);
}

/*
class SchemeWordCombination //����� ��������������
{
public:
	//string MainWord; //������� �����
	//string DependentWord; //��������� �����

	PartOfSpeech MainWord; //������� �����
	PartOfSpeech DependentWord; //��������� �����

	string TypeOfConnection; //��� �������������� ����� (������������, ����������, ����������)
	string TypeByMainWord; //��� �������������� �� ��������� �������� ����� (����������, �������, ��������)
	string TypeByQuestion; //��� �� ������� (���������������, ���������, ������������������)
	string TypeByConposition; //��� �� ������� (�������, �������, ���������������)
	string TypeByDegreeOfRelatedness; //��� �� ������� ����������� ����������� (���������, �����������, ���������� ���������
									  //� �������������
};

class  WordCombination //��������������
{
public:
	list<Word> WordComb; //���� ��������������

	list<SchemeWordCombination> SchemeWordComb; //����� ��������������
};



list<SchemeWordCombination> SyntacticAnalysis(list<Word> WordComb) //�������������� ������
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
	//��������� ��������� �������� �����
	//SetConsoleCP(1251);// ��������� ������� �������� win-cp 1251 � ����� �����
	//SetConsoleOutputCP(1251); // ��������� ������� �������� win-cp 1251 � ����� ������

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

		/*cout << "1) �������� ������� � �������\n";
		cout << "2) ������� ������� �� �������\n";
		cout << "3) ��������� ����� �� �������\n";
		cout << "0) �����\n";
		cout << "�����: ";
		cin >> item1;
		cin.ignore();

		t = 0;
		delete[] str;

		switch (item1)
		{
		case 1: //�������� ������� � �������
		{
			strcpy_s(str, sizeof(str), "��������");
		}
		case 2: //������� ������� �� �������
		{
			if (item1 == 2)
			{
				strcpy_s(str, sizeof(str), "�������");
			}

			int item = -1;

			cout << endl;
			cout << "1) " << str << " ���������\n";
			cout << "2) " << str << " �������\n";
			cout << "3) " << str << " ���������\n";
			cout << "4) " << str << " ����� ����� ������� ����������\n";
			cout << "0) �����\n";
			cout << "�����: ";
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
		case 3: //��������� ����� �� �������
		{*/

		//_DEBUG_ERROR("Hello!!!");
			char c[256];
		
			ifstream fin("input.txt");
			ofstream fout("output.txt", ios::app);
			
			fin >> c;
			fout << endl << "�����: " << c << endl;
			Word* word = new Word(c);			

			while (fin >> c)
			{
				fout << endl << endl << "�����: " << c << endl;
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