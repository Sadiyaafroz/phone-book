#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 200
#include <ctype.h>
typedef struct {
      int id;
      char firstName[30];
      char lastName[30];
      char mobileNumber[20];
}Contact;

Contact phonebook[MAX_SIZE];
int currentSize =0;
void addEntry();
void display(int index);
void search(char *key ,int type);
void strtolower(char *str);

int main()
{
    addEntry();
    display(0);
    display(1);
    search("sadiya",1);//search by 1st name
    search("4564",2);//search by phn no
    return 0;
}
void addEntry()
{   if(currentSize == MAX_SIZE){

    puts("Error: phonebook is full");
    return;

}
    Contact c;
    printf("Enter First Name :");
    gets(c.firstName);
    printf("Enter List Name :");
    gets(c.lastName);
    printf("Mobile Number :");
    gets(c.mobileNumber);
    phonebook[currentSize] = c;
    ++currentSize;
}
void display(int index)
{

   if(index <0 ||index>= currentSize)
   {

       puts("Error: invalid index");
       return;
   }
   Contact c = phonebook[index];
   printf("First Name : %s\n",c.firstName);
   printf("Last Name : %s\n",c.lastName);
   printf("Mobile Number: %s\n",c.mobileNumber);
}
void strtolower(char *str)
{
   int len = strlen(str);
   int i;
   for(i=0;i<len;i++){
 str[i]= tolower(str[i]);

   }

}


void search(char *key, int type)
{ int found =0;
  int i;
  strtolower(key);
  char content[45];

  if(type==0){//search 1st name
     for(i=0;i<currentSize;i++) {
    strcpy(content,phonebook[i].firstName);
    strtolower(content);
      if(strcmp(content,key)==0) {
        display(1);
        found=1;
     }
       }
         }
if(type==1){//search last name
    for(i=0;i<currentSize;i++) {
        strcpy(content,phonebook[i].lastName);
    strtolower(content);
      if(strcmp(content,key)==0) {
        display(1);
        found=1;
     }
       }
}
if(type==2){//search phn no
     for(i=0;i<currentSize;i++) {
        strcpy(content,phonebook[i].mobileNumber);
    strtolower(content);
      if(strcmp(content,key)==0) {
        display(1);
        found=1;
     }
       }
}
else{
    puts("error:invalid search type!!");
    return;
}
if(!found){
    puts("not found in the phone book");
}
}
