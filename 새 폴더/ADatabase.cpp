#include "header.h"
#include "ADatabase.h"
#include <iostream>
#include <stdexcept>
using namespace std;


	ADatabase::ADatabase() {mnextArticleNumber = kFirstArticleNumber;}
	ADatabase::~ADatabase() {}

	Article& ADatabase::addArticle(string title, string newspaper, string keywords, int likes, int dislikes, string time, string incase, string content)
	{
		Article theArticle;
		theArticle.setarticle(title, newspaper, keywords, likes, dislikes, time, incase, content);
		theArticle.setAricleid(mnextArticleNumber++);
		mArticle.push_back(theArticle);
		return mArticle[mArticle.size() - 1];
	}

	Article& ADatabase::getArticle(int inArticleid)
	{
		for (auto iter = mArticle.begin(); iter != mArticle.end(); ++iter)
		{
			if (iter->getAriticleid() == inArticleid)
				return *iter;
		}
		cerr << "No article with number " << inArticleid << endl;
		throw exception();
	}
	
	void ADatabase::displayALL() const
	{
		for (auto iter = mArticle.begin(); iter != mArticle.end(); ++iter)
		{	

			iter->display();
		}

	}
	void ADatabase::display_Target(string ntitle) const                         
	{
		int count = 0;
		for (auto iter = mArticle.begin(); iter != mArticle.end(); ++iter)
		{
			if (iter->getnewspaper() == ntitle)
			{
				iter->display();
				count++;
			}
		}
		if (count == 0)
		{
			cout << "기사제목과 일치하는 기사가 없습니다" << endl; //수정
		}		
	}
	void ADatabase::display_case(string ncase) const
	{
		int count_like = 0;
		int count_dislike = 0;
		int count = 0;
		for (auto iter = mArticle.begin(); iter != mArticle.end(); ++iter)
		{
			if (iter->getincase() == ncase)
			{
				cout << "기사 식별번호 : [" << iter->getAriticleid() << "]" << endl;
				cout << "기사제목: " << iter->gettitle() << endl;
				cout << "관련 키워드: " << iter->getkeywords() << endl;
				count++;
				count_like = count_like + iter->getlikes();
				count_dislike = count_dislike + iter->getdislikes();
			}
		}
		if (count == 0)
		{
			cout << "기사제목과 일치하는 기사가 없습니다" << endl; //수정
		}
		else
			cout << ncase << "에 대한 호불호는 호:" << count_like << "불호:" << count_dislike << "입니다" << endl;
			

	}

	void ADatabase::displaycurrent(int inArticleid) const            //
	{
		int count = 0;
		for (auto iter = mArticle.begin(); iter != mArticle.end(); ++iter)
		{
			if (iter->getAriticleid() == inArticleid)
			{
				iter->displaymore();
				count++;
			}
		}
		if (count == 0)
		{
			cout << "식별번호와 일치하는 기사가 없습니다" << endl; //수정
		}
	}
	
	string ADatabase::getarticletitle(int inArticleid) const
	{
		string title;
		int count = 0;
		for (auto iter = mArticle.begin(); iter != mArticle.end(); ++iter)
		{
			if (iter->getAriticleid() == inArticleid)
			{
				return iter->gettitle();
				count++;
				break;
			}
		}
		if (count == 0)
		{
			cout << "식별번호와 일치하는 언론사가 없습니다." << endl;
		}
		else
			return title;
	}
          