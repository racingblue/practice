#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

void createContact(AddressBook *addressBook);
int validate(char number[]);
int validate_mail(char mail[]);
int searchname(AddressBook *addressBook, char *temp);
int searchnumber(AddressBook *addressBook, char temp[]);
int searchemail(AddressBook *addressBook, char temp[]);
void contactswap(int index, AddressBook *addressBook);
//void saveAndExit(struct AddressBook *addressBook);
//void saveContactsToFile(AddressBook *AddressBook);

int count;
    // Sort contacts based on the chosen criteria
    void listContacts(AddressBook *addressBook,int s)
    {
        re_enter:
        printf("\nEnter sort option Ascending(0)/Decending(1)");
        scanf("%d",&s);

        if(s==1)
        {
             for(int j=26;j>0;j--)
            {
                for(int i=1;i<=count;i++)
                {
                    if(addressBook->contacts[i].name[0]==(64+j)||addressBook->contacts[i].name[0]==(96+j))
                     printf("%s\t%s\t%s\n",addressBook->contacts[i].name,addressBook->contacts[i].number,addressBook->contacts[i].email);

                }

            }
        }
        else if(s==0)
        {
            for(int j=0;j<26;j++)
            {
                for(int i=1;i<=count;i++)
                {
                    if(addressBook->contacts[i].name[0]==(65+j)||addressBook->contacts[i].name[0]==(97+j))
                     printf("%s\t%s\t%s\n",addressBook->contacts[i].name,addressBook->contacts[i].number,addressBook->contacts[i].email);

                }

            }
            

        }
        else
        {
             printf("\nInvalid option");
             goto re_enter;

        }
       
    	
    }
    

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    populateAddressBook(addressBook);
    

    // Load contacts from file during initialization (After files)
    //loadContactsFromFile(AddressBook);
}

void saveAndExit(AddressBook *addressBook) {

    saveContactsToFile(addressBook);
    // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


//void createContact(AddressBook *AddressBook)
//{

//}

void createContact(AddressBook *addressBook)
{
    
    //struct AddressBook addressBook[100];
    
    printf("Enter name :");
    scanf("%s",addressBook->contacts[count+1].name);
    once:
    printf("\nEnter mobile number :");
    scanf("%s",addressBook->contacts[count+1].number); 
    getchar();
    int val=validate(addressBook->contacts[count+1].number);
    if(val==0)
        goto once;
    
    remail:
    printf("Enter email ID :");
    scanf("%s",addressBook->contacts[count+1].email);
    int eval=validate_mail(addressBook->contacts[count+1].email);
    if(eval)
    printf("\n\nSaved swccessfully");
    else
    goto remail;
    
}
int validate(char number[])
{
    //static int count=0;
    int c=0;
    for(int i=0;i<10;i++)
    {
       if(number[i]>='0'&&number[i]<='9')
       c++;
    }
    if(c!=10)
    {
       printf("Enter valid number\n");
       return 0;
    }
    else
    return 1;
    
    
}
int validate_mail(char mail[])
{
    int at=0,dot=0;
    //char temp[]={"->com"};
    for(int i=0;mail[i]!='\0';i++)
    {
        
        if(mail[i]=='@')
        at=1;
        if(mail[i]=='.')
        dot=1;
    }
    if(at!=1&&dot!=1)
    {
        printf("\nEnter proper mail ID");
        return 0;

    }
    else
    {
        count+=1;
        printf("%d",count);
        return 1;
    }
    
    
}
	/* Define the logic to create a Contacts */
    


//void searchContact(AddressBook *AddressBook) 

int searchContact(AddressBook *addressBook)
{
    int option;
    printf("choose option to search");
    printf("\n1->Name");
    printf("\n2->Mobile number");
    printf("\n3->Email\n");
    scanf("\n%d",&option);
   // getchar();
    char tempname[50];
    char tempnumber[10];
    char tempmail[30];
    getchar();
    if(option==1)
    {
        printf("Enter name");
        //getchar();
       
        scanf("%[^\n]",tempname);
        getchar();
        //fgets(tempname,10,stdin);
         
               int index= searchname(addressBook,tempname);
               return index;
    }
     else if(option==2)
    {
        printf("Enter number");
        scanf("%s",tempnumber);
       getchar();
                int index=searchnumber(addressBook,tempnumber);
                return index;
    }
    else if(option==3)
    {
        printf("Enter Email");
        scanf("%s",tempmail);
        getchar();
                int index=searchemail(addressBook,tempmail);
                return index;
    }
    else
    printf("Give proper option");
return 0;
}
    /* Define the logic for search */
    

int searchname(AddressBook *addressBook,char *temp)
{
      int flag;
      int out=0;
      int len=0;
     
      while(*temp!='\0')
      {
        *temp++;
        len++;

      }
     // for(len;len>0;len--)//to get the name if half of string matches
      //{
         for(int i=1;i<=count;i++)
        {
        flag=1;
        for(int j=0;j<len;j++)
        {
            if(temp[j]==addressBook->contacts[i].name[j])
            flag=0;
            
           
            
        }
        printf("\nname%s",addressBook->contacts[1].name);
           printf("\nnum%s",addressBook->contacts[1].number);
           printf("\nemail%s",addressBook->contacts[1].email);
        if(flag==0)
        {
            out=1;
           printf("\nname%s",addressBook->contacts[i].name);
           printf("\nnum%s",addressBook->contacts[i].number);
           printf("\nemail%s",addressBook->contacts[i].email);
           return i;
        }
        }
         if(out==0)
         printf("No matching found"); 
          return 0;

     // }
   
      /*  if(flag!=0)
        {
            out=1;
           printf("\n%s",addressBook->contacts[i].name);
           printf("\n%s",addressBook->contacts[i].number);
           printf("\n%s",addressBook->contacts[i].email);
           return i;
        }
       */
    } 
   


int searchnumber(AddressBook *addressBook,char *temp)
{
      int flag;
      int out=0;
    for(int i=0;i<count;i++)
    {
        flag=0;
        for(int j=0;temp[j]!='\0';j++)
        {
            if(temp[j]!=addressBook->contacts[i].number[j])
            flag=1;
            break;
        }
        if(flag!=1)
        {
            out=1;
            printf("\n%s",addressBook->contacts[i].name);
           printf("\n%s",addressBook->contacts[i].number);
           return i;
        }
       
    } 
    if(out==0)
    printf("No matching found"); 

}
int searchemail(AddressBook *addressBook,char *temp)
{
      int flag;
      int out=0;
    for(int i=0;i<count;i++)
    {
        flag=0;
        for(int j=0;temp[j]!='\0';j++)
        {
            //printf("%c",addressBook->contacts->email[j]);
            if(temp[j]==addressBook->contacts[i].email[j])
            flag==1;
        }
        if(flag!=1)
        {
            out=1;
            printf("\n%s",addressBook->contacts[i].name);
           printf("\n%s",addressBook->contacts[i].email);
           return i;
        }
       
    } 
    if(out==0)
    printf("No matching found"); 

}

//void editContact(AddressBook *AddressBook)

	/* Define the logic for Editcontact */
void editContact(AddressBook *addressBook)
{
   int index=searchContact(addressBook);

    int option;
    printf("\nChoose which option you want to edit");
    printf("\n1->Name");
    printf("\n2->Number");
    printf("\n3->Email");
    scanf("%d",&option);
    char tempname[10];
    char tempnumber[10];
    char tempmail[15];

    if(option == 1)
    {
        printf("\nEnter new name");
        getchar();
        scanf("%[^\n]",tempname);
        int i;
        for(i=0;tempname[i]!='\0';i++)
        {
            addressBook->contacts[index].name[i]=tempname[i];

        }
        addressBook->contacts[index].name[i]='\0';
        
         printf("\nSuccesfully updated");
    }
    
     else if(option==2)
    {
        nonce:
        printf("\nEnter new number");
        scanf("%s",tempnumber);
       
                int val=validate(tempnumber);
                if(val)
                {
                    for(int i=0;i<count;i++)
                    {
                        addressBook->contacts[index].number[i]=tempnumber[i];
                    }
                    printf("\nSuccesfully updated");

                }
                else
                {
                    printf("\nupdate failed");
                    goto nonce;
                }
    }
    else if(option==3)
    {
        once:
        printf("\nEnter new Email");
        scanf("%s",tempmail);
        
                int val=validate_mail(tempmail);
                if(val)
                {
                    int i=0;
                    for(i=0;tempmail[i]!='\0';i++)
                    {
                        addressBook->contacts[index].email[i]=tempnumber[i];
                    }
                    addressBook->contacts[index].email[i]='\0';
                    printf("Successfully updated");
                    
                }
                else
                goto once;
    }
    else
    printf("Give proper option");
}
    


void deleteContact(AddressBook *addressBook)
{
    //listContacts();
    printf("Enter name to delete");
    getchar();
    char tempname[15];
    scanf("%[^\n]",tempname);
   printf("test");
    int val =searchname(addressBook,tempname);
    //printf("\n%s\t%s\t%s",addressBook->contacts[val]->name,addressBook->contacts[val]->number,addressBook->contacts[val]->email);
    printf("\nAre you sure want to delete(Press 1 or 0)");
    int n;
    scanf("%d",&n);
    if(n)
    contactswap(val, addressBook);
    
	/* Define the logic for deletecontact */
   
}
void contactswap(int index,AddressBook *addressBook)
{
    int done=0;
    if(index==count)
    {
        count-=1;
        done=1;
    }
    for(int i=index;i<count;i++)
    { 
        addressBook->contacts[i]=addressBook->contacts[i+1];
        done=1;
        
    }
    if(done)
    {
        count-=1;
         printf("\nDeleted successfully");
    }
   
}
void saveContactsToFile(AddressBook *addressBook)
{

}

/*
int main() {
    int choice;
    AddressBook addressBook;
    initialize(&addressBook); // Initialize the address addressBook

    do {
        printf("\nAddress addressBook Menu:\n");
        printf("1-> Create contact\n");
        printf("2-> Search contact\n");
        printf("3-> Edit contact\n");
        printf("4-> Delete contact\n");
        printf("5-> List all contacts\n");
    	printf("6-> Save contacts\n");		
        printf("7-> Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addContact(&addressBook);
                break;
            case 2:
                searchContact(&addressBook);
                break;
            case 3:
                editContact(&addressBook);
                break;
            case 4:
                deleteContact(&addressBook);
                break;
            case 5:          
                listContacts(&addressBook, sortChoice);
                break;
            case 6:
                printf("Saving and Exiting->->->\n");
                //saveContactsToFile(&AddressBook);
                break;
            default:
                printf("Invalid choice-> Please try again->\n");
        }
    } while (choice != 7);
    
       return 0;
}
*/
