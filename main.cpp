#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>
#include <cstring>
#include <iomanip>
#include <ios>
// #include "monster.h"
#include "player.h"
#include "LL.h"
#include "Queue.h"

using namespace std;

int main() {
  int p;
  Queue q;
  do{
    srand(time(0));  
  Player player;
  // const int numMonsters = 3;
  LL monsterList;
  //int id;
  string name;

  //CHANGE from array to Linked List.....
  monsterList.insert(Monster(20));
  monsterList.insert(Monster(30));
  monsterList.insert(Monster(40));
  monsterList.sortMonsters();  
  
  //use sorting to sort the monsters that player have to face up with
  // Monster monsters[numMonsters] = {Monster(20), Monster(40), Monster(30)};  
  // sortMonsters(monsters,numMonsters); 
  
  cout << "⠀⠀⠀⠀       ⠀⠀⠀⣠⢴⠶⠀⠀⠀⠀⠀⠀⠀⠀⠀⠤⡄⡀ \n"
     "⠀⠀⠀⠀       ⠀⢰⠄⢇⠀⠀⠀⠀⣠⠒⡐⢂⠀⠀⠀⣸⠩⡄⠀⠀⠀ \n"
     "⠀⠀⠀⠀       ⠀⠘⡄⢠⠊⣙⠕⠁⠰⢀⣁⠼⡙⠕⡎⠢⢈⠇⠀⠀⠀ \n"
     "⠀⠀   ⠀    ⠀⢀⡄⣸⣰⢝⡎⠀⡆⠂⢐⣬⠉⢢⠈⣜⢪⣇⠠⢤⡀⠀ \n"
     "⠀⠀       ⠀⠀⡠⠋⠀⡔⠩⢿⠀⠘⢦⣀⡨⢟⣀⣸⠀⣟⠣⠕⠒⡀⢡⠀\n"
     "⠀       ⠀⢀⢴⠁⠀⣜⡀⠀⠸⠀⠀⣀⢤⠒⣒⠺⠆⠀⡇⠀⢀⢤⠇⢀⡆\n"
     "       ⡀⠀⣘⣵⢀⢠⡦⠇⠀⠀⡇⣬⣧⣆⣣⣋⣃⣸⣤⠁⠀⢸⣴⠀⠈⡹\n"
     "       ⠻⡽⠭⢿⡟⢩⠁⠀⢀⡠⢗⠙⣉⣁⣒⡊⠒⡅⡎⠀⠀⠀⠑⠚⠚⠁\n"
     "⠀       ⠈⡩⢋⠕⣉⠄⢊⢡⠔⠈⣇⠀⠀⠀⠀⢀⡇⠃⢄⠀⠀⠀⠀⠀⠀\n"
     "⠀⠀       ⠘⢤⣭⡰⠬⠒⢁⠔⠈⠀⠈⠉⠉⠉⠁⠀⠑⠤⠁⢒⠀⠀⠀⠀\n"
     "⠀   ⠀    ⠀⠀⠀⠀⠈⠃⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⡌⠀⢀⠏⠀⠀⠀⠀\n"
     "⠀       ⠀⠀⢀⣤⢤⠤⡃⠀⠱⠀⠀⠀⠀⠀⠀⢀⣜⠀⡠⢦⠠⣄⠀⠀⠀\n"
     "⠀⠀       ⠀⠘⠣⠧⠤⠄⠀⠐⠁⠀⠀⠀⠀⠀⠘⠒⠒⠀⠘⠒⠛⠀⠀⠀" <<endl;
  /*cout<< "  ! Welcome to the game, Our brave warrior !"<< endl;
  cout<< "*Your goal is to defeat 3 monsters and face the final boss, Thanos.*"<< endl;
*/
  cout<<"+-------------------------------------------+"<<endl;
  cout<<"|    Welcome to the game, Brave Warrior!    |"<<endl;
  cout<<"|                                           |"<<endl;
  cout<<"|  Your goal: defeat 3 monsters and face    |"<<endl;
  cout<<"|             the final boss, Thanos.       |"<<endl;
// cout<<"|                                           |"<<endl;
  cout<<"+-------------------------------------------+"<<endl;

    node* current = 
  monsterList.getHead();
  int i=0;
  while(current){
    Monster currentMonster = current -> monster;
    cout<< "\n                ☠ Monster " <<i+1<<" ☠"<<endl;
    battle(player,currentMonster);
    current = current->next;
    i++;
  }


//Global warming quiz
  int check=bossquiz(player);
  
//If fail Attack boss
  if(check<3){
    cout<<"\n\nYou fail HAHAHA. I'm going to kill you all."<<endl;
    cout<< "\n----- 𓆩Final Boss Thanos𓆪 -----"<<endl;
    Monster thanos(200);  

    bossbattles(player,thanos);   

    cout<<"\n =======================================================" << endl;
    cout<<"\nCongratulations! You have defeated Thanos and saved the universe. You win!!!"<< endl;
}

//Successfully swayed Thanos' mind   
  // Queue q;
    else{ cout<<"\nGreat Warrior!\n You have showed me that you cared for your own planet...\n I shall leave you alone and you keep conserve this \n BEAUTIFUL star called Earth! \nFare well... \n-THANOS"<<endl;
    
    cout<<"Enter the name to save the passing Thanos test streak:"<<endl;
    cin >> name ;
    q.enqueue(name,check);
    cout<<"Thanos has left the planet earth..." <<endl;  
    cout<<"CONGRATULATION! You have successfully saved the universe!!!"<<endl;

    cout<<"Winning global warming test streak: " <<endl;
    q.print(check);

    }
    
    cout<<"\n\nDo you want to play again? (Yes press 1/No press 2): "<<endl;
    cin>>p;  
  }while(p==1);
  
/*  q.enqueue(id,name);
cout<<"Thanos have left the planet earth..."<<endl;  
cout<<"CONGRATULATION! You have successfully saved the universe!!!"<<endl; */
  return 0; 
}






