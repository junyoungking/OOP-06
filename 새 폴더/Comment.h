#pragma once
#include "header.h"
#include "Article.h"
#include<iostream>
using namespace std;



	const int kDefaultstartingcomment = 10000;
	class Comment
	{
	public:
		Comment();

		void display() const;

		void setcomment(string username, string time, string content, string article);
		void setcommentid(int commentid);

		string getarticle() const;
		string getusername() const;
		string getcontent() const;
		string gettime() const;
		int getcommentid() const;
		string getreportuser() const;
		int getreprotcount() const;
		string filtering(string sentence); 


	protected:
		string marticle;
		int mcommentid;
		string musername;
		string mtime;
		string mcontent;
		int mreport_count;
		string mreport_users;
	};



