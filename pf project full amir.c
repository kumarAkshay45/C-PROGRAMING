#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include<stdlib.h>
//#include<time.h>
#include<string.h>
#include<unistd.h>
void serviceroom();
void add();  
void list();
void edit();  
void delete1();
void search();
void loader(void);
char speak_input();
char put();
char time();
int output(int);
char drinks();
char input();

void login()
{

	int a=0,i=0;
    char uname[10];
    char  c =' ';
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="pass";
   // c=sizeof(pass);
    do
{
	//system("cls");

     
    printf("\n  **************************  LOGIN FORM  **************************  ");
    printf(" \n                       ENTER USERNAME:-");
	scanf("%s", &uname);
	printf(" \n                       ENTER PASSWORD:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) 
		break;
	    else
		 printf("*");
	    i++;
	}
	pword[i]='\0';

	i=0;

		if(strcmp(uname,user)==0 && strcmp(pword,pass)==0)
	{
			 printf("\n\n\n");
			 	loader();
			 	printf("\n\n");
			 for(i=0;i<40;i++)
		printf("-");
	
	printf(" WELCOME !!!! LOGIN IS SUCCESSFUL");
	 for(i=0;i<40;i++)
		printf("-");
     getch();
	break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;

		getch();

	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");

		getch();

		}
		system("cls");
}
struct data{                                //STRUCTURE DECLARATION
 char i[20],q[20],c[12],Q,m[100];
 int amount,n,qr;
};

struct drink{
int quantity,total,n,k[5],q;
char name_of_drink[20];
};

struct CustomerDetails   
{
	char roomnumber[10];
	char name[20];
	char address[25];
	char phonenumber[15];
	char nationality[15];
	char email[20];
	char period[10];
	char arrivaldate[10];
}s,q;

int main(){     // MAIN FUNCTION
	int i=0;
char q;

	char w;
	int day;
	float single=2500.00;
	float doubl=50000.00;
	float lux=10000.0;
	char customername;
	char choice;
    login();
    system("cls");
	while (1)      
	{
		system("cls");
	
		
		printf("\n\n\t");
		put();
		printf("     ********************************  |MAIN MENU|  ******************************* \n");
		for(i=0;i<40;i++)
		printf("-");
		printf("\n");
		//setcolor(10);
		printf("\n\t\t\t *Please enter your choice for menu*:");
		printf("\n\n");
		printf(" \n Enter 1 -> Book a room");
		printf("\n------------------------");
		printf(" \n Enter 2 -> View Customer Record");
		printf("\n----------------------------------");
		printf(" \n Enter 3 -> Delete Customer Record");
		printf("\n-----------------------------------");
		printf(" \n Enter 4 -> Search Customer Record");
		printf("\n-----------------------------------");
		printf(" \n Enter 5 -> Edit Record");
		printf("\n-----------------------");
		printf(" \n Enter 6 -> room service ");
		printf("\n-----------------");
		printf(" \n Enter 7 -> Exit ");
		printf("\n-----------------");
		printf("\n");
		for(i=0;i<40;i++)
		printf("-");
	   
	    for(i=0;i<40;i++)
		printf("-");

		choice=getche();
		choice=toupper(choice);
		switch(choice)           // SWITCH STATEMENT
		{
			case '1':
				
				system("cls");
			
			     printf("\nin which catigre of room  you want ");
				 printf(" \n Enter s -> SINGLE BED ROOM        price per day =%.f",single);
	     	     printf("\n--------------------------------------------------------");
	    	     printf(" \n Enter d -> DOUBLE BED ROOM        price per day =%.f",doubl);
		         printf("\n--------------------------------------------------------");
		         printf(" \n Enter l -> LUXURY ROOM               price per day =%.f",lux);
	           	 printf("\n--------------------------------------------------------"); 
	           	 w=getche();
	           	 
	           	 switch(w){
	           	 	case 's':{
	           	 			printf("\nhow many days you stay ");
	           	 			scanf("%d",&day);
	           	 		   single=single*day;
	           	 		   printf("\nyour total bill is: %.2f",single);
	           	 		   getch();
	           	 		   	add();
	           	 		   	
	           	 		   
							break;
						}
					case 'd':{
						printf("\nhow many days you stay ");
	           	 			scanf("%d",&day);
	           	 		   doubl=doubl*day;
	           	 		   printf("\nyour total bill is: %.2f",doubl);
	           	 		   getch();
						add();
						break;
					}
					case 'l':{
						printf("\nhow many days you stay ");
	           	 			scanf("%d",&day);
	           	 		   lux=lux*day;
	           	 		   printf("\nyour total bill is: %.2f",lux);
	           	 		   getch();
						 add();
						break;
					}	
					}

				break;
			case '2':{
				
			
				list();
				break;
			}
			case '3':{
					delete1();
				break;
			}
				
			case '4':{
					search();
				break;
			}
				
				
			case '5':{
					edit();
				break;
			}
				
			
				
			case '6':{
				serviceroom();
				break;
			}	
			case '7':
				system("cls");
			//	getch();
				printf("\n\n\t *****THANK YOU*****");
				printf("\n\t FOR TRUSTING OUR SERVICE");
			  	break;
				exit(0);
			
			
			default:
			system("cls");
				printf("Incorrect Input");
				printf("\n Press any key to continue");
				getch();
		}
	}
}

void add()
{    int i;
	FILE *f;
	int j=1;
	char test;
	f=fopen("add.dox","ab+");
	if(f==NULL)
	{   f=fopen("add.dox","wb+");
		system("cls");
		printf("Please hold on while we set our database in your computer!!");
		printf("\n Process completed press any key to continue!! ");
		getch();
	}

	while(1)
	{
		system("cls");
		try1:
		printf("\n Enter Customer Details:");
		printf("\n**************************");
		fflush(stdin);
		printf("\n Enter Room number:\n");
	         scanf("%s",&s.roomnumber);
		for(i=0;i<sizeof(s.roomnumber);i++){

	   while(( fread(&q,sizeof(struct CustomerDetails),1,f)!=0)){
	   	if(strcmpi(q.roomnumber,s.roomnumber)==0){
		   		printf("ERROR THIS IS ROOM IS ALREADY ALLOCATED TO SOMEONE : ");
	//	goto try1;
	    printf("\n Enter Room number:\n");
	      scanf("%s",&s.roomnumber);
			if(strcmpi(q.roomnumber,s.roomnumber)==0){
		   		printf("ERROR THIS IS ROOM IS ALREADY ALLOCATED TO SOMEONE : ");
			   fflush(stdin);
			   	goto try1;
			   break;}
			   }
			   else{
			   	continue;
			   }
			    }}
		fflush(stdin);
		printf("\nEnter Name:\n");
		gets(s.name);
		printf("\nEnter Address:\n");
		gets(s.address);
		printf("\nEnter Phone Number:\n");
		gets(s.phonenumber);
		printf("\nEnter Nationality:\n");
    	gets(s.nationality);
		printf("Enter Email:\n");
		gets(s.email);
		printf("Enter Period(\'x\'days):\n");
		gets(s.period);
		printf("Enter Arrival date(dd\\mm\\yyyy):\n");
		gets(s.arrivaldate);
		fwrite(&s,sizeof(struct CustomerDetails),1,f);
		fflush(stdin);
		 printf(" time :%s",s.period);
		printf("\n\n1 Room is successfully booked!!");
		printf("\n Press esc key to exit,  any other key to add another customer detail:");
		test=getche();
		if(test==27)
			break;
 
	}
	//fprintf(f,"\n");
	fclose(f);

}

void list()
{
	FILE *f;
	int i;struct CustomerDetails x;
	f=fopen("add.dox","rb");
	system("cls");
	printf("\nROOM   ");
	printf("  NAME\t ");
	printf("ADDRESS\t  ");
	printf("PHONENUMBER\t   ");
	printf("NATIONALITY\t    ");
	printf("\tEMAIL \t        ");
	printf(" PERIOD \t       ");
	printf("ARRIVALDATE\t\n");

	for(i=0;i<118;i++)
		printf("-");
		printf("\n");
		rewind(f);
while(fread(&x,sizeof(struct CustomerDetails),1,f)!=0){
	   printf("%s ",x.roomnumber);
		printf("   %s\t   ",x.name);
		printf("%s\t  ",x.address);
		printf("%s\t    ",x.phonenumber);
		printf("%s\t    ",x.nationality);
		printf("%s\t     ",x.email);
		printf("%s\t\t   ",x.period);
		printf("%s\t\t\t     \n",x.arrivaldate);
		 
	
//	printf("\n");
}
	for(i=0;i<118;i++)
		printf("-");

	fclose(f);
	getch();
}

void delete1()
{
	struct CustomerDetails y;
	FILE *f,*t;
	int i=1;
	char room[20];
	if((t=fopen("temp.dox","wb"))==NULL)
	exit(0);
	if((f=fopen("add.dox","rb"))==NULL)
	exit(0);
	system("cls");
	printf("\nEnter the Room Number of the hotel to be deleted from the database: \n");
	fflush(stdin);
	scanf("%s",room);
	while(fread(&y,sizeof(struct CustomerDetails),1,f)!=0)
	{
		if(strcmp(y.roomnumber,room)==0)
		{       i=0;
			continue;
		}
		else
			fwrite(&y,sizeof(struct CustomerDetails),1,t);
	}
	if(i==1)
	{
		printf("\n\n Records of Customer in this  Room number is not found!!");
	
		getch();
		fclose(f);
		fclose(t);
	
	}else
	
	fclose(f);
	fclose(t);
	remove("add.dox");
	rename("temp.dox","add.dox");
	printf("\n\nThe Customer is successfully removed....");
	fclose(f);
	fclose(t);
	getch();
}

void search()
{
    system("cls");
	FILE *f;
	char room[10];
	char nam[20];
	int flag=1;
	char ch;
	fflush(stdin);
	printf("Enter 'r/R' from Room number of the customer to search its details: \n");
	printf(" Enter 'n/N' name of the customer to search its details \n");
	fflush(stdin);
	scanf("%c",&ch);
	switch(ch){
	      case 'R':
		  case 'r':{
		  	printf("Enter Room number of the customer to search its details: \n");
		  		scanf("%s", &room);
			break;
		  }
		 case 'N':
		 case 'n':{
		 	printf("Enter name of the customer to search its details \n");
		 	  scanf("%s",&nam);
			break;
		 }} 
		 
	f=fopen("add.dox","rb+");
     	if(f==0)
    	exit(0);

    
	while(fread(&s,sizeof(s),1,f)!=0)
	{ //printf("%s,",room);
		if(strcmp(s.roomnumber,room)==0||(strcmp(s.name,nam))==0){
			flag=0;
			printf("\n\tRecord Found\n ");
			printf("\nRoom Number:\t%s",s.roomnumber);
			printf("\nName:\t%s",s.name);
			printf("\nAddress:\t%s",s.address);
			printf("\nPhone number:\t%s",s.phonenumber);
			printf("\nNationality:\t%s",s.nationality);
			printf("\nEmail:\t%s",s.email);
			printf("\nPeriod:\t%s",s.period);
			printf("\nArrival date:\t%s",s.arrivaldate);
			flag=0;
			break;
		}
	}
	if(flag==1){
		printf("\n\tRequested Customer could not be found!");
	}
	getch();
	fclose(f);
}

void edit()
{
	FILE *f,*f2;
	int k=1;
	char room[20];

long int size=sizeof(s);
	
    	if((f2=fopen("myfile.dox","wb"))==NULL)
	    exit(0);
		if((f=fopen("add.dox","rb+"))==NULL)
		exit(0);

		system("cls");
   	printf("Enter Room number of the customer to edit:\n\n");
	scanf("%s",&room);
	fflush(stdin);

	struct CustomerDetails s1;
	while(fread(&s,sizeof(s ),1,f)==1)
{  
		if(strcmp(s.roomnumber,room)==0)
		{
	
	     
				 k=0;
			printf("\nEnter Room Number     :");
			gets(s.roomnumber);
			printf("\nEnter Name    :");
			fflush(stdin);
			gets(s.name);
			printf("\nEnter Address        :");
			gets(s.address);
			printf("\nEnter Phone number :");
			gets(s.phonenumber);
			printf("\nEnter Nationality :");
			gets(s.nationality);
			printf("\nEnter Email :");
			gets(s.email);
			printf("\nEnter Period :");
			gets(s.period);
			printf("\nEnter Arrival date :");
			gets(s.arrivaldate);
//			fseek(f,size,SEEK_CUR);  //to go to desired position infile
		fwrite(&s,sizeof(s),1,f2);
		}else{
			fwrite(&s,sizeof(s),1,f2);
			}
				
		
//			
		
		  
	}
		  

	
	       
    	if(k==1){
		printf("\n\nTHE RECORD DOESN'T EXIST!!!!");
		
	
		fclose(f);
			fclose(f2);
			getch();
			main(); 
		
	}
	
     fclose(f);
	 fclose(f2);
	remove("add.dox");
	rename("myfile.dox","add.dox");
	printf("\n\n\t\tYOUR RECORD IS SUCCESSFULLY EDITED!!!");
	getch();


}
void serviceroom()
{

int q,nus,total,b,p,f,s,n=0,l[5],j;

//char z[20],w[]="fast food",y[]="meal",d[]="drinks";

char burger='b';

char pizza ='p';

char  franchfrice='f';

char sandwich='s';

char choice,choice1,choice2,choice3,choice4;
speak_input();
printf(" \n***************WELCOME TO THAR PARKAR HOTEL*************************\n\n");
printf("|*********************************************************************  |\n");
printf("|                              HOTEL MENU                               |\n");
printf("|***********************************************************************|\n");
printf("|    FAST FOOD                      |          MEAL                     |\n");
printf("|***********************************************************************|\n");
printf("|    1-burger                       |          1-chiken karahi          |\n");
printf("|***********************************************************************|\n");
printf("|    2-pizza                        |          2-chiken handi           |\n");
printf("|***********************************************************************|\n");
printf("|    3-french fries                 |          3-achar gosht            |\n");
printf("|***********************************************************************|\n");
printf("|    4-sandwitch                    |          4-gravi handi            |\n");
printf("|***********************************************************************|\n");
printf("|   ($RIFRESMENT$)                  |          5-mutton white handi     |\n");
printf("|***********************************************************************|\n");
printf("|    1-coke                         |          6-achar gosht            |\n");
printf("|***********************************************************************|\n");
printf("|    2-sprite                       |          7-panner handi           |\n");
printf("|***********************************************************************|\n");
printf("|    3-banana shake                 |          8-panner white handi     |\n");
printf("|***********************************************************************|\n");
printf("|    4-strawberry shake             |          9-plan roti              |\n");
printf("|***********************************************************************|\n");
printf("|    5-orange juice                 |           10-garlic naan          |\n");
printf("|***********************************************************************|\n");
printf("|    6-date juice                   |           10-garlic naan          |\n");
printf("|***********************************************************************|\n");
printf("what do you want to order \n *1-fast food \n *2-meal\n *3-drinks \n");
scanf("%d",&j);
if(j==1){
printf("please select from the following menu \n B=burger \n p=pizza \n f=french fries \n s=sandwitch");
printf("\nenter number of snack you want to order");
scanf("%d",&nus);
switch(nus)
{
case 1:
	printf("please enter snack you want to order"); 
    scanf(" %c",&(choice));
    printf("enter quantity=");
    scanf(" %d",&q);

    	          printf("                 RECIPT\n");
	          printf("-----------------------------------------------\n");
				time();	
	printf("\n\nyou have ordered !\n");
	switch(choice)
	{
	case 'b':
		total=q*200;
		printf("%d  burger(s) your total bill is %dpkr",q,total);
		break;
	case 'p':
    total=q*500;
		printf("%d pizza(s) your total bill is %dpkr",q,total);
	    break;
	case 'f':
	     total=q*50;
		printf("%d franchfries(s) your total bill is %d pkr",q,total);
        break;	
	
	case 's':
	     total=q*150;
		printf("%d fandwich(s) your total bill is %dpkr",q,total);
        break;
        sleep(3);
	}
	break;
	case 2:
     	printf("please 1 enter snack you want to order="); 
         scanf(" %c",&choice1);
         printf("enter quantity=");
         scanf(" %d",&q);
        	printf("please 2 enter snack you want to order="); 
         scanf(" %c",&choice);
         printf("enter quantity=");
         scanf(" %d",&q);
         if(choice1=='b'&&choice=='p'||choice1=='p'&&choice=='b'){
         	     printf("                 RECIPT\n");
	          printf("-----------------------------------------------\n");
			    time();	
                     //speak();
		 	      printf("\nyou ordered!");
	      printf("\n%d burger(s) your total bill is %d pkr",q,b=q*200);
		  printf("\n%d pizza(s) your total bill is %d pkr",q,p=q*500);
	     printf("\nvalue %dpkr",total=b+p);
		 sleep(3);
		 }
	     else if(choice1=='b'&&choice=='f'||choice1=='f'&&choice=='b'){
		 
	           	            printf("                 RECIPT\n");
	          printf("-----------------------------------------------\n");
         				time();	
//                  speak();
	      printf("\nyou ordered!");
	      printf("\n  %d burger(s) your total bill is %d pkr",q,b=q*200);
	    printf("\n    %d franchfries(s) your total bill is %d pkr",q,f=q*50); 
	     printf("\nvalue %dpkr",total=f+b);
		 sleep(3);}
	     else if(choice1=='b'&&choice=='s'||choice1=='s'&&choice=='b'){
		  printf("                 RECIPT\n");
	     printf("----------------------------------------------\n");
		  time();
//              speak();
	      printf("\nyou ordered!");
	      printf("\n %d burger(s) your total bill is %dpkr",q,b=q*200);
	    printf("\n   %d sandwich(s) your total bill is %dpkr",q,s=q*150); 
	    // loader();
		 printf("\nyour total bill is %dpkr",total=s+b);
		 sleep(3);}
	     
         
      else if(choice1=='p'&&choice=='f'||choice1=='f'&&choice=='p'){
		     
		  printf("                 RECIPT\n");
	     printf("-----------------------------------------------\n");
		  time();
//              speak();
	      printf("\nyou ordered!");
	      printf("\n %d  pizza(s)your total bill is %dpkr",q,p=q*500);
	      
	    printf("\n   %d  franchfries(s)your total bill is %dpkr",q,f=q*50); 
		 printf("\nvalue %dpkr",total=f+p);
		          sleep(3);
		 }
	     else if(choice1=='p'&&choice=='s'||choice1=='s'&&choice=='p'){
		 

	        printf("                 RECIPT\n");
	     printf("-----------------------------------------------\n");
		  time();
//	          speak();
	      printf("\nyou ordered!");
	      printf("\n%d    pizza(s) your total bill is %d pkr",q,p=q*500);
	    printf("\n  %d    sandwich(s)your total bill is %d pkr",q,s=q*150); 
	     loader();
		 printf("\nyour total bill is %dpkr",total=s+p);
		 sleep(3);} 
       else if(choice1=='f'&&choice=='s'||choice1=='s'&&choice=='f'){
		 
	     
	            printf("                 RECIPT\n");
	          printf("-----------------------------------------------\n");
				time();
//				    speak();	
		  printf("\nyou ordered!");
	      printf("\n %d   sandwich(s) your total bill is   %dpkr",q,s=q*150);
	    printf("\n %d   franchfries(s) your total bill is  %dpkr",q,f=q*50); 
	     loader();
		 printf("\nyour total bill is %dpkr",total=f+s);
		 sleep(3);} 
	     break;
	
         case 3:
         printf("please 1 enter snack you want to order="); 
         scanf(" %c",&choice1);
         printf("enter quantity=");
         scanf(" %d",&q);
			printf("please 2 enter snack you want to order="); 
         scanf(" %c",&choice);
         printf("enter quantity=");
         scanf(" %d",&q);
         	printf("please 3 enter snack you want to order="); 
         scanf(" %c",&choice2);
         printf("enter quantity=");
         scanf(" %d",&q);
         if((choice1=='b'&&choice=='p'&&choice2=='f')||(choice1=='b'&&choice=='f'&&choice2=='p'||choice1=='p'&&choice=='f'&&choice2=='b'||choice1=='p'&&choice=='b'&&choice2=='f'||choice1=='f'&&choice=='p'&&choice2=='b'||choice1=='f'&&choice=='b'&&choice2=='p')){
          	     printf("                 RECIPT\n");
	          printf("-----------------------------------------------\n");
				time();	
//                speak();
	      printf("\nyou ordered!");
	    printf("\n%d   franchfries(s) your total bill is %dpkr",q,f=q*50);
		  printf("\n%d burger(s) your total bill is %dpkr",q,b=q*200);
	    printf("\n%d   pizza(s) your total bill is %dpkr",q,p=q*500);
	     loader();
		 printf("\n your total bill is %dpkr",total=b+p+f);
		 sleep(3);}
	
	     else if(choice1=='b'&&choice=='s'&&choice2=='p'||choice1=='b'&&choice=='p'&&choice2=='s'||choice1=='p'&&choice=='b'&&choice2=='s'||choice1=='p'&&choice=='s'&&choice2=='b'||choice1=='s'&&choice=='b'&&choice2=='p'||choice1=='s'&&choice=='p'&&choice2=='b'){
		        printf("                 RECIPT\n");
	          printf("-----------------------------------------------\n");
			    time();	
//                    speak();
	       	      printf("\nyou ordered!");
	      printf("\n%d burger(s) your total bill is %dpkr",q,b=q*200);
	    printf("\n%d   sandwich(s) your total bill is %dpkr",q,s=q*150); 
	    printf("\n%d   pizza(s) your total bill is %dpkr",q,p=q*500);
		 printf("\nvalue %dpkr",total=s+b+p);
		 sleep(3);}
		  else if(choice1=='b'&&choice=='s'&&choice2=='f'||choice1=='b'&&choice=='f'&&choice2=='s'||choice1=='f'&&choice=='s'&&choice2=='b'||choice1=='f'&&choice=='b'&&choice2=='s'||choice1=='s'&&choice=='b'&&choice2=='f'||choice1=='s'&&choice=='f'&&choice2=='b'){
		 
	       	      printf("                 RECIPT\n");
	          printf("-----------------------------------------------\n");
                getch();
				time();	
//                  speak();
	      printf("\nyou ordered!");
	      printf("\n%d burger(s) your total bill is %dpkr",q,b=q*200);
	    printf("\n%d sandwich(s) your total bill is %dpkr",q,s=q*150); 
	    printf("\n%d franchfries(s)your total bill is %dpkr",q,f=q*50);
		 loader();
		 printf("\nyour total bill is %dpkr",total=s+b+f);
		  sleep(3);
		  } 
         break;
         case 4:
         	
			 printf("enter the 1 snacks which you want to order ");
         	  scanf(" %c",&choice);
         	switch(choice)
         	{
			case 'b' ... 's':
         	 printf("please again 1 enter snack you want to order="); 
         scanf(" %c",&choice1);
         printf("enter quantity=");
         scanf(" %d",&q);
			printf("please 2 enter snack you want to order="); 
         scanf(" %c",&choice4);
         printf("enter quantity=");
         scanf(" %d",&q);
         	printf("please 3 enter snack you want to order="); 
         scanf(" %c",&choice2);
         printf("enter quantity=");
         scanf(" %d",&q);
              	printf("please 4 enter snack you want to order="); 
         scanf(" %c",&choice3);
         printf("enter quantity=");
         scanf(" %d",&q);
           	     printf("                 RECIPT\n");
	          printf("-----------------------------------------------\n");
			    time();	
//                     speak();
	      printf("\nyou ordered!");
	      printf("\n%d burger(s) your total bill is %dpkr",q,b=q*200);
	      printf("\n%d pizza(s)  your total bill is %dpkr",q,p=q*500);
	     printf("\n%d  sandwich(s) your total bill is %dpkr",q,s=q*150); 
	     printf("\n%d  franchfries(s) your total bill is %dpkr",q,f=q*50);
	     loader();
		 printf("\nvalue %dpkr",total=s+b+f+p);
		  sleep(3);
		  } 
         break;
         }
	 }
	 else
	   if(j==2){
      input();
  }
  else 
       if(j==3){
	    drinks();
	   }
	   //return(0);
}
char input(){
	struct data l;
	int i;
	l.amount=0;
printf("enter the karahi or handi you want to order in given menu \n");
printf("***************************************************************\n");
printf("\n * 1-chiken karahi full 1000 half 500\n * 2-chiken handi full 1200 half 600\n * 3-achar gosht full 1200 half 600\n * 4-gravi handi full 1200 half 600\n * 5-mutton white handi full 2000 half 1000\n * 6-nihari handi full 1500 half 750\n* 7-panner handi full 1200 half 600\n* 8-panner white handi full 1800 half 900\n* 9-plan roti=100\n* 10-garlic naan=140\n");
printf("***************************************************************\n");

printf("enter the number of thing you want to order==>");
scanf("%d",&l.n);
loader();
fflush(stdin);
for(i=0;i<l.n;i++){
printf("enter the %d thing==>",i+1);
gets(l.i);
strcpy(l.m,l.i);
l.c[0]=strcmp(l.i,"chicken karahi");
if(l.c[0]==0){
printf("enter the quantity of chicken karahi==>");
gets(l.q);
l.Q=strcmp(l.q,"full");
if(l.Q==0){
l.amount=l.amount+1000;
}
else
l.amount=l.amount+500;
}
else if(l.c[0]!=0){
l.c[1]=strcmp(l.i,"chicken handi");
if(l.c[1]==0){
printf("enter the quantity of chicken handi==>");
gets(l.q);
l.Q=strcmp(l.q,"full");
if(l.Q==0){
l.amount=l.amount+1200;
}
else
l.amount=l.amount+600;
}
else if(l.c[1]!=0){
l.c[2]=strcmp(l.i,"achar gosht");
if(l.c[2]==0){
printf("enter the quantity of achar gosht==>");
gets(l.q);
l.Q=strcmp(l.q,"full");
if(l.Q==0){
l.amount=l.amount+1201; 
}
else
l.amount=l.amount+601;
}
else if(l.c[2]!=0){
l.c[3]=strcmp(l.i,"gravi handi");
if(l.c[3]==0){
printf("enter the quantity of gravi handi==>");
gets(l.q);
l.Q=strcmp(l.q,"full");
if(l.Q==0){
l.amount=l.amount+1201;
}
else
l.amount=l.amount+601;
}
else if(l.c[3]!=0){
l.c[4]=strcmp(l.i,"mutton white handi");
if(l.c[4]==0){
printf("enter the quantity of mutton white handi==>");
gets(l.q);
l.Q=strcmp(l.q,"full");
if(l.Q==0){
l.amount=l.amount+2001;
}
else
l.amount=l.amount+1000;
}
else if(l.c[4]!=0){
l.c[5]=strcmp(l.i,"nihari handi");
if(l.c[5]==0){
printf("enter the quantity of nihari handi full or half");
gets(l.q);
l.Q=strcmp(l.q,"full");
if(l.Q==0){
l.amount=l.amount+1500;
}
else
l.amount=l.amount+750;
}
else if(l.c[5]!=0){
l.c[6]=strcmp(l.i,"panner handi");
if(l.c[6]==0){
printf("enter the quantity of  panner handi full or half==>");
gets(l.q);
l.Q=strcmp(l.q,"full");
if(l.Q==0){
l.amount=l.amount+1201;
}
else
l.amount=l.amount+600;
}
else if(l.c[6]!=0){
l.c[7]=strcmp(l.i,"panner white handi");
if(l.c[7]==0){
printf("enter the quantity of  panner handi full or half==>");
gets(l.q);
l.Q=strcmp(l.q,"full");
if(l.Q==0){
l.amount=l.amount+1800;
}
else
l.amount=l.amount+900;
}
else if(l.c[7]!=0){
l.c[8]=strcmp(l.i,"plan roti");
if(l.c[8]==0){
printf("enter the quantity of  plan roti==>");
scanf("%d",&l.qr);
l.amount=l.amount+(100*l.qr);
}
else if(l.c[8]!=0){
l.c[8]=strcmp(l.i,"garlic naan");
if(l.c[9]==0){
printf("enter the quantity of garlic naan==>");
scanf("%d",&l.qr);
l.amount=l.amount+(140*l.qr);
}
}
}
}
}
}
}
}
}
}
}
  output(l.amount);
}
int output(int total){
	    int i;
		          printf("                 RECIPT\n");
	         printf("-----------------------------------------------\n");
                getch();
				time();	
            //ak(spe);
printf("\n\nyour total bill is %d",total);
}
char drinks(){
	struct drink d;
	printf("@*@*@*@*@*@*@*@*@*@*@*@*@*@*@*@*@*@*@*@*@*@*@*@*@*@*@*@");
	printf("\n@* 1-coke\n@* 2-sprite\n@* 3-banana shake\n@* 4-strawberry shake\n@* 5-orange juice\n@* 6-date juice");
	printf("\n@*@*@*@*@*@*@*@*@*@*@*@*@*@*@*@*@*@*@*@*@*@*@*@*@*@*@*@");
int i;
printf("\nenter number of drinks you want to order");
scanf("%d",&d.n);
for(i=0;i<d.n;i++){
printf("enter the %d drink",i);
fflush(stdin);
gets(d.name_of_drink);
d.k[0]=strcmp(d.name_of_drink,"coke");
if(d.k[0]==0){
printf("enter the quantity of drinks");
scanf("%d",&d.q);
d.total=d.q*60;
}
else
 if(d.k[0]!=0){
 d.k[1]=strcmp(d.name_of_drink,"sprite");
if(d.k[1]==0){
printf("enter the quantity of drinks");
scanf("%d",&d.q);
d.total=d.q*60;
} 
 else
 if(d.k[1]!=0){
 d.k[2]=strcmp(d.name_of_drink,"banana shake");
if(d.k[2]==0){
printf("enter the quantity of juice");
scanf("%d",&d.q);
d.total=d.q*150;
}
 else
 if(d.k[2]!=0){
 d.k[3]=strcmp(d.name_of_drink,"strawberry shake");
if(d.k[3]==0){
printf("enter the quantity of juice");
scanf("%d",&d.q);
d.total=d.q*250;
}
 else
 if(d.k[3]!=0){
 d.k[4]=strcmp(d.name_of_drink,"orange juice");
if(d.k[4]==0){
printf("enter the quantity of juice");
scanf("%d",&d.q);
d.total=d.q*200;
}
if(d.k[4]!=0){
 d.k[5]=strcmp(d.name_of_drink,"date juice");
if(d.k[5]==0){
printf("enter the quantity of juice");
scanf("%d",&d.q);
d.total=d.q*300;
 }
}
}
}
}
}
}
//speak();
printf("                 RECIPT\n");
	         printf("-----------------------------------------------\n");
                time();	
printf("\n\nyour total bill is %d",d.total);
sleep(3);
}





void loader(){
int i;
//system("cls");

printf("\n\n\n\n\n\n\n\t\t\tplease wait loading...");
 for(i=0;i<3;i++){
	 sleep(1);
 printf("%c",219);
  system("cls");
 }
}

char time(){ 
     printf("date :        %s              time:           %s",__DATE__,__TIME__);
}
   char speak_input(){
char call[100]="what  do  you  want  to  order  from  this  menu";
     char think[100];
     strcpy(think,"espeak \"");
     strcat(think,call);
      strcat(think,"\"");
      system(think);
}
char put(){
  char a[100]="WELCOME  TO  THAR   PARKAR   HOTEL";
     char b[100];
     strcpy(b,"espeak \"");
     strcat(b,a);
      strcat(b,"\"");
      system(b);
}  
  
