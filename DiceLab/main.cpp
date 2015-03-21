//
//  main.cpp
//  DiceLab
//
//  Created by Nick Williams on 9/4/14.
//  Copyright (c) 2014 Ninjaneer. All rights reserved.
//
//  Description: A User is prompted to enter integers based on dice rolls. If the entry is not an
//               integer within 1 - 6, the prgram ends. After all five integers are entered, the
//               program reports back specifics about the combination of numbers.
//
//               Sentence Modification code was added to format sentences properly. 


#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main(int argc, const char * argv[])
{
//Variable Declarations
    int roll [5];
    int numbers [6] = { };
    int rollNumber = 0;
    int count = 0;
    
    string strNumbers [6] = {"One", "Two", "Three", "Four", "Five", "Six"};
    string plural1;
    string plural2;
    string plural3 = "es";
    string yesNo;
    string doDoNot;
    string happySad;
    
    bool fullHouse = false;
    bool longStraight = false;
    bool smallStraight = false;
    
    
    //Game Introduction and Requirements
    cout << "Let's Play!" << endl << endl;
    cout << "Rules:\n" << "Roll 5 Dice, One At A Time, And Enter Your Results.\n";
    cout << "Your Entries Must Be Integers.\n";
    cout << "Your Integers Must Be 1, 2, 3, 4, 5, or 6.\n";
    cout << "If You Do Not Follow These Rules, This Program Will Terminate!"
    << endl << endl;
    
    //Do_While Loop that stores user entries in an Array
    {
        do
        {
            rollNumber += 1;
        
            cout << "Enter dice roll number " << rollNumber << ": ";
            cin >> roll [rollNumber];
        
            if ((roll [rollNumber] >= 1) && (roll [rollNumber] <= 6))
            {
                if (roll [rollNumber] == 1)
                {
                    numbers [0] += 1;
                }
        
                if (roll [rollNumber] == 2)
                {
                    numbers [1] += 1;
                }
        
                if (roll [rollNumber] == 3)
                {
                    numbers [2] += 1;
                }
        
                if (roll [rollNumber] == 4)
                {
                    numbers [3] += 1;
                }
        
                if (roll [rollNumber] == 5)
                {
                    numbers [4] += 1;
                }
        
                if (roll [rollNumber] == 6)
                {
                    numbers [5] += 1;
                }
            }
            else
            {
                exit(1);
            }
        }
        while (rollNumber < 5);
    }
    
    //Quantity Results Output
    cout << "Here are your results!" << endl << endl << endl;
    
    //Loop to print each Quantity Result, pulling information from the Arrays.
    {
        do
        {
            if (numbers [count] == 1)
            {
                plural1 = "is";
                plural2 = "";
            }
            else
            {
                plural1 = "are";
                plural2 = "s";
            }
        
            {
                if ((count == 5) && (numbers [count] != 1))
                    cout << "There " << plural1 << " " << numbers [count] <<
                    " " << strNumbers [count] << plural3 << "." << endl;
                else
                    cout << "There " << plural1 << " " << numbers [count] <<
                    " " << strNumbers [count] << plural2 << "." << endl;
            }
        
            count += 1;
        }
        while (count < 6);
    
        cout << endl << endl;
    }
    
    //Winning Combos Output
    
    //Three of a Kind (With Full House Qualifier)
    {
        count = 0;
    
        while (count < 7)
        {
            if (numbers [count] >= 3)
            {
                yesNo = "Yes";
                doDoNot = "";
                happySad = "!\n";
                
                if ((numbers [0] == 2) ||
                    (numbers [1] == 2) ||
                    (numbers [2] == 2) ||
                    (numbers [3] == 2) ||
                    (numbers [4] == 2) ||
                    (numbers [5] == 2))
                    {
                        fullHouse = true;
                    }
                
                break;
            }
            else
            {
                yesNo = "No";
                doDoNot = "do not ";
                happySad = ". :-(\n";
            }
            count += 1;
        }
        cout << yesNo << ", you " << doDoNot << "have a Three of a Kind" << happySad;
    }
    
    //Four of a Kind
    {
        count = 0;
        
        while (count < 7)
        {
            if (numbers [count] >= 4)
            {
                yesNo = "Yes";
                doDoNot = "";
                happySad = "!\n";
                break;
            }
            else
            {
                yesNo = "No";
                doDoNot = "do not ";
                happySad = ". :-(\n";
            }
            count += 1;
        }
        cout << yesNo << ", you " << doDoNot << "have a Four of a Kind" << happySad;
    }

    //Five of a Kind
    {
        count = 0;
        
        while (count < 7)
        {
            if (numbers [count] == 5)
            {
                yesNo = "Yes";
                doDoNot = "";
                happySad = "!\n";
                break;
            }
            else
            {
                yesNo = "No";
                doDoNot = "do not ";
                happySad = ". :-(\n";
            }
            count += 1;
        }
        cout << yesNo << ", you " << doDoNot << "have a Five of a Kind" << happySad;
    }

    //Full House
    {
        if (fullHouse == true)
        {
            yesNo = "Yes";
            doDoNot = "";
            happySad = "!\n";
        }
        else
        {
            yesNo = "No";
            doDoNot = "do not ";
            happySad = ". :-(\n";
        }

        cout << yesNo << ", you " << doDoNot << "have a Full House" << happySad;
    }

    //Long Straight & Small Straight Determinations
    {
        if (((numbers [0] == 1) &&
             (numbers [1] == 1) &&
             (numbers [2] == 1) &&
             (numbers [3] == 1) &&
             (numbers [4] == 1) &&
             (numbers [5] == 0)) ||  //OR
            ((numbers [0] == 0) &&
             (numbers [1] == 1) &&
             (numbers [2] == 1) &&
             (numbers [3] == 1) &&
             (numbers [4] == 1) &&
             (numbers [5] == 1)))
            {
                longStraight = true;
            }
        
    }
    
    {
        if (((numbers [0] >= 1) &&
             (numbers [1] >= 1) &&
             (numbers [2] >= 1) &&
             (numbers [3] >= 1) &&
             (numbers [4] <= 1) &&
             (numbers [5] <= 1)) ||  //OR
            ((numbers [0] <= 1) &&
             (numbers [1] >= 1) &&
             (numbers [2] >= 1) &&
             (numbers [3] >= 1) &&
             (numbers [4] >= 1) &&
             (numbers [5] <= 1)) ||  //OR
            ((numbers [0] <= 1) &&
             (numbers [1] <= 1) &&
             (numbers [2] >= 1) &&
             (numbers [3] >= 1) &&
             (numbers [4] >= 1) &&
             (numbers [5] >= 1)))
        {
            smallStraight = true;
        }
    }
    
    //Long Straight
    {
        if (longStraight == true)
        {
            yesNo = "Yes";
            doDoNot = "";
            happySad = "!\n";
        }
        else
        {
            yesNo = "No";
            doDoNot = "do not ";
            happySad = ". :-(\n";
        }
        
        cout << yesNo << ", you " << doDoNot << "have a Long Straight" << happySad;
    }
    
    //Small Straight
    {
        if (smallStraight == true)
        {
            yesNo = "Yes";
            doDoNot = "";
            happySad = "!\n";
        }
        else
        {
            yesNo = "No";
            doDoNot = "do not ";
            happySad = ". :-(\n";
        }
        
        cout << yesNo << ", you " << doDoNot << "have a Small Straight" << happySad << endl;
    }
    
    cout << "Thank you for playing!\n";
    
    return 0;
}

