#include "student.h"
//��ͼ����ʹ��ļ���ʾ
void Tips_Openfile() {
	printf("\n\t\t\tversion2.0 design in 2021.7 ");
	printf("\n\n\t\t\t***********************************\n");
	printf("\n\n\t\t\t***********************************\n");
	printf("\t\t\t*  ��ӭʹ��ѧ���ɼ�����ϵͳ2.0��  *\n");
	printf("\t\t\t*\t\t\t\t  *\n");
	printf("\t\t\t*---------------------------------*\n");
	printf("\t\t\t* ʹ��˵��:\t\t\t  *");
	printf("\n\t\t\t*\t\t\t\t  *");
	printf("\n\t\t\t*\t\t\t\t  *");
	printf("\n\t\t\t*\t  ��ʾ��:�ƿ�1��.txt\t  *\n");
	printf("\t\t\t***********************************\n");
}
//��������
void CreateList() {
	pStu = (LNode *)malloc(sizeof(LNode));	//����ͷ���
	pStu->pnext = NULL;
}

void Title() {
	printf("\n\t\t\tѧ��\t\t����\t�Ա�\t���Դ���\t��ɢ��ѧ\t�ߵ���ѧ");
}

//���ļ�ģ��
void OpenFile() {
	char ch;
	//���������ṹ��ָ��
	LNode *pnew = NULL;
	LNode *ptemp = NULL;
	CreateList();			//�ȴ�������
	ptemp = pStu;			//��ʱָ�룬������Ϊ���ӽڵ���м���

	Tips_Openfile();
	while(1) {

		printf("\t\t\t�������ļ�����");
		scanf("%s",&filename);
		if((fp = fopen(filename,"r")) == NULL) {		//ֻ���ķ�ʽ��һ�������ڵ��ļ�
			printf("\n\t\t\tû�иð༶�����ݣ��Ƿ���Ҫ������(Y/N)");
			printf("\n\t\t\t��--Y\n");
			printf("\t\t\t��--N\n");
			printf("\t\t\t��ѡ��    ");
			fflush(stdin);								//���������������

			scanf("%c",&ch);
			if (ch == 'y'|| ch == 'Y') {				//ѡ�񴴽��µ��ļ�
				if((fp=fopen(filename,"a+")) == NULL) {	//���´����ļ�ʧ��
					printf("\t\t\t����ʧ�ܣ�");
					exit(0);
				} else {								//�����ɹ�
					break;
				}
			} else {									//���������ļ�
				printf("\t\t\t��������ļ�\n");
				continue;								//����ѡ��������ļ�
			}
		} else {										//�ļ����ڲ��򿪳ɹ�
			break;
		}
	}

	while(1) {
		pnew=(LNode *)malloc(sizeof(LNode));
		if(fscanf(fp,"%d\t%s\t%s\t%f\t%f\t%f\n",&pnew->data.num, pnew->data.name, pnew->data.gender, &pnew->data.Lmath, &pnew->data.Dmath, &pnew->data.Amath) == EOF) {
			free(pnew);		//���û�����ݿɶ��ˣ���Ҫ���Ѿ��´����Ľ���ͷ�
			break;
		}
		//β�巨������
		pnew->pnext = NULL;  //�������β���ָ���
		ptemp->pnext = pnew;
		ptemp = ptemp->pnext;
	}
	fclose(fp);
}

//���˵���ʾ
void Welcome() {
	printf("\n\t\t\tversion2.0 design in 2021.7 ");
	printf("\n\n\t\t\t***********************************\n");
	printf("\n\n\t\t\t***********************************\n");
	printf("\t\t\t*  ��ӭʹ��ѧ���ɼ�����ϵͳ2.0��  *\n");	
	printf("\n\n\t\t\t***********************************\n");
	printf("\t\t\t*********ѧ���ɼ�����˵�**********\n");
	printf("\t\t\t*\t\t\t\t  *\n");
	printf("\t\t\t*-----------1.���ҹ���------------*\n");
	printf("\t\t\t*-----------2.��ӹ���------------*\n");
	printf("\t\t\t*-----------3.ɾ������------------*\n");
	printf("\t\t\t*-----------4.�޸Ĺ���------------*\n");
	printf("\t\t\t*-----------5.ͳ�ƹ���------------*\n");
	printf("\t\t\t*-----------6.�˳�ϵͳ------------*\n");
	printf("\t\t\t*\t\t\t\t  *\n");
	printf("\t\t\t***********************************\n");
}

void Count_num() {
	LNode *pA,*pD,*pL;				//����ָ�������ߵĽ��
	LNode *ptemp = pStu->pnext;
	int countA=0,countD=0,countL=0;//�������ųɼ��в��������
	int sum=0;
	sum = CountStudent();
	if(!ptemp) {
		
		printf("\t\t\tû��ѧ����¼���밴���������...\n");
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
	printf("\t\t\tͳ�ƽ��\n");
	printf("\t\t\t��������������:%d���ˣ�\n",countA);
	printf("\t\t\t��ɢ����������:%d���ˣ�\n",countD);
	printf("\t\t\t�ߴ�����������:%d���ˣ�\n",countL);

	printf("\t\t\t�ð༶������Ϊ:%d���ˣ�\n",sum);
	printf("\t\t\t������߷ֵ�ѧ����%s ��%.2f��\n",pA->data.name,pA->data.Amath);
	printf("\t\t\t��ɢ��߷ֵ�ѧ����%s ��%.2f��\n",pD->data.name,pD->data.Dmath);
	printf("\t\t\t�ߴ���߷ֵ�ѧ����%s ��%.2f��\n",pL->data.name,pL->data.Lmath);
	printf("\t\t\t�밴���������...");
	getch();
	return;
}


//ͳ��ѧ��������
int CountStudent() {
	int n=0;
	//��������,ͳ��ѧ������
	LNode *p = pStu->pnext;
	while(p != NULL) {
		n++;
		p = p->pnext;
	}
	return n;
}

//���ѧ����Ϣ
void  AddInfor() {
	LNode* ptemp ;
	int num;
	LNode* pnew = NULL;
	printf("\n\t\t\tversion2.0 design in 2021.7 ");
	printf("\n\n\t\t\t***********************************\n");
	printf("\n\n\t\t\t***********************************\n");
	printf("\t\t\t*  ��ӭʹ��ѧ���ɼ�����ϵͳ2.0��  *\n");	
	printf("\n\n");
	printf("\t\t\t****�������ѧ����Ϣ****\n");
	printf("\t\t\t������Ҫ��Ӽ���ѧ������Ϣ��  ");
	scanf("%d",&num);

	for(int i=0; i<num; i++) {
		pnew = (LNode*)malloc(sizeof(LNode));
		printf("\t\t\t---������ӵ�%d��ѧ����Ϣ---\n",i+1);
		printf("\t\t\t������ѧ�ţ� ");
		scanf("%d",&pnew->data.num);

		ptemp = pStu->pnext;
		while(ptemp != NULL) {
			if(pnew->data.num == ptemp->data.num) {
				printf("\t\t\tѧ���ظ������������룺 ");
				scanf("%d",&pnew->data.num);
				ptemp = pStu->pnext;		//ptemp������������ѧ���Ƿ���ظ�
				continue;
			} else {
				ptemp = ptemp->pnext;
			}
		}
		//ѧ�Ų��ظ�����������ѧ����Ϣ
		printf("\t\t\t������������ ");
		scanf("%s",pnew->data.name);
		printf("\t\t\t�������Ա� ");
		scanf("%s",pnew->data.gender);
		printf("\t\t\t���������Դ����ɼ�: ");
		scanf("%f",&pnew->data.Lmath);
		printf("\t\t\t��������ɢ��ѧ�ɼ��� ");
		scanf("\t%f",&pnew->data.Dmath);
		printf("\t\t\t������ߵ���ѧ�ɼ��� ");
		scanf("\t%f",&pnew->data.Amath);

		if(pStu->pnext == NULL) {		// ������û������
			pnew->pnext = NULL;
			pStu->pnext = pnew;
		} else {						//������������
			ptemp = pStu; 				//ptemp��ͷ��㿪ʼ����
			while(ptemp != NULL) {
				if(ptemp->pnext != NULL) {
					if(pnew->data.num > ptemp->data.num && pnew->data.num < ptemp->pnext->data.num) { //pnew��ѧ�ű�ǰһ���� �Ⱥ�һ��С
						pnew->pnext = ptemp->pnext;
						ptemp->pnext = pnew;
						break;			//����ɹ����˳�ѭ��
					}
				} else {				//ptemp->pnext == NULL,��ʱptemp��β��
					pnew->pnext = NULL;
					ptemp->pnext = pnew;
					break;
				}
				ptemp = ptemp->pnext;
			}
		}
	}
	printf("\t\t\t��ӳɹ���");
	printf("\n\t\t\t�ļ������Ѹ��£�");
	printf("\t\t\t�밴���������...");
}

//�������ݵ��ļ�
void SaveData() {
	LNode *ptemp = pStu->pnext;
	if((fp=fopen(filename,"w")) == NULL) {
		printf("\t\t\t�ļ���ʧ�ܣ�");
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
		printf("\t\t\t�ļ���ʧ�ܣ�");
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
		printf("\t\t\t�ļ���ʧ�ܣ�");
	} else {
		while(ptemp != NULL) {
			fprintf(fp,"%d\t%f\t%f\t%f\n",ptemp->data.num,  ptemp->data.Lmath, ptemp->data.Dmath, ptemp->data.Amath);
			ptemp = ptemp->pnext;		}
	}
	fclose(fp);
}

int Count_check() {
	LNode *ptemp = pStu->pnext;
	int countA=0,countD=0,countL=0;//�������ųɼ��в��������
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
		printf("\t\t\t�ļ���ʧ�ܣ�");
	    if((fp=fopen("GraduateCheck.txt","w")) == NULL) {
		printf("\t\t\t�ļ���ʧ�ܣ�");
	} else {
		    
			fprintf(fp,"%f\t%f\n",total,check);
		}
	}
	fclose(fp);
}





//ɾ��������
void DeleteMain() { //�Ȳ��ң���ɾ��
	int choice;
	do {
    	printf("\n\t\t\tversion2.0 design in 2021.7 ");
	    printf("\n\n\t\t\t***********************************\n");
    	printf("\n\n\t\t\t***********************************\n");
    	printf("\t\t\t*  ��ӭʹ��ѧ���ɼ�����ϵͳ2.0��  *\n");		
		printf("\n\n");
		printf("\t\t\t����ʹ��ɾ�����ܣ�\n");
		printf("\t\t\t1����ѧ��ɾ��\n");
		printf("\t\t\t2��������ɾ��\n");
		printf("\t\t\t3������������\n");
		printf("\t\t\t��ѡ��");
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

//��ѧ��ɾ���Ĺ��ܺ���
void DeleteNum() {
	int num;

	printf("\t\t\t����ɾ��ѧ����Ϣ\n");
	printf("\t\t\t��������Ҫ��ɾ����ѧ��ѧ��:");
	scanf("%d",&num);

	LNode *q;
	q = FindNumFun(num);
	DelOperation(q);
}

//������ɾ���Ĺ��ܺ���
void DeleteName() {
	char name[20];
	printf("\t\t\t����ɾ��ѧ���ɼ���Ϣ\n");
	printf("\t\t\t��������Ҫɾ��ѧ��������:");
	scanf("%s",name);
	LNode *q;
	q = FindNameFun(name);
	DelOperation(q);
}

//ɾ��������������
//ͨ��ǰ�����ɾ��ѧ���ɼ���Ϣ
void DelOperation(LNode *q) {
	LNode *ptemp;
	if(q) {
		printf("\t\t\t��ɾ����ѧ���ɼ���Ϣ���£�\n");
		Title();
		printf("\n\t\t\t%d\t%s\t%s\t%.2f\t\t%.2f\t\t%.2f\n", q->data.num, q->data.name, q->data.gender, q->data.Lmath, q->data.Dmath, q->data.Amath);
		ptemp = pStu;
		while(ptemp->pnext != q) {
			ptemp = ptemp->pnext;
		}
		ptemp->pnext = q->pnext;
		free(q);
		printf("\n\t\t\tɾ�������ɹ���\n");
	}
	SaveData();
	printf("\n\t\t\t�ļ������Ѹ��£�");
	printf("\t\t\t�밴���������...");
	getch();
	return;
}

//�޸ĺ���
void Modify() { //�Ȳ��ҵ����ٶԽ���е����ݽ��и�ֵ
	char ch,name[20];
	int num;
	int n,choice;
	LNode* change;
	printf("\t\t\t*********���ڸ���ѧ����Ϣ**********\n");
	printf("\n\t\t\t1.��ѧ�Ų��Ҹ���ѧ���ɼ���Ϣ");
	printf("\n\t\t\t2.���������Ҹ���ѧ���ɼ���Ϣ");
	printf("\n\t\t\t��ѡ��  ");
	while(1) {
		scanf("%d", &choice);
		if( choice == 1) {
			printf("\n\t\t\t*��������Ҫ���ĵ�ѧ��ѧ�ţ� ");
			scanf("%ld", &num);
			change = FindNumFun(num);
			break;
		} else if( choice == 2) {
			printf("\n\t\t\t*��������Ҫ���ĵ�ѧ�������� ");
			scanf("%s",name);
			change = FindNameFun_Modify(name);
			break;
		} else {
			printf("\n\t\t\t�������");
			continue;
		}
	}
	if(change == NULL) {

		printf("\n\t\t\tѧ����Ϣ������,�޷����ģ�����\n");
		printf("\n\t\t\t�밴���������...");
		getch();
		return;
	}
	Title();
	printf("\n\t\t\t%d\t%s\t%s\t%.2f\t\t%.2f\t\t%.2f\n", change->data.num, change->data.name, change->data.gender, change->data.Lmath, change->data.Dmath, change->data.Amath);
	printf("\t\t\t�����Ƿ�ȷ���޸ĸ�ѧ���ɼ���Ϣ����Y/N��");
	fflush(stdin);
	scanf("%c",&ch);
	if (ch == 'y'|| ch == 'Y') {
		printf("\n\t\t\t������Ҫ�޸ĵ���Ϣ�ǣ�");
		printf("\n\t\t\t1.ѧ�� 2.����  3.�Ա�  4.���Դ���  5.��ɢ��ѧ  6.�ߵ���ѧ  ");
		printf("\n\t\t\t��ѡ�� ");
		while(1) {
			scanf("%d",&n);
			switch(n) {
					system("pause");
				case 1:
					printf("\t\t\t�������µ�ѧ�ţ�");
					scanf("%d",change->data.num);
					break;
				case 2:
					printf("\t\t\t������������ ");
					scanf("%s",change->data.name);
					break;
				case 3:
					printf("\t\t\t�������Ա� ");
					scanf("%s",change->data.gender);
					break;
				case 4:
					printf("\t\t\t���������Դ����ɼ�: ");
					scanf("%f",&change->data.Lmath);
					break;
				case 5:
					printf("\t\t\t��������ɢ��ѧ�ɼ��� ");
					scanf("%f",&change->data.Dmath);
					break;
				case 6:
					printf("\t\t\t������ߵ���ѧ�ɼ��� ");
					scanf("%f",&change->data.Amath);
					break;
				default:
					printf("\t\t\tѡ��������������룺  ");
					continue;
			}
			break;
		}
		printf("\n\t\t\tѧ����Ϣ�Ѿ�������ϣ�����\n");
		SaveData();
		printf("\n\t\t\t�ļ������Ѹ��£�");
		printf("\n\t\t\t�밴���������...");
		getch();
		return;
	}
}

//ȫ���鿴����
void PrintfAll() {
	
	printf("\n\n");
	printf("\t\t\t---������ȫ��ѧ���ĳɼ�---\n");
	LNode * ptemp1 = pStu->pnext ;

	if( ptemp1 == NULL) {	//���ļ���û������
		printf("\t\t\tû�����ݣ��밴���������...");
		getch();
		return;
	}
	Title();
	printf("\n");
	while(ptemp1 != NULL) {
		printf("\t\t\t%d\t%s\t%s\t%.2f\t\t%.2f\t\t%.2f\n", ptemp1->data.num, ptemp1->data.name, ptemp1->data.gender, ptemp1->data.Lmath, ptemp1->data.Dmath, ptemp1->data.Amath);
		ptemp1 = ptemp1->pnext;
	}
	printf("\t\t\t�����������...");
	getch();
	return;
}

//��ѧ�Ų��ҵĵײ㺯��
LNode* FindNumFun(int num) {
	LNode * pre = pStu;
	LNode* q ;
	while (1) {
		if (pre->pnext && (pre->pnext->data.num == num)) {
			q = pre->pnext;	//�Ѿ���ѧ���ҵ�
			return q;
			break;
		} else {
			if (pre->pnext != NULL) {
				pre = pre->pnext;
			} else {
				printf("\n\t\t\tû�в�ѯ����ѧ����Ϣ��\n");
				return 0;	/*���û���ҵ��ͷ���һ����ָ��*/
				break;
			}
		}
	}
}

//�����޸Ĺ��ܵ�--���������ҵĵײ㺯��
LNode* FindNameFun_Modify(char name[]) {
	LNode *ptemp = pStu;
	ptemp = ptemp -> pnext;//  ��ptempָ��ͷ��㣬��ʱӦ��ptemp=ptemp->pnext
	LNode *q;

	while(ptemp != NULL) {
		if(!strcmp(ptemp->data.name,name)) {	//�ҵ��� ������Ψһ
			q = ptemp;
			return q;
			break;
		}
	}
	printf("\n\t\t\t���޴���!\n");
	return 0;
}

//���������ҵĵײ㺯��
LNode* FindNameFun(char name[]) {
	LNode *ptemp = pStu;
	ptemp = ptemp -> pnext;//  ��ptempָ��ͷ��㣬��ʱӦ��ptemp=ptemp->pnext
	LNode *q;
	int n=0;

	while(ptemp != NULL) {
		if(!strcmp(ptemp->data.name,name)) {	//�ҵ��� ������Ψһ
			n++;
			if(n==1)
			{
				Title();
			}
			printf("\n\t\t\t%d\t%s\t%s\t%.2f\t\t%.2f\t\t%.2f\n", ptemp->data.num, ptemp->data.name, ptemp->data.gender, ptemp->data.Lmath, ptemp->data.Dmath, ptemp->data.Amath);
		}
		ptemp = ptemp -> pnext;//�������ң���Ϊ���������������
	}
	//������
	if(n == 0) {
		printf("\n\t\t\t���޴���!\n");
		return 0;
	}
}

//��ѧ�Ų��ҵĹ��ܺ���
void SearchNum() { //��ʱptemp=pStu��û������
	int num;
	
	printf("\n\n\t\t\t***********************************\n");
	printf("\t\t\t*****���ڰ�ѧ�Ų�ѯѧ����Ϣ********\n");
	printf("\t\t\t*��������Ҫ���ҵ�ѧ��:  ");
	scanf("%d",&num);
	LNode *ptemp;

	ptemp = FindNumFun(num);
	if(ptemp) {
		Title();
		printf("\n\t\t\t%d\t%s\t%s\t%.2f\t\t%.2f\t\t%.2f\n", ptemp->data.num, ptemp->data.name, ptemp->data.gender, ptemp->data.Lmath, ptemp->data.Dmath, ptemp->data.Amath);
	}
	printf("\t\t\t�밴���������...");
	getch();
	return;
}

//���������ҵĹ��ܺ���
void SearchName() {
	char name[20];
	
	printf("\n\n\t\t\t***********************************\n");
	printf("\t\t\t********���ڰ���������ѧ����Ϣ*********\n");
	printf("\t\t\t*��������Ҫ���ҵ�����:  ");
	scanf("%s",name);
	LNode *ptemp;
	ptemp = FindNameFun(name);

	if(ptemp) {
		Title();
		printf("\n\t\t\t%d\t%s\t%s\t%.2f\t\t%.2f\t\t%.2f\n", ptemp->data.num, ptemp->data.name, ptemp->data.gender, ptemp->data.Lmath, ptemp->data.Dmath, ptemp->data.Amath);
	}
	printf("\t\t\t�밴���������...");
	getch();
	return;
}

//����������
void SearchMain() {
	int choice;
	do {
    	printf("\n\t\t\tversion2.0 design in 2021.7 ");
     	printf("\n\n\t\t\t***********************************\n");
    	printf("\n\n\t\t\t***********************************\n");
    	printf("\t\t\t*  ��ӭʹ��ѧ���ɼ�����ϵͳ2.0��  *\n");	
    	printf("\n\n\t\t\t***********************************\n");		
		printf("\n\n\t\t\t***********************************\n");
		printf("\t\t\t*********���ڲ���ѧ����Ϣ**********\n");
		printf("\t\t\t*\t\t\t\t  *\n");
		printf("\t\t\t*----------1.��ѧ�Ų���-----------*\n");
		printf("\t\t\t*----------2.����������-----------*\n");
		printf("\t\t\t*----------3.�鿴ȫ��ѧ����Ϣ-----*\n");
		printf("\t\t\t*----------4.����������-----------*\n");
		printf("\t\t\t*\t\t\t\t  *\n");
		printf("\t\t\t***********************************\n");
		printf("\t\t\t��ѡ��");
		fflush(stdin);
		scanf("%d",&choice);
		if(choice !=1 && choice !=2 && choice !=3 && choice != 4) {
			continue;
		}
		if (!choice) {
			printf("\t\t\t�����ַ��������������룡");
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
		printf("\t\t\t��ѡ�� ");
		scanf("%c",&choice);
		if(choice == '1' || choice =='2' || choice =='3' || choice == '4' || choice == '5' || choice == '6') {
			break;
		}
	}
	return choice;
}

//����������
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
				//����
				SearchMain();
				break;
			case '2':
				//���
				AddInfor();
				break;
			case '3':
				//ɾ��
				DeleteMain();
				break;
			case '4':
				//�޸�
				Modify();
				break;
			case '5':
				//ͳ��
				Count_num();
				break;
			case '6':
				//�˳�
				SaveData_1();
				SaveData_2();
				SaveData_3();
				SaveData();//�˳�ʱ�������ļ�
				break;
		}
		if( choice == '6') {
			printf("\n\t\t\t��лʹ�ñ���ϵͳ���ټ���");
			break;
		}
	} while(1);

	return 0;
}
