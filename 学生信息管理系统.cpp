/*
ʵ������ֹ���
��� �� ����������ע�ͣ��Լ���������������������ɾ���޸ĺ����� 
����ΰ �� ����ͼ��˼·��ͼ��ͳ�Ƴɼ�����������߷֣�ƽ���֣���ӡ�ɼ��������Լ����������������� 
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

List MakeEmpty(){//���������ؿձ� 
	List L = (struct LNode*)malloc(sizeof(struct LNode));
	L->Next = NULL;
	return L;
}

bool Creat(List L,int m,int n){//���� m��ѧ������Ϣ nΪ��Ŀ�� 
    List s;
	for(int i = 0;i < m;i++){
		s = (struct LNode*)malloc(sizeof(struct LNode));
		scanf("%s",s->name);
		scanf("%s",s->id);
		if(strlen(s->id) != 10){
		printf("����ѧ�Ŵ��󣬴���ʧ��\n");//ѧ�ű���Ϊ10λ 
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
		printf("������Ҫ���ѧ����������ѧ�źͳɼ�:\n");
		scanf("%s %s",&p,&q);
		for(int i = 0;i < n;i++){
			scanf("%d",&s->score[i]);
		}
		if(strlen(q) == 10){
			strcpy(s->id,q);
			strcpy(s->name,p);
			List w = Head->Next;
			while(w != NULL){//�����ظ���Ϣ 
				if(strcmp(s->id,w->id) == 0){
					printf("���и�ѧ����Ϣ�����ʧ�ܣ�\n");
					return false;
				}
				else{
					w = w->Next; 
				}
			}
			s->Next = Head->Next;
		    Head->Next = s;
		    printf("��ӳɹ���\n");
		    return true;
		}
		else{
			printf("����ѧ�Ŵ������ʧ�ܣ�\n");
			return false;
		}
	}
}


bool DeleteorChange(List L,int n){
	ElementType ID[10];
	printf("��������Ҫ�Ķ���ѧ����ѧ�ţ�");
	scanf("%s",&ID);
	if(strlen(ID) != 10){
		printf("����ѧ�Ŵ��󣬸Ķ�ʧ��\n");
		return false;
	}
	while(L){
		if(strcmp(L->Next->id,ID) == 0){
			printf("ѧ���Ѳ��ҵ�,��������Ӧ����ѡ��ǰ����ţ�\n");
			printf("1��ɾ��ѧ����Ϣ\n");
			printf("2���޸�ѧ����Ϣ\n");
			int function;
			scanf("%d",&function);
			switch(function){
				case 1:
					L->Next = L->Next->Next;
					printf("ɾ���ɹ���\n");
					return true;
				case 2:
					printf("�������µ�Ҫ�Ķ���ѧ����Ϣ��\n"); 
					scanf("%s%s",L->Next->name,L->Next->id);
					if(strlen(L->Next->id) != 10){
					printf("����ѧ�Ŵ����޸�ʧ��\n");//ѧ�ű���Ϊ10λ 
					return false;
					}
					for(int j=0;j<n;j++){
						scanf("%d",&L->Next->score[j]);
					}
					printf("�޸ĳɹ���\n");
					return true;
			}
		}
		L = L->Next;
	}
	printf("δ�ҵ���ѧ����Ϣ��ɾ��ʧ�ܣ�\n"); 
	return false;
}


bool FindMaxGrade(List StuInformation,int n){
	PtrToLNode Head,P;
	if(StuInformation->Next == NULL) 
	return false;
	Head = StuInformation->Next;//Head ָ���һ����� 
	for(int i = 0;i < n;i++){//�� for ѭ���Ҹ�����߷� 
		PtrToLNode Pmax = Head;//Pmax ָ���һ����� 
		P = StuInformation->Next->Next;//P ָ��ڶ������
		while(P != NULL){
			if(P->score[i] > Pmax->score[i]){
				Pmax = P;
			}
			P = P->Next;
		}
		printf("��Ŀ%d ��߷֣�%d\n",i+1,Pmax->score[i]);
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
		printf("��Ŀ%d ƽ���֣�%.3lf\n",i+1,avg);
	}
}

void PrintList(List StuInformation,int n){//���ѧ����Ϣ 
	printf("��ǰ��ѧ����ϢΪ��\n");
	List Head;
	Head = StuInformation->Next;
	while(Head != NULL){
		printf("%s %s ",Head->name,Head->id);
		for(int i = 0;i < n;i++){
			printf("��Ŀ%d��",i+1);
			printf("%d ",Head->score[i]);
		}
		printf("\n"); 
		Head = Head->Next;
	}
}

int main(){
	int m,n;
	printf("\t\t\t\t\t\t��ӭʹ��ѧ������ϵͳ��\n");
	printf("��⵽��δ����ѧ����Ϣ�����Ƚ��г�ʼ��\n");
	printf("���������봴����ѧ����Ϣ����ѧ�������Լ�ѧ����Ŀ��");
	scanf("%d %d",&m,&n); 
	printf("������ѧ����Ϣ:\n");
	List L;
	L = MakeEmpty();
	Creat(L,m,n);//���� m��ѧ������Ϣ nΪ��Ŀ�� 
	printf("��ʼ����ɣ�\n");
	printf("��ѡ����ϣ��ִ�еĹ��ܲ�������Ӧ����ѡ��ǰ����ţ�\n");
	printf("1������ѧ����Ϣ\n");
	printf("2���޸�ѧ����Ϣ\n");
	printf("3��ͳ��ѧ���ɼ�\n");
	printf("4���˳�����ϵͳ\n");
	int x = 1;
	while(x > 0&&x < 4){
		int function;
		scanf("%d",&function); 
		x = function;
		switch(function){
			case 1:
				Insert_student(L,n);//nΪ��Ŀ��
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
				printf("�˳��ɹ���ѧ����Ϣ���Զ����棡\n");
				break;
		}
		if(x > 0&&x < 4){
			printf("��������һ��ָ��\n");
		}else if(x > 4||x <= 0){
			printf("��Чָ��\n");
		}
	}
	return 0; 
}


