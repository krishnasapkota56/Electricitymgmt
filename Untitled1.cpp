#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct date
{
int day;
int month;
int year;
}d1,d2;
struct details
{
	char name[20];
	char address[20];
	int meterno;
	int currentunit;
	int previousunit;
	float energycharge;
	float totalamount;
}obj;
void addrecords();
void viewrecords();
void modifyrecords();
void deleterecords();
void searchrecords();
void payment();
void bill();
void totalamount();
int main()
{
	int i,choice;
	printf("*******Welcome to Electricity Management System******");
	do{
		printf("\n\tHow may i help you?");
		printf("\n1.\tAdd Customers details.");
		printf("\n2.\tView Customers details.");
		printf("\n3.\tModify Records of Customers");
		printf("\n4.\tDelete Records of Customers");
		printf("\n5.\tSearch Records of Customers");
		printf("\n6.\tMake bill of Customer");
		printf("\n7.\tPayment By Customer");
		printf("\n8.\tView total amount Collected in a date");
		printf("\n9.\tQuit");
		printf("\n\n\tEnter what you want to do?");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				addrecords();
				break;
				case 2:
					viewrecords();
					break;
					case 3:
						modifyrecords();
						break;
						case 4:
						deleterecords();
						break;
						case 5:
							searchrecords();
							break;
							case 6:
								bill();
								break;
								case 7:
									payment();
									break;
									case 8:
										totalamount();
										break;
										case 9:
											printf("\n\n\t\t\t\tTHANK YOU");
											printf("\n\n\t\t\t\tFOR USING OUR SERVICE");
											exit(0);
											break;
											default:
											printf("Incorrect Input");
											printf("\nAny key to continue");
											getch();
		}
		printf("Do you want to continue?");
	}while(choice!=9);
getch();
return 0;
}
void addrecords()
{	
	FILE *f;
	char test;
	f=fopen("electricity.txt","ab+");
	if(f==0)
	{   f=fopen("electricity.txt","wb+");
		system("cls");
		printf("please wait while we configure your computer");
		printf("/npress any key to continue");
		getch();
	}
	while(1)
	{
		printf("\n Name:");
		scanf("%s",&obj.name);
		printf("\n Address:");
		scanf("%s",&obj.address);
		printf("\n Meter Number:");
		scanf("%d",&obj.meterno);
		fwrite(&obj,sizeof(obj),1,f);
		printf("1 record successfully added");
		printf("\n Press esc key to exit, any other key to add other record:");
		test=getche();
		if(test==27)
			break;
	}
	fclose(f);
}
void viewrecords()
{
	FILE *f;
	int i;
	if((f=fopen("electricity.txt","rb"))==NULL)
		exit(0);
	printf("Name\t\tAddress\t\t\tMeter Number\n");
	while(fread(&obj,sizeof(obj),1,f))
	{
		printf("\n\n%s\t\t%s\t\t%d",obj.name,obj.address,obj.meterno);
	}

fclose(f);
getch();
}
void modifyrecords()
{
FILE *f;
	int meterno;
	if((f=fopen("electricity.txt","rb+"))==NULL)
	exit(0);
	printf("Enter meter number of the customer to modify:");
	scanf("%d",&meterno);
	while(fread(&obj,sizeof(obj),1,f)==1)
	{ 
		if(obj.meterno==meterno)
		{
			printf("\n Enter Name:");
			scanf("%s",&obj.name);
			printf("\n Enter Address: ");
			scanf("%s",&obj.address);
			printf("\n Enter Meter Number: ");
			scanf("%d",&obj.meterno);
			fwrite(&obj,sizeof(obj),1,f);
			break;
		}
	}
	fclose(f);
}
void deleterecords()
{
	FILE *f,*t;
	int i=1;
	int meternumber;
	if((t=fopen("temp.txt","wb+"))==NULL)
	exit(0);
	if((f=fopen("electricity.txt","rb+"))==NULL)
	exit(0);
	printf("Enter the meter number to be deleted from the Database");
	scanf("%d",&meternumber);
	while(fread(&obj,sizeof(obj),1,f)==1)
	{
		if((obj.meterno,meternumber)==0)
		{       i=0;
			continue;

		}
		else
			fwrite(&obj,sizeof(obj),1,t);
	}
	if(i==1)
	{
		printf("Meter number \"%d\" not found",meternumber);
		remove("electricity.txt");
		rename("temp.txt","electricity.txt");
		getch();
		fclose(f);
		fclose(t);
		main();
	}
	remove("electricity.txt");
	rename("temp.txt","electricity.txt");
	printf("The Number %s Successfully Deleted!!!!",meternumber);
	fclose(f);
	fclose(t);
	getch();
}
void searchrecords()
{
		FILE *f;
	int meternumber;
	int flag=1;
	f=fopen("electricity.txt","rb+");
	if(f==0)
		exit(0);
	printf("Enter Meter Number to search in our database");
	scanf("%d",&meternumber);
	while(fread(&obj,sizeof(obj),1,f))
	{
		if((obj.meterno==meternumber))
		{	
			printf(" Record Found ");
			printf("\n\nName: %s\nAddress: %s\nMeter Number:%d\n",obj.name,obj.address,obj.meterno);
			flag=0;
			break;
		}
		else if(flag==1)
		{	
			printf("Requested Meter Number Not found in our database");
		}
	}
	getch();
	fclose(f);
}
void bill()
{
FILE *f;
	int meterno,consumedunit;
	int flag=1;
	if((f=fopen("electricity.txt","rb+"))==NULL)
		exit(0);
		printf("Enter Meternumber of whose you want to make bill");
		scanf("%d",&meterno);
		while(fread(&obj,sizeof(obj),1,f)==1)
		{
			if(obj.meterno==meterno)
			{	
			printf("Enter the date of meter reading");
			scanf("%d%d%d",&d1.day,&d1.month,&d1.year);
			printf("Enter current reading on meter");
			scanf("%d",&obj.currentunit);
			printf("\n\t NEPAL");
			printf("\n\t Electricity Authority");
			printf("\nName:",&obj.name);
			printf("\nAddress:",&obj.address);
			printf("\nMeter number:",&obj.meterno);
			printf("\nCurrent Unit:",obj.currentunit);
			printf("\nPrevious unit:",obj.previousunit);
			consumedunit=obj.currentunit-obj.previousunit;
			printf("\nConsumed unit=%d",&consumedunit);
		{
		if (consumedunit<=10)
		{
		obj.energycharge=consumedunit*5;
		}
		else if (consumedunit<=20)
		{
		obj.energycharge=50+((consumedunit-10)*8);	
		}
		else if (consumedunit<=30)
		{
		obj.energycharge=130+((consumedunit-30)*10);
		}
		else 
		obj.energycharge=230+((consumedunit-30)*15);
		}
		printf("energycharge=%d",&obj.energycharge);
			flag=0;
			break;
			obj.previousunit=obj.currentunit;
			fwrite(&obj,sizeof(obj),1,f);
		}
		else if(flag==1)
		{	
			printf("Requested Meter Number Not found in our database");
		}
		}
		printf("Pay Your Bill In Time");
		getch();
		fclose(f);
			
}
void payment()
{ 
printf("Enter today's date");
scanf("%d%d%d",&d2.day,&d2.month,&d2.year);
	FILE *f;
	int meterno;
	float fine,discount;
	long int size=sizeof(obj);
	if((f=fopen("electricity.txt","rb+"))==NULL)
		exit(0);
	printf("Enter meter number of the Customer for payment");
	scanf("%d",&meterno);
	while(fread(&obj,sizeof(obj),1,f)==1)
	{
		if((obj.meterno,meterno)==0)
		{
			printf("\n Name: %s",obj.name);
			printf("\n Address: %s",obj.address);
			printf("\n Current amount: %f",obj.energycharge);
			printf("\n");
			if ((d2.day<d1.day+20)&&(d2.month<d1.month)&&(d2.year<d1.year))
	 		fine=2/100*obj.energycharge;
	 		else
	 		fine=0;
	 		printf("\n\t Fine:%d",&fine);
	 		}
	 		{
	 		if ((d2.day<d1.day+7)&&(d2.month<d1.month)&&(d2.year<d1.year))
	 		discount=2/100*obj.energycharge;
	 		else 
	 		discount=0;
	 		printf("\n\tdiscount=%d",&discount);
	 		}
	 		obj.totalamount=obj.energycharge+fine-discount;
			fseek(f,-size,SEEK_CUR);
			fwrite(&obj,sizeof(obj),1,f);
			break;
		}
	printf("THANK YOU %s FOR YOUR TIMELY PAYMENTS",obj.name);
	getch();
	fclose(f);
}
void totalamount()
{
FILE *f,*t;
	int c,i;
	float amount;
	struct date
	{
		int day;
		int month;
		int year;
	}d;
	if((t=fopen("temp.txt","wb+"))==NULL)
	exit(0);
	if((f=fopen("electricity.txt","rb+"))==NULL)
	exit(0);
	printf("Enter the date of which date you want to see");
	scanf("%d/%d/%d",d.day,d.month,d.year);
	while(fread(&obj,sizeof(obj),1,f)==1)
	{
		if((d2.day==d.day)&&(d2.month==d.month)&&(d2.year==d.year)==0)
		{       i=0;
			continue;

		}
		else
	if(i==1)
	{
		c++;
		amount=amount+obj.totalamount;
		printf("Total Amount Collected=%f",amount);
		printf("Number of people paid in a day=%d",c);
		getch();
		fclose(f);
		fclose(t);
	}
}
}
