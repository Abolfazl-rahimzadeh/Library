//libraries
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>

//functions
char U ='g';
int choice,bkn=0;
char bl[1050][100];

void delay(float s)
{
	float ms=s*1000;  //######
	clock_t st =clock();
	while(clock()<st+ms);		
}

void show(char txt[])
{
    for (int i = 0; i < strlen(txt); i++)
	{
        printf("%c", txt[i]);
        fflush(stdout);  // Flush the output to ensure it's immediately visible
      // Introduce a 100ms (100000 microseconds) delay between each character
     delay(0.04);
    }
}
void spl(char sp, int a)
{
		for(int i=0;i<a;i++)
			printf("%c",sp);
	show("\n");
}

void byebye()
{
	system("color 04");
	spl('~',119);
	show("\t\t\t\t\t\t      SEE YOU SOON! \n")	;
}

void welcome()
{
	spl('#',119);
	printf("\t\t\t\t\t\t");
	show(" welcome to the library ")	;
	printf("\n");
	spl('#',119);
}

void prs()
{
	
	show("press any key to continue! ");
		getch();
		delay(0.4);
		show(".");
		delay(0.4);
		show(".");
		delay(0.4);
		show(".");
		delay(0.4);
		show(".");
		delay(0.5);
}

void srtbk(char arr[1050][100])
{ int i, j;
    char temp[100]; // Change the size to match the string array size

    for (i = 0; i < bkn-1; i++) 
	{
        for (j = i+1; j < bkn; j++) 
		{
            if (strcmp(arr[i], arr[j]) > 0) 
			{
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }
}

void sbkl()
{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


	srtbk(bl);

	for (int i = 0; i<bkn; i++)
	{

			
	SetConsoleTextAttribute(hConsole,
  FOREGROUND_GREEN );
	show("(");

  SetConsoleTextAttribute(hConsole,
  FOREGROUND_RED | FOREGROUND_INTENSITY );
//		printf("\n%s\n", bl[i]);
	show(bl[i]);
		
	SetConsoleTextAttribute(hConsole,
  FOREGROUND_GREEN );
	show(")\n");
	}
}

void bkl()
{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	

	for (int i = 0; i<bkn; i++)
	{

			
	SetConsoleTextAttribute(hConsole,
  FOREGROUND_GREEN );
	show("(");

  SetConsoleTextAttribute(hConsole,
  FOREGROUND_RED | FOREGROUND_INTENSITY );
//		printf("\n%s\n", bl[i]);
	show(bl[i]);
		
	SetConsoleTextAttribute(hConsole,
  FOREGROUND_GREEN );
	show(")\n");
	}
	
}

void bkc()
{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

  SetConsoleTextAttribute(hConsole,
  FOREGROUND_RED | FOREGROUND_GREEN );
	show("the number of books is: ");
	printf("%d\n", bkn);
}

void addbk()
{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	SetConsoleTextAttribute(hConsole,
  FOREGROUND_RED | FOREGROUND_GREEN );
	show("Enter the name of book: ");
	
	
	SetConsoleTextAttribute(hConsole,
  FOREGROUND_GREEN );
	char bkt[50];
	scanf("%s", bkt);

	strcpy(bl[bkn], bkt);

	
	bkn++;
}

void ulg() 
{
    char id[20], ps[20];  

    system("color 70");
    
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

  SetConsoleTextAttribute(hConsole,
   FOREGROUND_RED  );
    
    show("ENTER YOUR USER ID: ");
  SetConsoleTextAttribute(hConsole,
    FOREGROUND_INTENSITY | FOREGROUND_INTENSITY  | BACKGROUND_INTENSITY );
    scanf("%s", id);  

SetConsoleTextAttribute(hConsole,
    FOREGROUND_RED  );
    

    show("ENTER YOUR PASSWORD: ");
SetConsoleTextAttribute(hConsole,
    FOREGROUND_INTENSITY | FOREGROUND_INTENSITY  | BACKGROUND_INTENSITY );
    scanf("%s", ps);  
    

    if (strcmp(id, "admin") == 0 && strcmp(ps, "Admin12") == 0)
	{
		SetConsoleTextAttribute(hConsole,
    FOREGROUND_GREEN  );
      show("YOU HAVE SECCUSSFULY LOGINED.");
         U = 'm';
    } else {
        SetConsoleTextAttribute(hConsole,
    FOREGROUND_RED  );
		printf("Login failed\n");
    }
    
    delay(2);
    
   system("cls");
    system("color 07");
}

void dlbk()
{
	 
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

  SetConsoleTextAttribute(hConsole,
   FOREGROUND_RED  );
    if (bkn == 0) {
        show("There are no books yet.\n\n");
        return;
    }

    char title[50];
   
  	SetConsoleTextAttribute(hConsole,
  FOREGROUND_RED | FOREGROUND_GREEN );
    show("Enter the title of the book: ");
    	
	SetConsoleTextAttribute(hConsole,
  FOREGROUND_GREEN );
    scanf("%s", title);
    
    int found = 0;
    for (int i = 0; i < bkn; i++) {
        if (strcmp(bl[i], title) == 0) {
            found = 1;
            for (int j = i; j < bkn - 1; j++) {
                strcpy(bl[j], bl[j + 1]);
            }
            (bkn)--;
             SetConsoleTextAttribute(hConsole,
  			 FOREGROUND_GREEN  );
            show("The book was deleted successfully!\n\n");
            break;
        }
    }
    
    if (!found)
	{
		 SetConsoleTextAttribute(hConsole,
   FOREGROUND_RED  );
        show("The book is not available.\n\n");
    }
}

void bks()
{
    char searchTitle[100];
   
   HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

  SetConsoleTextAttribute(hConsole,
    FOREGROUND_RED  );
   
    show("Enter the title to search: ");
   SetConsoleTextAttribute(hConsole,
    FOREGROUND_GREEN  );
    scanf("%s", searchTitle);
SetConsoleTextAttribute(hConsole,
    FOREGROUND_RED  );
    int found = 0;
    for (int i = 0; i < bkn; i++)
	{
        if (strcmp(bl[i], searchTitle) == 0)
		{
			show("the book \"");
            SetConsoleTextAttribute(hConsole,
    FOREGROUND_GREEN  );
			show(bl[i]);
            SetConsoleTextAttribute(hConsole,
    FOREGROUND_RED  );
            show("\" exist .");
//		    printf("\n%s\n", bl[i]);
            found = 1;
        }
    }

    if (!found)
	{
        show("The book is not available!\n\n");
    }
}


int menu()
{
	
//	system("color 03");		
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

   SetConsoleTextAttribute(hConsole,
    FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
	spl('=',119);
 
     SetConsoleTextAttribute(hConsole,
    FOREGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY );

	show("\nwhat do you want to do ?");
	show("\nEnter the number of the opration u wanna do for selection:");
	printf("\n\n\n");
			delay(0.4);	
	show("\n1. view and sort the book list.");
		delay(0.4);
	show("\n2. view the book list.");
		delay(0.8);
	show("\n3. search in the book list.");
		delay(0.8);
	show("\n4. count the books.");
		delay(0.4);
	if(U!='m')
	show("\n5. login as a manager.");
	if(U=='m')
	{
	show("\n5. add a book.");
		delay(0.4);
	show("\n6. delete a book.");	
		delay(0.4);
	show("\n7. log out.");
	}	
			delay(0.4);
	show("\n0. exit.");
		delay(0.4);
	show("\nyour choice is option ( )\b\b");
	 SetConsoleTextAttribute(hConsole,
    FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
	scanf("%d",&choice);
	
	
}

void error()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

  SetConsoleTextAttribute(hConsole,
     FOREGROUND_RED );
    show("\t\a\t\a\t\a\t\a\t\a\t\a     ENTER CORROCTLY!\n\t\a\t\a\t\a\t\a\t\a\t\a     YUOR CHOICE IS: ");
    	scanf("%d",choice);
    	
}
// main
int main()
{
		int r=0;
		welcome();
		prs();
		printf("\n"); 

	while(1)
	{
	menu();	
//	show("%d",choice);
		switch(choice)
		{
			case (0):
					byebye();
				exit(1);
				
			case(1):	
				sbkl();
				break;
			case(2):
				bkl();
				break;
			case(3):
				bks();
				break;
			case(4):
				bkc();
				break;
			case(5):
				if(U=='g')
					ulg();
				else
					addbk();
				break;
			case(6):
				if(U=='m')
				{
				dlbk();
				}
				else
					error();
				break;
			case(7):
				if(U=='m')
				{
				U='g';
				}
				else
					error();
				break;
//			default:
//				error();
///	clrscr();
	}
	if(r<=2)
	r++;
	else
	{
		show("the screen will be clear in 10s");
		delay(1);
			show("\b\b\b 9s");
		delay(1);
			show("\b\b\b 8s");
		delay(1);
			show("\b\b\b 7s");
		delay(1);
			show("\b\b\b 6s");
		delay(1);
			show("\b\b\b 5s");
		delay(1);
			show("\b\b\b 4s");
		delay(1);
			show("\b\b\b 3s");
		delay(1);
			show("\b\b\b 2s");
		delay(1);
			show("\b\b\b 1s");
		delay(1);
	system("cls");
	}
	
//	getch();
	
	
	}
	return 0;
}
