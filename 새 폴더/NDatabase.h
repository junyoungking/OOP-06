#pragma once
#include "header.h"
#include "Newspaper.h"
#include <iostream>
#include <stdexcept>
using namespace std;
#include<vector>


	const int kFirstNewspaperNumber = 1000;


	class NDatabase
	{
	public:
		NDatabase();
		~NDatabase();


		Newspaper& addNewspaper(string title, int likes, int dislikes);


		Newspaper& getNewspaper(int inArticleid);


		void displayALL() const;


		void displaycurrent(int inNewspaperid) const;
		string ID_Title_Changer(int newspaperid) const;


	protected:
		vector<Newspaper> mNewspaper;
		int mnextNewspaperNumber;
	};
