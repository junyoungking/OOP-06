#include "header.h"
#include "NDatabase.h"
#include <iostream>
using namespace std;


	NDatabase::NDatabase()
	{
		mnextNewspaperNumber = kFirstNewspaperNumber;
	}
	NDatabase::~NDatabase() {}
										
	Newspaper& NDatabase::addNewspaper(string title, int likes, int dislikes)// 여기서 title은 신문사 이야기하는것
	{
		Newspaper theNewspaper;
		theNewspaper.setnewspaper(title, likes, dislikes);
		theNewspaper.setnewspaperid(mnextNewspaperNumber++);
		mNewspaper.push_back(theNewspaper);
		return mNewspaper[mNewspaper.size() - 1];

	}



	Newspaper& NDatabase::getNewspaper(int inNewspaperid)
	{
		for (auto iter = mNewspaper.begin(); iter != mNewspaper.end(); ++iter)
		{
			if (iter->getnewspaperid() == inNewspaperid)
				return *iter;
		}
		cerr << "No Newspaper with number " << inNewspaperid << endl;
		throw exception();
	}
	void NDatabase::displayALL() const
	{
		for (auto iter = mNewspaper.begin(); iter != mNewspaper.end(); ++iter)
		{	
			iter->display();
		}

	}
	void NDatabase::displaycurrent(int inNewspaperid) const
	{
		int count = 0;
		for (auto iter = mNewspaper.begin(); iter != mNewspaper.end(); ++iter)
		{
			if (iter->getnewspaperid() == inNewspaperid)
			{
				iter->displaymore();
				count++;
			}
		}
		if (count == 0) 
		{
			cout << "식별번호와 일치하는 언론사가 없습니다" << endl;
		}
	}
	string NDatabase::ID_Title_Changer(int newspaperid) const
	{	
		string title;
		int count = 0;
		for (auto iter = mNewspaper.begin(); iter != mNewspaper.end(); ++iter)
		{
			if (iter->getnewspaperid() == newspaperid)
			{
				 title = iter->gettitle();
				 count++;
				 break;
			}
		}
		if (count == 0)
		{
			
			cout << "식별번호와 일치하는 언론사가 없습니다." << endl;
			return "";
		}
		else
			return title;
	}

	