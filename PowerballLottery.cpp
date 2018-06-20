#include "PowerballLottery.h"

PowerballLottery::PowerballLottery()
{
	RandomNumber balls(1,69);
	RandomNumber powerBall(1,26);

	mBall1 = balls.random();
	mBall2 = balls.random();
	while(mBall1 == mBall2)
	{
		mBall2 = balls.random();
	}
	mBall3 = balls.random();
	while((mBall1 == mBall3) || (mBall2 == mBall3))
	{
		mBall3 = balls.random();
	}
	mBall4 = balls.random();
	while((mBall1 == mBall4) || (mBall2 == mBall4) || (mBall3 == mBall4))
	{
		mBall4 = balls.random();
	}
	mBall5 = balls.random();
	while((mBall1 == mBall5) || (mBall2 == mBall5) || (mBall3 == mBall5) || (mBall4 == mBall5))
	{
		mBall5 = balls.random();
	}
	mPowerball = powerBall.random();

}

PowerballLottery::PowerballLottery(int ball1, int ball2, int ball3, int ball4, int ball5, int powerball)
{
	mBall1 = ball1;
	mBall2 = ball2;
	mBall3 = ball3;
	mBall4 = ball4;
	mBall5 = ball5;
	mPowerball = powerball;
}

int PowerballLottery::getBall1()
{
	return mBall1;
}

int PowerballLottery::getBall2()
{
	return mBall2;
}

int PowerballLottery::getBall3()
{
	return mBall3; 
}

int PowerballLottery::getBall4()
{
	return mBall4;
}

int PowerballLottery::getBall5()
{
	return mBall5;
}

int PowerballLottery::getPowerball()
{
	return mPowerball;
}


PowerballTicket PowerballLottery::quickPick()
{
	int tempB1;
	int tempB2;
	int tempB3;
	int tempB4;
	int tempB5;
	int tempPB;

	RandomNumber balls(1,69);
	RandomNumber powerBall(1,26);

	tempB1 = balls.random();
	tempB2 = balls.random();
	while(tempB1 == tempB2)
	{
		tempB2 = balls.random();
	}
	tempB3 = balls.random();
	while((tempB1 == tempB3) || (tempB2 == tempB3))
	{
		tempB3 = balls.random();
	}
	tempB4 = balls.random();
	while((tempB1 == tempB4) || (tempB2 == tempB4) || (tempB3 == tempB4))
	{
		tempB4 = balls.random();
	}
	tempB5 = balls.random();
	while((tempB1 == tempB5) || (tempB2 == tempB5) || (tempB3 == tempB5) || (tempB4 == tempB5))
	{
		tempB5 = balls.random();
	}
	tempPB = powerBall.random();

	PowerballTicket tempTicket(tempB1, tempB2, tempB3, tempB4, tempB5, tempPB);
	return tempTicket;

}

PowerballLottery::WinningPossibility PowerballLottery::checkTicket(PowerballTicket ticket)
{
	int numberWon = 0;
	bool powerBallWon = false;
	WinningPossibility answer = WinningPossibility::NOTWINNING;

	if(ticket.getPowerball() == mPowerball)
	{
		powerBallWon = true;
	}
	if((ticket.getBall1() == mBall1)||(ticket.getBall1() == mBall2)||(ticket.getBall1() == mBall3)||(ticket.getBall1() == mBall4)||(ticket.getBall1() == mBall5))
	{
		numberWon++;
	}
	if((ticket.getBall2() == mBall1)||(ticket.getBall2() == mBall2)||(ticket.getBall2() == mBall3)||(ticket.getBall2() == mBall4)||(ticket.getBall2() == mBall5))
	{
		numberWon++;
	}
	if((ticket.getBall3() == mBall1)||(ticket.getBall3() == mBall2)||(ticket.getBall3() == mBall3)||(ticket.getBall3() == mBall4)||(ticket.getBall3() == mBall5))
	{
		numberWon++;
	}
	if((ticket.getBall4() == mBall1)||(ticket.getBall4() == mBall2)||(ticket.getBall4() == mBall3)||(ticket.getBall4() == mBall4)||(ticket.getBall4() == mBall5))
	{
		numberWon++;
	}
	if((ticket.getBall5() == mBall1)||(ticket.getBall5() == mBall2)||(ticket.getBall5() == mBall3)||(ticket.getBall5() == mBall4)||(ticket.getBall5() == mBall5))
	{
		numberWon++;
	}

	if(powerBallWon)
	{
		if(numberWon == 0)
		{
			answer = WinningPossibility::POWERBALL;
		}
		else if(numberWon == 1)
		{
			answer = WinningPossibility::ONEPLUSPOWERBALL;
		}
		else if(numberWon == 2)
		{
			answer = WinningPossibility::TWOPLUSPOWERBALL;
		}
		else if(numberWon == 3)
		{
			answer = WinningPossibility::THREEPLUSPOWERBALL;
		}
		else if(numberWon == 4)
		{
			answer = WinningPossibility::FOURPLUSPOWERBALL;
		}
		else if(numberWon == 5)
		{
			answer = WinningPossibility::FIVEPLUSPOWERBALL;
		}
	}
	else if(!powerBallWon)
	{
		if(numberWon == 3)
		{
			answer = WinningPossibility::THREE;
		}
		else if(numberWon == 4)
		{
			answer = WinningPossibility::FOUR;
		}
		else if(numberWon == 5)
		{
			answer = WinningPossibility::FIVE;
		}
		else if(numberWon < 3)
		{
			answer = WinningPossibility::NOTWINNING;
		}
	}

	return answer;
}

void PowerballLottery::printWhatHappened(PowerballTicket ticket)
{

	WinningPossibility answer = checkTicket(ticket);
	if(answer == WinningPossibility::NOTWINNING)
	{
		std::cout << "You didn't win anything. Please buy another ticket!\n";
	}
	else if(answer == WinningPossibility::POWERBALL)
	{
		std::cout << "You matched just the powerball. Congratulations!\n";
	}
	else if(answer == WinningPossibility::ONEPLUSPOWERBALL)
	{
		std::cout << "You matched one ball plus the powerball. Congratulations!\n";
	}
	else if(answer == WinningPossibility::TWOPLUSPOWERBALL)
	{
		std::cout << "You matched two balls plus the powerball. Congratulations!\n";
	}
	else if(answer == WinningPossibility::THREE)
	{
		std::cout << "You matched three balls but not the powerball. Congratulations!\n";
	}
	else if(answer == WinningPossibility::THREEPLUSPOWERBALL)
	{
		std::cout << "You matched three balls plus the powerball. Congratulations!\n";
	}
	else if(answer == WinningPossibility::FOUR)
	{
		std::cout << "You matched four balls but not the powerball. Congratulations!\n";
	}
	else if(answer == WinningPossibility::FOURPLUSPOWERBALL)
	{
		std::cout << "You matched four balls plus the powerball. Congratulations!\n";
	}
	else if(answer == WinningPossibility::FIVE)
	{
		std::cout << "You matched five balls but not the powerball. Congratulations!\n";
	}
	else if(answer == WinningPossibility::FIVEPLUSPOWERBALL)
	{
		std::cout << "You won the jackpot - all balls plus the powerball. Congratulations!\n";
	}
}