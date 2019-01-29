/*
	Author: Chanchal Kumar
	Email: ckgec98@gmail.com
*/
#include<stdio.h>
#include<stdlib.h> //because malloc() is used in the program
struct node
{
	char *partyName[10];
	struct node *link;
};

struct node *START=NULL;

struct node* createNode()
{
	struct node *n;
	n=(struct node *)malloc(sizeof(struct node));
	return(n);
}

void insertNode(char s1[10])
{
	struct node *temp,*t;
	temp=createNode();
	temp->partyName[10]=s1;
	temp->link=NULL;
       //	printf("%s",s1);
	if(START==NULL)
	{
		START=temp;
	}
	else
	{
		t=START;
		while(t->link!=NULL)
			t=t->link;
		t->link=temp;
	}
}

int checkParty(char s1[])
{
	struct node *temp;
	temp=START;
	while(temp!=NULL)
	{
		if(temp->partyName[10]==s1)
			return 1;
		temp=temp->link;
	}
	return 0;
}

int menu()
{
	int ch;
	printf("Welcome To Election 2019\n");
	printf("Vote among the following Parties:-\n");
	printf("1.BJP\n2.CONG.\n3.AAP\n4.NOTA(None Of The Above)\n");
	scanf("%d",&ch);
	return(ch);
}


void main()
{
	int voter=1,res,bjp=0,cong=0,aap=0,nota=0;
	while(voter==1)
	{
		clrscr();
		switch(menu())
		{
			case 1:
				if(checkParty("BJP"))
					bjp++;
				else
				{
					insertNode("BJP");
					bjp++;
				}
				break;
			case 2:
				if(checkParty("CONG"))
					cong++;
				else
				{
					insertNode("CONG");
					cong++;
				}
				break;
			case 3:
				if(checkParty("AAP"))
					aap++;
				else
				{
					insertNode("AAP");
					aap++;
				}
				break;
			case 4:
				if(checkParty("NOTA"))
					nota++;
				else
				{
					insertNode("NOTA");
					nota++;
				}
				break;
			default:
				printf("Wrong Choice\n");
		}
		if(menu()==1||2||3||4)
		{
		printf("THANKYOU! Your response is recorded\n");
		printf("Is there any other Voter Available?\n1.YES\n2.No,Display the result:\n");
		scanf("%d",&voter);
		}
	}
	if(voter==2)
	{
		printf("No.of votes given to BJP is %d\n",bjp);
		printf("No.of votes given to CONGRESS is %d\n",cong);
		printf("No.of votes given to AAP is %d\n",aap);
		printf("No.of votes given to NOTA is %d\n",nota);
		getch();
	}
}
