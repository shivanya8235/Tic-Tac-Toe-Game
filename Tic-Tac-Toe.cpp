#include<iostream>
using namespace std;
 char Board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
 string s1;
 string s2;
 int row;
 int column;
 char token='x';
 bool tie=false;
 void f1(){
    cout<<"    |    |    \n";
    cout<<" "<<Board[0][0]<<"  | "<<Board[0][1]<<"  | "<<Board[0][2]<<" \n";
    cout<<"____|____|____\n";
    cout<<"    |    |    \n";
    cout<<" "<<Board[1][0]<<"  | "<<Board[1][1]<<"  | "<<Board[1][2]<<" \n";
    cout<<"____|____|____\n";
    cout<<"    |    |    \n";
    cout<<" "<<Board[2][0]<<"  | "<<Board[2][1]<<"  | "<<Board[2][2]<<" \n";
    cout<<"    |    |    \n";
 }

 void f2(){

 int digit;

 if(token=='x'){
   cout<<s1<<" Please Enter ";
   cin>>digit;
 }
 if(token=='0'){
   cout<<s2<<" Please Enter ";
   cin>>digit;
 }
 if(digit==1){
   row=0;
   column=0;
 }
 if(digit==2){
   row=0;
   column=1;
 }
 if(digit==3){
   row=0;
   column=2;
 }
 if(digit==4){
   row=1;
   column=0;
 }
 if(digit==5){
   row=1;
   column=1;
 }
 if(digit==6){
   row=1;
   column=2;
 }
 if(digit==7){
   row=2;
   column=0;
 }
 if(digit==8){
   row=2;
   column=1;
 }
 if(digit==9){
   row=2;
   column=2;
 }
 else if(digit<1 || digit>9){
 cout<<"Invalid!!!"<<endl;
 }

 if(token=='x' && Board[row][column]!='x' && Board[row][column]!='0'){
   Board[row][column]='x';
   token='0';
 }
 else if(token=='0' && Board[row][column]!='x' && Board[row][column]!='0'){
   Board[row][column]='0';
   token='x';
 }
 else{
   cout<<"There is no empty space!"<<endl;
   f2();
 }
 f1();

 }
 bool f3(){
   for(int i=0;i<3;i++){
      if(Board[i][0]==Board[i][1] && Board[i][0]==Board[i][2] || Board[0][i]==Board[1][i] && Board[0][i]==Board[2][i]){
         return true;
      }
   }
      if(Board[0][0]==Board[1][1] && Board[1][1]==Board[2][2] ||Board[0][2]==Board[1][1] && Board[1][1]==Board[2][0]){
         return true;
      }
     for(int i=0;i<3;i++){
       for(int j=0;j<3;j++){
         if(Board[i][j]!='x' && Board[i][j]!='0'){
            return false;
         }
       }
     }
     tie=true;
     return false;
 }
 
 int main(){
    cout<<"Enter the name of the player 1: \n";
    getline(cin,s1);
    cout<<"Enter the name of the player 2: \n";
    getline(cin,s2);

    cout<<s1<<" is the first player so,he/she will play first \n";
    cout<<s2<<" is the second player so,he/she will play the next \n";

   while(!f3()){
      f1();
      f2();
      f3();
   }
   if(token=='x' && tie==false){
      cout<<s2<<"Wins!"<<endl;
      cout<<s1<<" wants to play again"<<endl;

   }
   else if(token=='0' && tie==false){
      cout<<s1<<"Wins!"<<endl;
   }
   else{
      cout<<"Game is draw!"<<endl;
   }
 }
