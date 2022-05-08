#include "header.h"
#include "Newspaper.h"
#include<iostream>
using namespace std;


	Newspaper::Newspaper()
		: mtitle(""), mdislikes(0), mlikes(0), mnewspaperid(-1) {}

	void Newspaper::display() const // ���� ���������� �ʴ´�.
	{
		cout << "�Ź��� �ĺ���ȣ: [ " << getnewspaperid() << " ]" << endl;
		cout << "�깮�� �̸�: " << gettitle() << endl;
		cout << endl;
	}

	void Newspaper::displaymore() const
	{
		cout << "�Ź��� �ĺ���ȣ: [ " << getnewspaperid() << " ]" << endl;
		cout << "�Ź��� �̸�: " << gettitle() << '\n' << "���ƿ��: " << getlikes() << " / �Ⱦ���: " << getdislikes() << endl;
		cout << endl;
	}

	void Newspaper::setnewspaper(string title, int likes, int dislikes)
	{
		mtitle = title;
		mlikes = likes;
		mdislikes = dislikes;
	}

	void Newspaper::setnewspaperid(int newspaperid)
	{
		mnewspaperid = newspaperid;
	}

	int Newspaper::getnewspaperid() const
	{
		return mnewspaperid;
	}
	string Newspaper::gettitle() const
	{
		return mtitle;
	}
	int Newspaper::getlikes() const
	{
		return mlikes;
	}
	int Newspaper::getdislikes() const
	{
		return mdislikes;
	}
	
	