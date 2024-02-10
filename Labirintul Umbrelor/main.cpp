#include <bits/stdc++.h> //librarie care contine toate librariile C++
using namespace std;



void hr(){//horizontal rule - pentru organizarea textului
    cout<<"--------------------------------------------"<<endl;
}

///constant values
const int maxHealth = 5;
const int maxEnergy = 100;

///creates players and enemies
struct character{
    string name, abilityName; // name of ability (4)
    int hp, defence, energy, damage, shield; // 1-normal attack, 2-charged attack, 3-heal, 4-ability
};

character player[6];
character enemy[100];
void initializePlayers(){
    ///player characters
    player[1] = {"Aqua", "Full Heal!", 5, 0, 100, 1, 0}; //water
    player[2] = {"Sylvanus", "Strong Shield", 5, 0, 100, 3, 0}; //wood
    player[3] = {"Ignis", "Burn!", 5, 0, 100, 2, 0}; //fire
    player[4] = {"Aurum", "Full Shield!", 5, 0, 100, 1, 0}; //metal
    player[5] = {"Terra", "Strong Heal!", 5, 0, 100, 2, 0}; //earth
    ///enemy characters
    enemy[1] = {"goblin", "Stick Throw!", 5, 0, 100, 1, 0};
    enemy[2] = {"skeleton", "Stick Throw!", 6, 0, 100, 2, 0};
    enemy[3] = {"wolf", "Stick Throw!", 4, 0, 100, 3, 0};
    enemy[4] = {"zombie", "Stick Throw!", 8, 0, 100, 1, 0};
    enemy[5] = {"ghost", "Stick Throw!", 7, 0, 100, 2, 0};
    enemy[6] = {"dark entity", "Stick Throw!", 20, 0, 100, 2, 0};
}

void startStory(){
    cout<<"The Shadow Labyrinth!"<<endl;
    hr();
    cout<<"In the elemental world, the Shadows have taken the Light, forcing an era of darkness upon the world"<<endl;
    cout<<"Five heroes, representing their elemental nation, have formed a team and decided to take on the challenge of finding the light and bringing it back!"<<endl;
    cout<<"The light is kept in a strange labyrinth, called the Shadow Labyrinth, filled with monsters and traps!"<<endl;
    cout<<"Will the heroes manage to find the light and abolish the dark curse from the world, of will they ultimately find their doom?"<<endl;
    cout<<"Good luck! You'll need it! Hahahaha!"<<endl;
}

void win(){
    hr();
    cout<<"Thanks to your team's heroic efforts, the light was found and balance returned to the Elemental World!"<<endl;
    cout<<"You and your team will forever be seen as the heroes of this world, and will forever be remembered!"<<endl;
    cout<<"Congratulations!";
    exit(0);
}

void lose(){
    hr();
    cout<<"You lost!";
    exit(0);
}

void showStats(){
    cout<<endl;
    hr();
    for(int i=1; i<6; i++){
        cout<<player[i].name<<endl;
        cout<<"Health = "<<player[i].hp<<endl;
        cout<<"Energy = "<<player[i].energy<<endl;
        cout<<"Damage = "<<player[i].damage<<endl;
        cout<<"Special Ability = "<<player[i].abilityName<<endl;
        cout<<endl;
    }
    hr();
}

void checkDeath(){
    for(int i=1; i<6; i++){
        if(player[i].hp<=0){
            cout<<"Oh no! "<<player[i].name<<" has died!"<<endl;
            lose();
        }
    }
}

void fight(character enemyClass){
    character enemy = enemyClass;
    int round = 1;
    int action;
    int action2;
    int a=0;
    while(a<1){
        hr();
        if(round%2==1){
            cout<<"Who do you want to go?"<<endl;
            cout<<"Aqua(1)"<<endl;
            cout<<"Sylvanus(2)"<<endl;
            cout<<"Ignis(3)"<<endl;
            cout<<"Aurum(4)"<<endl;
            cout<<"Terra(5)"<<endl;
            hr();
            cout<<"Action: ";
            cin>>action;
            hr();
            while(action<1 || action>5){
                cout<<endl<<"That's not a valid response. The response must be a number from the list. Please re-enter your response:"<<endl;
                cout<<"Action: ";
                cin>>action;
                hr();
            }
            cout<<"What do you want "<<player[action].name<<" to do?"<<endl;
            if(player[action].energy>=10) cout<<"Normal attack       (1) - lose 10 energy"<<endl;
            if(player[action].energy>=20) cout<<"Heavy Attack        (2) - lose 20 energy"<<endl;
            if(player[action].energy>=30) cout<<"Heal itself         (3) - lose 30 energy"<<endl;
            if(player[action].energy>=50) cout<<"Use Special Ability (4) - lose 50 energy"<<endl;
            if(player[action].energy>=0)  cout<<"Rest                (5) - gain 40 energy"<<endl;
            hr();
            cout<<"Action: ";
            cin>>action2;
            hr();
            while(action2<1 || action2>5 || (player[action].energy<10 && action2 == 1) || (player[action].energy<20 && action2 == 2) || (player[action].energy<30 && action2 == 3) || (player[action].energy<50 && action2 == 4)){
                cout<<endl<<"That's not a valid response. The response must be a number from the list. Please re-enter your response:"<<endl;
                cout<<"Action: ";
                cin>>action2;
                hr();
            }
            if(action2 == 5){
                player[action].energy += 40;
                if(player[action].energy>maxEnergy) player[action].energy = maxEnergy;
                cout<<player[action].name<<" now has "<<player[action].energy<<" energy!"<<endl;
                hr();
            }
            if(action2 == 1){
                player[action].energy-=10;
                int rand1 = rand()%5+1;
                if(rand1 == 5){
                    cout<<"Attack missed!"<<endl;
                }
                else{
                    cout<<"You used Normal Attack!"<<endl;
                    int damage = player[action].damage + rand()%2;
                    cout<<player[action].name<<" dealt "<<damage<<" damage to "<<enemy.name<<endl;
                    enemy.hp -= damage;
                    if(enemy.hp<0) enemy.hp = 0;
                    cout<<"The "<<enemy.name<<" now has "<<enemy.hp<<" HP left!"<<endl;
                    if(enemy.hp==0)a++;
                }
            }
            else if(action2 == 2){
                player[action].energy-=20;
                int rand1 = rand()%4+1;
                if(rand1 == 4){
                    cout<<"Attack missed!"<<endl;
                }
                else{
                    cout<<"You used Heavy Attack!"<<endl;
                    int damage = player[action].damage + rand()%3 + 1;
                    cout<<player[action].name<<" dealt "<<damage<<" damage to "<<enemy.name<<endl;
                    enemy.hp -= damage;
                    if(enemy.hp<0) enemy.hp = 0;
                    cout<<"The "<<enemy.name<<" now has "<<enemy.hp<<" HP left!"<<endl;
                    if(enemy.hp==0)a++;
                }
            }
            else if(action2 == 3){
                player[action].energy-=30;
                player[action].hp += 2;
                if(player[action].hp>maxHealth) player[action].hp = maxHealth;
                cout<<player[action].name<<" healed."<<endl;
                cout<<player[action].name<<" now has "<<player[action].hp<<" HP!"<<endl;
            }
            else if(action2 == 4){
                player[action].energy-=50;
                cout<<player[action].name<<" used "<<player[action].abilityName<<"!"<<endl;
                ///Aqua's special ability
                if(action == 1){
                    for(int i=1; i<6; i++){
                        player[i].hp+=2;
                        if(player[i].hp>maxHealth) player[i].hp = maxHealth;
                    }
                    cout<<"All allies have been healed 2 HP!"<<endl;
                }
                ///Sylvanus's special ability
                else if(action == 2){
                    int resp;
                    cout<<"Who do you want to use "<<player[action].abilityName<<" on?"<<endl;
                    cout<<"Aqua(1)"<<endl;
                    cout<<"Sylvanus(2)"<<endl;
                    cout<<"Ignis(3)"<<endl;
                    cout<<"Aurum(4)"<<endl;
                    cout<<"Terra(5)"<<endl;
                    hr();
                    cout<<"Action: ";
                    cin>>resp;
                    hr();
                    while(action<1 || action>5){
                        cout<<endl<<"That's not a valid response. The response must be a number from the list. Please re-enter your response:"<<endl;
                        cout<<"Action: ";
                        cin>>resp;
                        hr();
                    }
                    player[resp].shield+=3;
                    cout<<player[resp].name<<" now has "<<player[resp].shield<<" shield!"<<endl;
                }
                ///Ignis's special ability
                else if(action == 3){
                    int damage = player[action].damage + rand()%5 + 1;
                    cout<<player[action].name<<" dealt "<<damage<<" damage!";
                    enemy.hp -= damage;
                    if(enemy.hp<0) enemy.hp = 0;
                    cout<<"The "<<enemy.name<<" now has "<<enemy.hp<<" HP left!"<<endl;
                    if(enemy.hp==0)a++;
                }
                ///Aurum's special ability
                else if(action ==4){
                    for(int i=1; i<6; i++){
                        player[i].shield++;
                    }
                    cout<<"All allies have gained 1 shield point!"<<endl;
                }
                ///Terra's special ability
                else if(action == 5){
                    int resp;
                    cout<<"Who do you want to use "<<player[action].abilityName<<" on?"<<endl;
                    cout<<"Aqua(1)"<<endl;
                    cout<<"Sylvanus(2)"<<endl;
                    cout<<"Ignis(3)"<<endl;
                    cout<<"Aurum(4)"<<endl;
                    cout<<"Terra(5)"<<endl;
                    hr();
                    cout<<"Action: ";
                    cin>>resp;
                    hr();
                    while(action<1 || action>5){
                        cout<<endl<<"That's not a valid response. The response must be a number from the list. Please re-enter your response:"<<endl;
                        cout<<"Action: ";
                        cin>>resp;
                        hr();
                    }
                    player[resp].hp+=4;
                    cout<<player[resp].name<<" now has "<<player[resp].hp<<" HP!"<<endl;
                }
            }
        }
        else{
            int randPlayer = rand()%5 + 1;
            int damage = enemy.damage + rand()%3;
            int damageCopy = damage;
            int hit = rand()%7 + 1;
            if(hit != 7){
                player[randPlayer].shield-=damage;
                if(player[randPlayer].shield<0){
                    damage = player[randPlayer].shield*-1;
                    player[randPlayer].shield = 0;
                    player[randPlayer].hp -= damage;
                    if(player[randPlayer].hp<0) player[randPlayer].hp = 0;
                }
                cout<<"The "<<enemy.name<<" dealt "<<damageCopy<<" damage to "<<player[randPlayer].name<<"!"<<endl;
                cout<<player[randPlayer].name<<" now has "<<player[randPlayer].hp<<" HP and "<<player[randPlayer].shield<<" shield!"<<endl;
                checkDeath();
            }
            else{
                cout<<"Phew! The attack missed!"<<endl;
            }
        }
        round++;
    }
    cout<<endl;
    hr();
    cout<<"Congratulations! You won the battle!"<<endl;
    hr();
}

void run(character enemyClass){
    hr();
    character enemy = enemyClass;
    int randNum = rand()%6+1;
    int randDmg = rand()%2+1;
    if(randNum<6){
        cout<<"You managed to run, but the "<<enemy.name<<" dealt ("<<randDmg<<") damage to "<<player[randNum].name<<"!";
        cout<<endl;
        player[randNum].hp-=randDmg;
        checkDeath();
    }
    else{
        cout<<"You managed to escape the "<<enemy.name<<" unscathed!";
        cout<<endl;
        hr();
    }
}

void negotiate(character enemyClass){
    character enemy = enemyClass;
    int randNum = rand()%2+1;
    hr();
    cout<<"You tried to negotiate with the "<<enemy.name<<"."<<endl;
    if(randNum==1){
        cout<<"(It worked!)"<<endl;
        cout<<"The "<<enemy.name<<" told you to have a nice day and left."<<endl;
    }
    else{
        cout<<"(It failed!)"<<endl;
        cout<<"You must fight him!";
        cout<<endl;
        fight(enemy);
    }
}


void approachedByEnemy(character enemyClass){
    character enemy = enemyClass;
    string response;
    hr();
    cout<<"You were suddenly approached by a "<<enemy.name<<"!"<<endl<<endl;
    cout<<"What will you do?"<<endl;
    cout<<"Fight (1)"<<endl;
    cout<<"Run (2)"<<endl;
    cout<<"Try to negotiate (3)"<<endl;
    hr();
    cout<<"Action: ";
    cin>>response;
    while(response!="1" && response!="2" && response !="3"){
        cout<<endl<<"That's not a valid response. The response must be a number between 1 and 3. Please re-enter your response:"<<endl;
        cout<<"Action: ";
        cin>>response;
    }
    if(response=="1"){fight(enemy);}
    else if(response=="2"){run(enemy);}
    else if(response=="3"){negotiate(enemy);}
}

void trap(){
    hr();
    cout<<"Oh no! You fell into a trap!"<<endl;
    int randPlayer = rand()%6+1;
    int damage = rand()%2;
    if(damage==0){
        cout<<"Fortunately, everyone was able to escape unharmed!";
    }
    else if(randPlayer == 6){
        cout<<"Being pushed one after another, you WHOLE team was dealt "<<damage<<" damage!"<<endl;
        for(int i=1; i<6; i++){
            player[i].hp-=damage;
        }
        checkDeath();
    }
    else{
        cout<<"Unfortunately, "<<player[randPlayer].name<<" was hurt and lost "<<damage<<" HP!"<<endl;
        player[randPlayer].hp-=damage;
    }
    hr();
}

void randomEventFunct(int num){
    hr();
    if(num==1){
        cout<<"What luck! You found a fountain in the labyrinth! Your whole team gained 2 life points! :D"<<endl;
        for(int i=1; i<6; i++){
            player[i].hp+=2;
        }
    }
    else if(num==2){
        int randPlayer = rand()%5+1;
        cout<<player[randPlayer].name<<" found a lucky coin!"<<endl;
        int randShield = rand()%4+1;
        cout<<player[randPlayer].name<<" doesn't know it yet, but has gained"<<randShield<<"points of shield! :)"<<endl;
        player[randPlayer].shield+=randShield;
    }
    else if(num==3){
        int randShield = rand()%2+1;
        cout<<"Wow, who would have thought that you would find an old armory?? Your whole team geared up and gained"<<randShield<<" points of shield!!"<<endl;
        for(int i=1; i<6; i++){
            player[i].shield+=randShield;
        }
    }
    else if(num==4){
        cout<<"You found a small fire camp. Though it's not much, it helped your team relax and get ready to continue the adventure more relaxed!"<<endl;
        cout<<"Your energy has been replenished to 100!"<<endl;
        for(int i=1; i<6; i++){
            player[i].energy=100;
        }
    }
    hr();
}

void moveThroughLabyrinth(){
    hr();
    cout<<"There are three paths in front of you, each leading to a different place in the labyrinth."<<endl;
    cout<<"Upon entering one of the rooms, the doors will be forever shut, not allowing you to go back."<<endl;
    hr();
    cout<<"So, where do you want to go?"<<endl;
    cout<<"Forwards (F)"<<endl;
    cout<<"Right (R)"<<endl;
    cout<<"Left (L)"<<endl;
    cout<<"Press (S) to see your team's stats"<<endl;
    string resp;
    hr();
    cout<<"Action: ";
    cin>>resp;
    while(resp!="F" && resp!="R" && resp !="L" && resp!="f" && resp!="r" && resp !="l" && resp!="S" && resp!="s"){
        cout<<endl<<"That's not a valid response. The response must be a number between 1 and 3. Please re-enter your response:"<<endl;
        cout<<"Action: ";
        cin>>resp;
    }
    int randomEvent = rand()%101; ///Nu am mai avut timp sa fac mersul prin labirint :((
    if(resp == "S" || resp == "s") showStats();
    else{
        if(randomEvent==100) win();
        else if(randomEvent<100 && randomEvent >= 80)trap();
        else if(randomEvent<80 && randomEvent>=40){
            int randomEnemy = rand()%6 + 1;
            approachedByEnemy(enemy[randomEnemy]);
        }
        else if(randomEvent <40 && randomEvent>=0){
            randomEventFunct(randomEvent%10);
        }
    }
}

void StartGame(){
    startStory();
    int i=1;
    while(i){
        moveThroughLabyrinth();
    }
}

int main()
{
    srand((unsigned) time(NULL));
    initializePlayers();
    StartGame();
    return 0;
}
