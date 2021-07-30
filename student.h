#include <stdio.h>		//��׼������������� 
#include <stdlib.h>		//���ڶ�̬�ڴ����
#include <string.h>		//�ַ����⺯�� 
#include <conio.h>		//��Ļ���������� 
#include <Windows.h>


//����ѧ��������Ϣ�ṹStudentInfo
typedef struct Stu {
	int num;			//ѧ��
	char name[20];		//����
	char gender[10];	//�Ա� 
	float Amath;		//�����ɼ�
	float Dmath;		//��ɢ��ѧ�ɼ�
	float Lmath;		//���Դ����ɼ�
} STU; 					//ѧ���ṹ������

//����ѧ���ҿ���ϢGraduateCheck
typedef struct GraduateCheck {
	int num;			//ѧ��
	char check[20];		//���޹ҿ����
} GC; 			


//����ѧ���ɼ���ϢStudentScore
typedef struct StudentScore {
	int num;			//ѧ��
	char gender[10];		//�Ա� 
	float Amath;		//�����ɼ�
	float Dmath;		//��ɢ��ѧ�ɼ�
	float Lmath;		//���Դ����ɼ�
} SC; 	




typedef struct LNode {			//���嵥����������
	STU data;					//ÿ�������һ������Ԫ��
	struct LNode *pnext;		//ָ��ָ����һ�����
} LNode;

LNode *pStu = NULL;				//����һ������ͷ����ָ��
FILE *fp = NULL;				//�����ļ�ָ��
char filename[20];				//�ļ���

void Welcome();					//��������ʾ
void Title();					//��ӡ̧ͷ��Ϣ 
void Tips_Openfile();			//�ļ�����ʾ������ʾ 
void Count_num();				//ͳ�ư༶�ɼ�����
int CountStudent();				//ͳ�ư༶ѧ������
void Tongji(); 
void OpenFile();				//���ļ�
void CreateList();				//��������
void SaveData();				//�����ݱ��浽�ļ��� 

void  SearchMain();				//���Һ���
void PrintfAll();				//�鿴����ѧ����Ϣ 
void SearchNum();				//��ѧ�Ų��ң�ע��ѧ����Ψһ��
void SearchName(); 				//���������ң�ע���������ܲ�Ψһ
LNode* FindNumFun(int num);		//��ѧ�Ų��ҵĵײ㺯�� 
LNode* FindNameFun(char name[]);//���������ҵĵײ㺯�� 
LNode* FindNameFun_Modify(char name[]); 
void  AddInfor();				//���ѧ���������� 
void DeleteMain();				//ɾ��������
void DeleteNum(); 				//��ѧ��ɾ��
void DeleteName();				//������ɾ��
void DelOperation(LNode *q);	//ɾ���������� 

