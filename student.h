#include <stdio.h>		//标准输入输出函数库 
#include <stdlib.h>		//用于动态内存分配
#include <string.h>		//字符串库函数 
#include <conio.h>		//屏幕操作函数库 
#include <Windows.h>


//定义学生所有信息结构StudentInfo
typedef struct Stu {
	int num;			//学号
	char name[20];		//姓名
	char gender[10];	//性别 
	float Amath;		//高数成绩
	float Dmath;		//离散数学成绩
	float Lmath;		//线性代数成绩
} STU; 					//学生结构体类型

//定义学生挂科信息GraduateCheck
typedef struct GraduateCheck {
	int num;			//学号
	char check[20];		//有无挂科情况
} GC; 			


//定义学生成绩信息StudentScore
typedef struct StudentScore {
	int num;			//学号
	char gender[10];		//性别 
	float Amath;		//高数成绩
	float Dmath;		//离散数学成绩
	float Lmath;		//线性代数成绩
} SC; 	




typedef struct LNode {			//定义单链表结点类型
	STU data;					//每个结点存放一个数据元素
	struct LNode *pnext;		//指针指向下一个结点
} LNode;

LNode *pStu = NULL;				//声明一个链表头结点的指针
FILE *fp = NULL;				//定义文件指针
char filename[20];				//文件名

void Welcome();					//主界面显示
void Title();					//打印抬头信息 
void Tips_Openfile();			//文件打开提示操作显示 
void Count_num();				//统计班级成绩函数
int CountStudent();				//统计班级学生人数
void Tongji(); 
void OpenFile();				//打开文件
void CreateList();				//创建链表
void SaveData();				//将数据保存到文件中 

void  SearchMain();				//查找函数
void PrintfAll();				//查看所有学生信息 
void SearchNum();				//按学号查找，注意学号是唯一的
void SearchName(); 				//按姓名查找，注意姓名可能不唯一
LNode* FindNumFun(int num);		//按学号查找的底层函数 
LNode* FindNameFun(char name[]);//按姓名查找的底层函数 
LNode* FindNameFun_Modify(char name[]); 
void  AddInfor();				//添加学生人数函数 
void DeleteMain();				//删除主函数
void DeleteNum(); 				//按学号删除
void DeleteName();				//按姓名删除
void DelOperation(LNode *q);	//删除操作函数 

