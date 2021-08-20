/*
	编辑时间：2020/06/24
	组员：李万方、罗忠发 
*/
#include <stdio.h>
#include <conio.h>
#include"StudentSystem.h"
Statis sta_class[COURSE],sta_total;//单科统计及总成绩统计
student stu_sum[N];//存储从文件读取的学生信息
int count=0;//读取学生信息个数计数
int main() { 
	system("color 9f");//设置字体及背景颜色
	printf("\n\n\t\t\t\t---------欢迎登录学生成绩管理系统---------\n");
	record();//登录密码
	read_file();//读取文件
	menu();//循环调用主界面菜单
	return 0;
} 
//菜单界面
void menu() {
	while(1){ 
	system("cls");
	printf("\n\n\t\t\t------  温馨提示：为确保数据不出错，请正确退出系统  ------");
	printf("\n\n\t\t\t\t---------欢迎使用学生成绩管理系统---------\n\n");
	printf("\t\t\t\t\t*************************\n");
	printf("\t\t\t\t\t*   1.浏览成绩信息.     *\n");
	printf("\t\t\t\t\t*   2.成绩录入.         *\n");
	printf("\t\t\t\t\t*   3.查询.             *\n");
	printf("\t\t\t\t\t*   4.更改学生成绩.     *\n");
	printf("\t\t\t\t\t*   5.删除学生信息.     *\n");
	printf("\t\t\t\t\t*   6.重置密码.         *\n");
	printf("\t\t\t\t\t*   7.保存.             *\n");
	printf("\t\t\t\t\t*   8.导出.             *\n");
	printf("\t\t\t\t\t*   0.退出程序.         *\n");
	printf("\t\t\t\t\t*************************\n");
	printf("\t\t\t\t\t请输入您的选择：");
	char key=getch();
	system("cls"); 
	switch(key) {
		case '0':my_exit();break;
		case '1':studentmsg_look(0);break;
		case '2':studentmsg_in(-1);break;
		case '3':find_msg();break;
		case '4':msg_modify();break;
		case '5':student_del();break;
		case '6':set_pswd();break; 
		case '7':msg_save();break;
		case '8':msg_export();break;
		default:
			printf("\n\t\t\t******************无效输入*****************\n\t\t\t");
			system("pause");break;
	}  
	}
}
void my_exit(){
		printf("\n\t\t\t退出之前是否保存您的修改(y/n)：\n"); 
		char c;
		while((c=getch()) && (c!='y' && c!='n')){
			printf("\n\t\t\t******************无效输入(y/n)*****************\n\t\t\t");
		}
		if(c=='y'){
			msg_save();
		}else{
			
		}
		exit(0);
}
//密码读取 
void record() {
	FILE *fp;
	char password[PSWD];
	int count=0;
	int i;
	if((fp=fopen("studentpswd.dat","r"))==NULL){
		printf("\n\n\t\t\t\t\t[安全提示]:读取密码数据失败，请谨慎操作！\n");
		i=1;
		do{
			printf("\n\t\t\t\t\t请输入登录密码\n");
			printf("\t\t\t\t\t(初始密码：liwanfang): ");
			scanf("%s",password);
		
			if(strcmp(password,"liwanfang")==0) {
				
				printf("\n\t\t\t\t\t正在登录");
				Sleep(500);
				printf(" .");
				Sleep(500);
				printf(" .");
				Sleep(500);
				printf(" .");
				Sleep(500);
				printf("\n\t\t\t\t\t登	录	成	功！");
				Sleep(1000);
				return;
			}else{
				if(i==3){
				printf("\n\t\t\t\t\t你没机会啦，强制退出...\n\t\t\t");
				exit(1);
				}
				printf("\n\t\t\t\t\t密码错误！您还有%d次机会...\t\t\t\n",3-i);
			}
			i++;
		}while(1);
	}
	rewind(fp);
	while(count<PSWD && fread(&mima,PSWD*sizeof(char),1,fp)==1);
	int len=strlen(mima);
	 
	for(i=0;i<len;i++){
		mima[i]=mima[i]-i-520;//密码解密 
	}
	fclose(fp); 
	i=1;
	do{
		printf("\n\t\t\t\t\t请输入登录密码\n");
		printf("\t\t\t\t\t(初始密码：liwanfang): ");
		scanf("%s",password);
	
		if(strcmp(password,mima)==0) {
			printf("\n\t\t\t\t\t正在登录");
			Sleep(500);
			printf(" .");
			Sleep(500);
			printf(" .");
			Sleep(500);
			printf(" .");
			Sleep(500);
			printf("\n\t\t\t\t\t登	录	成	功！");
			Sleep(500);
			return;
		}else{
			if(i==3){
			printf("\n\t\t\t\t\t你没机会啦，强制退出...\n\t\t\t");
			exit(1);
			}
			printf("\n\t\t\t\t\t密码错误！您还有%d次机会...\t\t\t\n",3-i);
		}
		i++;
	}while(1);
	system("pause"); 
}
//文件读取
int read_file() {
	FILE *pstudent,*pstudent1;//文件指针
	int size = sizeof(student);//结构大小
	if ((pstudent = fopen("studentmsg.txt", "a+b")) == NULL) { //打开文件或创建并打开文件
		fputs("Can't open studengmsg.txt file\n",stderr);//若打开失败，提示并退出
		exit(1);
	}
	if ((pstudent1 = fopen("studentdata.txt", "a+b")) == NULL) { //打开文件或创建并打开文件
		fputs("Can't open studengmsg.txt file\n",stderr);//若打开失败，提示并退出
		exit(1);
	}
	rewind(pstudent); //定位到文件开始
	rewind(pstudent1); //定位到文件开始
	while (count < N &&  fread(&stu_sum[count], size,1, pstudent) == 1) { //读取文件
		fwrite(&stu_sum[count], size, 1,pstudent1);//备份
		count++;//计数递增，定位到文件末尾
	}
	fclose(pstudent);//关闭文件
	fclose(pstudent1);//关闭文件
}
//信息导出
int msg_export(){
	FILE *msg=fopen("msg.txt","w");
	fprintf(msg,"\n\t\t\t\t\t\t -----  学生成绩一览表（%d人）  -----\n\n",count);
	fprintf(msg,"\t%-6s%-12s%-15s%-15s%-15s%-15s%-15s%-15s\n\n","编号","姓名","学号",cls_name[0], 
		       cls_name[1],cls_name[2],"总成绩","平均分");
	fclose(msg);
	studentmsg_look(1);
} 
//信息浏览
void studentmsg_look(int flag) {
	if(count==0) {
		printf("\n\t\t\t\t\t\t\t  -----系统无任何信息  -----");
		printf("\n\t\t\t\t\t\t\t按任意键返回...");
		getch() ;
		return;
	}
	sort(COURSE+1);//总成绩排序 
	
	int i;
	//单科及格人数及总分初始化 
	for(i=0;i<COURSE;i++){
		sta_class[i].pass_num = 0;
		sta_class[i].total_score=0;
		sta_class[i].average_score=0;
		sta_class[i].total_score=0;
	}
	//总成绩及格人数及总分初始化 
	sta_total.pass_num = 0;
	sta_total.total_score = 0; 
	
	FILE *msg=fopen("msg.txt","a");
	if(flag==0){
			//打印标题栏
		print_title(1);
	}else{
		if(msg==NULL){
				printf("\t\t导出失败！\n");
				return;
		}
	} 
	for(i=0; i<count; i++) {
		int j=0;
		//单人总成绩计算
		stu_sum[i].total_score= stu_sum[i].course[0].score+stu_sum[i].course[1].score+stu_sum[i].course[2].score;

		//单人平均成绩计算
		stu_sum[i].average_score=stu_sum[i].total_score/COURSE;
		if(i==0) {
			//全班最高分，最低分初始化
			sta_total.max_score = stu_sum[i].total_score;
			sta_total.min_score = stu_sum[i].total_score;
			sta_total.average_min = stu_sum[i].average_score;
			sta_total.average_max = stu_sum[i].average_score;
			//单科最高分、最低分统计
			sta_class[0].max_score = stu_sum[i].course[0].score;
			sta_class[1].max_score = stu_sum[i].course[1].score;
			sta_class[2].max_score = stu_sum[i].course[2].score;
			sta_class[0].min_score = stu_sum[i].course[0].score;
			sta_class[1].min_score = stu_sum[i].course[1].score;
			sta_class[2].min_score = stu_sum[i].course[2].score;
			
		} else {
			//全班最高分、最低分统计
			if(stu_sum[i].total_score > sta_total.max_score)
				sta_total.max_score = stu_sum[i].total_score;
			if(stu_sum[i].total_score < sta_total.min_score)
				sta_total.min_score = stu_sum[i].total_score;

			//平均分最高分最低分统计
			if(stu_sum[i].average_score < sta_total.average_min)
				sta_total.average_min = stu_sum[i].average_score;
			if(stu_sum[i].average_score > sta_total.average_max)
				sta_total.average_max = stu_sum[i].average_score;

			//单科最高分、最低分统计
			if(stu_sum[i].course[0].score > sta_class[0].max_score)
				sta_class[0].max_score = stu_sum[i].course[0].score;
			if(stu_sum[i].course[1].score > sta_class[1].max_score)
				sta_class[1].max_score = stu_sum[i].course[1].score;
			if(stu_sum[i].course[2].score > sta_class[2].max_score)
				sta_class[2].max_score = stu_sum[i].course[2].score;

			if(stu_sum[i].course[0].score < sta_class[0].min_score)
				sta_class[0].min_score = stu_sum[i].course[0].score;
			if(stu_sum[i].course[1].score < sta_class[1].min_score)
				sta_class[1].min_score = stu_sum[i].course[1].score;
			if(stu_sum[i].course[2].score < sta_class[2].min_score)
				sta_class[2].min_score = stu_sum[i].course[2].score;
		}
		//及格人数统计
		if(stu_sum[i].course[0].score>=60) sta_class[0].pass_num++;
		if(stu_sum[i].course[1].score>=60) sta_class[1].pass_num++;
		if(stu_sum[i].course[2].score>=60) sta_class[2].pass_num++;
		if(stu_sum[i].total_score >= ((COURSE*100)*0.6)) sta_total.pass_num++;
		//全班总成绩计算（主要用于算平均成绩）
		sta_total.total_score += stu_sum[i].total_score;
		//单科总成绩计算（主要用于算平均成绩）
		sta_class[0].total_score += stu_sum[i].course[0].score;
		sta_class[1].total_score += stu_sum[i].course[1].score;
		sta_class[2].total_score += stu_sum[i].course[2].score;

		//打印学生信息
		if(flag==0)
			print(i,1);//参数1：带编号打印
		else{
			//导出学生信息
		   fprintf(msg,"\t%-6d%-12s%-15s%-15.2f%-15.2f%-15.2f%-15.2f%-15.2f\n\n",i+1,stu_sum[i].name,
	       stu_sum[i].id,stu_sum[i].course[j].score,stu_sum[i].course[j+1].score,
		   stu_sum[i].course[j+2].score,stu_sum[i].total_score,stu_sum[i].average_score);
		} 
	}
	//全班平均分计算
	sta_total.average_score = sta_total.total_score/count;
	//单科平均分计算
	sta_class[0].average_score = sta_class[0].total_score/count;
	sta_class[1].average_score = sta_class[1].total_score/count;
	sta_class[2].average_score = sta_class[2].total_score/count;
	//及格率计算
	sta_total.pass_rate = sta_total.pass_num*1.0/count;
	sta_class[0].pass_rate = sta_class[0].pass_num*1.0/(float)count;
	sta_class[1].pass_rate =sta_class[1].pass_num*1.0/ (float)count;
	sta_class[2].pass_rate = sta_class[2].pass_num*1.0/(float)count;
	if(flag==0){
	
		printf("\n\n\t%-33s%-15.2f%-15.2f%-15.2f%-15.2f%-15.2f\n","最高分：",
		       sta_class[0].max_score,sta_class[1].max_score,sta_class[2].max_score
		       ,sta_total.max_score,sta_total.average_max) ;
		printf("\n\t%-33s%-15.2f%-15.2f%-15.2f%-15.2f%-15.2f\n","最低分：",
		      sta_class[0].min_score,sta_class[1].min_score,sta_class[2].min_score
		       ,sta_total.min_score,sta_total.average_min) ;
		printf("\n\t%-33s%-15.2f%-15.2f%-15.2f%-15.2f\n","平均分：",sta_class[0].average_score,
		sta_class[1].average_score,sta_class[2].average_score,sta_total.average_score);
		printf("\n\t%-33s%-15d%-15d%-15d%-15d\n","及格人数：",
		       sta_class[0].pass_num,sta_class[1].pass_num,sta_class[2].pass_num
		       ,sta_total.pass_num);
		printf("\n\t%-33s%-15.2f%-15.2f%-15.2f%-15.2f\n","及格率：",
		       sta_class[0].pass_rate,sta_class[1].pass_rate,sta_class[2].pass_rate
		       ,sta_total.pass_rate);
		printf("\n\t按任意键返回...");
		getch() ;
	}else{
		fprintf(msg,"\n\n\t%-33s%-15.2f%-15.2f%-15.2f%-15.2f%-15.2f\n","最高分：",
	       sta_class[0].max_score,sta_class[1].max_score,sta_class[2].max_score
	       ,sta_total.max_score,sta_total.average_max) ;
		fprintf(msg,"\n\t%-33s%-15.2f%-15.2f%-15.2f%-15.2f%-15.2f\n","最低分：",
		      sta_class[0].min_score,sta_class[1].min_score,sta_class[2].min_score
		       ,sta_total.min_score,sta_total.average_min) ;
		fprintf(msg,"\n\t%-33s%-15.2f%-15.2f%-15.2f%-15.2f\n","平均分：",sta_class[0].average_score,
		sta_class[1].average_score,sta_class[2].average_score,sta_total.average_score);
		fprintf(msg,"\n\t%-33s%-15d%-15d%-15d%-15d\n","及格人数：",
		       sta_class[0].pass_num,sta_class[1].pass_num,sta_class[2].pass_num
		       ,sta_total.pass_num);
		fprintf(msg,"\n\t%-33s%-15.2f%-15.2f%-15.2f%-15.2f\n","及格率：",
		       sta_class[0].pass_rate,sta_class[1].pass_rate,sta_class[2].pass_rate
		       ,sta_total.pass_rate);
		  printf("\n\n\t\t\t学生成绩信息导出成功。。。\n");
		  printf("\n\t\t\t按任意键返回..");
		  getch();
	}
	fclose(msg); 
}
//成绩录入/修改
void studentmsg_in(int flag) {
	int i;
	student msg;
	if(flag==-1){
		puts("\n\t\t\t\t\t\t -----  学生信息录入  -----\n");
	}
	printf("\n\t\t\t请输入姓名：");
	do{
		printf("\n\t\t\t请输入姓名<最少四个字符>：");
		scanf("%s",msg.name);
		system("cls"); 
	} while(strlen(msg.name)<4);
	printf("\t\t\t请输入学号：");
	scanf("%s",msg.id);
	//查重
	int index=find_id1(msg.id);
	if(index!=-1 && index!=flag) {
		system("cls");
		int j=0;
		puts("\n\t\t\t\t\t\t -----  学号与以下学生重复  -----\n");
		printf("\t%-12s%-15s%-15s%-10s%-15s%-10s%-15s%-10s%-15s%-15s\n","姓名","学号","课程1",
		       "成绩","课程2","成绩","课程3","成绩","总成绩","平均分");
		print(index,0);
	} else {
		for(i=0; i<COURSE; i++) {
			strcpy(msg.course[i].clsNumber,cls_num[i]);
			strcpy(msg.course[i].clsName,cls_name[i]);
			do {
				printf("\t\t\t请输入%s成绩(0-100)：",msg.course[i].clsName);
				scanf("%f",&msg.course[i].score);
			} while(msg.course[i].score<0 || msg.course[i].score>100);
		}
		char key;
		if(flag==-1) {
			do {
				printf("\t\t\t确定录入？(y/n)：");
				fflush(stdin);//清空缓冲区
				key=getch();
				if(key=='y') {
					stu_sum[count]=msg;
					count++;
					printf("\n\t\t\t信息录入成功");
					break;
				} else if(key=='n') {
					printf("\n\t\t\t信息录入取消");
					break;
				} else {
					printf("\n\t\t\t******************无效输入*****************\n");
				}
			} while(key != 'y' && key!='n');
		} else {
			do {
				printf("\t\t\t确定修改？(y/n)：");
				fflush(stdin);//清空缓冲区
				key= getch();
				if(key=='y') {
					stu_sum[flag]=msg;
					printf("\n\t\t\t信息修改成功");
					break;
				} else if(key=='n') {
					printf("\n\t\t\t信息修改取消");
					break;
				} else {
					printf("\n\t\t\t******************无效输入*****************\n");

				}
			} while(key != 'y' && key !='n');
		}
	}
	printf("\n\t\t\t按任意键返回");
	getch() ;
}
//保存
void msg_save() {
	int filecount = 0;
	FILE * pstudent;//文件指针
	int size = sizeof (student);//结构大小
	if ((pstudent = fopen("studentmsg.txt", "w")) == NULL) { //打开文件或创建并打开文件
		fputs("Can't open studengmsg.txt file\n",stderr);//若打开失败，提示并退出
		exit(1);
	}
	rewind(pstudent);          // go to start of file  定位到文件开始
	if (count >=N) { //若计数值达到最大最大书籍数量，提示并退出
		fputs("The studentmsg.txt file is full.", stderr);
		exit(2);
	}
	for(filecount=0; filecount<count; filecount++) {
		fwrite(&stu_sum[filecount], size, 1,pstudent);
	}
	fclose(pstudent);
	puts("\n\n\t正在保存...") ;
	Sleep(100);
	puts("\t保	存	成	功!") ;
	printf("\n\t按任意键返回...");
	getch() ;
}
//密码设置
void set_pswd() {
	FILE *fp;
	printf("\n\n"); 
	do {
		printf("\t\t\t[提示]密码必须是6-16位的数字，字符组合\n");
		printf("\t\t\t请输入...\n\t\t\t：");
		scanf("%s",mima);
	} while(strlen(mima)<6||strlen(mima)>16);
	char key;
	int len=strlen(mima);
	int i=0;
	for(;i<len;i++){
		mima[i]=mima[i]+i+520;//密码加密 
	}
	do {
		printf("\t\t\t确定修改？(y/n)：");
		fflush(stdin);//清空缓冲区
		key=getch();
		if(key=='y') {
			if((fp=fopen("studentpswd.dat","wb"))==NULL) {
				printf("[警告!]密码设置出错！\n");
				system("pause");
				return;
			}
			fwrite(&mima,strlen(mima)*sizeof(char), 1,fp);
			printf("\n\t\t\t密码设置成功！\n\t");
			fclose(fp);
			break;
		} else if(key=='n') {
			printf("\n\t\t\t密码更改取消\t\t");
			break;
		} else {
			printf("\n\t\t\t******************无效输入*****************\n");
		}
	} while(key != 'y' && key!='n');
	printf("\t\t") ;
	system("pause");
}
//信息查找
void find_msg() {
	if(count==0) {
		printf("\n\t\t\t\t\t-----系统无任何信息-----");
		printf("\n\t\t\t\t\t按任意键返回...");
		getch() ;
		return;
	}
	
	do {
		system("cls");
		puts("\n\t\t\t\t\t\t -----  学生信息查找  -----\n");
		fflush(stdin);//清空缓冲区
		puts("\n\t\t\t1.按学号查询");
		puts("\t\t\t2.按姓名查询");
		puts("\t\t\t3.按课程查询");
		puts("\t\t\t0.返回");
		printf("\t\t\t请输入您的选择：");
		char key=getch();
		system("cls");
		switch(key) {
			case '1':find_id();	break;
			case '2':find_name();break;
			case '3':find_clsname();break;
			case '0':return;
			default:printf("\t\t\t******************无效输入*****************\n");
				fflush(stdin);//清空缓冲区
				printf("\t按任意键返回...");
				getch();
		}
	} while(1);


}
//按学号查询
void find_id() {
	int index=0;
	int flag=0;
	char f_id[ID];
	puts("\n\t\t\t\t\t\t -----  学生信息查找  -----\n");
	printf("\n\t\t\t\t\t\t请输入学号：");
	scanf("%s",f_id);

	for(index=0; index<count; index++) {
		if(strstr(stu_sum[index].id,f_id)!=NULL) {
			if(flag==0) {
				print_title(0);//打印标题栏 
			}
			print(index,0);//打印学生信息 
			flag=1;
		}
	}
	if(flag==0) {
		puts("\n\t未找到相关信息");
	}
	printf("\t按任意键返回...");
	fflush(stdin);//清空缓冲区
	getch() ;
}
//按姓名查询
void find_name() {
	int flag=0;
	int index=0;
	char f_name[NAME];
	puts("\n\t\t\t\t\t\t -----  学生信息查找  -----\n");
	printf("\n\t\t\t\t请输入姓名：");
	scanf("%s",f_name);
	for(index=0; index<count; index++) {
		if(strstr(stu_sum[index].name,f_name)!=NULL) {
			if(flag==0) {
				print_title(0);//打印标题栏 
			}
			print(index,0);//打印学生信息 
			flag=1;
		}
	}
	if(flag==0) {
		puts("\n\t未找到相关信息");
	}
	printf("\t按任意键返回...");
	fflush(stdin);//清空缓冲区
	getch() ;
}
//按课程名查询
void find_clsname() {
	do {
		system("cls");
		puts("\n\t\t\t\t\t\t -----  学生信息查找  -----\n");
		fflush(stdin);//清空缓冲区
		printf("\n\t\t\t\t1.%s\n",cls_name[0]);
		printf("\t\t\t\t2.%s\n",cls_name[1]);
		printf("\t\t\t\t3.%s\n",cls_name[2]);
		puts("\t\t\t\t0.返回\n\n");
		printf("\t\t\t\t请输入您的选择：");
		char key= getch();
		system("cls");
		switch(key) {
			case '1':find_cls(1);break;
			case '2':find_cls(2);break;
			case '3':find_cls(3);break;
			case '0':return;
			default:
				printf("\t\t\t******************无效输入*****************\n");
				fflush(stdin);//清空缓冲区
				printf("\t按任意键返回...");
				getch();
		}
	} while(1);

}
//打印标题栏
void print_title(int flag) {
	if(flag==0) {
		puts("\n\t\t\t\t\t\t-----  找到的学生信息 -----\n");
		printf("\t%-12s%-15s%-15s%-15s%-15s%-15s%-15s\n\n","姓名","学号",cls_name[0], 
		       cls_name[1],cls_name[2],"总成绩","平均分");
	} else {
		
		printf("\n\t\t\t\t\t\t -----  学生成绩一览表（%d人）  -----\n\n",count);
		printf("\t%-6s%-12s%-15s%-15s%-15s%-15s%-15s%-15s\n\n","编号","姓名","学号",cls_name[0], 
		       cls_name[1],cls_name[2],"总成绩","平均分");
	
	}
}
//打印学生信息 index:索引，flag:0-无排号 非0：有排号
void print(int index,int flag) {
	int j=0;
	if(flag==0) {
		printf("\t%-12s%-15s%-15.2f%-15.2f%-15.2f%-15.2f%-15.2f\n\n",stu_sum[index].name,
		       stu_sum[index].id,stu_sum[index].course[j].score,stu_sum[index].course[j+1].score,
			   stu_sum[index].course[j+2].score,stu_sum[index].total_score,stu_sum[index].average_score);
	} else {
		//信息浏览打印，有排号
		printf("\t%-6d%-12s%-15s%-15.2f%-15.2f%-15.2f%-15.2f%-15.2f\n\n",index+1,stu_sum[index].name,
		       stu_sum[index].id,stu_sum[index].course[j].score,stu_sum[index].course[j+1].score,
			   stu_sum[index].course[j+2].score,stu_sum[index].total_score,stu_sum[index].average_score);
	}

}
//删除
void student_del() {
	if(count==0) {
		printf("\n\t\t\t\t\t-----系统无任何信息-----");
		printf("\n\t\t\t\t\t按任意键返回...");
		getch() ;
		return;
	}
	char del_id[ID] ;
	int index,right;
	puts("\n\t\t\t\t\t\t -----  学生信息删除  -----\n");
	fflush(stdin);
	printf("\n\t\t\t请输入需要删除的学生学号：");
	//查找
	index=find_id1(gets(del_id));

	if(index!=-1) {
		print_title(0);
		print(index,0) ;
		char key;
		do {
			fflush(stdin);//清空缓冲区
			printf("\t确定删除？(y/n)：");
			key=getch();
			if(key=='y') {
				right=count-1;
				for(; index<right; index++) {
					stu_sum[index]=stu_sum[index+1];
				}
				count--;
				puts("\n\t删除成功");
				break;
			} else if(key=='n') {
				puts("\n\t信息删除取消");
				break;
			} else {
				printf("\n\t*****************无效输入*****************\n");
			}
		} while(key != 'y' && key!='n');
	} else {
		puts("\t没有找到相关学生信息");
	}
	printf("\t按任意键返回...");
	getch() ;
}
//按学号查找，若找到返回关键字的索引，否则返回-1
int find_id1(char find[]) {
	int index,flag=0;
	int left=0;
	int right=count-1;
	while(left<=right && count>0) {
		if(left==right && strcmp(stu_sum[left].id,find)==0) {
			flag=1;
			index=left;
			break;
		}
		if(left<right && strcmp(stu_sum[left].id,find)==0) {
			flag=1;
			index=left;
			break;
		}
		if(left<right && strcmp(stu_sum[right].id,find)==0) {
			flag=1;
			index=right;
			break;
		}
		left++;
		right--;
	}
	if(flag==1) return index;
	else return -1;
}
//更改
void msg_modify() {
	if(count==0) {
		printf("\n\t\t\t\t\t-----系统无任何信息-----");
		printf("\n\t\t\t\t\t按任意键返回...");
		getch() ;
		return;
	}
	puts("\n\t\t\t\t\t\t -----  学生信息修改  -----\n");
	char modify_id[ID];
	student stu_modify;
	printf("\n\t请输入学生学号：");
	int index=find_id1(gets(modify_id));
	if(index!=-1) {
		print_title(0);
		print(index,0);
		studentmsg_in(index);
	} else {
		puts("\t没有找到相关学生信息");
		printf("\t按任意键返回...");
		getch();
	}

}
//课程按名查找 
void find_cls(int flag) {
	puts("\n\t\t\t\t -----  学生信息查找  -----\n");
	printf("\n\t\t\t\t----- %s（%s）-----\n\n",
	cls_name[flag-1],cls_num[flag-1]);
	printf("\t\t%-15s%-15s%-15s%-15s\n\n","排名","姓名","学号","成绩");
	int i;
	sort(flag);
	for(i=0; i<count; i++) {
		printf("\t\t%-15d%-15s%-15s%-15.2f\n\n",i+1,stu_sum[i].name,
		stu_sum[i].id,stu_sum[i].course[flag-1].score);
	}
	fflush(stdin);//清空缓冲区
	printf("\t按任意键返回...");
	getch();
}
//不同的key，按不同课程不进行排序,若key大于课程数目，按照总成绩排序
void sort(int key) {
	int i,j;
	student temp;
	//按照课程一成绩排序
	if(key <= COURSE) {
		for(i=0; i<count; i++) {
			for(j=0; j<count-i-1; j++) {
				if(stu_sum[j].course[key-1].score < stu_sum[j+1].course[key-1].score) {
					temp=stu_sum[j];
					stu_sum[j]=stu_sum[j+1];
					stu_sum[j+1]=temp;
				}
			}
		}
	} else {
		for(i=0; i<count; i++) {
			for(j=0; j<count-i-1; j++) {
				if(stu_sum[j].total_score < stu_sum[j+1].total_score) {
					temp=stu_sum[j];
					stu_sum[j]=stu_sum[j+1];
					stu_sum[j+1]=temp;
				}
			}
		}
	}
}

