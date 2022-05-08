#pragma once
#include "header.h"
#include <iostream>
#include "Comment.h"
#include <vector>
using namespace std;
class CDatabase
{
public:
	CDatabase();
	Comment& addComment(string username, string time, string content, string article);

	
	void displaycurrent(string aritcle) const;
protected:
	const int kFirstCommentNumber = 0000;
	vector<Comment> mComment;
	int mnextCommentNumber;
};

