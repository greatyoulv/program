#include<iostream>
#include<fstream> 
#include<string.h> 
using namespace std;
 
/*学生信息结点*/
class Student
{
	public:
	char name[20];
	int num;
	Student *next;
	
	void input();
	void ReadFile(ifstream &in);
};
 
/*往结点输入信息*/
void Student::input()
{
	cout<<"please enter student's name:";
	cin>>name;
	cout<<"please enter student's num:";
	cin>>num;
	return ; 
}
 
/*从文档中读取值到结点*/
void Student::ReadFile(ifstream &in)
{
	in>>name>>num;
}
 
/*学生信息结点链表*/
class StudentMessage
{
	public:
	StudentMessage();	
	~StudentMessage();
	
	/*关于学生信息这个类所用到的函数*/
	void Show_Menu();
	void Add_Node();
	void Del_node();
	void Display();
	void Find(); 
	void Modify();
	void Load();
	void Save();
	void Clean();
	void Swap_node(Student *q,Student*p);
	void Sort(); 
	
	private: 
	/*StudentMessage类可以看作是以Studet类为结点的链表*/ 
	Student *head;  //链表头 
	Student *end;	//链表尾 
	
	ifstream in;
	ofstream out;
};
 
/*构造函数*/
/*这个构造函数可以在打开程序时，就自动加载原有的学生信息*/ 
StudentMessage::StudentMessage()
{
	/*初始化，头尾结点*/ 
	head = new Student;
	head->next = new Student;
	end = head->next; 
	
	ifstream in("file.txt"); //原有的学生信息是放在文件file.txt中的 
	
	/*Important Part！*/
	/*下面很关键，不这样做的话达不到效果。首先要先向文件读一下，才能判断
	文件是否为空，因为eof()不能用来判断文件是否为空，eof()是根据文件的状态标识
	来判断文件是否为空的，当读取文件时，遇到结尾时，系统会改变文件的状态标识
	，这时候才会返回EOF，才能用eof()判断。不先读一下的话，in.eof()是不会返回
	正值的，即使文件为空*/
	char ch = in.get();
	if(in.eof())
	{
		cout<<"file is empty"<<endl;
	}
	
	/*若文件非空*/	
	while(!in.eof())
	{
		end->ReadFile(in);
		if(end->name[0]=='\0')break;  //这里也是比较关键的，不加这一句的话
									 //程序会把文件最后结束的标记也都出来		
		end->next = new Student;
		end = end->next;
	}
}
 
/*析构函数*/
StudentMessage::~StudentMessage()
{
	Save();    //当正常退出程序的时候，保存数据到file.txt中 
	Student *pos = head->next;
	Student *temp;
	while(pos!=end)
	{
		temp = pos;
		pos = pos->next;
		delete temp;
	}
	delete head,end;
}
 
/*
/*增加结点*/
void StudentMessage::Add_Node()
{
	char quit;
	while(1)
	{
		end->input();
		end->next = new Student;
		end = end->next;
		
		cout<<"continue or not?,Y/N"<<endl;
		cin>>quit;
		switch(quit)
		{
			case'Y':
			case'y':break;
			case'n':
			case'N':return;break;
			default:cout<<"error input,again,please..Y/N";
					cin>>quit;
		}
	}
	cout<<"add node success!"<<endl;
	system("pause");
}
 
 
/*修改结点*/
void StudentMessage::Modify()
{
	char name[20];
	cout<<"enter the name you want to modify:";
	cin>>name;
	
	Student *pos = head->next;
	for(pos;pos!=end;pos=pos->next)
	{
		if(strcmp(name,pos->name)==0)
		{
			pos->input();
			break;
		}	
	}
	cout<<"Modify success!..."<<endl;
	system("pause");
} 
 
/*删除结点*/
void StudentMessage::Del_node()
{
	int del_flag = 0;
	char name[20];
	if(head->next == end)
	{cout<<"Empty...."<<endl;return;}
	
	cout<<"please enter the name you want to delete:";
	cin>>name;
	
	Student *p = head->next;
	Student *q = head; 
	
	for(p;p!=end;p->next)
	{
		if(strcmp(p->name,name)==0) 
		{
			del_flag = 1;
			q->next = p->next;
			delete p;
			break;		
		}
		else
		{
			q=q->next;
			p=p->next;
		}
	}	
	if(del_flag == 0)
	{cout<<"Can not Find the name you want."<<endl;}
	
	cout<<"del node success!"<<endl;
	system("pause");
} 
 
/*查找学生信息*/
void StudentMessage::Find()
{
	char name[20];
	cout<<"please enter name you want to find:";
	cin>>name;
 
	Student *pos = head->next;
	if(pos==end)
	{
		cout<<"Student Message is Empty..."<<endl;
		return ;
	}
	
	for(pos;pos!=end;pos=pos->next)
	{
		if(strcmp(pos->name,name)==0)
		{
			cout<<"Find it!"<<endl;
			cout<<"name:"<<pos->name<<endl;
			cout<<"num:"<<pos->num<<endl;
			return;
		}
	}
	cout<<"Can not Find the name...";
}
 
/*保存学生信息*/
void StudentMessage::Save()
{
	out.open("file.txt");
	Student *pos = head->next;
	if(head->next== end)
	{
		cout<<"StudentMessage List is Empty...."<<endl;
		return ;
	}
	else
	{
		for(pos;pos!=end;pos=pos->next)
		{
			out<<'\t'<<pos->name<<'\t'<<pos->num;//格式最好这样写
										//因为一开始会把文件读一下，以判断
										//文件是否为空，所以前面最后用‘\t’
										//来增加几个空格，给他读一个空格，
										//以不读到正常数据，后面就不要有空格
										//以为当程序从file.txt读信息时，可能
										//会把空格也当是一个数据结点读进程序	
		}
	}
	out.close();
	
	cout<<"Save node success!"<<endl;
}
 
/*显示结点*/
void StudentMessage::Display()
{
	if(head->next==end)
	{cout<<"Empty..."<<endl;}
	
	Student *pos;
	pos = head->next;
	for(pos;pos!=end;pos=pos->next)
	{
		cout<<endl;
		cout<<pos->name<<endl;
		cout<<pos->num<<endl;
		cout<<endl;
	}
	system("pause");
}
 
/*结点交换*/
void StudentMessage::Swap_node(Student *q,Student *p)
{
	char Tname[20];
	int Tnum;
	
	strcpy(Tname,p->name);
	Tnum = p->num;
	
	strcpy(p->name,q->name);
	p->num = q->num;
	
	strcpy(q->name,Tname);
	q->num = Tnum;	
}
 
/*以num位准排序*/
void StudentMessage::Sort()
{
	Student *p,*q;
	p=head->next;
	
	/*冒泡排序*/
	for(p;p!=end;p=p->next)
	{
		for(q=p->next;q!=end;q=q->next)
		{
			if(q->num > p->num)
			{
				Swap_node(q,p);		
			}	
		}
	} 
	cout<<"sort success!"<<endl;
	system("pause");
}
 
/*清空文档*/
void StudentMessage::Clean()
{
	ofstream out("file.txt",ios::trunc);
	out.close();
	exit(0);//用exit使程序退出程序的时候，不调用StudentMessage类的析构函数，
			//否则又会把内存的数据写到file.txt文件中 
}
 
/*显示菜单*/
void StudentMessage::Show_Menu()
{
	cout<<"0.退出程序"<<endl;
	cout<<"1.增加结点"<<endl;
	cout<<"2.删除结点"<<endl;
	cout<<"3.显示所有学生信息"<<endl; 
	cout<<"4.修改学生信息"<<endl; 
	cout<<"5.查找学生信息"<<endl;
	cout<<"6.清空文档"<<endl;
	cout<<"7.排序"<<endl; 
} 
 
int main()
{
	StudentMessage sm;    //创建类对象，并调用其构造函数
					     //把file.txt中的学生信息数据读到内存中		
	int choice;
	
	while(1)
	{
		sm.Show_Menu();
		cout<<"please enter your choice:";
		cin>>choice;
		switch(choice)
		{
			case 0:return 0;break;
			case 1:sm.Add_Node();break;
			case 2:sm.Del_node();break;
			case 3:sm.Display();break;		
			case 4:sm.Modify();break;
			case 5:sm.Find();break;
			case 6:sm.Clean();break;
			case 7:sm.Sort();break;
		}		
		system("cls");	
	}
	return 0;
}
