#include <iostream>
#include <cstdlib>
#include <ctime>
#include "monster.h"

using namespace std;
class Player{
 public:
    int hp;
    int potions;
    int stone;
    Player():hp(100),potions(0),stone(0) {}

    bool alive(){
      return hp>0;
    }

    void takeDmg(int damage){
      hp-=damage;
    }

    bool HvyAtt() {
      int success = rand() % 10;  
      return success < 5; //chanceตีหนัก 30%
    }

    void usePotion(){
      if(potions>0){
        hp=100;  //use potion to restore Hp
        potions--;
        cout<< "You used a potion and restored your Hp to 100."<<endl;
      } 
      else cout<< "You don't have any potions left!" <<endl;
    }

    void adstone(){
      stone++;
    }

// use overloading operator to increase the potions //
    void operator++(){
      potions++;
      cout<< "You received a potion from the defeated monster!"<<endl;
    }
};


void displayOpt(Player& player){
 cout<< "Choose your action:" <<endl;
 cout<< "1. Heavy Attack (50% chance to double damage)" <<endl;
 cout<< "2. Normal Attack (100% hit with normal damage)" <<endl;
 cout<< "3. Use Potion (restore full health)" <<endl;
 cout<< "Potions: "<< player.potions <<endl;
}

void displaySt(const Player& player,const Monster& monster){
  cout<< "\n     Player's Hp: " << player.hp <<" | Monster's Hp: "         <<monster.hp<<endl;
}

void battle(Player& player, Monster& monster){
while(player.alive()&&monster.alive()){
  displaySt(player,monster);
  displayOpt(player);

    int choice;
    cout<<"Enter your choice (1-3): ";
    cin >>choice;

  switch(choice){
    case 1: {
      // Heavy Attack
        int success= player.HvyAtt();  //30% chance of success samesame with monster
          if(success ){
            int damage=rand()%6+20;  //Random damage between 10 and 30
            monster.takeDmg(damage);
            cout<< "You successfully landed a heavy attack, dealing "                     <<damage <<" damage." <<endl;
          } 
          else cout<< "\nYour heavy attack missed!" <<endl;
      break;
    }
        
    case 2:{
      // Normal Attack 
        int damage=rand()%11+5;  //Random damage between 5 and 15
        monster.takeDmg(damage);
        cout<< "\nYou landed a normal attack, dealing "<<damage<<
          " damage."<<endl;
      break;
    }
        
    case 3:{
      //Use Potion
        player.usePotion();
      break;
    }
            
    default:
      cout<< "Invalid choice. Please enter a number between 1 and 3."<<endl;
      continue;
    }
        
  if(!monster.alive()){
    displaySt(player,monster);
    cout <<"Hooray! You defeated the monster!"<<endl;
    if(monster.dropPotion()){
      ++player; // use overloading operator
    }
  return;
  }
        //Monsters turn
        bool hvyAttSuccess=monster.HvyAtt();
        if(hvyAttSuccess){
            int damage=monster.calAttDmg();
            damage*=2;  // Double damage for monste heavy attack
            player.takeDmg(damage);
            cout<<"The monster successfully landed a heavy attack, dealing "<<damage<<" damage!"<<endl;
        } 
        else{
            int damage=monster.calAttDmg();
            player.takeDmg(damage);
            cout<<"The monster landed a normal attack, dealing "<<damage<<" damage."<<endl;
        }
        if(!player.alive()){
            displaySt(player,monster);
            cout<<"Damn!! you are a noob. "<<"You were defeated by the monster. Game over."<<endl;
            exit(0);
        }
    }
}

void bossbattles(Player& player,Monster& monster){
  while(player.alive() && monster.alive()){
  displaySt(player,monster);
  cout<< "Choose your action:" <<endl;
  cout<< "1. Dice game to steal the stone!" <<endl;
  cout<< "2. Normal Attack (100% hit with normal damage)" <<endl;
  cout<< "3. Use Potion (restore full health)" <<endl;
  cout<< "Potions: "<< player.potions <<endl;
    

    int choice;
    cout<<"Enter your choice (1-3): ";
    cin>>choice;
    int i = player.stone + 1;
    switch(choice){
      case 1:{
        int number;
        int response;
        srand(time(NULL));

        number = rand() % 4+1;

          do{
            cout<<"Enter your guess (1-4): ";
              cin>>response;
            if(response>number){
              int damage = 3;
              cout<<"Too high!"<<endl;
              player.takeDmg(damage);
              cout<<"Thanos successfully landed a heavy attack, dealing "<<damage<<" damage!"<<endl;
              displaySt(player,monster);

            }
            else if (response < number){
              int damage = 3;
              cout<<"Too low!"<<endl;
              player.takeDmg(damage);
              cout<<"Thanos successfully landed a heavy attack, dealing "<<damage<<" damage!"<<endl;
              displaySt(player,monster);
            }
            else{
              int damage = 10;
              cout<<"You won!"<<endl;
              cout<<"Number is "<<number<<endl;
              monster.takeDmg(damage);
              cout<< "\nYou landed a diced attack, dealing " <<damage <<" damage." <<endl;
              player.adstone();
              if(monster.dropPotion()){++player;}
              cout<< "\nYou stealed a stone from Thanos!!" <<endl;
              cout<<"Stone count = "<< player.stone<<endl;
              displaySt(player,monster);
            }
          }
          while(response!=number);

        // cout<<"Out of Time!"<<endl;
        // cout<<"Number is "<<number<<endl;
   }
      case 2:{
          // Normal Attack
          // int i = player.stone;
          int damage=(rand()%11+5)*i;  //Normal attack multiply the stone collected from Thanos
          monster.takeDmg(damage);
          cout<< "\nYou landed a special attack, dealing " <<damage <<" damage." <<endl;
          break;
      }
      case 3:{
          //Use Potion
          player.usePotion();
          break;
      }
    }

    bool hvyAttSuccess=monster.HvyAtt();
    if(hvyAttSuccess){
        int damage=monster.calAttDmg();
        damage*=2;  // Double damage for monste heavy attack
        player.takeDmg(damage);
        cout<<"The monster successfully landed a heavy attack, dealing "<<damage<<" damage!"<<endl;
    } 
    else{
        int damage=monster.calAttDmg();
        player.takeDmg(damage);
        cout<<"The monster landed a normal attack, dealing "<<damage<<" damage."<<endl;
    }
    if(!player.alive()){
        displaySt(player,monster);
        cout<<"Damn!! you are a noob. "<<"You were defeated by the monster. Game over."<<endl;
        exit(0);
    }
     // else cout<<"=============================================="<<endl;
     //  cout<<"\nCongratulations! You have defeated Thanos and saved the universe. You win!!!"<< endl;
  }
}

int bossquiz(Player& player){
  int count=0,x;

  cout<<"\n\n'Now Human! Tell me some good reasons that\nI should not kill half of your population to protect this \nGlobal Warming!!'-THANOS\n"<<endl;
  cout<<"=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n"<<endl;
  cout<<"'If you manage to answer all my questions CORRECTLY,\nI will let you live. If NOT, you will have to face ME \nAGhHAHAHHA!!' -THANOS"<<endl;
  
  
//Q.1/////////////////////// ans 3 na.
  cout<<"\n\nQuestion 1: Which of the following is NOT a greenhouse gas contributing to global warming?"<<endl;
  cout<<"1. CO2 (Carbon Dioxide)"<<endl;
  cout<<"2. CH4 (Methane)"<<endl;
  cout<<"3. O2  (Oxygen)"<<endl;
  cout<<"4. N2O (Nitrous Oxide)"<<endl;
while(true){
  cout<<"Answer: ";
  cin>>x;
  if(x==3){
    cout<<"Correct! Not bad for the first question!"<<endl;
    count++;
    break;
  }  
  else if(x<1||x>4){
    cout<<"Invalid choice. Please enter a number between 1-4."<<endl;
  }
  else{
    cout<<"Wrong!"<<endl;
    break;
  }
}  

//Q.2/////////////////////// ans 4.
  cout<<"\nQuestion 2: What is the primary source of human-caused carbon dioxide emissions?"<<endl;
  cout<<"1. Industrial processes"<<endl;
  cout<<"2. Deforestation"<<endl;
  cout<<"3. Agriculture"<<endl;
  cout<<"4. Burning fossil fuels"<<endl;
  while(true){
    cout<<"Answer: ";
    cin>>x;
    if(x==4){
      cout<<"Correct!"<<endl;
      count++;
      break;
    }  
    else if(x<1||x>4){
      cout<<"Invalid choice. Please enter a number between 1-4."<<endl;
    }
    else{
      cout<<"Wrong!"<<endl;
      break;
    }
  }  
  
//Q.3/////////////////////// ans 1.
  cout<<"\nQuestion 3: What is the main consequence of melting polar ice caps due to global warming?"<<endl;
  cout<<"1. Increased sea levels"<<endl;
  cout<<"2. Reduced ocean acidity"<<endl;
  cout<<"3. Expansion of polar bear habitats"<<endl;
  cout<<"4. Decreased rainfall patterns"<<endl;
  while(true){
    cout<<"Answer: ";
    cin>>x;
    if(x==1){
      cout<<"Correct! 2 Only question left!!"<<endl;
      count++;
      break;
    }  
    else if(x<1||x>4){
      cout<<"Invalid choice. Please enter a number between 1-4."<<endl;
    }
    else{
      cout<<"Wrong!"<<endl;
      break;
    }
  }  
  
//Q.4/////////////////////// ans 1.
  cout<<"\nQuestion 4: Which renewable energy source has the highest potential for reducing carbon emissions?"<<endl;
  cout<<"1. Solar power"<<endl;
  cout<<"2. Wind power"<<endl;
  cout<<"3. Geothermal energy"<<endl;
  cout<<"4. Hydroelectric power"<<endl;
  while(true){
    cout<<"Answer: ";
    cin>>x;
    if(x==1){
      cout<<"Correct!"<<endl;
      count++;
      break;
    }  
    else if(x<1||x>4){
      cout<<"Invalid choice. Please enter a number between 1-4."<<endl;
    }
    else{
      cout<<"Wrong!"<<endl;
      break;
    }
  }  

//Q.5/////////////////////// ans 2.
  cout<<"\nQuestion 5: Which of the following is NOT a solution for global warming?"<<endl;
  cout<<"1. Using compact florescent light (CFL) bulbs"<<endl;
  cout<<"2. Deforestaion"<<endl;
  cout<<"3. Reducing fossil feul consumption"<<endl;
  cout<<"4. Planting more trees"<<endl;
  while(true){
    cout<<"Answer: ";
    cin>>x;
    if(x==2){
      cout<<"Correct!"<<endl;
      count++;
      break;
    }  
    else if(x<1||x>4){
      cout<<"Invalid choice. Please enter a number between 1-4."<<endl;
    }
    else{
      cout<<"Wrong!"<<endl;
      break;
    }
  } 
  return count;
}  




void sortMonsters(Monster *monsters,int size){
    for(int i=0;i<size-1;++i){
      for(int j=0;j<size-i-1;++j){
        if(monsters[j].hp>monsters[j+1].hp){
          swap(monsters[j],monsters[j+1]);
   }
  }
 }
}

