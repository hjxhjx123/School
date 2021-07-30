#include "student.h"
//视图界面和打开文件提示
void Tips_Openfile() {
	printf("\n\t\t\tversion2.0 design in 2021.7 ");
	printf("\n\n\t\t\t***********************************\n");
	printf("\n\n\t\t\t***********************************\n");
	printf("\t\t\t*  欢迎使用学生成绩管理系统2.0！  *\n");
	printf("\t\t\t*\t\t\t\t  *\n");
	printf("\t\t\t*---------------------------------*\n");
	printf("\t\t\t* 使用说明:\t\t\t  *");
	printf("\n\t\t\t*\t\t\t\t  *");
	printf("\n\t\t\t*\t\t\t\t  *");
	printf("\n\t\t\t*\t  打开示例:计科1班.txt\t  *\n");
	printf("\t\t\t***********************************\n");
}
//创建链表
void CreateList() {
	pStu = (LNode *)malloc(sizeof(LNode));	//创建头结点
	pStu->pnext = NULL;
}

void Title() {
	printf("\n\t\t\t学号\t\t姓名\t性别\t线性代数\t离散数学\t高等数学");
}

//打开文件模块
void OpenFile() {
	char ch;
	//创建两个结构体指针
	LNode *pnew = NULL;
	LNode *ptemp = NULL;
	CreateList();			//先创建链表
	ptemp = pStu;			//临时指针，用于作为连接节点的中间结点

	Tips_Openfile();
	while(1) {

		printf("\t\t\t请输入文件名：");
		scanf("%s",&filename);
		if((fp = fopen(filename,"r")) == NULL) {		//只读的方式打开一个不存在的文件
			printf("\n\t\t\t没有该班级的数据，是否需要创建？(Y/N)");
			printf("\n\t\t\t是--Y\n");
			printf("\t\t\t否--N\n");
			printf("\t\t\t请选择：    ");
			fflush(stdin);								//清除缓冲区的数据

			scanf("%c",&ch);
			if (ch == 'y'|| ch == 'Y') {				//选择创建新的文件
				if((fp=fopen(filename,"a+")) == NULL) {	//重新创建文件失败
					printf("\t\t\t创建失败！");
					exit(0);
				} else {								//创建成功
					break;
				}
			} else {									//不创建新文件
				printf("\t\t\t请打开其他文件\n");
				continue;								//继续选择打开其他文件
			}
		} else {										//文件存在并打开成功
			break;
		}
	}

	while(1) {
		pnew=(LNode *)malloc(sizeof(LNode));
		if(fscanf(fp,"%d\t%s\t%s\t%f\t%f\t%f\n",&pnew->data.num, pnew->data.name, pnew->data.gender, &pnew->data.Lmath, &pnew->data.Dmath, &pnew->data.Amath) == EOF) {
			free(pnew);		//如果没有数据可读了，需要将已经新创建的结点释放
			break;
		}
		//尾插法插入结点
		pnew->pnext = NULL;  //让链表的尾结点指向空
		ptemp->pnext = pnew;
		ptemp = ptemp->pnext;
	}
	fclose(fp);
}

//主菜单显示
void Welcome() {
	printf("\n\t\t\tversion2.0 design in 2021.7 ");
	printf("\n\n\t\t\t***********************************\n");
	printf("\n\n\t\t\t***********************************\n");
	printf("\t\t\t*  欢迎使用学生成绩管理系统2.0！  *\n");	
	printf("\n\n\t\t\t***********************************\n");
	printf("\t\t\t*********学生成绩管理菜单**********\n");
	printf("\t\t\t*\t\t\t\t  *\n");
	printf("\t\t\t*-----------1.查找功能------------*\n");
	printf("\t\t\t*-----------2.添加功能------------*\n");
	printf("\t\t\t*-----------3.删除功能------------*\n");
	printf("\t\t\t*-----------4.修改功能------------*\n");
	printf("\t\t\t*-----------5.统计功能------------*\n");
	printf("\t\t\t*-----------6.退出系统------------*\n");
	printf("\t\t\t*\t\t\t\t  *\n");
	printf("\t\t\t***********************************\n");
}

void Count_num() {
	LNode *pA,*pD,*pL;				//用于指向分数最高的结点
	LNode *ptemp = pStu->pnext;
	int countA=0,countD=0,countL=0;//保存三门成绩中不及格的人
	int sum=0;
	sum = CountStudent();
	if(!ptemp) {
		
		printf("\t\t\t没有学生记录！请按任意键继续...\n");
		getch();
		return;
	}
	
	pA=pD=pL=ptemp;
	while(ptemp) {
		if(ptemp->data.Amath<60)		countA++;
		if(ptemp->data.Dmath<60)		countD++;
		if(ptemp->data.Lmath<60)		countL++;

		if(ptemp->data.Amath >= pA->data.Amath)		pA=ptemp;
		if(ptemp->data.Dmath >= pD->data.Dmath)		pD=ptemp;
		if(ptemp->data.Lmath >= pL->data.Lmath)		pL=ptemp;
		ptemp=ptemp->pnext;
	}
	printf("\t\t\t统计结果\n");
	printf("\t\t\t高数不及格人数:%d（人）\n",countA);
	printf("\t\t\t离散不及格人数:%d（人）\n",countD);
	printf("\t\t\t线代不及格人数:%d（人）\n",countL);

	printf("\t\t\t该班级总人数为:%d（人）\n",sum);
	printf("\t\t\t高数最高分的学生：%s ：%.2f分\n",pA->data.name,pA->data.Amath);
	printf("\t\t\t离散最高分的学生：%s ：%.2f分\n",pD->data.name,pD->data.Dmath);
	printf("\t\t\t线代最高分的学生：%s ：%.2f分\n",pL->data.name,pL->data.Lmath);
	printf("\t\t\t请按任意键继续...");
	getch();
	return;
}


//统计学生总人数
int CountStudent() {
	int n=0;
	//遍历链表,统计学生人数
	LNode *p = pStu->pnext;
	while(p != NULL) {
		n++;
		p = p->pnext;
	}
	return n;
}

//添加学生信息
void  AddInfor() {
	LNode* ptemp ;
	int num;
	LNode* pnew = NULL;
	printf("\n\t\t\tversion2.0 design in 2021.7 ");
	printf("\n\n\t\t\t***********************************\n");
	printf("\n\n\t\t\t***********************************\n");
	printf("\t\t\t*  欢迎使用学生成绩管理系统2.0！  *\n");	
	printf("\n\n");
	printf("\t\t\t****正在添加学生信息****\n");
	printf("\t\t\t请问您要添加几个学生的信息：  ");
	scanf("%d",&num);

	for(int i=0; i<num; i++) {
		pnew = (LNode*)malloc(sizeof(LNode));
		printf("\t\t\t---正在添加第%d个学生信息---\n",i+1);
		printf("\t\t\t请输入学号： ");
		scanf("%d",&pnew->data.num);

		ptemp = pStu->pnext;
		while(ptemp != NULL) {
			if(pnew->data.num == ptemp->data.num) {
				printf("\t\t\t学号重复，请重新输入： ");
				scanf("%d",&pnew->data.num);
				ptemp = pStu->pnext;		//ptemp用来检查输入的学号是否会重复
				continue;
			} else {
				ptemp = ptemp->pnext;
			}
		}
		//学号不重复就依次输入学生信息
		printf("\t\t\t请输入姓名： ");
		scanf("%s",pnew->data.name);
		printf("\t\t\t请输入性别： ");
		scanf("%s",pnew->data.gender);
		printf("\t\t\t请输入线性代数成绩: ");
		scanf("%f",&pnew->data.Lmath);
		printf("\t\t\t请输入离散数学成绩： ");
		scanf("\t%f",&pnew->data.Dmath);
		printf("\t\t\t请输入高等数学成绩： ");
		scanf("\t%f",&pnew->data.Amath);

		if(pStu->pnext == NULL) {		// 链表中没有数据
			pnew->pnext = NULL;
			pStu->pnext = pnew;
		} else {						//链表中有数据
			ptemp = pStu; 				//ptemp从头结点开始遍历
			while(ptemp != NULL) {
				if(ptemp->pnext != NULL) {
					if(pnew->data.num > ptemp->data.num && pnew->data.num < ptemp->pnext->data.num) { //pnew的学号比前一个大 比后一个小
						pnew->pnext = ptemp->pnext;
						ptemp->pnext = pnew;
						break;			//插入成功后退出循环
					}
				} else {				//ptemp->pnext == NULL,此时ptemp在尾部
					pnew->pnext = NULL;
					ptemp->pnext = pnew;
					break;
				}
				ptemp = ptemp->pnext;
			}
		}
	}
	printf("\t\t\t添加成功！");
	printf("\n\t\t\t文件数据已更新！");
	printf("\t\t\t请按任意键继续...");
}

//保存数据到文件
void SaveData() {
	LNode *ptemp = pStu->pnext;
	if((fp=fopen(filename,"w")) == NULL) {
		printf("\t\t\t文件打开失败！");
	} else {
		while(ptemp != NULL) {
			fprintf(fp,"%d\t%s\t%s\t%f\t%f\t%f\n",ptemp->data.num, ptemp->data.name, ptemp->data.gender, ptemp->data.Lmath, ptemp->data.Dmath, ptemp->data.Amath);
			ptemp = ptemp->pnext;
		}
	}
	fclose(fp);
}

void SaveData_1() {
	LNode *ptemp = pStu->pnext;
	if((fp=fopen("StudentInfo.txt","w")) == NULL) {
		printf("\t\t\t文件打开失败！");
	} else {
		while(ptemp != NULL) {
			fprintf(fp,"%d\t%s\t%s\n",ptemp->data.num, ptemp->data.name, ptemp->data.gender);
			ptemp = ptemp->pnext;
		}
	}
	fclose(fp);
}


void SaveData_2() {
	LNode *ptemp = pStu->pnext;
	if((fp=fopen("StudentScore.txt","w")) == NULL) {
		printf("\t\t\t文件打开失败！");
	} else {
		while(ptemp != NULL) {
			fprintf(fp,"%d\t%f\t%f\t%f\n",ptemp->data.num,  ptemp->data.Lmath, ptemp->data.Dmath, ptemp->data.Amath);
			ptemp = ptemp->pnext;		}
	}
	fclose(fp);
}

int Count_check() {
	LNode *ptemp = pStu->pnext;
	int countA=0,countD=0,countL=0;//保存三门成绩中不及格的人
	int s;
	return s= countA+countD+countL;
	while(ptemp) {
		if(ptemp->data.Amath<60)		countA++;
		if(ptemp->data.Dmath<60)		countD++;
		if(ptemp->data.Lmath<60)		countL++;
	}
	return s;
}




void SaveData_3() {
int  total = 3*CountStudent();
int check = Count_check();
	if((fp=fopen("StudentScore.txt","w")) == NULL) {
		printf("\t\t\t文件打开失败！");
	    if((fp=fopen("GraduateCheck.txt","w")) == NULL) {
		printf("\t\t\t文件打开失败！");
	} else {
		    
			fprintf(fp,"%f\t%f\n",total,check);
		}
	}
	fclose(fp);
}





//删除主函数
void DeleteMain() { //先查找，再删除
	int choice;
	do {
    	printf("\n\t\t\tversion2.0 design in 2021.7 ");
	    printf("\n\n\t\t\t***********************************\n");
    	printf("\n\n\t\t\t***********************************\n");
    	printf("\t\t\t*  欢迎使用学生成绩管理系统2.0！  *\n");		
		printf("\n\n");
		printf("\t\t\t正在使用删除功能：\n");
		printf("\t\t\t1、按学号删除\n");
		printf("\t\t\t2、按姓名删除\n");
		printf("\t\t\t3、返回主界面\n");
		printf("\t\t\t请选择：");
		scanf("%d",&choice);

		switch(choice) {
			case 1:
				DeleteNum();
				break;
			case 2:
				DeleteName();
				break;
		}
	} while(choice != 3);
}

//按学号删除的功能函数
void DeleteNum() {
	int num;

	printf("\t\t\t正在删除学生信息\n");
	printf("\t\t\t请输入你要的删除的学生学号:");
	scanf("%d",&num);

	LNode *q;
	q = FindNumFun(num);
	DelOperation(q);
}

//按姓名删除的功能函数
void DeleteName() {
	char name[20];
	printf("\t\t\t正在删除学生成绩信息\n");
	printf("\t\t\t请输入你要删除学生的姓名:");
	scanf("%s",name);
	LNode *q;
	q = FindNameFun(name);
	DelOperation(q);
}

//删除操作基础函数
//通过前驱结点删除学生成绩信息
void DelOperation(LNode *q) {
	LNode *ptemp;
	if(q) {
		printf("\t\t\t已删除的学生成绩信息如下：\n");
		Title();
		printf("\n\t\t\t%d\t%s\t%s\t%.2f\t\t%.2f\t\t%.2f\n", q->data.num, q->data.name, q->data.gender, q->data.Lmath, q->data.Dmath, q->data.Amath);
		ptemp = pStu;
		while(ptemp->pnext != q) {
			ptemp = ptemp->pnext;
		}
		ptemp->pnext = q->pnext;
		free(q);
		printf("\n\t\t\t删除操作成功！\n");
	}
	SaveData();
	printf("\n\t\t\t文件数据已更新！");
	printf("\t\t\t请按任意键继续...");
	getch();
	return;
}

//修改函数
void Modify() { //先查找到，再对结点中的数据进行赋值
	char ch,name[20];
	int num;
	int n,choice;
	LNode* change;
	printf("\t\t\t*********正在更改学生信息**********\n");
	printf("\n\t\t\t1.按学号查找更改学生成绩信息");
	printf("\n\t\t\t2.按姓名查找更改学生成绩信息");
	printf("\n\t\t\t请选择：  ");
	while(1) {
		scanf("%d", &choice);
		if( choice == 1) {
			printf("\n\t\t\t*请输入您要更改的学生学号： ");
			scanf("%ld", &num);
			change = FindNumFun(num);
			break;
		} else if( choice == 2) {
			printf("\n\t\t\t*请输入您要更改的学生姓名： ");
			scanf("%s",name);
			change = FindNameFun_Modify(name);
			break;
		} else {
			printf("\n\t\t\t输入错误！");
			continue;
		}
	}
	if(change == NULL) {

		printf("\n\t\t\t学生信息不存在,无法更改！！！\n");
		printf("\n\t\t\t请按任意键继续...");
		getch();
		return;
	}
	Title();
	printf("\n\t\t\t%d\t%s\t%s\t%.2f\t\t%.2f\t\t%.2f\n", change->data.num, change->data.name, change->data.gender, change->data.Lmath, change->data.Dmath, change->data.Amath);
	printf("\t\t\t请问是否确定修改该学生成绩信息？（Y/N）");
	fflush(stdin);
	scanf("%c",&ch);
	if (ch == 'y'|| ch == 'Y') {
		printf("\n\t\t\t请问需要修改的信息是：");
		printf("\n\t\t\t1.学号 2.姓名  3.性别  4.线性代数  5.离散数学  6.高等数学  ");
		printf("\n\t\t\t请选择： ");
		while(1) {
			scanf("%d",&n);
			switch(n) {
					system("pause");
				case 1:
					printf("\t\t\t请输入新的学号：");
					scanf("%d",change->data.num);
					break;
				case 2:
					printf("\t\t\t请输入姓名： ");
					scanf("%s",change->data.name);
					break;
				case 3:
					printf("\t\t\t请输入性别： ");
					scanf("%s",change->data.gender);
					break;
				case 4:
					printf("\t\t\t请输入线性代数成绩: ");
					scanf("%f",&change->data.Lmath);
					break;
				case 5:
					printf("\t\t\t请输入离散数学成绩： ");
					scanf("%f",&change->data.Dmath);
					break;
				case 6:
					printf("\t\t\t请输入高等数学成绩： ");
					scanf("%f",&change->data.Amath);
					break;
				default:
					printf("\t\t\t选择错误！请重新输入：  ");
					continue;
			}
			break;
		}
		printf("\n\t\t\t学生信息已经更改完毕！！！\n");
		SaveData();
		printf("\n\t\t\t文件数据已更新！");
		printf("\n\t\t\t请按任意键继续...");
		getch();
		return;
	}
}

//全部查看函数
void PrintfAll() {
	
	printf("\n\n");
	printf("\t\t\t---以下是全部学生的成绩---\n");
	LNode * ptemp1 = pStu->pnext ;

	if( ptemp1 == NULL) {	//该文件中没有数据
		printf("\t\t\t没有数据！请按任意键继续...");
		getch();
		return;
	}
	Title();
	printf("\n");
	while(ptemp1 != NULL) {
		printf("\t\t\t%d\t%s\t%s\t%.2f\t\t%.2f\t\t%.2f\n", ptemp1->data.num, ptemp1->data.name, ptemp1->data.gender, ptemp1->data.Lmath, ptemp1->data.Dmath, ptemp1->data.Amath);
		ptemp1 = ptemp1->pnext;
	}
	printf("\t\t\t按任意键继续...");
	getch();
	return;
}

//按学号查找的底层函数
LNode* FindNumFun(int num) {
	LNode * pre = pStu;
	LNode* q ;
	while (1) {
		if (pre->pnext && (pre->pnext->data.num == num)) {
			q = pre->pnext;	//已经按学号找到
			return q;
			break;
		} else {
			if (pre->pnext != NULL) {
				pre = pre->pnext;
			} else {
				printf("\n\t\t\t没有查询到该学生信息！\n");
				return 0;	/*如果没有找到就返回一个空指针*/
				break;
			}
		}
	}
}

//用于修改功能的--按姓名查找的底层函数
LNode* FindNameFun_Modify(char name[]) {
	LNode *ptemp = pStu;
	ptemp = ptemp -> pnext;//  即ptemp指向头结点，此时应让ptemp=ptemp->pnext
	LNode *q;

	while(ptemp != NULL) {
		if(!strcmp(ptemp->data.name,name)) {	//找到了 姓名不唯一
			q = ptemp;
			return q;
			break;
		}
	}
	printf("\n\t\t\t查无此人!\n");
	return 0;
}

//按姓名查找的底层函数
LNode* FindNameFun(char name[]) {
	LNode *ptemp = pStu;
	ptemp = ptemp -> pnext;//  即ptemp指向头结点，此时应让ptemp=ptemp->pnext
	LNode *q;
	int n=0;

	while(ptemp != NULL) {
		if(!strcmp(ptemp->data.name,name)) {	//找到了 姓名不唯一
			n++;
			if(n==1)
			{
				Title();
			}
			printf("\n\t\t\t%d\t%s\t%s\t%.2f\t\t%.2f\t\t%.2f\n", ptemp->data.num, ptemp->data.name, ptemp->data.gender, ptemp->data.Lmath, ptemp->data.Dmath, ptemp->data.Amath);
		}
		ptemp = ptemp -> pnext;//继续查找，因为可能有重名的情况
	}
	//找完了
	if(n == 0) {
		printf("\n\t\t\t查无此人!\n");
		return 0;
	}
}

//按学号查找的功能函数
void SearchNum() { //此时ptemp=pStu，没有数据
	int num;
	
	printf("\n\n\t\t\t***********************************\n");
	printf("\t\t\t*****正在按学号查询学生信息********\n");
	printf("\t\t\t*请输入你要查找的学号:  ");
	scanf("%d",&num);
	LNode *ptemp;

	ptemp = FindNumFun(num);
	if(ptemp) {
		Title();
		printf("\n\t\t\t%d\t%s\t%s\t%.2f\t\t%.2f\t\t%.2f\n", ptemp->data.num, ptemp->data.name, ptemp->data.gender, ptemp->data.Lmath, ptemp->data.Dmath, ptemp->data.Amath);
	}
	printf("\t\t\t请按任意键继续...");
	getch();
	return;
}

//按姓名查找的功能函数
void SearchName() {
	char name[20];
	
	printf("\n\n\t\t\t***********************************\n");
	printf("\t\t\t********正在按姓名查找学生信息*********\n");
	printf("\t\t\t*请输入你要查找的姓名:  ");
	scanf("%s",name);
	LNode *ptemp;
	ptemp = FindNameFun(name);

	if(ptemp) {
		Title();
		printf("\n\t\t\t%d\t%s\t%s\t%.2f\t\t%.2f\t\t%.2f\n", ptemp->data.num, ptemp->data.name, ptemp->data.gender, ptemp->data.Lmath, ptemp->data.Dmath, ptemp->data.Amath);
	}
	printf("\t\t\t请按任意键继续...");
	getch();
	return;
}

//查找主函数
void SearchMain() {
	int choice;
	do {
    	printf("\n\t\t\tversion2.0 design in 2021.7 ");
     	printf("\n\n\t\t\t***********************************\n");
    	printf("\n\n\t\t\t***********************************\n");
    	printf("\t\t\t*  欢迎使用学生成绩管理系统2.0！  *\n");	
    	printf("\n\n\t\t\t***********************************\n");		
		printf("\n\n\t\t\t***********************************\n");
		printf("\t\t\t*********正在查找学生信息**********\n");
		printf("\t\t\t*\t\t\t\t  *\n");
		printf("\t\t\t*----------1.按学号查找-----------*\n");
		printf("\t\t\t*----------2.按姓名查找-----------*\n");
		printf("\t\t\t*----------3.查看全部学生信息-----*\n");
		printf("\t\t\t*----------4.返回主界面-----------*\n");
		printf("\t\t\t*\t\t\t\t  *\n");
		printf("\t\t\t***********************************\n");
		printf("\t\t\t请选择：");
		fflush(stdin);
		scanf("%d",&choice);
		if(choice !=1 && choice !=2 && choice !=3 && choice != 4) {
			continue;
		}
		if (!choice) {
			printf("\t\t\t输入字符错误！请重新输入！");
			break;
		}
		switch(choice) {
			case 1:
				SearchNum();
				break;
			case 2:
				SearchName();
				break;
			case 3:
				PrintfAll();
				break;
			case 4:
				break;
		}
		if( choice == 4) {
			break;
		}
	} while(1);
}

char Get_choice() {
	char choice;
	while(1) {
		fflush(stdin);
		printf("\t\t\t请选择： ");
		scanf("%c",&choice);
		if(choice == '1' || choice =='2' || choice =='3' || choice == '4' || choice == '5' || choice == '6') {
			break;
		}
	}
	return choice;
}

//程序主函数
int main() {
    system("color F0");
	char choice;
	OpenFile();
	do {
		Welcome();
		fflush(stdin);
		choice = Get_choice();
		switch(choice) {
			case '1':
				//查找
				SearchMain();
				break;
			case '2':
				//添加
				AddInfor();
				break;
			case '3':
				//删除
				DeleteMain();
				break;
			case '4':
				//修改
				Modify();
				break;
			case '5':
				//统计
				Count_num();
				break;
			case '6':
				//退出
				SaveData_1();
				SaveData_2();
				SaveData_3();
				SaveData();//退出时，保存文件
				break;
		}
		if( choice == '6') {
			printf("\n\t\t\t感谢使用本次系统！再见！");
			break;
		}
	} while(1);

	return 0;
}
