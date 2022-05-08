#pragma once
#include "header.h"
#include<iostream>
using namespace std;
#include<vector>
#include"Article.h"




	class ADatabase
	{
	public:
		ADatabase();
		~ADatabase();

		Article& addArticle(string title, string newspaper, string keywords, int likes, int dislikes, string time, string incase, string content);
		Article& getArticle(int inArticleid);
		void displayALL() const;
		void display_Target(string ntitle) const;
		void display_case(string ncase) const;
		void displaycurrent(int inArticleid) const;
		string getarticletitle(int inArticleid) const;


	protected:
		const int kFirstArticleNumber = 1000;
		vector<Article> mArticle;
		int mnextArticleNumber;
	};
	


