#ifndef STUDENT
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#define NAME 20//���ֳ��� 
#define ID 15//ѧ�ų��� 
#define CLSNUM 10 //�γ̺� 
#define N 100 //���ѧ����
#define PSWD 18 //�����ַ����� 
#define CLSNAME 50 //�γ����ַ��� 
#define COURSE 3 //�γ���Ŀ 
char Directory[50]={"./temp/studentmsg.dat"};
char mima[PSWD];//��ȡ����
int pwdSaveFlag=0;
//�ɼ�ͳ�ƽṹ�� 
typedef struct{
	float max_score;//��߷� 
	float min_score;//��ͷ�
	float average_max;//ƽ������߷� 
	float average_min;//ƽ������ͷ�
	float average_score;//ƽ���� 
	float total_score;//�ܷ�
	float pass_rate;//������ 
	int pass_num;//�������� 
}Statis;
//ѧ���ɼ��ṹ�� 
typedef struct{
	char clsNumber[CLSNUM];//�γ̺� 
	char clsName[CLSNAME];//�γ��� 
	float score;//�ɼ�
}Course;
typedef struct{
	char name[NAME];//���� 
	char id[ID];//ѧ�� 
	Course course[COURSE];//3�ſγ� 
	float total_score;//�����ܳɼ� 
	float average_score;//����ƽ���ɼ� 
}student;
typedef struct {
	char pwd[PSWD];
	int len;
}PWD;
char cls_num[COURSE][CLSNUM]={"001","002","003"};
char cls_name[COURSE][CLSNAME]={"C���Գ������","Java�������","Python�������"} ;
void record();//��¼ 
void menu();//�˵�����
int read_file(void);
void studentmsg_in();//��Ϣ¼��
void studentmsg_look(int);//��Ϣ�鿴
void student_del();//��Ϣɾ��
void find_msg();//��Ϣ���� 
void set_pswd();//�������� 
void msg_save();//�ļ����� 
void find_id();//��ѧ�Ų�ѯ
void find_name();//��������ѯ
void find_clsname();//���γ�����ѯ
void msg_modify();//��Ϣ�޸� 
void print_title(int flag) ;
void find_cls();//�γ�1 
void sort(int key);//���� 
void print(int index,int flag);//��ӡ���������Ӧ�ṹ�� 
int find_id1(char find[]);//����ϵͳ���Ƿ�����عؼ�����Ϣ�����з���������û�з���-1 
int msg_export();//ѧ����Ϣ���������±� 
void my_exit();
#endif
