#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int toss(int a) 
{
    int comp_toss = rand() % 2 + 1;
    if (comp_toss == 1)
    {
      if (a == 1) 
      {
        cout << "You won the toss." << endl;
        int choice;
        cout << "Press 1 for batting and 2 for bowling: ";
        cin >> choice;
        while (choice < 1 || choice > 2) 
         {
            cout << "Wrong input!! Please try again: ";
            cin >> choice;
         }
     if (choice == 1) 
     {
      cout << "You choose batting." << endl;
     } 
    else 
     {
      cout << "You choose bowling." << endl;
     }
    return choice;
 } 
 else 
    {
     cout << "You lost the toss." << endl;
     int choice = rand() % 2 + 1;
     if (choice == 1) 
     {
      cout << "Computer chooses bowling, and you're batting." << 
     endl;
     }
     else 
     {
      cout << "Computer chooses batting, and you're bowling." << 
      endl;
     }
     return choice;
    }
 } 
    else
  {
     if (a == 2)
      {
       cout << "You won the toss." << endl;
       int choice;
       cout << "Press 1 for batting and 2 for bowling: ";
       cin >> choice;
       while (choice < 1 || choice > 2)
        {
         cout << "Wrong input!! Please try again: ";
         cin >> choice;
        }
    if (choice == 1)
  {
    cout << "You choose batting." << endl;
  }
  else
   {
     cout << "You choose bowling." << endl;
   }
  return choice;
    }
    else  
    {
       cout << "You lost the toss." << endl;
       int choice = rand() % 2 + 1;
       if (choice == 1) 
     {
         cout << "Computer chooses bowling, and you're batting." << 
         endl;
     } 
     else 
     {
      cout << "Computer chooses batting, and you're bowling." << 
      endl;
     }
   return choice;
   }
 }
}
int batting(int target = -1) 
{
    int score = 0;
    int run;
    cout << "Enter 1-6: ";
    cin >> run;
    while (run > 6 || run < 1) 
    {
    cout << "Wrong input!! Please try again: ";
    cin >> run;
    }
    int comp_run;
    comp_run = rand() % 6 + 1;
    cout << "Computer play is: " << comp_run << endl;
    while (run != comp_run) 
    {
     score += run;
     if (target > 0 && score >= target) 
     {
     cout << "You won the match" << endl;
     return -1;
     }
     cout << "Your runs: " << score << endl;
     cout << "Enter 1-6: ";
     cin >> run;
    while (run > 6 || run < 1) 
    {
      cout << "Wrong input!! Please try again: ";
      cin >> run;
    }
     comp_run = rand() % 6 + 1;
     cout << "Computer play is: " << comp_run << endl;
    }
    cout << "You're out!!" << endl;
    cout << "Your score: " << score << endl;
    return score;
}
int bowling(int target = -1) 
{
    int score = 0;
    int run;
    cout << "Enter 1-6: ";
    cin >> run;
    while (run > 6 || run < 1)
     {
     cout << "Wrong input!! Please try again: ";
     cin >> run;
    }
     int comp_run;
      comp_run = rand() % 6 + 1;
      cout << "Computer play is: " << comp_run << endl;
     while (run != comp_run) 
     {
       score += comp_run;
       if (target > 0 && score >= target)
        {
           cout << "You lost" << endl;
           return -1;
        }
       cout << "Computer runs: " << score << endl;
       cout << "Enter 1-6: ";
       cin >> run;
       while (run > 6 || run < 1)
        {
        cout << "Wrong input!! Please try again: ";
        cin >> run;
        }
       comp_run = rand() % 6 + 1;
       cout << "Computer play is: " << comp_run << endl;
     }
       cout << "Computer is out!!" << endl;
       cout << "Computer score: " << score << endl;
       return score;
}
int main() 
{
      srand(time(0));
      int coin_toss;
      cout << "Choose 1 for head and 2 for tail: ";
      cin >> coin_toss;
      while (coin_toss < 1 || coin_toss > 2) 
      {
       cout << "Wrong input!! Please try again: ";
      cin >> coin_toss;
      }
      int choice = toss(coin_toss);
      int score;
      if (choice == 1) 
      {
       score = batting();
       cout << "Mine Target: " << score + 1 << endl;
      } 
      else
      {
       score = bowling();
       cout << "Computer's Target: " << score + 1 << endl;
      }
      int target = score + 1;
      if (choice == 1) 
      {
       score = bowling(target);
       if (score >= 0 && score > target - 1) 
       {
        cout << "You lose" << endl;
       } 
       else if (score >= 0 && score < target - 1) 
       {
        cout << "You win" << endl;
       } else if (score >= 0 && score == target - 1)
       {
       cout << "Tied" << endl;
       }
      } 
      else
       {
         score = batting(target);
        if (score >= 0 && score > target - 1) 
        {
         cout << "You win" << endl;
        } else if (score >= 0 && score < target - 1) 
        {
         cout << "You lose" << endl;
        } else if (score >= 0 && score == target - 1) 
        {
         cout << "Tied" << endl;
        }
       }
 return 0;
 }
