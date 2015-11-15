/*///////////////////////////////////////////////////////
                    ������� ������
*////////////////////////////////////////////////////////
#pragma once
#include <iostream>
#include <fstream>
#include <list>
#include <iterator>
using namespace std;

/*struct DictionaryMorpheme //������� ������
{
	list<string> ending;
	list<string> suffix;
	list<string> prefix;
	list<string> LettersBeforeZeroEnding;
};*/

class DictionaryMorpheme //������� ������
{
public:
	DictionaryMorpheme();
	~DictionaryMorpheme();

	list<string> GetEnding() const;
	list<string> GetSuffix() const;
	list<string> GetPrefix() const;
	list<string> GetLettersBeforeZeroEnding() const;

	void ReadFromFiles();
	void SaveToFiles() const;

	friend ostream& operator<<(ostream& os, const DictionaryMorpheme& a);

private:
	list<string> ending;
	list<string> suffix;
	list<string> prefix;
	list<string> lettersBeforeZeroEnding;
};

DictionaryMorpheme::DictionaryMorpheme()
{
}

DictionaryMorpheme::~DictionaryMorpheme()
{
}

namespace std {
	// ��������� �������� "������" ������������ ���� std
	inline ostream& operator<< (ostream& out, const string c)
	{
		return (out << c.c_str());
	}
}

void Filing(const list<string> a, const string c1, const string c2) //��������� ������ � ����
{
	ofstream fout(c1);

	fout << c2 << " " << a.size() << " ";

	for (list<string>::const_iterator p = a.begin(); p != a.end(); p++)
	{
		fout << p->c_str() << " ";
	}

	fout.close();
}

list<string> ReadingFile(const string c1, const string c2) //��������� ������ �� �����
{
	list<string> a;

	ifstream fin(c1);
	char c[256];

	fin >> c;

	if (!strcmp(c, c2.c_str()))
	{
		fin >> c;
		int k = atoi(c);

		for (int i = 0; i < k; i++)
		{
			fin >> c;
			a.push_back(c);
		}
	}

	return a;
}

void DictionaryMorpheme::ReadFromFiles()
{
	this->ending = ReadingFile("endings.txt", "endings");
	this->suffix = ReadingFile("suffix.txt", "suffix");
	this->prefix = ReadingFile("prefix.txt", "prefix");
	this->lettersBeforeZeroEnding = ReadingFile("LettersBeforeZeroEnding.txt", "LettersBeforeZeroEnding");
}

/*
DictionaryMorpheme ReadDictionaryMorphemeFiles() //��������� ������� ������ �� ������
{
	DictionaryMorpheme* a = new DictionaryMorpheme;
	a->ending = ReadingFile("endings.txt", "endings");
	a->suffix = ReadingFile("suffix.txt", "suffix");
	a->prefix = ReadingFile("prefix.txt", "prefix");
	a->LettersBeforeZeroEnding = ReadingFile("LettersBeforeZeroEnding.txt", "LettersBeforeZeroEnding");
	return *a;
}*/

void DictionaryMorpheme::SaveToFiles() const
{
	Filing(this->ending, "endings.txt", "endings");
	Filing(this->suffix, "suffix.txt", "suffix");
	Filing(this->prefix, "prefix.txt", "prefix");
	Filing(this->lettersBeforeZeroEnding, "LettersBeforeZeroEnding.txt", "LettersBeforeZeroEnding");
}

/*void SaveDictionaryMorphemeFiles(const DictionaryMorpheme &a) //��������� ������� ������ � �����
{
	Filing(a.ending, "endings.txt", "endings");
	Filing(a.suffix, "suffix.txt", "suffix");
	Filing(a.prefix, "prefix.txt", "prefix");
	Filing(a.LettersBeforeZeroEnding, "LettersBeforeZeroEnding.txt", "LettersBeforeZeroEnding");
}*/

ostream& operator<<(ostream& os, const DictionaryMorpheme &a)
{
	os << "������� ������." << endl;

	os << "���������: ";
	copy(a.prefix.begin(), a.prefix.end(), ostream_iterator<string>(os, " -> "));

	os << endl << "��������: ";
	copy(a.suffix.begin(), a.suffix.end(), ostream_iterator<string>(os, " -> "));

	os << endl << "���������: ";
	copy(a.ending.begin(), a.ending.end(), ostream_iterator<string>(os, " -> "));

	os << endl << "����� ����� ������� ����������: ";
	copy(a.lettersBeforeZeroEnding.begin(), a.lettersBeforeZeroEnding.end(), ostream_iterator<string>(os, " -> "));
	os << endl << endl;
}

/*void PrintDictionaryMorpheme(const DictionaryMorpheme &a) //���������� ������� ������ �� ������
{
	ofstream fout("output.txt", ios::app);

	fout << "������� ������." << endl ;

	fout << "���������: ";
	copy(a.prefix.begin(), a.prefix.end(), ostream_iterator<string>(fout, " -> "));

	fout << endl << "��������: ";
	copy(a.suffix.begin(), a.suffix.end(), ostream_iterator<string>(fout, " -> "));

	fout << endl << "���������: ";
	copy(a.ending.begin(), a.ending.end(), ostream_iterator<string>(fout, " -> "));

	fout << endl << "����� ����� ������� ����������: ";
	copy(a.LettersBeforeZeroEnding.begin(), a.LettersBeforeZeroEnding.end(), ostream_iterator<string>(fout, " -> "));
	fout << endl << endl;

	fout.close();
}*/