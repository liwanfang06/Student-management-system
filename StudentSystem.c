/*
	�༭ʱ�䣺2020/06/24
	��Ա�����򷽡����ҷ� 
*/
#include <stdio.h>
#include <conio.h>
#include"StudentSystem.h"
Statis sta_class[COURSE],sta_total;//����ͳ�Ƽ��ܳɼ�ͳ��
student stu_sum[N];//�洢���ļ���ȡ��ѧ����Ϣ
int count=0;//��ȡѧ����Ϣ��������
int main() { 
	system("color 9f");//�������弰������ɫ
	printf("\n\n\t\t\t\t---------��ӭ��¼ѧ���ɼ�����ϵͳ---------\n");
	record();//��¼����
	read_file();//��ȡ�ļ�
	menu();//ѭ������������˵�
	return 0;
} 
//�˵�����
void menu() {
	while(1){ 
	system("cls");
	printf("\n\n\t\t\t------  ��ܰ��ʾ��Ϊȷ�����ݲ���������ȷ�˳�ϵͳ  ------");
	printf("\n\n\t\t\t\t---------��ӭʹ��ѧ���ɼ�����ϵͳ---------\n\n");
	printf("\t\t\t\t\t*************************\n");
	printf("\t\t\t\t\t*   1.����ɼ���Ϣ.     *\n");
	printf("\t\t\t\t\t*   2.�ɼ�¼��.         *\n");
	printf("\t\t\t\t\t*   3.��ѯ.             *\n");
	printf("\t\t\t\t\t*   4.����ѧ���ɼ�.     *\n");
	printf("\t\t\t\t\t*   5.ɾ��ѧ����Ϣ.     *\n");
	printf("\t\t\t\t\t*   6.��������.         *\n");
	printf("\t\t\t\t\t*   7.����.             *\n");
	printf("\t\t\t\t\t*   8.����.             *\n");
	printf("\t\t\t\t\t*   0.�˳�����.         *\n");
	printf("\t\t\t\t\t*************************\n");
	printf("\t\t\t\t\t����������ѡ��");
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
			printf("\n\t\t\t******************��Ч����*****************\n\t\t\t");
			system("pause");break;
	}  
	}
}
void my_exit(){
		printf("\n\t\t\t�˳�֮ǰ�Ƿ񱣴������޸�(y/n)��\n"); 
		char c;
		while((c=getch()) && (c!='y' && c!='n')){
			printf("\n\t\t\t******************��Ч����(y/n)*****************\n\t\t\t");
		}
		if(c=='y'){
			msg_save();
		}else{
			
		}
		exit(0);
}
//�����ȡ 
void record() {
	FILE *fp;
	char password[PSWD];
	int count=0;
	int i;
	if((fp=fopen("studentpswd.dat","r"))==NULL){
		printf("\n\n\t\t\t\t\t[��ȫ��ʾ]:��ȡ��������ʧ�ܣ������������\n");
		i=1;
		do{
			printf("\n\t\t\t\t\t�������¼����\n");
			printf("\t\t\t\t\t(��ʼ���룺liwanfang): ");
			scanf("%s",password);
		
			if(strcmp(password,"liwanfang")==0) {
				
				printf("\n\t\t\t\t\t���ڵ�¼");
				Sleep(500);
				printf(" .");
				Sleep(500);
				printf(" .");
				Sleep(500);
				printf(" .");
				Sleep(500);
				printf("\n\t\t\t\t\t��	¼	��	����");
				Sleep(1000);
				return;
			}else{
				if(i==3){
				printf("\n\t\t\t\t\t��û��������ǿ���˳�...\n\t\t\t");
				exit(1);
				}
				printf("\n\t\t\t\t\t�������������%d�λ���...\t\t\t\n",3-i);
			}
			i++;
		}while(1);
	}
	rewind(fp);
	while(count<PSWD && fread(&mima,PSWD*sizeof(char),1,fp)==1);
	int len=strlen(mima);
	 
	for(i=0;i<len;i++){
		mima[i]=mima[i]-i-520;//������� 
	}
	fclose(fp); 
	i=1;
	do{
		printf("\n\t\t\t\t\t�������¼����\n");
		printf("\t\t\t\t\t(��ʼ���룺liwanfang): ");
		scanf("%s",password);
	
		if(strcmp(password,mima)==0) {
			printf("\n\t\t\t\t\t���ڵ�¼");
			Sleep(500);
			printf(" .");
			Sleep(500);
			printf(" .");
			Sleep(500);
			printf(" .");
			Sleep(500);
			printf("\n\t\t\t\t\t��	¼	��	����");
			Sleep(500);
			return;
		}else{
			if(i==3){
			printf("\n\t\t\t\t\t��û��������ǿ���˳�...\n\t\t\t");
			exit(1);
			}
			printf("\n\t\t\t\t\t�������������%d�λ���...\t\t\t\n",3-i);
		}
		i++;
	}while(1);
	system("pause"); 
}
//�ļ���ȡ
int read_file() {
	FILE *pstudent,*pstudent1;//�ļ�ָ��
	int size = sizeof(student);//�ṹ��С
	if ((pstudent = fopen("studentmsg.txt", "a+b")) == NULL) { //���ļ��򴴽������ļ�
		fputs("Can't open studengmsg.txt file\n",stderr);//����ʧ�ܣ���ʾ���˳�
		exit(1);
	}
	if ((pstudent1 = fopen("studentdata.txt", "a+b")) == NULL) { //���ļ��򴴽������ļ�
		fputs("Can't open studengmsg.txt file\n",stderr);//����ʧ�ܣ���ʾ���˳�
		exit(1);
	}
	rewind(pstudent); //��λ���ļ���ʼ
	rewind(pstudent1); //��λ���ļ���ʼ
	while (count < N &&  fread(&stu_sum[count], size,1, pstudent) == 1) { //��ȡ�ļ�
		fwrite(&stu_sum[count], size, 1,pstudent1);//����
		count++;//������������λ���ļ�ĩβ
	}
	fclose(pstudent);//�ر��ļ�
	fclose(pstudent1);//�ر��ļ�
}
//��Ϣ����
int msg_export(){
	FILE *msg=fopen("msg.txt","w");
	fprintf(msg,"\n\t\t\t\t\t\t -----  ѧ���ɼ�һ����%d�ˣ�  -----\n\n",count);
	fprintf(msg,"\t%-6s%-12s%-15s%-15s%-15s%-15s%-15s%-15s\n\n","���","����","ѧ��",cls_name[0], 
		       cls_name[1],cls_name[2],"�ܳɼ�","ƽ����");
	fclose(msg);
	studentmsg_look(1);
} 
//��Ϣ���
void studentmsg_look(int flag) {
	if(count==0) {
		printf("\n\t\t\t\t\t\t\t  -----ϵͳ���κ���Ϣ  -----");
		printf("\n\t\t\t\t\t\t\t�����������...");
		getch() ;
		return;
	}
	sort(COURSE+1);//�ܳɼ����� 
	
	int i;
	//���Ƽ����������ֳܷ�ʼ�� 
	for(i=0;i<COURSE;i++){
		sta_class[i].pass_num = 0;
		sta_class[i].total_score=0;
		sta_class[i].average_score=0;
		sta_class[i].total_score=0;
	}
	//�ܳɼ������������ֳܷ�ʼ�� 
	sta_total.pass_num = 0;
	sta_total.total_score = 0; 
	
	FILE *msg=fopen("msg.txt","a");
	if(flag==0){
			//��ӡ������
		print_title(1);
	}else{
		if(msg==NULL){
				printf("\t\t����ʧ�ܣ�\n");
				return;
		}
	} 
	for(i=0; i<count; i++) {
		int j=0;
		//�����ܳɼ�����
		stu_sum[i].total_score= stu_sum[i].course[0].score+stu_sum[i].course[1].score+stu_sum[i].course[2].score;

		//����ƽ���ɼ�����
		stu_sum[i].average_score=stu_sum[i].total_score/COURSE;
		if(i==0) {
			//ȫ����߷֣���ͷֳ�ʼ��
			sta_total.max_score = stu_sum[i].total_score;
			sta_total.min_score = stu_sum[i].total_score;
			sta_total.average_min = stu_sum[i].average_score;
			sta_total.average_max = stu_sum[i].average_score;
			//������߷֡���ͷ�ͳ��
			sta_class[0].max_score = stu_sum[i].course[0].score;
			sta_class[1].max_score = stu_sum[i].course[1].score;
			sta_class[2].max_score = stu_sum[i].course[2].score;
			sta_class[0].min_score = stu_sum[i].course[0].score;
			sta_class[1].min_score = stu_sum[i].course[1].score;
			sta_class[2].min_score = stu_sum[i].course[2].score;
			
		} else {
			//ȫ����߷֡���ͷ�ͳ��
			if(stu_sum[i].total_score > sta_total.max_score)
				sta_total.max_score = stu_sum[i].total_score;
			if(stu_sum[i].total_score < sta_total.min_score)
				sta_total.min_score = stu_sum[i].total_score;

			//ƽ������߷���ͷ�ͳ��
			if(stu_sum[i].average_score < sta_total.average_min)
				sta_total.average_min = stu_sum[i].average_score;
			if(stu_sum[i].average_score > sta_total.average_max)
				sta_total.average_max = stu_sum[i].average_score;

			//������߷֡���ͷ�ͳ��
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
		//��������ͳ��
		if(stu_sum[i].course[0].score>=60) sta_class[0].pass_num++;
		if(stu_sum[i].course[1].score>=60) sta_class[1].pass_num++;
		if(stu_sum[i].course[2].score>=60) sta_class[2].pass_num++;
		if(stu_sum[i].total_score >= ((COURSE*100)*0.6)) sta_total.pass_num++;
		//ȫ���ܳɼ����㣨��Ҫ������ƽ���ɼ���
		sta_total.total_score += stu_sum[i].total_score;
		//�����ܳɼ����㣨��Ҫ������ƽ���ɼ���
		sta_class[0].total_score += stu_sum[i].course[0].score;
		sta_class[1].total_score += stu_sum[i].course[1].score;
		sta_class[2].total_score += stu_sum[i].course[2].score;

		//��ӡѧ����Ϣ
		if(flag==0)
			print(i,1);//����1������Ŵ�ӡ
		else{
			//����ѧ����Ϣ
		   fprintf(msg,"\t%-6d%-12s%-15s%-15.2f%-15.2f%-15.2f%-15.2f%-15.2f\n\n",i+1,stu_sum[i].name,
	       stu_sum[i].id,stu_sum[i].course[j].score,stu_sum[i].course[j+1].score,
		   stu_sum[i].course[j+2].score,stu_sum[i].total_score,stu_sum[i].average_score);
		} 
	}
	//ȫ��ƽ���ּ���
	sta_total.average_score = sta_total.total_score/count;
	//����ƽ���ּ���
	sta_class[0].average_score = sta_class[0].total_score/count;
	sta_class[1].average_score = sta_class[1].total_score/count;
	sta_class[2].average_score = sta_class[2].total_score/count;
	//�����ʼ���
	sta_total.pass_rate = sta_total.pass_num*1.0/count;
	sta_class[0].pass_rate = sta_class[0].pass_num*1.0/(float)count;
	sta_class[1].pass_rate =sta_class[1].pass_num*1.0/ (float)count;
	sta_class[2].pass_rate = sta_class[2].pass_num*1.0/(float)count;
	if(flag==0){
	
		printf("\n\n\t%-33s%-15.2f%-15.2f%-15.2f%-15.2f%-15.2f\n","��߷֣�",
		       sta_class[0].max_score,sta_class[1].max_score,sta_class[2].max_score
		       ,sta_total.max_score,sta_total.average_max) ;
		printf("\n\t%-33s%-15.2f%-15.2f%-15.2f%-15.2f%-15.2f\n","��ͷ֣�",
		      sta_class[0].min_score,sta_class[1].min_score,sta_class[2].min_score
		       ,sta_total.min_score,sta_total.average_min) ;
		printf("\n\t%-33s%-15.2f%-15.2f%-15.2f%-15.2f\n","ƽ���֣�",sta_class[0].average_score,
		sta_class[1].average_score,sta_class[2].average_score,sta_total.average_score);
		printf("\n\t%-33s%-15d%-15d%-15d%-15d\n","����������",
		       sta_class[0].pass_num,sta_class[1].pass_num,sta_class[2].pass_num
		       ,sta_total.pass_num);
		printf("\n\t%-33s%-15.2f%-15.2f%-15.2f%-15.2f\n","�����ʣ�",
		       sta_class[0].pass_rate,sta_class[1].pass_rate,sta_class[2].pass_rate
		       ,sta_total.pass_rate);
		printf("\n\t�����������...");
		getch() ;
	}else{
		fprintf(msg,"\n\n\t%-33s%-15.2f%-15.2f%-15.2f%-15.2f%-15.2f\n","��߷֣�",
	       sta_class[0].max_score,sta_class[1].max_score,sta_class[2].max_score
	       ,sta_total.max_score,sta_total.average_max) ;
		fprintf(msg,"\n\t%-33s%-15.2f%-15.2f%-15.2f%-15.2f%-15.2f\n","��ͷ֣�",
		      sta_class[0].min_score,sta_class[1].min_score,sta_class[2].min_score
		       ,sta_total.min_score,sta_total.average_min) ;
		fprintf(msg,"\n\t%-33s%-15.2f%-15.2f%-15.2f%-15.2f\n","ƽ���֣�",sta_class[0].average_score,
		sta_class[1].average_score,sta_class[2].average_score,sta_total.average_score);
		fprintf(msg,"\n\t%-33s%-15d%-15d%-15d%-15d\n","����������",
		       sta_class[0].pass_num,sta_class[1].pass_num,sta_class[2].pass_num
		       ,sta_total.pass_num);
		fprintf(msg,"\n\t%-33s%-15.2f%-15.2f%-15.2f%-15.2f\n","�����ʣ�",
		       sta_class[0].pass_rate,sta_class[1].pass_rate,sta_class[2].pass_rate
		       ,sta_total.pass_rate);
		  printf("\n\n\t\t\tѧ���ɼ���Ϣ�����ɹ�������\n");
		  printf("\n\t\t\t�����������..");
		  getch();
	}
	fclose(msg); 
}
//�ɼ�¼��/�޸�
void studentmsg_in(int flag) {
	int i;
	student msg;
	if(flag==-1){
		puts("\n\t\t\t\t\t\t -----  ѧ����Ϣ¼��  -----\n");
	}
	printf("\n\t\t\t������������");
	do{
		printf("\n\t\t\t����������<�����ĸ��ַ�>��");
		scanf("%s",msg.name);
		system("cls"); 
	} while(strlen(msg.name)<4);
	printf("\t\t\t������ѧ�ţ�");
	scanf("%s",msg.id);
	//����
	int index=find_id1(msg.id);
	if(index!=-1 && index!=flag) {
		system("cls");
		int j=0;
		puts("\n\t\t\t\t\t\t -----  ѧ��������ѧ���ظ�  -----\n");
		printf("\t%-12s%-15s%-15s%-10s%-15s%-10s%-15s%-10s%-15s%-15s\n","����","ѧ��","�γ�1",
		       "�ɼ�","�γ�2","�ɼ�","�γ�3","�ɼ�","�ܳɼ�","ƽ����");
		print(index,0);
	} else {
		for(i=0; i<COURSE; i++) {
			strcpy(msg.course[i].clsNumber,cls_num[i]);
			strcpy(msg.course[i].clsName,cls_name[i]);
			do {
				printf("\t\t\t������%s�ɼ�(0-100)��",msg.course[i].clsName);
				scanf("%f",&msg.course[i].score);
			} while(msg.course[i].score<0 || msg.course[i].score>100);
		}
		char key;
		if(flag==-1) {
			do {
				printf("\t\t\tȷ��¼�룿(y/n)��");
				fflush(stdin);//��ջ�����
				key=getch();
				if(key=='y') {
					stu_sum[count]=msg;
					count++;
					printf("\n\t\t\t��Ϣ¼��ɹ�");
					break;
				} else if(key=='n') {
					printf("\n\t\t\t��Ϣ¼��ȡ��");
					break;
				} else {
					printf("\n\t\t\t******************��Ч����*****************\n");
				}
			} while(key != 'y' && key!='n');
		} else {
			do {
				printf("\t\t\tȷ���޸ģ�(y/n)��");
				fflush(stdin);//��ջ�����
				key= getch();
				if(key=='y') {
					stu_sum[flag]=msg;
					printf("\n\t\t\t��Ϣ�޸ĳɹ�");
					break;
				} else if(key=='n') {
					printf("\n\t\t\t��Ϣ�޸�ȡ��");
					break;
				} else {
					printf("\n\t\t\t******************��Ч����*****************\n");

				}
			} while(key != 'y' && key !='n');
		}
	}
	printf("\n\t\t\t�����������");
	getch() ;
}
//����
void msg_save() {
	int filecount = 0;
	FILE * pstudent;//�ļ�ָ��
	int size = sizeof (student);//�ṹ��С
	if ((pstudent = fopen("studentmsg.txt", "w")) == NULL) { //���ļ��򴴽������ļ�
		fputs("Can't open studengmsg.txt file\n",stderr);//����ʧ�ܣ���ʾ���˳�
		exit(1);
	}
	rewind(pstudent);          // go to start of file  ��λ���ļ���ʼ
	if (count >=N) { //������ֵ�ﵽ�������鼮��������ʾ���˳�
		fputs("The studentmsg.txt file is full.", stderr);
		exit(2);
	}
	for(filecount=0; filecount<count; filecount++) {
		fwrite(&stu_sum[filecount], size, 1,pstudent);
	}
	fclose(pstudent);
	puts("\n\n\t���ڱ���...") ;
	Sleep(100);
	puts("\t��	��	��	��!") ;
	printf("\n\t�����������...");
	getch() ;
}
//��������
void set_pswd() {
	FILE *fp;
	printf("\n\n"); 
	do {
		printf("\t\t\t[��ʾ]���������6-16λ�����֣��ַ����\n");
		printf("\t\t\t������...\n\t\t\t��");
		scanf("%s",mima);
	} while(strlen(mima)<6||strlen(mima)>16);
	char key;
	int len=strlen(mima);
	int i=0;
	for(;i<len;i++){
		mima[i]=mima[i]+i+520;//������� 
	}
	do {
		printf("\t\t\tȷ���޸ģ�(y/n)��");
		fflush(stdin);//��ջ�����
		key=getch();
		if(key=='y') {
			if((fp=fopen("studentpswd.dat","wb"))==NULL) {
				printf("[����!]�������ó���\n");
				system("pause");
				return;
			}
			fwrite(&mima,strlen(mima)*sizeof(char), 1,fp);
			printf("\n\t\t\t�������óɹ���\n\t");
			fclose(fp);
			break;
		} else if(key=='n') {
			printf("\n\t\t\t�������ȡ��\t\t");
			break;
		} else {
			printf("\n\t\t\t******************��Ч����*****************\n");
		}
	} while(key != 'y' && key!='n');
	printf("\t\t") ;
	system("pause");
}
//��Ϣ����
void find_msg() {
	if(count==0) {
		printf("\n\t\t\t\t\t-----ϵͳ���κ���Ϣ-----");
		printf("\n\t\t\t\t\t�����������...");
		getch() ;
		return;
	}
	
	do {
		system("cls");
		puts("\n\t\t\t\t\t\t -----  ѧ����Ϣ����  -----\n");
		fflush(stdin);//��ջ�����
		puts("\n\t\t\t1.��ѧ�Ų�ѯ");
		puts("\t\t\t2.��������ѯ");
		puts("\t\t\t3.���γ̲�ѯ");
		puts("\t\t\t0.����");
		printf("\t\t\t����������ѡ��");
		char key=getch();
		system("cls");
		switch(key) {
			case '1':find_id();	break;
			case '2':find_name();break;
			case '3':find_clsname();break;
			case '0':return;
			default:printf("\t\t\t******************��Ч����*****************\n");
				fflush(stdin);//��ջ�����
				printf("\t�����������...");
				getch();
		}
	} while(1);


}
//��ѧ�Ų�ѯ
void find_id() {
	int index=0;
	int flag=0;
	char f_id[ID];
	puts("\n\t\t\t\t\t\t -----  ѧ����Ϣ����  -----\n");
	printf("\n\t\t\t\t\t\t������ѧ�ţ�");
	scanf("%s",f_id);

	for(index=0; index<count; index++) {
		if(strstr(stu_sum[index].id,f_id)!=NULL) {
			if(flag==0) {
				print_title(0);//��ӡ������ 
			}
			print(index,0);//��ӡѧ����Ϣ 
			flag=1;
		}
	}
	if(flag==0) {
		puts("\n\tδ�ҵ������Ϣ");
	}
	printf("\t�����������...");
	fflush(stdin);//��ջ�����
	getch() ;
}
//��������ѯ
void find_name() {
	int flag=0;
	int index=0;
	char f_name[NAME];
	puts("\n\t\t\t\t\t\t -----  ѧ����Ϣ����  -----\n");
	printf("\n\t\t\t\t������������");
	scanf("%s",f_name);
	for(index=0; index<count; index++) {
		if(strstr(stu_sum[index].name,f_name)!=NULL) {
			if(flag==0) {
				print_title(0);//��ӡ������ 
			}
			print(index,0);//��ӡѧ����Ϣ 
			flag=1;
		}
	}
	if(flag==0) {
		puts("\n\tδ�ҵ������Ϣ");
	}
	printf("\t�����������...");
	fflush(stdin);//��ջ�����
	getch() ;
}
//���γ�����ѯ
void find_clsname() {
	do {
		system("cls");
		puts("\n\t\t\t\t\t\t -----  ѧ����Ϣ����  -----\n");
		fflush(stdin);//��ջ�����
		printf("\n\t\t\t\t1.%s\n",cls_name[0]);
		printf("\t\t\t\t2.%s\n",cls_name[1]);
		printf("\t\t\t\t3.%s\n",cls_name[2]);
		puts("\t\t\t\t0.����\n\n");
		printf("\t\t\t\t����������ѡ��");
		char key= getch();
		system("cls");
		switch(key) {
			case '1':find_cls(1);break;
			case '2':find_cls(2);break;
			case '3':find_cls(3);break;
			case '0':return;
			default:
				printf("\t\t\t******************��Ч����*****************\n");
				fflush(stdin);//��ջ�����
				printf("\t�����������...");
				getch();
		}
	} while(1);

}
//��ӡ������
void print_title(int flag) {
	if(flag==0) {
		puts("\n\t\t\t\t\t\t-----  �ҵ���ѧ����Ϣ -----\n");
		printf("\t%-12s%-15s%-15s%-15s%-15s%-15s%-15s\n\n","����","ѧ��",cls_name[0], 
		       cls_name[1],cls_name[2],"�ܳɼ�","ƽ����");
	} else {
		
		printf("\n\t\t\t\t\t\t -----  ѧ���ɼ�һ����%d�ˣ�  -----\n\n",count);
		printf("\t%-6s%-12s%-15s%-15s%-15s%-15s%-15s%-15s\n\n","���","����","ѧ��",cls_name[0], 
		       cls_name[1],cls_name[2],"�ܳɼ�","ƽ����");
	
	}
}
//��ӡѧ����Ϣ index:������flag:0-���ź� ��0�����ź�
void print(int index,int flag) {
	int j=0;
	if(flag==0) {
		printf("\t%-12s%-15s%-15.2f%-15.2f%-15.2f%-15.2f%-15.2f\n\n",stu_sum[index].name,
		       stu_sum[index].id,stu_sum[index].course[j].score,stu_sum[index].course[j+1].score,
			   stu_sum[index].course[j+2].score,stu_sum[index].total_score,stu_sum[index].average_score);
	} else {
		//��Ϣ�����ӡ�����ź�
		printf("\t%-6d%-12s%-15s%-15.2f%-15.2f%-15.2f%-15.2f%-15.2f\n\n",index+1,stu_sum[index].name,
		       stu_sum[index].id,stu_sum[index].course[j].score,stu_sum[index].course[j+1].score,
			   stu_sum[index].course[j+2].score,stu_sum[index].total_score,stu_sum[index].average_score);
	}

}
//ɾ��
void student_del() {
	if(count==0) {
		printf("\n\t\t\t\t\t-----ϵͳ���κ���Ϣ-----");
		printf("\n\t\t\t\t\t�����������...");
		getch() ;
		return;
	}
	char del_id[ID] ;
	int index,right;
	puts("\n\t\t\t\t\t\t -----  ѧ����Ϣɾ��  -----\n");
	fflush(stdin);
	printf("\n\t\t\t��������Ҫɾ����ѧ��ѧ�ţ�");
	//����
	index=find_id1(gets(del_id));

	if(index!=-1) {
		print_title(0);
		print(index,0) ;
		char key;
		do {
			fflush(stdin);//��ջ�����
			printf("\tȷ��ɾ����(y/n)��");
			key=getch();
			if(key=='y') {
				right=count-1;
				for(; index<right; index++) {
					stu_sum[index]=stu_sum[index+1];
				}
				count--;
				puts("\n\tɾ���ɹ�");
				break;
			} else if(key=='n') {
				puts("\n\t��Ϣɾ��ȡ��");
				break;
			} else {
				printf("\n\t*****************��Ч����*****************\n");
			}
		} while(key != 'y' && key!='n');
	} else {
		puts("\tû���ҵ����ѧ����Ϣ");
	}
	printf("\t�����������...");
	getch() ;
}
//��ѧ�Ų��ң����ҵ����عؼ��ֵ����������򷵻�-1
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
//����
void msg_modify() {
	if(count==0) {
		printf("\n\t\t\t\t\t-----ϵͳ���κ���Ϣ-----");
		printf("\n\t\t\t\t\t�����������...");
		getch() ;
		return;
	}
	puts("\n\t\t\t\t\t\t -----  ѧ����Ϣ�޸�  -----\n");
	char modify_id[ID];
	student stu_modify;
	printf("\n\t������ѧ��ѧ�ţ�");
	int index=find_id1(gets(modify_id));
	if(index!=-1) {
		print_title(0);
		print(index,0);
		studentmsg_in(index);
	} else {
		puts("\tû���ҵ����ѧ����Ϣ");
		printf("\t�����������...");
		getch();
	}

}
//�γ̰������� 
void find_cls(int flag) {
	puts("\n\t\t\t\t -----  ѧ����Ϣ����  -----\n");
	printf("\n\t\t\t\t----- %s��%s��-----\n\n",
	cls_name[flag-1],cls_num[flag-1]);
	printf("\t\t%-15s%-15s%-15s%-15s\n\n","����","����","ѧ��","�ɼ�");
	int i;
	sort(flag);
	for(i=0; i<count; i++) {
		printf("\t\t%-15d%-15s%-15s%-15.2f\n\n",i+1,stu_sum[i].name,
		stu_sum[i].id,stu_sum[i].course[flag-1].score);
	}
	fflush(stdin);//��ջ�����
	printf("\t�����������...");
	getch();
}
//��ͬ��key������ͬ�γ̲���������,��key���ڿγ���Ŀ�������ܳɼ�����
void sort(int key) {
	int i,j;
	student temp;
	//���տγ�һ�ɼ�����
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

