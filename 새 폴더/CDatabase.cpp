#include "header.h"
#include "CDatabase.h"

CDatabase::CDatabase() {
	mnextCommentNumber = kFirstCommentNumber;
}


Comment& CDatabase::addComment(string username, string time, string content, string article)
{
	Comment theComment;
	theComment.setcomment(username, time, content, article);
	theComment.setcommentid(mnextCommentNumber++);
	mComment.push_back(theComment);
	return mComment[mComment.size() - 1];
}



void CDatabase::displaycurrent(string inarticle) const
{
	int count = 0;
	for (auto iter = mComment.begin(); iter != mComment.end(); ++iter)
	{
		if (iter->getarticle() == inarticle)
		{
			iter->display();
			count++;
		}
	}
	if (count == 0)
	{
		cout << "기사의 댓글이 없습니다." << endl;
	}
	
}