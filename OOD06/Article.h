#pragma once
#include "header.h"
#include "Comment.h"
#include <iostream>
#include <vector>
using namespace std;



	
	const int kDefaultstartingarticle = 10000;
	class Article
	{
	public:
		Article();			
		
		void display() const;
		void displaymore() const;

		
		void setarticle(string title, string newspaper, string keywords, int likes, int dislikes, string time, string incase, string content);

		
		void setAricleid(int n);

		
		string gettitle() const;
		string getcontent() const;
		string gettime() const;
		int getAriticleid() const;
		string getnewspaper() const;
		string getkeywords() const;
		int getlikes() const;
		string getcase() const;
		int getdislikes() const; // Ãß°¡
		string getincase() const;
		
	protected:
		string mtitle;
		string mcontent;
		string mkeywords;
		int mlikes;
		int mdislikes;
		string mnewspaper;
		int mArticleid;
		string mtime;
		string mcase;

		
	};

