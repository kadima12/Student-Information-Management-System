/*
实验任务分工：
李长庆 ： 创建函数，注释，以及最后的完善整个程序（完善删除修改函数） 
刘浩伟 ： 流程图，思路导图，统计成绩函数（找最高分，平均分，打印成绩单），以及完善最后的整个程序 
*/ 
#include<stdio.h> 
#include<string.h>
#include<stdlib.h>
typedef char ElementType;
typedef int _ElementType;
typedef struct LNode* PtrToLNode;
struct LNode {
    ElementType name[20];
    ElementType id[10];
    _ElementType score[20];
    PtrToLNode Next;
};
typedef PtrToLNode List;

List MakeEmpty(){//创建并返回空表 
	List L = (struct LNode*)malloc(sizeof(struct LNode));
	L->Next = NULL;
	return L;
}

bool Creat(List L,int m,int n){//创建 m个学生的信息 n为科目数 
    List s;
	for(int i = 0;i < m;i++){
		s = (struct LNode*)malloc(sizeof(struct LNode));
		scanf("%s",s->name);
		scanf("%s",s->id);
		if(strlen(s->id) != 10){
		printf("输入学号错误，创建失败\n");//学号必须为10位 
		return false;
	}
		for(int j = 0;j < n;j++){
			scanf("%d",&s->score[j]);
		}
		s->Next = L->Next;
		L->Next = s;
	}
	return true;
}


bool Insert_student(List Head,int n){
	List s;
	s = (LNode*)malloc(sizeof(struct LNode));
	char p[20],q[10];
	while(Head != NULL){
		printf("请输入要添加学生的姓名、学号和成绩:\n");
		scanf("%s %s",&p,&q);
		for(int i = 0;i < n;i++){
			scanf("%d",&s->score[i]);
		}
		if(strlen(q) == 10){
			strcpy(s->id,q);
			strcpy(s->name,p);
			List w = Head->Next;
			while(w != NULL){//避免重复信息 
				if(strcmp(s->id,w->id) == 0){
					printf("已有该学生信息，添加失败！\n");
					return false;
				}
				else{
					w = w->Next; 
				}
			}
			s->Next = Head->Next;
		    Head->Next = s;
		    printf("添加成功！\n");
		    return true;
		}
		else{
			printf("输入学号错误，添加失败！\n");
			return false;
		}
	}
}


bool DeleteorChange(List L,int n){
	ElementType ID[10];
	printf("请输入您要改动的学生的学号：");
	scanf("%s",&ID);
	if(strlen(ID) != 10){
		printf("输入学号错误，改动失败\n");
		return false;
	}
	while(L){
		if(strcmp(L->Next->id,ID) == 0){
			printf("学号已查找到,请输入相应功能选项前的序号：\n");
			printf("1、删除学生信息\n");
			printf("2、修改学生信息\n");
			int function;
			scanf("%d",&function);
			switch(function){
				case 1:
					L->Next = L->Next->Next;
					printf("删除成功！\n");
					return true;
				case 2:
					printf("请输入新的要改动的学生信息：\n"); 
					scanf("%s%s",L->Next->name,L->Next->id);
					if(strlen(L->Next->id) != 10){
					printf("输入学号错误，修改失败\n");//学号必须为10位 
					return false;
					}
					for(int j=0;j<n;j++){
						scanf("%d",&L->Next->score[j]);
					}
					printf("修改成功！\n");
					return true;
			}
		}
		L = L->Next;
	}
	printf("未找到该学生信息，删除失败！\n"); 
	return false;
}


bool FindMaxGrade(List StuInformation,int n){
	PtrToLNode Head,P;
	if(StuInformation->Next == NULL) 
	return false;
	Head = StuInformation->Next;//Head 指向第一个结点 
	for(int i = 0;i < n;i++){//用 for 循环找各科最高分 
		PtrToLNode Pmax = Head;//Pmax 指向第一个结点 
		P = StuInformation->Next->Next;//P 指向第二个结点
		while(P != NULL){
			if(P->score[i] > Pmax->score[i]){
				Pmax = P;
			}
			P = P->Next;
		}
		printf("科目%d 最高分：%d\n",i+1,Pmax->score[i]);
	}
	return true;
}


void FindAvgGrade(List StuInformation,int n,int m){
	List Head;
	for(int i = 0;i < n;i++){
		Head = StuInformation->Next;
		_ElementType sum = 0;
		while(Head != NULL){
			sum += Head->score[i];
			Head = Head->Next; 
		}
	    double avg = (double)sum/m;
		printf("科目%d 平均分：%.3lf\n",i+1,avg);
	}
}

void PrintList(List StuInformation,int n){//输出学生信息 
	printf("当前的学生信息为：\n");
	List Head;
	Head = StuInformation->Next;
	while(Head != NULL){
		printf("%s %s ",Head->name,Head->id);
		for(int i = 0;i < n;i++){
			printf("科目%d：",i+1);
			printf("%d ",Head->score[i]);
		}
		printf("\n"); 
		Head = Head->Next;
	}
}

int main(){
	int m,n;
	printf("\t\t\t\t\t\t欢迎使用学生管理系统！\n");
	printf("检测到您未导入学生信息，请先进行初始化\n");
	printf("请输入您想创建的学生信息表中学生数量以及学科数目：");
	scanf("%d %d",&m,&n); 
	printf("请输入学生信息:\n");
	List L;
	L = MakeEmpty();
	Creat(L,m,n);//创建 m个学生的信息 n为科目数 
	printf("初始化完成！\n");
	printf("请选择您希望执行的功能并输入相应功能选项前的序号：\n");
	printf("1、插入学生信息\n");
	printf("2、修改学生信息\n");
	printf("3、统计学生成绩\n");
	printf("4、退出管理系统\n");
	int x = 1;
	while(x > 0&&x < 4){
		int function;
		scanf("%d",&function); 
		x = function;
		switch(function){
			case 1:
				Insert_student(L,n);//n为科目数
				PrintList(L,n); 
				break;
			case 2:
			    DeleteorChange(L,n);
			    PrintList(L,n);
				break;
			case 3:
				FindMaxGrade(L,n);
				FindAvgGrade(L,n,m);	
				break;
			case 4:
				printf("退出成功，学生信息已自动保存！\n");
				break;
		}
		if(x > 0&&x < 4){
			printf("请输入下一步指令\n");
		}else if(x > 4||x <= 0){
			printf("无效指令\n");
		}
	}
	return 0; 
}


