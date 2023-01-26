#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <iomanip>

using namespace std;

const int INVY_SIZE = 10;


void dispInv(string invy[], int &invySpaceOn, int g)
{
    cout << "Inventory:          Gold: " << g << endl;
    for (int y = 0; y < invySpaceOn; y++)
    {
        cout << y+1 << ". " << invy[y] << endl;
    }
}

void itemSwap(string invy[], int &invySpaceOn, int invySpaceChange)
{
    string temp = "blank";
    for (int x = invySpaceChange; x < invySpaceOn-1; x++)
    {
        temp = invy[x];
        invy[x] = invy[x+1];
        invy[x+1] = temp;
    }
    invySpaceOn--;
}

void itemBuy(string itemName, string invy[], int &invySpOn, int &g, int cost)
{
    if (invySpOn < INVY_SIZE && g >= cost)
    {
        cout << "You bought a " << itemName << "." << endl;
        invy[invySpOn] = itemName;
        invySpOn++;
        g-=cost;
    }
    else if (g < cost) cout << "You can't afford that." << endl;
    else cout << "Your inventory is full." << endl;
}

void shop(string invy[], int &invySpOn, int &g, int &e, int lev)
{
    int shopChoice = -1;

    while (shopChoice != 0)
    {
        cout << "Welcome to the shop.          Gold: " << g << endl;
        cout << "1. Weaponry" << endl;
        cout << "2. Armor" << endl;
        cout << "3. Spells" << endl;
        cout << "4. Consumables" << endl;
        cout << "5. Sell" << endl;
        cout << "0. Leave" << endl << "Selection: ";
        cin >> shopChoice;
        system("cls");

        if (shopChoice == 0)
        {
            cout << "You leave." << endl;
        }
        if (shopChoice == 1)
        {
            cout << "Weaponry Shop          Gold: " << g << endl;
            cout << endl << "Melee Weapons:" << endl;
            cout << "1. Steel Blade         Cost: " << lev*10 << endl;
            cout << "2. Bloody Sword        Cost: " << lev*20 << endl;
            cout << "3. Beserker Axe        Cost: " << lev*40 << endl;
            cout << "4. Assassin Dagger     Cost: " << lev*55 << endl;
            cout << "5. Hero Sword          Cost: " << lev*100 << endl;
            cout << endl << "Magic Weapons:" << endl;
            cout << "6. Wooden Staff        Cost: " << lev*10 << endl;
            cout << "7. Spellbook           Cost: " << lev*15 << endl;
            cout << "8. Mage's Wand         Cost: " << lev*25 << endl;
            cout << "9. Greater Spellbook   Cost: " << lev*40 << endl;
            cout << "10. Sage's Staff       Cost: " << lev*100 << endl;
            cout << "Selection: ";
            cin >> shopChoice;

            if (shopChoice == 1)itemBuy("Steel Blade", invy, invySpOn, g, lev*10);
            else if (shopChoice == 2)itemBuy("Bloody Sword", invy, invySpOn, g, lev*20);
            else if (shopChoice == 3)itemBuy("Beserker Axe", invy, invySpOn, g, lev*40);
            else if (shopChoice == 4)itemBuy("Assassin Dagger", invy, invySpOn, g, lev*55);
            else if (shopChoice == 5)itemBuy("Hero Sword", invy, invySpOn, g, lev*100);
            else if (shopChoice == 6)itemBuy("Wooden Staff", invy, invySpOn, g, lev*10);
            else if (shopChoice == 7)itemBuy("Spellbook", invy, invySpOn, g, lev*15);
            else if (shopChoice == 8)itemBuy("Mage's Wand", invy, invySpOn, g, lev*25);
            else if (shopChoice == 9)itemBuy("Greater Spellbook", invy, invySpOn, g, lev*40);
            else if (shopChoice == 10)itemBuy("Sage's Staff", invy, invySpOn, g, lev*10);
            else cout << "You can't afford that.";
            shopChoice = -1;
        }
        if (shopChoice == 2)
        {
            cout << "Armory:                Gold: " << g << endl;
            cout << endl << "Warrior Armor:" << endl;
            cout << "1. Steel Plate         Cost: " << lev*10 << endl;
            cout << "2. Royal Plate         Cost: " << lev*25 << endl;
            cout << "3. Heroic Armor        Cost: " << lev*80 << endl;
            cout << endl << "Magic Robes:" << endl;
            cout << "4. Mage's Robe         Cost: " << lev*10 << endl;
            cout << "5. Wizard Robe         Cost: " << lev*25 << endl;
            cout << "6. Sage's Robe         Cost: " << lev*80 << endl;
            cout << "Selection: ";
            cin >> shopChoice;

            if (shopChoice == 1)itemBuy("Steel Plate", invy, invySpOn, g, lev*10);
            else if (shopChoice == 2)itemBuy("Royal Plate", invy, invySpOn, g, lev*25);
            else if (shopChoice == 3)itemBuy("Heroic Armor", invy, invySpOn, g, lev*80);
            else if (shopChoice == 4)itemBuy("Mage's Robe", invy, invySpOn, g, lev*10);
            else if (shopChoice == 5)itemBuy("Wizard Robe", invy, invySpOn, g, lev*25);
            else if (shopChoice == 6)itemBuy("Sage's Robe", invy, invySpOn, g, lev*80);
            else cout << "You can't afford that.";
            shopChoice = -1;
        }
        if (shopChoice == 3)
        {
            cout << "Spell Shop            Gold: " << g << endl << endl;
            cout << "Attack Spells" << endl;
            cout << "1. Fireball           Cost: " << lev*5 << endl;
            cout << "2. ForceWave          Cost: " << lev*15 << endl;
            cout << "3. Thunderbolt        Cost: " << lev*25 << endl;
            cout << "4. Comet              Cost: " << lev*40 << endl;
            cout << "5. Meteor             Cost: " << lev*70 << endl << endl;
            cout << "Other Spells:" << endl;
            cout << "6. Heal               Cost: " << lev*10 << endl;
            cout << "7. FullHeal           Cost: " << lev*50 << endl;
            cout << "Selection: ";
            cin >> shopChoice;

            if (shopChoice == 1)itemBuy("Fireball", invy, invySpOn, g, lev*5);
            else if (shopChoice == 2)itemBuy("ForceWave", invy, invySpOn, g, lev*15);
            else if (shopChoice == 3)itemBuy("Thunderbolt", invy, invySpOn, g, lev*25);
            else if (shopChoice == 4)itemBuy("Comet", invy, invySpOn, g, lev*40);
            else if (shopChoice == 5)itemBuy("Meteor", invy, invySpOn, g, lev*70);
            else if (shopChoice == 6)itemBuy("Heal", invy, invySpOn, g, lev*10);
            else if (shopChoice == 7)itemBuy("FullHeal", invy, invySpOn, g, lev*50);
            else cout << "You can't afford that.";
            shopChoice = -1;
        }
        if (shopChoice == 4)
        {
            cout << "Consumables:      Gold: " << g << endl;
            cout << "1. HPotion        Cost: " << lev*2 << endl;
            cout << "2. MPotion        Cost: " << lev*2 << endl;
            cout << "3. SmokeBomb      Cost: " << lev*3 << endl;
            cout << "4. MindBoost      Cost: " << lev*4 << endl;
            cout << "5. BodyBoost      Cost: " << lev*4 << endl;
            cout << "6. RPotion        Cost: " << lev*5 << endl;
            cout << "7. HealScroll     Cost: " << lev*5 << endl;
            cout << "8. ManaShield     Cost: " << lev*10 << endl;
            cout << "9. DeadlyEdge     Cost: " << lev*10 << endl;
            cout << "Selection: ";
            cin >> shopChoice;

            if (shopChoice == 1)itemBuy("HPotion", invy, invySpOn, g, lev*2);
            else if (shopChoice == 2)itemBuy("MPotion", invy, invySpOn, g, lev*2);
            else if (shopChoice == 3)itemBuy("SmokeBomb", invy, invySpOn, g, lev*3);
            else if (shopChoice == 4)itemBuy("MindBoost", invy, invySpOn, g, lev*4);
            else if (shopChoice == 5)itemBuy("BodyBoost", invy, invySpOn, g, lev*4);
            else if (shopChoice == 6)itemBuy("RPotion", invy, invySpOn, g, lev*5);
            else if (shopChoice == 7)itemBuy("HealScroll", invy, invySpOn, g, lev*5);
            else if (shopChoice == 8)itemBuy("ManaShield", invy, invySpOn, g, lev*10);
            else if (shopChoice == 9)itemBuy("DeadlyEdge", invy, invySpOn, g, lev*10);
            else cout << "You can't afford that.";
            shopChoice = -1;
        }
        system("pause");
        system("cls");
    }
}

void dispStats(int lev, int Hp, int Mp, int Str, int Def, int Magic, int gp, int xp, int maxHp, int maxMp)
{
    cout << "Your Level: " << lev << " HP: " << Hp << " / " << maxHp << " MP: " << Mp << " / " << maxMp << " Strength: " << Str << " Defense: " << Def << " Magic: " << Magic << endl << "Your Gold: " << gp << " Your Exp: " << xp << " / ";
    if (lev == 1) cout << (lev*lev*lev/2)+1;
    else cout << (lev*lev*lev/2);
    cout << endl << endl;
}

string findEnemyName (int eLevel, int &eHP, int &eMP, int &eStr, int &eDef, int &eMagic, double &gMult, double &expMult)
{
    string eName = "PLACEHOLDER";
    int enemyNameNum;
    while (eName == "PLACEHOLDER")
    {
        enemyNameNum = rand()%10+1;

        if (enemyNameNum == 1 && eLevel < 10)
        {
            eName = "Dog";
            eHP = 100+ eLevel*2;
            eMP = 0;
            eStr = 5+ eLevel*2;
        }
        else if (enemyNameNum == 1 && eLevel > 10)
        {
            eName = "Rabid Dog";
            eHP = 400+ eLevel*20;
            eMP = 0;
            eStr = 25+ eLevel*8;
        }
        else if (enemyNameNum == 2 && eLevel > 1 && eLevel < 12)
        {
            eName = "Wolf";
            eHP = 80+eLevel*4;
            eMP = 0;
            eStr = 5+eLevel*4;
        }
        else if (enemyNameNum == 2 && eLevel > 12)
        {
            eName = "Vicious Wolf";
            eHP = 600+eLevel*10;
            eMP = 0;
            eStr = 75+eLevel*10;
            expMult = 2;
            gMult = 1.5;
        }
        else if (enemyNameNum == 3 && eLevel > 3 && eLevel < 14)
        {
            eName = "Goblin";
            eHP = 150 + eLevel*5;
            eMP = 0;
            eStr = 5 + eLevel*2;
            gMult = 1.25;
            expMult = 1.25;
        }
        else if (enemyNameNum == 3 && eLevel > 14)
        {
            eName = "Goblin Hero";
            eHP = 500 + eLevel*25;
            eMP = 0;
            eStr = 200 + eLevel*80;
            gMult = 2;
            expMult = 2;
        }
        else if (enemyNameNum == 4 && eLevel > 4 && eLevel < 15)
        {
            eName = "Troll";
            eHP = 200 + eLevel*20;
            eMP = 0;
            eDef = eLevel;
            eStr = 20 + eLevel;
            expMult = 1.5;
        }
        else if (enemyNameNum == 4 && eLevel > 15)
        {
            eName = "Troll Lord";
            eHP = 1000 + eLevel*100;
            eMP = 0;
            eDef = eLevel*2;
            eStr = 500 + eLevel*30;
            expMult = 2.5;
            gMult = 2;
        }
        else if (enemyNameNum == 5 && eLevel > 3 && eLevel < 18)
        {
            eName = "Bandit";
            eHP = 120 + eLevel *5;
            eMP = 50;
            eStr = 12 + eLevel *3;
            gMult = 2;
        }
        else if (enemyNameNum == 5 && eLevel > 18)
        {
            eName = "Pack of Bandits";
            eHP = 600 + eLevel *80;
            eMP = 100*eLevel;
            eStr = 60 + eLevel *50;
            gMult = 3;
            expMult = 2;
        }
        else if (enemyNameNum == 6 && eLevel > 5 && eLevel < 22)
        {
            eName = "Tiger";
            eHP = 150 + eLevel*8;
            eMP = 0;
            eStr = 20 + eLevel*4;
            expMult = 1.5;
        }
        else if (enemyNameNum == 6 && eLevel > 22)
        {
            eName = "Sabertooth Tiger";
            eHP = 1500 + eLevel*80;
            eMP = 0;
            eStr = 200 + eLevel*40;
            expMult = 2.75;
            gMult = 1.75;
        }
        else if (enemyNameNum == 7 && eLevel > 5 && eLevel < 25)
        {
            eName = "Squid";
            eHP = 180 + eLevel*12;
            eMP = 100;
            eStr = 15 + eLevel*2;
            expMult = 1.5;
        }
        else if (enemyNameNum == 7 && eLevel > 25)
        {
            eName = "Abyss Squid";
            eHP = 1800 + eLevel*120;
            eMP = 1000;
            eStr = 150 + eLevel*20;
            expMult = 2.75;
            gMult = 1.5;
        }
        else if (enemyNameNum == 8 && eLevel > 6 && eLevel < 27)
        {
            eName = "Lioness";
            eHP = 240 + eLevel*10;
            eMP = 50;
            eStr = 25 + eLevel*3;
            expMult = 1.75;
        }
        else if (enemyNameNum == 8 && eLevel > 27)
        {
            eName = "Queen Lioness";
            eHP = 2400 + eLevel*100;
            eMP = 500;
            eStr = 250 + eLevel*30;
            expMult = 2.75;
            gMult = 1.5;
        }
        else if (enemyNameNum == 9 && eLevel > 3 && eLevel < 28)
        {
            eName = "Dark Wizard";
            eHP = 80 + eLevel*5;
            eMP = 250 + eLevel*3;
            eMagic = 50 + eLevel * 2;
            eStr = 0;
            eDef = 5;
        }
        else if (enemyNameNum == 9 && eLevel > 28)
        {
            eName = "Demonic Wizard";
            eHP = 800 + eLevel*5;
            eMP = 1000 + eLevel*20;
            eMagic = 250 + eLevel * 25;
            eStr = 0;
            eDef = 5;
        }
        else if (enemyNameNum == 10 && eLevel > 10 && eLevel < 30)
        {
            eName = "Dragon";
            eHP = 1000 + eLevel*20;
            eMP = 500 + eLevel*10;
            eMagic = 75 + eLevel * 10;
            eStr = 40 + eLevel*15;
            eDef = 30 +eLevel*2;
            expMult = 10;
            gMult = 10;
        }
        else if (enemyNameNum == 10 && eLevel > 10 && eLevel < 30)
        {
            eName = "War Dragon";
            eHP = 10000 + eLevel*200;
            eMP = 5000 + eLevel*100;
            eMagic = 750 + eLevel * 150;
            eStr = 1000 + eLevel*150;
            eDef = 300 +eLevel*20;
            expMult = 25;
            gMult = 25;
        }
    }

    return eName;
}

void levelUp(int &level, int Health, int Mana, int &Strength, int &Defense, int &Magic, int &exp, int &maxH, int &maxM, int &sp)
{
    if (exp >=(level*level*level/2))
    {
        cout << "Level Up!" << endl;
        if (level < 20)
        {
            level++;
            maxH+=level*5;
            maxM+=level*2;
            Strength+=level;
            Defense+=level;
            Magic+=level;
            sp+=(level*2);
            cout << "Level +1!" << endl;
            cout << "Max Health +" << level*5 << endl;
            cout << "Max Mana +" << level*2 << endl;
            cout << "Strength +" << level << endl;
            cout << "Defense +" << level << endl;
            cout << "Magic +" << level << endl;
            cout << "You gained " << level*2 << " Skill Points!" << endl << endl;
        }
        else
        {
            level++;
            maxH+=100;
            maxM+=50;
            Strength+=25;
            Defense+=25;
            Magic+=25;
            sp+=(level*3);
            cout << "Level +1!" << endl;
            cout << "Max Health +100" << endl;
            cout << "Max Mana +50" << endl;
            cout << "Strength +25" << endl;
            cout << "Defense +25" << endl;
            cout << "Magic +25" << endl;
            cout << "You gained " << level*3 << " Skill Points!" << endl << endl;
        }
        exp=0;
    }
}

bool battle(int &level, int &Health, int &Mana, int &Strength, int &Defense, int &Magic, int &Gold, int &Experience, int &maxHp, int &maxMp, int &sPoints, int &invSpaceOn, string invy[])
{
    int attackOption, enemyHp =0, enemyMp =0, enemyStr =0, enemyDef =0, enemyMagic =0, enemyLevel =0, damageDone, didEscape, healScrollMP;
    double gM = 1, eM = 1;
    bool didRun = false;
    string status = "none";
    string enemyName = findEnemyName(level, enemyHp, enemyMp, enemyStr, enemyDef, enemyMagic, gM, eM);
    while (enemyHp > 0 && Health > 0)
    {
        dispStats(level, Health, Mana, Strength, Defense, Magic, Gold, Experience, maxHp, maxMp);
        cout << "Enemy HP: " << enemyHp << endl << "A wild " << enemyName << " has appeared!" << endl << endl << "Options: " << endl << "1. Melee Attack" << endl << "2. Magic Attack" << endl << "3. Bag" << endl << "4. Run" <<  endl <<"Selection: ";
        cin >> attackOption;
        system ("cls");
        if (attackOption == 1)
        {
            if (status == "bboost") damageDone = rand()%10+(Strength)*2 - enemyDef;
            else damageDone = rand ()%10+Strength - enemyDef;
            cout << "You did " << damageDone << " Damage!" << endl;
            enemyHp -= damageDone;
            cout << "Enemy HP Remaining: " << enemyHp << endl << endl;
            system("pause");
        }
        else if (attackOption == 2 && Mana >= level*2)
        {
            if (status == "mboost") damageDone = rand()%10+Magic*2.5;
            else damageDone = rand () % 10+Magic*1.3;
            cout << "You did " << damageDone << " Magic Damage at the cost of " << level*2 << " MP!" << endl;
            Mana-=level*2;
            enemyHp -= damageDone;
            cout << "Enemy HP Remaining: " << enemyHp << endl << endl;
            system("pause");
        }
        else if (attackOption == 2 && Mana < level*2)
        {
            cout << "Not enough Mana!";
            system("pause");
        }
        else if (attackOption == 3)
        {
            dispInv(invy, invSpaceOn, Gold);
            cout << "0. Nevermind" << endl << endl <<"What would you like to use? ";
            cin >> attackOption;
            if (attackOption-1 < invSpaceOn && attackOption > 0)
            {
                cout << "You used a " << invy[attackOption-1] << endl;
                if (invy[attackOption-1] == "HPotion")
                {
                    cout << "The HPotion heals your HP!" << endl;
                    Health+=maxHp*.5;
                    if (Health > maxHp) Health = maxHp;
                    system("pause");
                    invy[attackOption-1] = "EMPTY";
                    itemSwap(invy, invSpaceOn, attackOption-1);
                }
                else if (invy[attackOption-1] == "MPotion")
                {
                    cout << "The MPotion heals your MP!" << endl;
                    Mana+=maxMp*.5;
                    if (Mana > maxMp) Mana = maxMp;
                    system("pause");
                    invy[attackOption-1] = "EMPTY";
                    itemSwap(invy, invSpaceOn, attackOption-1);
                }
                else if (invy[attackOption-1] == "SmokeBomb")
                {
                    cout << "The SmokeBomb allowed you to safely escape!" << endl;
                    didRun = true;
                    system("pause");
                    system("cls");
                    invy[attackOption-1] = "EMPTY";
                    itemSwap(invy, invSpaceOn, attackOption-1);
                    break;
                }
                else if (invy[attackOption-1] == "MindBoost")
                {
                    cout << "The MindBoost increases your Magic for the remainder of this battle!" << endl;
                    status = "mboost";
                    system("pause");
                    invy[attackOption-1] = "EMPTY";
                    itemSwap(invy, invSpaceOn, attackOption-1);
                }
                else if (invy[attackOption-1] == "BodyBoost")
                {
                    cout << "The BodyBoost increases your Strength for the remainder of this battle!" << endl;
                    status = "bboost";
                    system("pause");
                    invy[attackOption-1] = "EMPTY";
                    itemSwap(invy, invSpaceOn, attackOption-1);
                }
                else if (invy[attackOption-1] == "RPotion")
                {
                    cout << "The RPotion will restore your HP and MP over time!" << endl;
                    status = "regen";
                    system("pause");
                    invy[attackOption-1] = "EMPTY";
                    itemSwap(invy, invSpaceOn, attackOption-1);
                }
                else if (invy[attackOption-1] == "HealScroll")
                {
                    cout << "How much mana do you want to use?" << endl;
                    cin >> healScrollMP;
                    cout << "You used " << healScrollMP << " to heal " << healScrollMP*2 << " HP." << endl;
                    Health += healScrollMP*2;
                    Mana -= healScrollMP;
                    if (Health > maxHp) Health = maxHp;
                    system("pause");
                    invy[attackOption-1] = "EMPTY";
                    itemSwap(invy, invSpaceOn, attackOption-1);
                }
                else if (invy[attackOption-1] == "ManaShield")
                {
                    cout << "The ManaShield will cause all damage you take to damage your MP instead of HP!"<< endl;
                    status = "manashield";
                    system("pause");
                    invy[attackOption-1] = "EMPTY";
                    itemSwap(invy, invSpaceOn, attackOption-1);
                }
                else if (invy[attackOption-1] == "DeadlyEdge")
                {
                    cout << "You deal massive damage!" << endl;
                    damageDone = (rand ()%10+Strength - enemyDef)*10;
                    cout << "You did " << damageDone << " Damage!" << endl;
                    enemyHp -= damageDone;
                    cout << "Enemy HP Remaining: " << enemyHp << endl << endl;
                    system("pause");
                    invy[attackOption-1] = "EMPTY";
                    itemSwap(invy, invSpaceOn, attackOption-1);
                }
                else
                {
                    cout << "You can't use that here." << endl;
                    system("pause");
                }
            }
        }
        else if (attackOption == 4)
        {
            didEscape = rand() % 3;
            if (didEscape == 1)
            {
                cout << "You ran from the battle..." << endl;
                didRun = true;
                system("pause");
                system("cls");
                break;
            }
            else
            {
                cout << "You failed to run!" << endl;
                system("pause");
            }
        }
        else
        {
            cout << "That's not a valid option!" << endl;
            system("pause");
            system("cls");
        }
        system("cls");
        if (enemyHp > 0)
        {
            cout << "The " << enemyName << " attacks!" << endl;
            damageDone = rand()%5+enemyStr - (Defense/2);
            if (damageDone < 0) damageDone = 1;
            cout << "You took " << damageDone << " damage!" << endl;
            if (status == "manashield")
            {
                Mana-=damageDone;
                if (Mana <= 0)
                {
                    Mana = 0;
                    cout << "You're out of Mana! The ManaShield wears off!" << endl;
                    status = "none";
                }
            }
            else Health-=damageDone;
            cout << "Remaining HP: " << Health << endl;
            system ("pause");
            system ("cls");
        }

        if (status == "regen")
        {
            cout << "You regen some HP and MP!" << endl;
            cout << "+" << Health*.1 << "HP" << endl;
            cout << "+" << Mana*.1 << "MP" << endl;
            Health+=Health*.1;
            Mana+=Mana*.1;
            if (Health > maxHp) Health = maxHp;
            if (Mana > maxMp) Mana = maxMp;
        }
    }

    if (enemyHp > 0 && didRun == false)
    {
        cout << "The hero has fallen...";
        return false;
    }
    else if (didRun == false && enemyHp <= 0)
    {
        status = "none";
        cout << "You defeated the " << enemyName << "!" << endl;
        cout << "You recieved " << (int)(level*level*eM) << " exp!" << endl << "You found " << (int)(level*2*gM) << " gold!" << endl;
        Experience+=(level*level*eM);
        Gold+=(level*2*gM);
        levelUp(level, Health, Mana, Strength, Defense, Magic, Experience, maxHp, maxMp, sPoints);
        system("pause");
        system("cls");
        return true;
    }
    else return true;
}

void skillPoints(int &sp, int &Str, int &Def, int &Mag, int &mHP, int &mMP)
{
    char choice;
    int pointsSpent;
    do
    {
        cout << "You have " << sp << " points to spend." << endl << "To put points into your Max HP, type h." << endl << "To put points into your Max MP, type a." << endl << "To put points into Strength, type s." << endl << "To put points into Defense, type d." << endl << "To put points in Magic, type m." << endl << "To leave type q." << endl << endl << "Selection: ";
        cin >> choice;
        if (choice != 'q')
        {
            cout << "How many points would you like to use? " << endl;
            cin >> pointsSpent;
        }
        if (choice == 's' && sp >= pointsSpent)
        {
            cout << "Strength +" << pointsSpent << endl;
            Str+=pointsSpent;
            sp-=pointsSpent;
        }
        else if (choice == 'd' && sp >= pointsSpent)
        {
            cout << "Defense +" << pointsSpent << endl;
            Def+=pointsSpent;
            sp-=pointsSpent;
        }
        else if (choice == 'm' && sp >= pointsSpent)
        {
            cout << "Magic +" << pointsSpent << endl;
            Mag+=pointsSpent;
            sp-=pointsSpent;
        }
        else if (choice == 'h' && sp >= pointsSpent)
        {
            cout << "HP +" << 5*pointsSpent << endl;
            mHP+=5*pointsSpent;
            sp-=pointsSpent;
        }
        else if (choice == 'a' && sp >= pointsSpent)
        {
            cout << "MP +" << 5*pointsSpent << endl;
            mMP+=5*pointsSpent;
            sp-=pointsSpent;
        }
        else if ((choice == 'm' || choice == 'd' || choice == 's' || choice == 'h' || choice == 'a')&&sp < pointsSpent)
        {
            cout << "Not enough points!" << endl;
        }
        system("pause");
        system("cls");
    }
    while (choice != 'q');
}

void healHPMP(int &health, int mHealth, int &mana, int mMana, int &g, int l)
{
    char healChoice;
    cout << "A heal will cost you " << l*2 << " gold.          Gold: " << g << endl << "Will you pay? (y/n): ";
    cin >> healChoice;
    if (healChoice == 'y' && g >= l*2)
    {
        cout << "You've been healed!" << endl;
        health = mHealth;
        mana = mMana;
        g-=l*2;
    }
    else cout << "You are not healed." << endl;

    system("pause");
    system("cls");
}

int main()
{
    int level = 1, playerHp = 100, currentHp = 100, playerMp = 50, currentMp = 50, playerStr = 10, playerDef = 5, playerMagic = 10, gold = 15, exp = 0, skillP = 0;
    bool wonBattle = true;
    string name;
    string inventory[INVY_SIZE];
    int invySpaceOn = 0;
    char action;
    srand(time(0));
    cout << "What is your name? " << endl << "My name is: ";
    cin >> name;
    system ("cls");
    while (wonBattle != false)
    {
        dispStats(level, currentHp, currentMp, playerStr, playerDef, playerMagic, gold, exp, playerHp, playerMp);
        cout << "Hello, " << name << "." << endl;
        cout << "b. Battle Monsters" << endl << "h. Heal" << endl << "p. Assign Stat Points" << endl << "s. Shop" << endl << "i. Display Inventory" << endl << "Selection: ";
        cin >> action;
        system("cls");
        if (action == 'b') wonBattle = battle(level, currentHp, currentMp, playerStr, playerDef, playerMagic, gold, exp, playerHp, playerMp, skillP, invySpaceOn, inventory);
        else if (action == 'h') healHPMP(currentHp, playerHp, currentMp, playerMp, gold, level);
        else if (action == 'p') skillPoints(skillP, playerStr, playerDef, playerMagic, playerHp, playerMp);
        else if (action == 's') shop(inventory, invySpaceOn, gold, exp, level);
        else if (action == 'i')
        {
            dispInv(inventory, invySpaceOn, gold);
            system("pause");
            system("cls");
        }
    }
}