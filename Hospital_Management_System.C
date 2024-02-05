#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<conio.h>
#include<windows.h>

void welcomescreen();
void title();
void addUsers();
void signup();
void saveUsers();
void login();
void mainmenu();
void addpatientrec();
void patientlist();
void dischargepatient();
void searchpatientrec();
void adddoctor();
void listdoctor();
void removedoctor();
void password();

struct User {
    char username[50];
    char password[50];
};


struct patient
{
	int id;
	char gender[20];
	char name[50];
	char disease[50];
	char address[50];
	char date[50];
}p;

struct doctor{
    int id;
    char gender[20];
    char name[50];
    char address[50];
    char specialize[50];
    char date[12];
}d;


struct User users[100];
int num = 0;


FILE *pk;
int i=0;
int main()
{
	welcomescreen();
	title();
    addUsers();
    int choice;

    while (1) 
	{
        title();
	    printf("\n\n\t\t\t\t\t       ************WELCOME************\n");
        printf("\n\t\t\t\t\t\t\t1. Login\n");
        printf("\t\t\t\t\t\t\t2. Signup\n");
        printf("\t\t\t\t\t\t\t3. Exit\n");
        printf("\n\n\t\t\t\t\t\tEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
		{
            case 1:
                login();
                break;
            case 2:
                signup();
                break;
            case 3:
                saveUsers();
                exit(0);
            default:
                printf("\n\n\t\t\t\tInvalid choice. Please try again...!!!\n");
        }
    }
	return 0;
}
void welcomescreen()
{
	system("color 4 ");
	printf("\n\n\n\n\t\t\t   ***************************************************************************\n");
	printf("\t\t\t   *\t\t\t           WELCOME TO  \t\t\t\t     *\n");
	printf("\t\t\t   *\t\t\t  HOSPITAL MANAGEMENT SYSTEM \t\t\t     *\n");
	printf("\t\t\t   ***************************************************************************\n");
	printf("\n\n\n\n\n\n\t\t\t\t\t\t Press any key to continue...!!!");
	getch();
	system("cls");
}
void title()
{
	system("color 4 ");
	printf("\n\n\n\n\t\t\t   ***************************************************************************\n");
	printf("\t\t\t   *\t\t\t           WELCOME TO  \t\t\t\t     *\n");
	printf("\t\t\t   *\t\t\t  HOSPITAL MANAGEMENT SYSTEM \t\t\t     *\n");
	printf("\t\t\t   ***************************************************************************\n");
}
void addUsers()
 {
    
	system("cls");
	FILE *file;
	file = fopen("users.txt", "r");
    if (file == NULL) 
	{
        return;
    }

    while (fscanf(file, "%s %s", users[num].username, users[num].password) != EOF)
	 {
        num++;
    }

    fclose(file);
    system("cls");
}

void saveUsers() 
{
    
	system("cls");
	FILE *file;
	file = fopen("users.txt", "w");
    if (file == NULL)
	 {
        printf("Error: Unable to save users.\n");
        exit(0);
    }

    for ( i = 0; i < num; i++) 
	{
        fprintf(file, "%s %s\n", users[i].username, users[i].password);
    }

    fclose(file);
    system("cls");
}
void takepassword(char pass[30])
{
    int i=0;
    char ch;
    while (1)
    {
        ch = getch();
        if (ch == 13)
        {
            pass[i] = '\0';
            break;
        }
        else if (ch == 8)
        {
            if (i > 0)
            {
                i--;
                printf("\b \b");
            }
        }
        else if (ch == 9 || ch == 32)
        {
            continue;
        }
        else
        {
            pass[i++] = ch;
            printf("*");
        }
    }
}
void login() 
{
	char username[50];
    char password[50];
    
    
	printf("\n\t\t\t\t\t\tEnter username: ");
    scanf("%s", username);

    printf("\t\t\t\t\t\tEnter password: ");
    takepassword(password);

    for ( i = 0; i < num; i++) 
	{
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) 
		{
            printf("\n\n\n\t\t\t\t\t\t\tLogin successful...");
            printf("\n\n\n\t\t\t\t\t\t\t\t\tWelcome, %s...\n", username);
            getch();
            mainmenu();
        }
    }

    printf("\n\n\t\t\t\t Login failed invalid username or password!!! \n\n\t\t\t\t\t\t\t\t\tPlease try again...!!!");
    getch(); 
    system("cls");
    
}
void signup() 
{
    system("cls");
    title();
	char username[50];
    char password[50];

    printf("\n\n\n\t\t\t\t\t\tEnter a new username: ");
    scanf("%s", username);

    for ( i = 0; i < num; i++) 
	{
        if (strcmp(username, users[i].username) == 0) 
		{
            printf("\n\n\t\t\t\tUsername already exists. So please choose a different one...\n");
            return;
        }
    }

    printf("\t\t\t\t\t\tEnter a new password: ");
    scanf("%s", password);
/*
    if (num < 100)
	 {
        strcpy(users[num].username, username);
        strcpy(users[num].password, password);
        num++;
        saveUsers();
        printf("Signup successful. You can now login with your new account.\n");
    } 
	
	{
        printf("Maximum number of users reached. Signup failed.\n");
    }
*/
}

void mainmenu()
{
	system("color 5 ");
	system("cls");
	int choice;
	title();
	char press;
	while(1){
		label:	
		printf("\n\t\t\t\t\t\t1. Add record of the patient");
		printf("\n\t\t\t\t\t\t2. Patient list");
		printf("\n\t\t\t\t\t\t3. Discharge the patient");
		printf("\n\t\t\t\t\t\t4. Search Patient record");
		printf("\n\t\t\t\t\t\t5. Add doctor record");
		printf("\n\t\t\t\t\t\t6. List doctor record");
		printf("\n\t\t\t\t\t\t7. Remove doctor record");
		printf("\n\t\t\t\t\t\t8. Exit");
		printf("\n\n\n\t\t\t\t\tChoose any number that you want: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				addpatientrec();
				break;
				
			case 2:
				patientlist();
				break;

			case 3:
				dischargepatient();
				break;
				
			case 4:
				searchpatientrec();
				break;
				
			case 5:
				adddoctor();
				break;
			
			case 6:
				listdoctor();
				break;
				
			case 7:
				removedoctor();
				break;
				
			case 8:
				exit(0);
				break;
				
			default:
				printf("\nThe choice is not valid...!!!\n");
				goto label;
			
		}
		/*printf("\nDo you want to continue?..Press Y to continue.");
		scanf("%c",&press);
		if(press=='y'||press=='Y')
		{
			goto label;
		}*/
		system("cls");
	}
}
	void addpatientrec()
	{
		system("color 4 ");
		FILE *pk;
		system("cls");
		title();
		printf("\n\t\t\t\t\t\t*******PATIENT RECORD******");
		pk=fopen("record.txt","ab");
		printf("\n\n\n\t\t\t\t\t Enter the patient Id: ");
	    scanf("%d",&p.id);
	    printf("\t\t\t\t\t Enter the Name of patient: ");
	    fflush(stdin);
	    gets(p.name);
	    printf("\t\t\t\t\t Enter the Gender: ");
	    fflush(stdin);	
	    gets(p.gender);
	    printf("\t\t\t\t\t Enter the Address of patient: ");
	    fflush(stdin);
	    gets(p.address);
	    printf("\t\t\t\t\t Enter the Disease of patient: ");
	    fflush(stdin);
	    gets(p.disease);
	    printf("\n\n\t\t\t\t\t Enter the Date: ");
	    fflush(stdin);
	    gets(p.date);
	    printf("\n\n\t\t\t\t\t\t\t\t Patient detail added successfully...!!!");
	    getch();
	    fwrite(&p,sizeof(p),1,pk);
	    fclose(pk);
	   // system("cls");
	}
	void patientlist()
	{
		system("color 6 ");
		system("cls");
		title();
		printf("\n\n\n\n\t\t\t\t\t\t**********PATIENT LIST**********\n");
		printf("\n\n\n\t\t%-10s %-20s %-15s %-30s %-15s %s\n", "Id"," Name","Gender","Address","Disease","Date");
        printf("\t------------------------------------------------------------------------------------------------------------------\n");
	    rewind(pk);
		pk=fopen("record.txt","rb");
	    while(fread(&p, sizeof(p), 1, pk) == 1)
	    {
			printf("\n\t\t%-10d %-20s %-15s %-30s %-15s %s\n", p.id,p.name,p.gender, p.address, p.disease, p.date);
	    	
		}
		fclose(pk);
		printf("\n\n\n\t\t\t\t\t\t\t Press any key to continue...!!!");
		getch();
		system("cls");
	}
	void dischargepatient()
	{
		system("color 8 ");
		int id,k=0;
		system("cls");
		title();
		FILE *s;
		printf("\n\n\n\n\t\t\t\t\t\t**********DISCHARGE PATIENT**********");
		printf("\n\n\n\t\t\t\t\t\t Enter patient Id:");
		scanf("%d",&id);
		pk=fopen("record.txt","rb");
		s=fopen("temp.txt","wb");
		while(fread(&p, sizeof(p), 1, pk) == 1)
		{

        if(id == p.id)
		{
            k=1;
           
		    continue;
        
		}
		
		else
		{
           
		    fwrite(&p, sizeof(p), 1, s);
        }
    }

    if(k==1)
	{
        printf("\n\n\n\n\t\t\t\t\t\t Patient Discharged Successfully...!!!");
        
    }
	else
	{
        printf("\n\n\t\t\t\t\t\tRecord Not Found !");
    }
	fclose(pk);
    fclose(s);
    remove("record.txt");
    rename("temp.txt", "record.txt");
    getch();
    system("cls");
}
	void searchpatientrec()
	 {
	 	system("color 3 ");
		 system("cls");
		title();
	 	int id ;
	 	int c=0;
	 	printf("\n\n\n\t\t\t\t\t  **********SEARCH PATIENT RECORD**********");
	 	//printf("\n\t\t\t\t\t\t\t-----------------------------");
	 	printf("\n\n\n\t\t\t\t\t\t Enter the ID: ");
	 	scanf("%d",&id);
	 	rewind(pk);
		pk=fopen("record.txt","rb");
	 	printf("\n\n\n\t\t%-10s %-20s %-20s %-25s %-15s %s\n", "Id"," Name","Gender","Address","Disease","Date");
        printf("\t  -------------------------------------------------------------------------------------------------------------\n");
	 	while(fread(&p, sizeof(p), 1, pk) == 1)
		 {

            if(id == p.id)
		    {
               	printf("\n\t\t%-10d %-20s %-20s %-25s %-15s %s\n", p.id,p.name,p.gender, p.address, p.disease, p.date);
            	c=1;
			}
		    
		 }
		 if (c==0)
		 {
		 	printf("\n\n\t\tRecord not found..");
		 }
       
       getch();
       system("cls");
	 
    }
    void adddoctor()
    {
    	system("color 4 ");
		system("cls");
    	title();
    	FILE *pk;
    printf("\n\n\n\t\t\t\t\t\t********************************");
	printf("\n\t\t\t\t\t\t\tDOCTOR RECORD");
	printf("\n\t\t\t\t\t\t********************************");
    pk=fopen("doctor.txt","ab");
    printf("\n\n\t\t\t\t\t\tEnter Doctor Id: ");
    scanf("%d", &d.id);

    printf("\t\t\t\t\t\tEnter Doctor Name: ");
    fflush(stdin); 
    gets(d.name);

    printf("\t\t\t\t\t\tEnter Doctor gender: ");
    fflush(stdin);
    gets(d.gender);

    printf("\t\t\t\t\t\tDoctor Specialize in: ");
    fflush(stdin);
    gets(d.specialize);
    
    printf("\n\t\t\t\t\t\tDate: ");
    fflush(stdin);
    gets(d.date);

    printf("\n\n\t\t\t\t\t\t\t\tDoctor Added Successfully...!!!\n\n");
    getch();
    fwrite(&d,sizeof(d),1,pk);
    fclose(pk);
    system("cls");
	}
	void listdoctor()
	{
		system("color 5 ");
		system("cls");
		title();
		//printf("\n\n\n\t\t\t********************************");
	    printf("\n\n\n\t\t\t\t\t\t\tDOCTOR RECORD");
	    printf("\n\n\n\t\t\t\t\t\t********************************");
	    printf("\n\n\n\n\t\t%-10s %-30s %-30s %-30s %s\n", "Id", "Name", "Gender", "Specialize","Date");
        printf("\t  -------------------------------------------------------------------------------------------------------------------\n");
        pk=fopen("doctor.txt","rb");
        rewind(pk);
		while(fread(&d, sizeof(d), 1, pk) == 1)
		{
			 printf("\t\t%-10d %-30s %-30s %-30s %s\n", d.id, d.name,d.gender, d.specialize, d.date);
			 
		}
		fclose(pk);
		printf("\n\n\n\t\t\t\t\t\t Press any key to continue...!!!");
		getch();
		system("cls");
	}
	void removedoctor()
	{
			system("color 8 ");
		int id,k=0;
		system("cls");
		title();
		FILE *n;
		printf("\n\n\n\t\t\t\t\t\t*******Remove Doctor***********");
		printf("\n\n\n\t\t\t\t\t\t Enter Doctor ID:");
		scanf("%d",&id);
		pk=fopen("doctor.txt","rb");
		n=fopen("temp.txt","wb");
		while(fread(&d, sizeof(d), 1, pk) == 1)
		{

        if(id == d.id)
		{
            k=1;
           
		    continue;
        
		}
		
		else
		{
           
		    fwrite(&d, sizeof(d), 1, n);
        }
    }

    if(k==1)
	{
        printf("\n\n\t\t\t\t\t\t Remove Successfully...!!!");
        
    }
	else
	{
        printf("\n\n\t\t\t\t\t\t Record Not Found !");
    }
	fclose(pk);
    fclose(n);
    remove("doctor.txt");
    rename("temp.txt", "doctor.txt");
    getch();
    system("cls");
	}



