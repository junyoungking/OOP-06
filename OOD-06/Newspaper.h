#pragma once
#include "header.h"
#include "Newspaper.h"
#include "Comment.h"
#include <iostream>
using namespace std;


	class Newspaper
	{
	public:
		Newspaper();

		void display() const;
		void displaymore() const;

		void setnewspaper(string title, int likes, int dislikes);

		void setnewspaperid(int n);

		int getnewspaperid() const;
		string gettitle() const;
		int getlikes()const ;     
		int getdislikes() const ; 
		
	private:
		int mnewspaperid;
		string mtitle;
		int mlikes;
		int mdislikes;

		

	};

