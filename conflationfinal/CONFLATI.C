#include<stdio.h>
#include<conio.h>
#include<string.h>
char stopwords[][8]={"i","big","am","m","a","we","are","it","of","this","and","is","to","at","in","was","with","doing","It","not","our"};
char suffixes[][8]={"able","ing","ion","y","ment"};
FILE *fp2;
typedef struct suffix   //structure for printing in file
{
	char stem[15];
	char term[15];
	int frequency;
	struct suffix *next;
}S;

typedef struct suff
{
	char stem[15];
	char term[15];
	int frequency;
}S1;


void suffixstripping(char word[15]);//for removing suffixes
void init(char p[15]);//for initialising structure
void freq();  //counting frequency,and removing common words
void main()
{

	char word[15],filename[30],buffer[300],ch=' ',*ptr;
	int i=0,j=0,m=0,flag=0,pos=0,ch1;
	FILE *fp,*fp1,*f;
	clrscr();


	printf("\n\n\nEnter file's name with extension:");
	flushall();
	gets(filename);
	fp=fopen(filename,"r");
	fp1=fopen("output1.txt","w");
	fp2=fopen("output2.txt","w");
	fprintf(fp2,"");
	fclose(fp2);

	//step1
	ptr=fgets(buffer,300,fp);

	while(ptr!=NULL)
	{
		init(word);

		while(buffer[j]!=(char)32 && buffer[j]!='\0')
		{

			word[i]=buffer[j];
			i++;
			j++;
		}
		if(word[i-1]=='.')
			i--;
		word[i]='\0';
		flag=0;
		for(m=0;m<21;m++)
		{
			if(strcmp(stopwords[m],word)==0)
			{
				flag=1;
				break;
			}
		}

		if(flag!=1 && strcmp(NULL,word))
		{
			fprintf(fp1,"%s",word);
			fprintf(fp1,"\n");
			//step 2
			suffixstripping(word);
		}
		i=0;
		if(buffer[j]==' ')
			j++;
		if(buffer[j]=='\0')
		{
			ptr=fgets(buffer,300,fp);
			j=0;
		}
	}

//step3
	freq();
	printf("\n\n\n\n it was success!");
	fcloseall();

	while(1)
	{
		printf("\n\n1.After removing stopwords \n2.After removing suffixes \n3.After counting frequency \n4.Exit");
		printf("\nEnter your choice:");
		scanf("%d",&ch1);
		switch(ch1)
		{
			case 1:
					printf("\n");
					f=fopen("output1.txt","r");
					ch=fgetc(f);
					while(ch!=EOF)
					{
						if(ch==" ")
							printf(" ");
						else if(ch=="\n")
							printf("\n");
						else
							printf("%c",ch);
						ch=fgetc(f);
					}
					fclose(f);
					break;

			case 2:
					printf("\n");
					f=fopen("output2.txt","r");
					ch=fgetc(f);
					while(ch!=EOF)
					{
						if(ch==" ")
							printf(" ");
						else if(ch=="\n")
							printf("\n");
						else
							printf("%c",ch);
						ch=fgetc(f);
					}
					fclose(f);
					break;

	   case 3:
					printf("\n");
					f=fopen("output3.txt","r");
					ch=fgetc(f);
					while(ch!=EOF)
					{
						if(ch==" ")
							printf(" ");
						else if(ch=='\n')
							printf("\n");
						else
							printf("%c",ch);
						ch=fgetc(f);
					}
				fclose(f);
				break;

	   case 4:	exit(0);
		}
	}

getch();
}

void suffixstripping(char word[15])
{

	char temp[15],temp1[15],word1[15],*t1,*t2;
	int i=0,len=0,len1=0,len2=0,ch=-1;
	S *s1;

	fp2=fopen("output2.txt","a");
	s1=(S*)malloc(sizeof(S));
	s1->frequency=48;
	s1->next=NULL;
	init(s1->stem);
	init(s1->term);
	init(temp1);
	init(temp);
	strcpy(temp1,word);
	strcpy(temp,word);
	t1=temp;
	t2=temp1;

	for(i=0;i<5;i++)
	{
		t1=temp;
		len=strlen(suffixes[i]);
		len1=strlen(temp);
		len2=len1-len;
		t1=t1+len2;

		if(strcmp(suffixes[i],t1)==0)
		{
			ch=i;
			break;
		}
	}

	switch(ch)
	{
		case 0:  //able
				*(t2+len2)='\0';
				if(strlen(temp1)>2 && temp1[strlen(temp1)-1]!='q')
				{
					strcpy(s1->stem,temp1);
					strcpy(s1->term,word);
					s1->frequency=49;

				}
				else
				{
					strcpy(s1->stem,word);
					strcpy(s1->term,word);
					s1->frequency=49;

				}

		break;

		case 1:        //ing

				*(t2+len2)='\0';
				if(strlen(temp1)>2 && temp1[strlen(temp1)-1]!='q')
				{
					t2=t2+strlen(temp1)-2;

					if(strcmp(t2,"at")==0 || strcmp(t2,"as")==0)
					{
						*(t2+2)='e';
						*(t2+3)='\0';

					}

					if(strcmp(t2,"bl")==0)
					{

						*(t2+2)='e';
						*(t2+3)='\0';

					}

					if(strcmp(t2,"iz")==0)
					{
						*(t2+2)='e';
						*(t2+3)='\0';

					}

					strcpy(s1->stem,temp1);
					strcpy(s1->term,word);
					s1->frequency=49;

				}
				else
				{
					strcpy(s1->stem,word);
					strcpy(s1->term,word);
					s1->frequency=49;

				}


			break;

			case 2:     //ion

					*(t2+len2)='\0';

					if(strlen(temp1)>2 && temp1[strlen(temp1)-1]!='q')
					{
						strcpy(s1->stem,temp1);
						strcpy(s1->term,word);
						s1->frequency=49;


					}
					else
					{
						strcpy(s1->stem,word);
						strcpy(s1->term,word);
						s1->frequency=49;

					}


			break;
					  //y
			case 3:

					*(t2+len2)='\0';

					if(strlen(temp1)>2 && temp1[strlen(temp1)-1]!='q')
					{
						t2=t2+strlen(temp1);

						*t2='i';
						*(t2+1)='\0';
						strcpy(s1->stem,temp1);
						strcpy(s1->term,word);
						s1->frequency=49;


					}
					else
					{
						strcpy(s1->stem,word);
						strcpy(s1->term,word);
						s1->frequency=49;

					}


			break;

			case 4://ment

					*(t2+len2)='\0';
					if(strlen(temp1)>2 && temp1[strlen(temp1)-1]!='q')
					{
						strcpy(s1->stem,temp1);
						strcpy(s1->term,word);
						s1->frequency=49;


					}
					else
					{
						strcpy(s1->stem,word);
						strcpy(s1->term,word);
						s1->frequency=49;

					}
			break;

			default:
					strcpy(s1->stem,word);
					strcpy(s1->term,word);
					s1->frequency=49; //ascii value of 1

	}

	fwrite(s1,sizeof(S),1,fp2);
	fprintf(fp2,"\n");
	free(s1);

	fclose(fp2);

}

void init(char p[15])
{
	int i;
	for(i=0;i<15;i++)
	p[i]='\0';
}

void freq()
{
	S *s,*head=NULL,*temp,*temp1,*temp2;
	S1 *s1;
	FILE *fp3,*fp4;
	int flag=1;
	char ch=' ';
	fp3=fopen("output3.txt","w");
	fprintf(fp3,"");
	fclose(fp3);
	fp3=fopen("output3.txt","a");
	fp2=fopen("output2.txt","r");
	fp4=fopen("output4.txt","w");
	ch=fgetc(fp2);

	while(ch!=EOF)
	{

		if(ch==" ")
		fprintf(fp4," ");
		if(ch=='\n')
		{
			ch=fgetc(fp2);
			continue;
		}
		else
			fprintf(fp4,"%c",ch);
		ch=fgetc(fp2);
	}

	fclose(fp4);
	fp4=fopen("output4.txt","r");

	while(flag!=0)
	{
		s=(S*)malloc(sizeof(S));
		s->next=NULL;
		init(s->stem);
		init(s->term);
		flag=fread(s,sizeof(S),1,fp4);
		s->next=NULL;

		if(head==NULL)
		{
			head=s;
			temp=head;
		}
		else
		{
			temp->next=s;
			temp=s;
		}


	}

	temp=head;
	temp1=head->next;

	while(temp->next!=NULL)
	{

		if(strcmp(temp->term,temp1->term)==0)
		{
			temp->frequency=temp->frequency+1;
			if(temp->next==temp1)
			{
				temp->next=temp1->next;
				free(temp1);
				temp1=temp->next;
			}
			else
			{
				temp2->next=temp1->next;
				free(temp1);
				temp1=temp2->next;
			}


		}
		else
		{

			temp2=temp1;
			temp1=temp1->next;
		}

		if(temp1==NULL)
		{

			temp=temp->next;
			temp1=temp->next;
		}
	}

	//comparing for last node
	if(strcmp(temp->term,temp1->term)==0)
	{
		temp->frequency=temp->frequency+1;
		if(temp->next==temp1)
		{
			temp->next=temp1->next;
			free(temp1);
			temp1=temp->next;
		}
		else
		{
			temp2->next=temp1->next;
			free(temp1);
			temp1=temp2->next;
		}
	}


	temp=head;
	while(temp->next!=NULL)
	{
		s1=(S1*)malloc(sizeof(S1));
		init(s1->stem);
		init(s1->term);
		strcpy(s1->stem,temp->stem);
		strcpy(s1->term,temp->term);
		s1->frequency=temp->frequency;

		fwrite(s1,sizeof(S1),1,fp3);

		temp=temp->next;
		fprintf(fp3,"\n");

		free(s1);
	}


	fcloseall();
}