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
			cout << "�������� ��ġ�ϴ� ��簡 �����ϴ�" << endl; //����
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
				cout << "��� �ĺ���ȣ : [" << iter->getAriticleid() << "]" << endl;
				cout << "�������: " << iter->gettitle() << endl;
				cout << "���� Ű����: " << iter->getkeywords() << endl;
				count++;
				count_like = count_like + iter->getlikes();
				count_dislike = count_dislike + iter->getdislikes();
			}
		}
		if (count == 0)
		{
			cout << "�������� ��ġ�ϴ� ��簡 �����ϴ�" << endl; //����
		}
		else
			cout << ncase << "�� ���� ȣ��ȣ�� ȣ:" << count_like << "��ȣ:" << count_dislike << "�Դϴ�" << endl;
			

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
			cout << "�ĺ���ȣ�� ��ġ�ϴ� ��簡 �����ϴ�" << endl; //����
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
			cout << "�ĺ���ȣ�� ��ġ�ϴ� ��л簡 �����ϴ�." << endl;
		}
		else
			return title;
	}
          