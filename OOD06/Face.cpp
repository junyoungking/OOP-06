#include "header.h"
#include "Face.h"
#include "ADatabase.h"
using namespace std;
#include <iostream>
#include <fstream>
#include <string>



	Face::Face(void)
	{
        

        makeadb();
        makecdb();
        makendb();
		
	}
	Face::~Face(void)
	{
	}

    void Face::Start()
    {
        Face* singleton = new Face();
        singleton->Run();
        delete singleton;
    }

    void Face::makeadb()
    {
        string title;
        string newspapername;
        string keyword;
        int likes=0;
        int dislikes=0;
        string time;
        string incase;
        string content;

        int button = 0;

        string line;
        ifstream file("article1.txt"); // example.txt 파일을 연다. 없으면 생성. 
        if (file.is_open()) {
            while (getline(file, line)) {
                if (line == "&") {
                    adb->addArticle(title, newspapername, keyword, likes, dislikes, time, incase, content);
                    title = ""; newspapername = ""; keyword = ""; likes = 0; dislikes = 0; time = ""; incase = ""; content = "";
                    button = -1;
                }
                else if (button == 0)
                {
                    title = line;
                }
                else if (button == 1)
                {
                    newspapername = line;
                }
                else if (button == 2)
                {
                    keyword = line;
                }
                else if (button == 3)
                {
                    likes = int(stoi(line));
                }
                else if (button == 4)
                {
                    dislikes = int(stoi(line));
                }
                else if (button == 5)
                {
                    time = line;
                }
                else if (button == 6)
                {
                    incase = line;
                }
                else if (button >= 7)
                {
                    content = line;
                }
                button++;
            }
            file.close(); // 열었떤 파일을 닫는다. 
        }
        else {
            cout << "Unable to open file";

        }
    }

    void Face::makendb()
    {
        string title;
        int likes=0;
        int dislikes=0;



        int button = 0;

        string line;
        ifstream file("newspaper1.txt"); // example.txt 파일을 연다. 없으면 생성. 
        if (file.is_open()) {
            while (getline(file, line)) {
                if (line == "&") {
                    ndb->addNewspaper(title, likes, dislikes);
                    title = ""; likes = 0; dislikes = 0;
                    button = -1;
                }
                else if (button == 0)
                {
                    title = line;
                }
                else if (button == 1)
                {
                    likes = int(stoi(line));
                }
                else if (button == 2)
                {
                    dislikes = int(stoi(line));
                }
                button++;
            }
            file.close(); // 열었떤 파일을 닫는다. 
        }
        else {
            cout << "Unable to open file";

        }
    }

    void Face::makecdb()
    {
        string username;
        string time;
        string article;
        string content;

        int button = 0;

        string line;
        ifstream file("comment1.txt"); // example.txt 파일을 연다. 없으면 생성. 
        if (file.is_open()) {
            while (getline(file, line)) {
                if (line == "&") {
                    cdb->addComment(username, time, content, article);
                    username = ""; time = ""; article = ""; content = "";
                    button = -1;
                }
                else if (button == 0)
                {
                    username = line;
                }
                else if (button == 1)
                {
                    time = line;
                }
                else if (button == 2)
                {
                    article = line;
                }
                else if (button >= 3)
                {
                    content = line;
                }
                button++;
            }
            file.close(); // 열었떤 파일을 닫는다. 
        }
        else {
            cout << "Unable to open file";

        }
    }


	

    void Face::Run()
    {
        while (1) {
            int num_x, num_y, num_z, News_num, article_num;
            string acase;
            string id;
            cout << "1번: 언론사 목록보기   " << "2번: 기사 목록보기   " << "3번: 프로그램 종료   " << endl;
            cout << "번호를 선택해주세요: ";
            cin >> num_x;
            if (num_x == 1) {
                cout << "<언론사 목록>" << endl;
                cout << endl;
                ndb->displayALL();
                
                while (1) {
                    cout << "1번: 언론사 자세히보기   " << "2번: 언론사 목록 다시보기   " << "3번: 돌아가기" << endl; 
                    cout << "번호를 선택해주세요: ";
                    cin >> num_y;
                    if (num_y == 1)
                    {
                        cout << "언론사의 식별번호를 입력해주세요: ";
                        cout << endl;
                        cin >> News_num;
                        ndb->displaycurrent(News_num);
                        id= ndb->ID_Title_Changer(News_num);
                        adb->display_Target(id);        //코드 수정을 통해서 뉴스아이디에 맞는 아티클만 나오게 해야됨 
                        while (1) {
                            cout << "1번: 기사 자세히 보기" << "2번: 돌아가기   " << endl;
                            cin >> num_z;
                            if (num_z == 1)
                            {
                                cout << "기사 식별번호를 입력하세요: ";
                                cin >> article_num;
                                adb->displaycurrent(article_num);
                                id=adb->getarticletitle(article_num);
                                ;
                                cdb->displaycurrent(id); //코드 수정을 통해서 아티클 넘버에 맞게 맞춰야됨
                       //       그 이후에 코멘트를 시간순서로 보여줘야 되는데 시간순서대로 보여줄 필요없이 댓글 작성시각만 보여주면 안되나 
                                cout << "이전화면으로 돌아갑니다." << endl;
                                cout << endl;
                            }
                            else if (num_z == 2)
                            {
                                cout << "이전페이지로 돌아갑니다" << endl;
                                cout << endl;
                                break;
                            }
                            else
                            {
                                cout << "error: 입력오류(1번부터 2번까지 숫자만 입력해주세요)" << endl;
                            }
                        }
                    }
                    else if (num_y == 2)
                    {
                        ndb->displayALL();
                        cout << "이전화면으로 돌아갑니다" << endl;
                        cout << endl;
                    }
                    else if (num_y == 3)
                    {
                        cout << "이전페이지로 돌아갑니다." << endl;
                        cout << endl;
                        break;
                    }
                    else
                    {
                        cout << "error: 입력오류(1번부터 3번까지 숫자만 입력해주세요)" << endl;
                    }
                }
            }

        
    
			else if (num_x == 2)
			{
                cout << "<기사 목록>" << endl;
                cout << endl;
				adb->displayALL();
				//
                while(1)
                {
                    cout << "1번: 기사 자세히보기  " << "2번: 핵심 사건 키워드와 반응보기  " << "3번: 기사 목록 다시보기  " << "4번: 돌아가기" << endl;
                    cout << "번호를 선택해주세요: ";
				    cin >> num_y;
                    if (num_y == 1)
                    {
                        cout << "기사 식별번호를 입력하세요: ";
                        cin >> article_num;
                        adb->displaycurrent(article_num);
                        id= adb->getarticletitle(article_num);
                        cdb->displaycurrent(id);
                        cout << "이전화면으로 돌아갑니다." << endl;
                        cout << endl;
                    }
                    else if (num_y == 2)
                    {
                        cout << "분류 키워드를 입력해주세요: " << endl;
                        cin >> acase;
                        adb->display_case(acase); // 해당기사의 식별번호, 제목, 주변키워드 반환, 분류 키워드 기사들의 총 좋아요 싫어요수 보여줌
                        while (1) {
                            cout << "1번: 기사 자세히 보기" << "2번: 돌아가기   " << endl;
                            cin >> num_z;
                            if (num_z == 1)
                            {

                                cout << "기사 식별번호를 입력하세요: ";
                                cin >> article_num;
                                adb->displaycurrent(article_num);
                                id.replace(0, adb->getarticletitle(article_num).length(), adb->getarticletitle(article_num));
                                cdb->displaycurrent(id);
                                cout << "이전화면으로 돌아갑니다." << endl;
                                cout << endl;
                            }
                            else if (num_z == 2)
                            {
                                cout << "이전페이지로 돌아갑니다" << endl;
                                cout << endl;
                                break;
                            }
                            else
                            {
                                cout << "error: 입력오류(1번부터 2번까지 숫자만 입력해주세요)" << endl;
                            }

}                        }
                    else if (num_y==3)
                    {
                        adb->displayALL();
                        cout << "이전화면으로 돌아갑니다." << endl;
                        cout << endl;
                    }
                    else if (num_y == 4)
                    {
                        cout << "이전페이지로 돌아갑니다" << endl;
                        break;
                    }
                    else
                    {
                        cout << "error: 입력오류(1번부터 4번까지 숫자만 입력해주세요)" << endl;
                    }
                }
            }
		
			
				

			else if (num_x == 3)
			{
				cout << "프로그램을 종료하겠습니다" << endl;
				break;
			}

			else
			{
				cout << "error: 입력오류(1번부터 3번까지 숫자만 입력해주세요)" << endl;
                cout << endl;
			}

		}
	}


	


