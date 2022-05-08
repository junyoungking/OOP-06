#include "header.h"
#include "Article.h"
#include "Comment.h"
#include<iostream>
#include <stdexcept>
using namespace std;


	Article::Article()
		: mtitle(""), mcontent(""), mnewspaper(""), mkeywords(""), mtime(""), mlikes(0), mdislikes(0), mArticleid(-1) 
	{
		
	}

	void Article::display() const
	{
		cout << "��� �ĺ���ȣ: [ " << getAriticleid() << " ]" << endl;
		cout << "��� ����: " << gettitle()  << endl;
		cout << "�ٽ� ���:" << getincase() << endl;
		cout << endl;
	}
	void Article::displaymore() const
	{
		cout << "��� �ĺ���ȣ: [ " << getAriticleid() << " ]" << endl;
		cout << "��� ����: " << gettitle() << '\n' << "Content: " << getcontent() << endl;
		cout << endl;
		cout << "�ؽ� ��ũ:" << getkeywords() << "  ���ƿ� �� : " << getlikes() << "  �Ⱦ�� �� :" << getdislikes() << endl;
		cout << endl;


	}


	
	
	void Article::setarticle(string title, string newspaper, string keywords, int likes, int dislikes, string time, string incase, string content)
	{
		mnewspaper = newspaper;
		mkeywords = keywords;
		mtitle = title;
		mcontent = content;
		mlikes = likes;
		mdislikes = dislikes;
		mtime = time;
		mcase = incase;

	}
	string Article::gettime() const
	{
		return mtime;
	}
	string Article::getnewspaper() const
	{
		return mnewspaper;
	}
	string Article::getkeywords() const
	{
		return mkeywords;
	}
	int Article::getlikes() const
	{
		return mlikes;
	}
	string Article::getcase() const
	{
		return string();
	}
	int Article::getdislikes() const //�߰�
	{
		return mdislikes;
	}
	string Article::gettitle() const
	{
		return mtitle;
	}
	string Article::getcontent() const
	{
		return mcontent;
	}
	void Article::setAricleid(int inArticleid)
	{
		mArticleid = inArticleid;
	}
	int Article::getAriticleid() const
	{
		return mArticleid;
	}
	string Article::getincase() const
	{
		return mcase;
	}


	

	