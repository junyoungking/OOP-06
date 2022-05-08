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
        ifstream file("article1.txt"); // example.txt ������ ����. ������ ����. 
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
            file.close(); // ������ ������ �ݴ´�. 
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
        ifstream file("newspaper1.txt"); // example.txt ������ ����. ������ ����. 
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
            file.close(); // ������ ������ �ݴ´�. 
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
        ifstream file("comment1.txt"); // example.txt ������ ����. ������ ����. 
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
            file.close(); // ������ ������ �ݴ´�. 
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
            cout << "1��: ��л� ��Ϻ���   " << "2��: ��� ��Ϻ���   " << "3��: ���α׷� ����   " << endl;
            cout << "��ȣ�� �������ּ���: ";
            cin >> num_x;
            if (num_x == 1) {
                cout << "<��л� ���>" << endl;
                cout << endl;
                ndb->displayALL();
                
                while (1) {
                    cout << "1��: ��л� �ڼ�������   " << "2��: ��л� ��� �ٽú���   " << "3��: ���ư���" << endl; 
                    cout << "��ȣ�� �������ּ���: ";
                    cin >> num_y;
                    if (num_y == 1)
                    {
                        cout << "��л��� �ĺ���ȣ�� �Է����ּ���: ";
                        cout << endl;
                        cin >> News_num;
                        ndb->displaycurrent(News_num);
                        id= ndb->ID_Title_Changer(News_num);
                        adb->display_Target(id);        //�ڵ� ������ ���ؼ� �������̵� �´� ��ƼŬ�� ������ �ؾߵ� 
                        while (1) {
                            cout << "1��: ��� �ڼ��� ����" << "2��: ���ư���   " << endl;
                            cin >> num_z;
                            if (num_z == 1)
                            {
                                cout << "��� �ĺ���ȣ�� �Է��ϼ���: ";
                                cin >> article_num;
                                adb->displaycurrent(article_num);
                                id=adb->getarticletitle(article_num);
                                ;
                                cdb->displaycurrent(id); //�ڵ� ������ ���ؼ� ��ƼŬ �ѹ��� �°� ����ߵ�
                       //       �� ���Ŀ� �ڸ�Ʈ�� �ð������� ������� �Ǵµ� �ð�������� ������ �ʿ���� ��� �ۼ��ð��� �����ָ� �ȵǳ� 
                                cout << "����ȭ������ ���ư��ϴ�." << endl;
                                cout << endl;
                            }
                            else if (num_z == 2)
                            {
                                cout << "������������ ���ư��ϴ�" << endl;
                                cout << endl;
                                break;
                            }
                            else
                            {
                                cout << "error: �Է¿���(1������ 2������ ���ڸ� �Է����ּ���)" << endl;
                            }
                        }
                    }
                    else if (num_y == 2)
                    {
                        ndb->displayALL();
                        cout << "����ȭ������ ���ư��ϴ�" << endl;
                        cout << endl;
                    }
                    else if (num_y == 3)
                    {
                        cout << "������������ ���ư��ϴ�." << endl;
                        cout << endl;
                        break;
                    }
                    else
                    {
                        cout << "error: �Է¿���(1������ 3������ ���ڸ� �Է����ּ���)" << endl;
                    }
                }
            }

        
    
			else if (num_x == 2)
			{
                cout << "<��� ���>" << endl;
                cout << endl;
				adb->displayALL();
				//
                while(1)
                {
                    cout << "1��: ��� �ڼ�������  " << "2��: �ٽ� ��� Ű����� ��������  " << "3��: ��� ��� �ٽú���  " << "4��: ���ư���" << endl;
                    cout << "��ȣ�� �������ּ���: ";
				    cin >> num_y;
                    if (num_y == 1)
                    {
                        cout << "��� �ĺ���ȣ�� �Է��ϼ���: ";
                        cin >> article_num;
                        adb->displaycurrent(article_num);
                        id= adb->getarticletitle(article_num);
                        cdb->displaycurrent(id);
                        cout << "����ȭ������ ���ư��ϴ�." << endl;
                        cout << endl;
                    }
                    else if (num_y == 2)
                    {
                        cout << "�з� Ű���带 �Է����ּ���: " << endl;
                        cin >> acase;
                        adb->display_case(acase); // �ش����� �ĺ���ȣ, ����, �ֺ�Ű���� ��ȯ, �з� Ű���� ������ �� ���ƿ� �Ⱦ��� ������
                        while (1) {
                            cout << "1��: ��� �ڼ��� ����" << "2��: ���ư���   " << endl;
                            cin >> num_z;
                            if (num_z == 1)
                            {

                                cout << "��� �ĺ���ȣ�� �Է��ϼ���: ";
                                cin >> article_num;
                                adb->displaycurrent(article_num);
                                id.replace(0, adb->getarticletitle(article_num).length(), adb->getarticletitle(article_num));
                                cdb->displaycurrent(id);
                                cout << "����ȭ������ ���ư��ϴ�." << endl;
                                cout << endl;
                            }
                            else if (num_z == 2)
                            {
                                cout << "������������ ���ư��ϴ�" << endl;
                                cout << endl;
                                break;
                            }
                            else
                            {
                                cout << "error: �Է¿���(1������ 2������ ���ڸ� �Է����ּ���)" << endl;
                            }

}                        }
                    else if (num_y==3)
                    {
                        adb->displayALL();
                        cout << "����ȭ������ ���ư��ϴ�." << endl;
                        cout << endl;
                    }
                    else if (num_y == 4)
                    {
                        cout << "������������ ���ư��ϴ�" << endl;
                        break;
                    }
                    else
                    {
                        cout << "error: �Է¿���(1������ 4������ ���ڸ� �Է����ּ���)" << endl;
                    }
                }
            }
		
			
				

			else if (num_x == 3)
			{
				cout << "���α׷��� �����ϰڽ��ϴ�" << endl;
				break;
			}

			else
			{
				cout << "error: �Է¿���(1������ 3������ ���ڸ� �Է����ּ���)" << endl;
                cout << endl;
			}

		}
	}


	


