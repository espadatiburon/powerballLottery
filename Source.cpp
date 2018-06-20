/*
Name: Harlan Chang
Course: CS20A
Date: 3/12/2016
Purpose: Powerball Lottery
Input/Output:
all asserts passed!
Press any key to continue . . .
*/
#include <iostream>
#include <string>
#include <cassert>
#include "PowerballLottery.h"
#include "PowerballTicket.h"

using namespace std;

int main()
{
           // test code
           PowerballTicket ticket( 1, 2, 3, 4, 5, 6 );
           assert( ticket.getBall1() == 1);
           assert( ticket.getBall2() == 2);
           assert( ticket.getBall3() == 3); 
           assert( ticket.getBall4() == 4);
           assert( ticket.getBall5() == 5);
           assert( ticket.getPowerball() == 6);
           PowerballLottery lottery( 1, 2, 3, 4, 5, 6 );
           assert( lottery.getBall1() == 1);
           assert( lottery.getBall2() == 2);
           assert( lottery.getBall3() == 3);
           assert( lottery.getBall4() == 4);
           assert( lottery.getBall5() == 5);
           assert( lottery.getPowerball() == 6);
           assert( lottery.checkTicket(ticket) == PowerballLottery::WinningPossibility::FIVEPLUSPOWERBALL);
           ticket = PowerballTicket( 1, 2, 3, 4, 5, 12 );
           assert( lottery.checkTicket(ticket) == PowerballLottery::WinningPossibility::FIVE);
           ticket = PowerballTicket( 1, 2, 3, 4, 15, 12 );
           PowerballTicket quickPickTicket( 1, 2, 3, 4, 5, 6);
           for (int i = 0; i < 20; i++)      {
               quickPickTicket = lottery.quickPick();
               // all the ball numbers need to be different...
               assert( quickPickTicket.getBall1() != quickPickTicket.getBall2() && 
                       quickPickTicket.getBall1() != quickPickTicket.getBall3() &&  
                       quickPickTicket.getBall1() != quickPickTicket.getBall4() &&
                       quickPickTicket.getBall1() != quickPickTicket.getBall5() && 
                       quickPickTicket.getBall2() != quickPickTicket.getBall3() &&         
                       quickPickTicket.getBall2() != quickPickTicket.getBall4() &&         
                       quickPickTicket.getBall2() != quickPickTicket.getBall5() &&    
                       quickPickTicket.getBall3() != quickPickTicket.getBall4() &&         
                       quickPickTicket.getBall3() != quickPickTicket.getBall5() &&     
                       quickPickTicket.getBall4() != quickPickTicket.getBall5()); 
          }
          cout << "all asserts passed!" << endl; 
   
          return 0;
}
 