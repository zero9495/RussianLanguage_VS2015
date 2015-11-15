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