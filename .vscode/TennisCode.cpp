#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>    
#include <time.h>

/* EXAMPLE OF INPUT:
4 (number of players participating in the tournament)
Alex 5 (the numbers are the utr ranks, so after the name put a space and number for each player)
Dan 8
Joe 9
Chris 3*/

using namespace std;
 
 struct x{
     string name;
     int utr;
   
  };
 
  bool func (x i, x j) {
     return (i.utr > j.utr);
  }
   
   bool result (int i, int j){
      int r = (rand() % (100)+1);
      //cout<< r<<" ";
      if(j==1){
         return true;
      }else if (i >= 8){
         if(r>5){
            return true;
         }else{
            return false;
         }
      }else if((i==6) or (i==7)){
         if(r>10){
            return true;
         }else{
            return false;
         }
      }else if((i==4)or(i==5)){
         if(r>20){
            return true;
         }else{
            return false;
         }
      }else if((i==2) or (i==3)){
         if(r>30){
            return true;
         }else{
            return false;
         }
      }else if(i==1){
         if(r>40){
            return true;
         }else{
            return false;
         }
      }else if(i==0){
         if(r>50){
            return true;
         }else{
            return false;
         }
      }
      return 0;
   }
     
   void swi(int& a, int& b,  string& c, string& d){        
      int x;
      string y;
      x = b;
      b = a;
      a = x;
      y = d;
      d = c;
      c = y;
   }
   
   void score(int& x, int& y){
      x=6;
      y = (rand() % 7);
      if((y==5)or(y==6)){
         x++;
      }
   }
     
int main() {
   
   int n;
  //cout<<"Number of players: [2, 4, 8, 16, 32, 64, 128]";
  cin>>n;
 
  vector <x> players(n);
 
  for(int i=0; i<n; i++){
     //cout<<"Player name: ";
     cin>>players[i].name;
      //cout<<"Player UTR: "; // UTR = Universal Tennis Rating
     cin>>players[i].utr;
  }

   sort(players.begin(), players.end(), func);
   
   cout<< "Number of players: " << n << endl;
   for(int i=0; i<n; i++){
      cout<<players[i].name<<" "<<"("<<players[i].utr<<")"<<endl;
   }
   
   vector <x> draw(n);
   
   for(int i=0; i<n/2; i++){
      draw[i].name = players[i].name;
      draw[i].utr = players[i].utr;
   }
 
   srand (time(NULL));
   int r = (rand() % (n/2)) + n/2;
   
   int aux[n];
   for(int i=0; i<n; i++){
      aux[i]=0;
   }
   
   for(int i=n/2; i<n; i++){
      while(aux[r]==1){
         r = (rand() % (n/2)) + n/2;
      }
      draw[i].name = players[r].name;
      draw[i].utr = players[r].utr;
      aux[r]=1;
   }
   
   int j=n-1;
   int bye=0;
   int z, q, w, dif;
   int l=0;
   int n1=n;
   vector <x> update(n);
   
   cout << "\n";
   
   while (n!=1){
      z=0;
      cout<<"Matches: \n";
      for(int i=0; i<n/2; i++){
         dif = (draw[i].utr-draw[j].utr);
         if(draw[j].utr==0){
            bye=1;
            n1--;
         }
         if(draw[i].utr < draw[j].utr){
            swi(draw[i].utr, draw[j].utr, draw[i].name, draw[j].name);  
         }
         cout<<draw[i].name<<" "<<"("<<draw[i].utr<<")"<<" vs "<<draw[j].name<<" "<<"("<<draw[j].utr<<") ->   ";
         if((result(dif, bye))==true){
            score(q,w);
            if(bye==0){
               cout<<draw[i].name<<"("<<draw[i].utr<<")"<<" -> "<<q<<" x "<< w <<endl;
            }else{
               cout<<draw[i].name<<"("<<draw[i].utr<<")"<<endl;
            }
            if(dif==0){
               update[l].name = draw[j].name;
               update[l].utr = draw[j].utr;
               l++;
               draw[z].name = draw[i].name;
               draw[z].utr = draw[i].utr+1;
               z++;
            }else{
               update[l].name = draw[j].name;
               update[l].utr = draw[j].utr;
               l++;
               draw[z].name = draw[i].name;
               draw[z].utr = draw[i].utr;
               z++;
            }
         }else{
            score(q,w);
            if(bye==0){
               cout<<draw[j].name<<"("<<draw[j].utr<<")"<<" -> "<<q<<" x "<< w <<endl;
            }else{
               cout<<draw[j].name<<"("<<draw[j].utr<<")"<<endl;
            }
            if(dif==0){
               update[l].name = draw[i].name;
               update[l].utr = draw[i].utr;
               l++;
               draw[z].name = draw[j].name;
               draw[z].utr = draw[j].utr+1;
               z++;
            }else{
               update[l].name = draw[i].name;
               update[l].utr = draw[i].utr-1;
               l++;
               draw[z].name = draw[j].name;
               draw[z].utr = draw[j].utr+1;
               z++;
            }
               
         }
         j--;
         bye=0;
      }    
     
      cout << "\n";
      cout << "Winner(s):\n";
      n=n/2;
      for(int i=0; i<n; i++){
         cout<<draw[i].name<<" "<<"("<<draw[i].utr<<")"<<endl;
      }
     
      cout << "\n";
   }
   
   update[l].name = draw[0].name;
   update[l].utr = draw[0].utr;
   
   cout << "New UTR: \n\n";
   
   sort(update.begin(), update.end(), func);
   
   for(int i=0; i<n1; i++){
         cout<<update[i].name<<" "<<"("<<update[i].utr<<")"<<endl;
      }
   
   return 0;
}