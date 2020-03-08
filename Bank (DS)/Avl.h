#include <iostream>
#include <windows.h>
#include<iomanip>
using namespace std;


//AVL code Start
struct node{
  //Data Entry
  string Name;
  string CNIC;
  char Gender;
  string Type;
  int Acc_Number;
  int pin;
  int bala;
  //Node
  node *right, *left;
  int height;
};
node *temp, *temp1, *temp2, *tempcell = NULL;
/////////////////////////////////////////////////////////////////////////////////////////Main Functions used in AVL
// Max Function
int max(int a, int b){
  if(a > b){return a;}
  else{return b;}
}
// Height Function
int height(struct node* temp){
  if(temp == NULL){return 0;}
  int lh = height(temp->left);
  int rh = height(temp->right);
  if(lh > rh){return lh+1;}
  else{return rh+1;}
}
// Left Rotation Function
struct node *left_rotation(struct node* temp2) {
  temp1 = temp2->right;
  temp2->right = temp1->left;
  temp1->left = temp2;

  temp2->height = max(height(temp2->left), height(temp2->right)) + 1;
  temp1->height = max(height(temp1->left), height(temp1->right)) + 1;
  return temp1;
}
// Right Rotation Function
struct node *right_rotation(struct node* temp2){
  temp1 = temp2->left;
  temp2->left = temp1->right;
  temp1->right = temp2;

  temp2->height = max(height(temp2->left), height(temp2->right)) +1;
  temp1->height = max(height(temp1->left), height(temp1->right)) +1;

  return temp1;
}
// right left rotation
struct node *right_left_rotation(struct node* temp3)   {
  temp3->right = right_rotation(temp3->right);
  return left_rotation(temp3);
}
// Left right rotation
struct node *left_right_rotation(node *temp3)     {
  temp3->left = left_rotation(temp3->left);
  return right_rotation(temp3);
}
//Minimum Function{
struct node *min(struct node* temp){
  if(temp == NULL){return 0;}
  if(temp->left == NULL){return temp;}
  else{min(temp->left);}
}
// balance function
struct node *balance(struct node* temp)  {
 if(temp == NULL){cout<<"No rotation is found "<<endl;}
 if( height(temp->left)-height(temp->right) > 1){
 if(height(temp->left->left) >= height(temp->left->right)){temp =right_rotation(temp);}
 else{temp =left_right_rotation(temp);}}
 else if( height(temp->right)-height(temp->left) > 1){if(height(temp->right->right) >= height(temp->right->left))
 {
  temp =left_rotation(temp);
 }
 else
 {
  temp =right_left_rotation(temp);
 }
 }
  temp->height = max(height(temp->left), height(temp->right)) + 1;
  return temp;
}
/////////////////////////////////////////////////////////////////////////////////////////END of main Functions in AVL


struct node *insertion(struct node* temp,string name,string cnc,char gen,string type,int account_no,int PIN,int bal){    ///////////////////////// insertion
 if(temp == NULL){
  temp = new node();
  temp->Name          = name;
  temp->CNIC          = cnc;
  temp->Gender        = gen;
  temp->Type          = type;
  temp->Acc_Number    = account_no;
  temp->pin           = PIN;
  temp->bala          = bal;
  temp->left          = NULL;
  temp->right         = NULL;
  temp->height        = 0;}

if(account_no < temp->Acc_Number){
     temp->left = insertion(temp->left, name, cnc,gen,type, account_no,PIN,bal);
  if(height(temp->left) - height(temp->right) == 2){
     if(account_no < temp->left->Acc_Number){temp = right_rotation(temp);}
     else{temp = left_right_rotation(temp);}}}

if(account_no > temp->Acc_Number){
    temp->right = insertion(temp->right, name, cnc,gen,type, account_no,PIN,bal);
  if(height(temp->right) - height(temp->left) == 2){
    if(account_no > temp->right->Acc_Number){temp = left_rotation(temp);}
    else{temp = right_left_rotation(temp);}}}

 temp->height = max(height(temp->left), height(temp->right)) +1 ;
 return temp;
}


struct node *deletion(struct node* temp, int x) ///////////////////////// deletion
{
 if(temp == NULL){
		return temp;}
 else if(x < temp->Acc_Number){
		temp->left = deletion(temp->left, x);}
 else if(x > temp->Acc_Number){
		temp->right = deletion(temp->right, x);}
 else if(temp->left && temp->right){
		tempcell = min(temp->right);
		temp->Acc_Number = tempcell->Acc_Number;
		temp->right = deletion(temp->right, temp->Acc_Number);}
 else{
		tempcell = temp;
 if(temp->left == NULL){
		temp = temp->right;}
 else if(temp->right == NULL){
		temp = temp->left;}
		delete tempcell;}
 if(temp != NULL){
		temp = balance(temp);}

 return temp;

}

int findMax(struct node* root)  ///////////////////////// find max
{
 if (root == NULL){return 0;}
 int res = root->Acc_Number;
 int lres = findMax(root->left);
 int rres = findMax(root->right);
 if (lres > res){res = lres;}
 if (rres > res)
      res = rres;
    return res;
}

bool search(struct node* temp, int x)  ///////////////////////// search
{
  while (temp != NULL)
    {
      
        if (x> temp->Acc_Number)
            temp = temp->right;

        
        else if (x < temp->Acc_Number)
           temp = temp->left;
        else
            return true;
    }
    return false;

}


int print_data(struct node* temp, int x) ///////////////////////// Print Function
{
 while (temp != NULL)
    {
    // pass right subtree as new tree
    if (x> temp->Acc_Number)
        temp = temp->right;

    // pass left subtree as new tree
    else if (x < temp->Acc_Number)
        temp = temp->left;
    else{
        cout<<"        ####################################################################################################################################"<<endl;
        cout<<" "<<endl;
        cout<<"          "<<"ACC_Number"<<"                 "<<"NAME"<<"                   "<<"CNIC"<<"                     "<<"GENDER"<<"            "<<"Type"<<"          "<<"Balance"<<endl;
        cout<<" "<<endl;
        cout<<"        ####################################################################################################################################"<<endl;
        cout<<" "<<endl;
        cout<<"             ";
        cout<<temp->Acc_Number;
        cout<<"            ";
        cout<<setw(18)<<temp->Name;
        cout<<"           ";
        cout<<temp->CNIC;
        cout<<"                ";
        cout<<temp->Gender;
        cout<<"                ";
        cout<<temp->Type;
        cout<<"             ";
        cout<<temp->bala<<endl;
        return true;
        }
    }
    return false;


}

void pre_order(struct node* temp)   ///////////////////////// pre order function
{
//cout << temp->pin<<endl;
if(temp->left != NULL){pre_order(temp->left);}
 //cout<<"          "<< setw(2)<<temp->Acc_Number;
 cout<<"             ";
 cout<<temp->Acc_Number;
 cout<<"            ";
 cout<<setw(18)<<temp->Name;
 cout<<"           ";
 cout<<temp->CNIC;
 cout<<"                ";
 cout<<temp->Gender;
 cout<<"                ";
 cout<<temp->Type;
 cout<<"             ";
 cout<<temp->bala<<endl;
 if(temp->right != NULL){pre_order(temp->right);}

}

void print_for_admin(struct node* temp)   ////////////////////////// print For order function
{
 if(temp->left != NULL){print_for_admin(temp->left);}
 cout<<"             ";
 cout<<temp->Acc_Number;
 cout<<"            ";
 cout<<setw(18)<<temp->Name;
 cout<<"           ";
 cout<<temp->CNIC;
 cout<<"                ";
 cout<<temp->Gender;
 cout<<"                ";
 cout<<temp->Type;
 cout<<"         ";
 cout<<temp->pin;
 cout<<"          ";
 cout<<temp->bala<<endl;
 if(temp->right != NULL){print_for_admin(temp->right);}

}



int deposit(struct node* temp,int acc_num,int PIN,int bal)   ///////////////////////// deposit Balance
{

 while (temp != NULL){
  if (acc_num> temp->Acc_Number){temp = temp->right;}
  else if (acc_num < temp->Acc_Number){temp = temp->left;}
  else{
    if(temp->pin == PIN){temp->bala= temp->bala +bal;}
    else if(temp->pin != PIN){return -1;}
       return 1;}}
  return 0;

}

int with_draw(struct node* temp,int acc_num,int PIN,int bal)   /////////////////////////  with_draw balance
{
 while (temp != NULL){
  if (acc_num> temp->Acc_Number){temp = temp->right;}
  else if (acc_num < temp->Acc_Number){temp = temp->left;}
  else{
    if(temp->pin == PIN){
        if((temp->bala < bal)){	return -1;	}
        else {temp->bala = temp->bala - bal;}}
	else if(temp->pin != PIN){return -2	;}
        return 1;}}
  return 0;

}


int change_info(struct node* temp,string name,string cnic,char gender,string type,int acc_num,int PIN)   ///////////////////////// Change Info
{

 while (temp != NULL){
  if (acc_num> temp->Acc_Number){temp = temp->right;}
  else if (acc_num < temp->Acc_Number){temp = temp->left;}
  else{
    if(temp->Acc_Number == acc_num){
           temp->Name = name;
           temp->CNIC = cnic;
           temp->Gender = gender;
           temp->pin = PIN;
           temp->Type = type;}

       return 1;}}
  return 0;

}

int check_acc_pin(struct node* temp,int acc_num,int PIN)   ///////////////////////// check acc & PIn number
{
 while (temp != NULL){
  if (acc_num> temp->Acc_Number){temp = temp->right;}
  else if (acc_num < temp->Acc_Number){temp = temp->left;}
  else{
    if(temp->pin == PIN){return 1;}
    else if(temp->pin != PIN){return -1;}}}

  return 0;

}


                                                          //-------------------xxxxxxxxxxxxxxxxx---------------------------\\


