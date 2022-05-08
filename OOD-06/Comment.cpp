#include "header.h"
#include "Comment.h"
#include <iostream>

using namespace std;


	Comment::Comment()
		:mcommentid(-1), musername(""), mtime(""), mcontent(""), mreport_count(0), mreport_users(""), marticle("") {}

	void Comment::display() const
	{
		cout << "------------------------" << endl;
		cout << "작성자: " << musername << '(' << "작성된 시각: " << mtime << ')' << endl;
		cout << "" << endl;
		cout << mcontent << endl;
		cout << "신고된 횟수: " << mreport_count << endl;
		cout << "------------------------" << endl;
	}

	void Comment::setcomment(string username, string time, string content, string article)
	{
		musername = username;
		mtime = time;
		mcontent = filtering(content);
		marticle = article;
	}
	void Comment::setcommentid(int commentid)
	{
		mcommentid = commentid;
	}
	
	int count(string word)
	{
		int cnt = 0;
		for (char i : word)
		{
			cnt++;
		}

		return cnt;
	}

	string Comment::filtering(string sentence)
	{
		string bad_word[] = { "씨발", "개새끼", "야발" };

		int bad_word_size = sizeof(bad_word) / sizeof(string);

		for (int i = 0; i < bad_word_size; ++i)
		{
			if (sentence.find(bad_word[i]) == 0)
			{
				sentence = sentence.replace(sentence.find(bad_word[i]), count(bad_word[i]), "*");
			}
		}

		return sentence;
	}

	string Comment::getarticle() const { return marticle;  }
	string Comment::getusername() const { return musername; }
	string Comment::getcontent() const { return mcontent; }
	string Comment::gettime() const { return mtime; }
	int Comment::getcommentid() const { return mcommentid; }
	string Comment::getreportuser() const { return mreport_users; }
	int Comment::getreprotcount() const { return mreport_count; }



