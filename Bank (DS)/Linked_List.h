#include <iostream>
#include <windows.h>
using namespace std;

//Linked List Start
struct log{
       string LOG;
       log* down;

};
struct log_handler{
       int Account_Number;
       log_handler* next;
       log* down;
};
struct log_handler *head  = NULL;


void insertion_for_log(int account_number) //Inserion in Linked List
{
  struct log_handler *newnode = new log_handler;
  log_handler *temp=NULL;
  log_handler *temp2 = NULL;
  if(head == NULL){
     newnode -> Account_Number = account_number;
     newnode -> next = NULL;
     newnode -> down = NULL;
     head = newnode;}
  else{for(temp2 = head; temp2-> next != NULL ; temp2 = temp2 -> next){}
     temp =new log_handler;
     temp -> Account_Number = account_number;
     temp2 -> next = temp;
     temp ->  next = NULL;
     temp -> down = NULL;}
}

void insert_log(int number,string nn) //Insert Logs 
{
  {
  struct log_handler *temp2 = new log_handler;
  struct log *temp =new log;
  struct log *newnode =new log;
  newnode -> LOG  = nn;
  newnode -> down=NULL;
  for(temp2 = head ; temp2 != NULL; temp2 = temp2 -> next){
     if(temp2 -> Account_Number == number){
      if(temp2->down == NULL){
         temp2 -> down  = newnode;
         newnode -> down = NULL;}
       else{
         temp = temp2 -> down;
         temp2 -> down  = newnode;
         newnode -> down = temp;}}}
}
}

int  display(int acc_num)    //Display Function 
{                                
   struct log_handler *temp=new log_handler;
   struct log *temp2 = new log;
   if(head == NULL){return 0;}
   else{
      for(temp = head; temp != NULL; temp = temp -> next){
       if(temp-> Account_Number == acc_num){
        for(temp2 = temp->down; temp2 != NULL; temp2 = temp2-> down)
        {
      	cout<<"                                 -> " <<  temp2-> LOG <<endl;
		}
		break;
	return 1;

}}
}}
int  display1(int acc_num)    //Display Function 
{                                
   struct log_handler *temp=new log_handler;
   struct log *temp2 = new log;
   if(head == NULL){return 0;}
   else{
      for(temp = head; temp != NULL; temp = temp -> next){
       if(temp-> Account_Number == acc_num){
        for(temp2 = temp->down; temp2 != NULL; temp2 = temp2-> down)
        {
      	 temp2-> LOG;
		}
		
	return 1;

}}
}}

                                                    //-------------------xxxxxxxxxxxxxxxxx---------------------------\\



