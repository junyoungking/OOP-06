#include "header.h"
#include "Newspaper.h"
#include<iostream>
using namespace std;


	Newspaper::Newspaper()
		: mtitle(""), mdislikes(0), mlikes(0), mnewspaperid(-1) {}

	void Newspaper::display() const // 현재 쓰고있지는 않는다.
	{
		cout << "신문사 식별번호: [ " << getnewspaperid() << " ]" << endl;
		cout << "산문사 이름: " << gettitle() << endl;
		cout << endl;
	}

	void Newspaper::displaymore() const
	{
		cout << "신문사 식별번호: [ " << getnewspaperid() << " ]" << endl;
		cout << "신문사 이름: " << gettitle() << '\n' << "좋아요수: " << getlikes() << " / 싫어요수: " << getdislikes() << endl;
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
	
	