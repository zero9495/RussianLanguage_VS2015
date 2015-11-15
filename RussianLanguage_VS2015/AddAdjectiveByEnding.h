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

void AddAdjectiveByEndingYIYandIY(list<Adjective> &AdjectiveList) //-��, ��
{
	//������� ���, ������������ �����, ��.�����
	Adjective* t1 = new Adjective("�������", "������������", "������������", null);
	MyPush(AdjectiveList, *t1);
	delete t1;

	//������� ���, ����������� �����, ��.�����
	t1 = new Adjective("�������", "������������", "�����������", null);
	MyPush(AdjectiveList, *t1);
	delete t1;
}

void AddAdjectiveByEndingOY(list<Adjective> &AdjectiveList) //-��
{
	//-������� ���, ������������ �����, ��.�����
	Adjective* t1 = new Adjective("�������", "������������", "������������", null);
	MyPush(AdjectiveList, *t1);
	delete t1;

	//- ������� ���, ����������� �����, ��.�����
	t1 = new Adjective("�������", "������������", "�����������", null);
	MyPush(AdjectiveList, *t1);
	delete t1;

	//- ������� ���, ����������� �����, ��.�����, ��������������
	t1 = new Adjective("�������", "������������", "�����������", "��������������");
	MyPush(AdjectiveList, *t1);
	delete t1;

	//- ������� ���, ��������� �����, ��.�����
	t1 = new Adjective("�������", "������������", "���������", null);
	MyPush(AdjectiveList, *t1);
	delete t1;

	//- ������� ���, ��������� �����, ��.�����, ��������������
	t1 = new Adjective("�������", "������������", "���������", "��������������");
	MyPush(AdjectiveList, *t1);
	delete t1;

	//- ������� ���, ������������ �����, ��.�����
	t1 = new Adjective("�������", "������������", "������������", null);
	MyPush(AdjectiveList, *t1);
	delete t1;

	//- ������� ���, ������������ �����, ��.�����, ��������������
	t1 = new Adjective("�������", "������������", "������������", "��������������");
	MyPush(AdjectiveList, *t1);
	delete t1;

	//- ������� ���, ���������� �����, ��.�����
	t1 = new Adjective("�������", "������������", "����������", null);
	MyPush(AdjectiveList, *t1);
	delete t1;

	//- ������� ���, ���������� �����, ��.�����, ��������������
	t1 = new Adjective("�������", "������������", "����������", "��������������");
	MyPush(AdjectiveList, *t1);
	delete t1;
}

void AddAdjectiveByEndingOEandEE(list<Adjective> &AdjectiveList) //-��, -��
{
	//- ������� ���, ������������ �����, ��.�����
	Adjective* t1 = new Adjective("�������", "������������", "������������", null);
	MyPush(AdjectiveList, *t1);
	delete t1;
}

void AddAdjectiveByEndingOGOandEGO(list<Adjective> &AdjectiveList) //-���, -���
{
	//- ������� ���, ����������� �����, ��.�����
	Adjective* t1 = new Adjective("�������", "������������", "�����������", null);
	MyPush(AdjectiveList, *t1);
	delete t1;

	//-������� ���, ����������� �����, ��.�����, ��������������
	t1 = new Adjective("�������", "������������", "�����������", "��������������");
	MyPush(AdjectiveList, *t1);
	delete t1;

	//- ������� ���, ����������� �����, ��.�����
	t1 = new Adjective("�������", "������������", "�����������", null);
	MyPush(AdjectiveList, *t1);
	delete t1;

	//- ������� ���, ����������� �����, ��.�����, ��������������
	t1 = new Adjective("�������", "������������", "�����������", "��������������");
	MyPush(AdjectiveList, *t1);
	delete t1;
}

void AddAdjectiveByEndingOMUandEMU(list<Adjective> &AdjectiveList) //-���, -���
{
	//-������� ���, ��������� �����, ��.�����
	Adjective* t1 = new Adjective("�������", "������������", "���������", null);
	MyPush(AdjectiveList, *t1);
	delete t1;

	//- ������� ���, ��������� �����, ��.�����, ��������������
	t1 = new Adjective("�������", "������������", "���������", "��������������");
	MyPush(AdjectiveList, *t1);
	delete t1;

	//- ������� ���, ��������� �����, ��.�����
	t1 = new Adjective("�������", "������������", "���������", null);
	MyPush(AdjectiveList, *t1);
	delete t1;

	//- ������� ���, ��������� �����, ��.�����, ��������������
	t1 = new Adjective("�������", "������������", "���������", "��������������");
	MyPush(AdjectiveList, *t1);
	delete t1;
}

void AddAdjectiveByEndingYUMandIM(list<Adjective> &AdjectiveList) //-��, ��
{
	//-������� ���, ������������ �����, ��.�����
	Adjective* t1 = new Adjective("�������", "������������", "������������", null);
	MyPush(AdjectiveList, *t1);
	delete t1;

	//- ������� ���, ������������ �����, ��.�����, ��������������
	t1 = new Adjective("�������", "������������", "������������", "��������������");
	MyPush(AdjectiveList, *t1);
	delete t1;

	//- ������� ���, ������������ �����, ��.�����
	t1 = new Adjective("�������", "������������", "������������", null);
	MyPush(AdjectiveList, *t1);
	delete t1;

	//- ������� ���, ������������ �����, ��.�����, ��������������
	t1 = new Adjective("�������", "������������", "������������", "��������������");
	MyPush(AdjectiveList, *t1);
	delete t1;

	//- ��������� �����, ��.�����, ��������������
	t1 = new Adjective(null, "�������������", "���������", "��������������");
	MyPush(AdjectiveList, *t1);
	delete t1;
}

void AddAdjectiveByEndingOMandEM(list<Adjective> &AdjectiveList) //-��, -��
{
	//-������� ���, ���������� �����, ��.�����
	Adjective* t1 = new Adjective("�������", "������������", "����������", null);
	MyPush(AdjectiveList, *t1);
	delete t1;

	//- ������� ���, ���������� �����, ��.�����, ��������������
	t1 = new Adjective("�������", "������������", "����������", "��������������");
	MyPush(AdjectiveList, *t1);
	delete t1;

	//- ������� ���, ���������� �����, ��.�����
	t1 = new Adjective("�������", "������������", "����������", null);
	MyPush(AdjectiveList, *t1);
	delete t1;

	//- ������� ���, ���������� �����, ��.�����, ��������������
	t1 = new Adjective("�������", "������������", "����������", "��������������");
	MyPush(AdjectiveList, *t1);
	delete t1;
}

void AddAdjectiveByEndingEY(list<Adjective> &AdjectiveList) //-��
{
	//-������� ���, ����������� �����, ��.�����
	Adjective* t1 = new Adjective("�������", "������������", "�����������", null);
	MyPush(AdjectiveList, *t1);
	delete t1;

	//- ������� ���, ����������� �����, ��.�����, ��������������
	t1 = new Adjective("�������", "������������", "�����������", "��������������");
	MyPush(AdjectiveList, *t1);
	delete t1;

	//- ������� ���, ��������� �����, ��.�����
	t1 = new Adjective("�������", "������������", "���������", null);
	MyPush(AdjectiveList, *t1);
	delete t1;

	//- ������� ���, ��������� �����, ��.�����, ��������������
	t1 = new Adjective("�������", "������������", "���������", "��������������");
	MyPush(AdjectiveList, *t1);
	delete t1;

	//- ������� ���, ������������ �����, ��.�����
	t1 = new Adjective("�������", "������������", "������������", null);
	MyPush(AdjectiveList, *t1);
	delete t1;

	//- ������� ���, ������������ �����, ��.�����, ��������������
	t1 = new Adjective("�������", "������������", "������������", "��������������");
	MyPush(AdjectiveList, *t1);
	delete t1;

	//- ������� ���, ���������� �����, ��.�����
	t1 = new Adjective("�������", "������������", "����������", null);
	MyPush(AdjectiveList, *t1);
	delete t1;

	//- ������� ���, ���������� �����, ��.�����, ��������������
	t1 = new Adjective("�������", "������������", "����������", "��������������");
	MyPush(AdjectiveList, *t1);
	delete t1;
}

void AddAdjectiveByEndingOYUandEYU(list<Adjective> &AdjectiveList) //-��, -��
{
	//-������� ���, ������������ �����, ��.�����
	Adjective* t1 = new Adjective("�������", "������������", "������������", null);
	MyPush(AdjectiveList, *t1);
	delete t1;
}

void AddAdjectiveByEndingUYUandYUYU(list<Adjective> &AdjectiveList) //-��, -��
{
	//-������� ���, ����������� �����, ��.�����
	Adjective* t1 = new Adjective("�������", "������������", "�����������", null);
	MyPush(AdjectiveList, *t1);
	delete t1;
}

void AddAdjectiveByEndingNULL(list<Adjective> &AdjectiveList) // �������
{
	//-������� ���, ������������ �����, ��.�����, ��������������
	Adjective* t1 = new Adjective("�������", "������������", "������������", "��������������");
	MyPush(AdjectiveList, *t1);
	delete t1;
}

void AddAdjectiveByEndingA(list<Adjective> &AdjectiveList) // -�
{
	//-������� ���, ������������ �����, ��.�����, ��������������
	Adjective* t1 = new Adjective("�������", "������������", "������������", "��������������");
	MyPush(AdjectiveList, *t1);
	delete t1;
}

void AddAdjectiveByEndingOandE(list<Adjective> &AdjectiveList) // -�, -�
{
	//-������� ���, ������������ �����, ��.�����, ��������������
	Adjective* t1 = new Adjective("�������", "������������", "������������", "��������������");
	MyPush(AdjectiveList, *t1);
	delete t1;
}

void AddAdjectiveByEndingUandYU(list<Adjective> &AdjectiveList) // -�, -�
{
	//-������� ���, ����������� �����, ��.�����, ��������������
	Adjective* t1 = new Adjective("�������", "������������", "�����������", "��������������");
	MyPush(AdjectiveList, *t1);
	delete t1;
}

void AddAdjectiveByEndingYIandI(list<Adjective> &AdjectiveList) // -�, -�
{
	//-������������ �����, ��.�����, ��������������
	Adjective* t1 = new Adjective(null, "�������������", "������������", "��������������");
	MyPush(AdjectiveList, *t1);
	delete t1;
}

void AddAdjectiveByEndingYIHandIH(list<Adjective> &AdjectiveList) // -��, -��
{
	//-����������� �����, ��.�����, ��������������
	Adjective* t1 = new Adjective(null, "�������������", "�����������", "��������������");
	MyPush(AdjectiveList, *t1);
	delete t1;

	//-���������� �����, ��.�����, ��������������
	t1 = new Adjective(null, "�������������", "����������", "��������������");
	MyPush(AdjectiveList, *t1);
	delete t1;
}

void AddAdjectiveByEndingYIMIandIMI(list<Adjective> &AdjectiveList) // -���, -���
{
	//-������������ �����, ��.�����, ��������������
	Adjective* t1 = new Adjective(null, "�������������", "������������", "��������������");
	MyPush(AdjectiveList, *t1);
	delete t1;
}