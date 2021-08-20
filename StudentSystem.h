#ifndef STUDENT
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#define NAME 20//名字长度 
#define ID 15//学号长度 
#define CLSNUM 10 //课程号 
#define N 100 //最大学生数
#define PSWD 18 //密码字符个数 
#define CLSNAME 50 //课程名字符数 
#define COURSE 3 //课程数目 
char Directory[50]={"./temp/studentmsg.dat"};
char mima[PSWD];//存取密码
int pwdSaveFlag=0;
//成绩统计结构体 
typedef struct{
	float max_score;//最高分 
	float min_score;//最低分
	float average_max;//平均分最高分 
	float average_min;//平均分最低分
	float average_score;//平均分 
	float total_score;//总分
	float pass_rate;//及格率 
	int pass_num;//及格人数 
}Statis;
//学生成绩结构体 
typedef struct{
	char clsNumber[CLSNUM];//课程号 
	char clsName[CLSNAME];//课程名 
	float score;//成绩
}Course;
typedef struct{
	char name[NAME];//姓名 
	char id[ID];//学号 
	Course course[COURSE];//3门课程 
	float total_score;//个人总成绩 
	float average_score;//个人平均成绩 
}student;
typedef struct {
	char pwd[PSWD];
	int len;
}PWD;
char cls_num[COURSE][CLSNUM]={"001","002","003"};
char cls_name[COURSE][CLSNAME]={"C语言程序设计","Java程序设计","Python程序设计"} ;
void record();//登录 
void menu();//菜单函数
int read_file(void);
void studentmsg_in();//信息录入
void studentmsg_look(int);//信息查看
void student_del();//信息删除
void find_msg();//信息查找 
void set_pswd();//密码重置 
void msg_save();//文件保存 
void find_id();//按学号查询
void find_name();//按姓名查询
void find_clsname();//按课程名查询
void msg_modify();//信息修改 
void print_title(int flag) ;
void find_cls();//课程1 
void sort(int key);//排序 
void print(int index,int flag);//打印输出索引对应结构体 
int find_id1(char find[]);//查找系统中是否有相关关键字信息，若有返回索引，没有返回-1 
int msg_export();//学生信息导出到记事本 
void my_exit();
#endif
