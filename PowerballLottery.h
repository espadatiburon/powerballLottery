#ifndef POWERBALLLOTTERY_H
#define POWERBALLLOTTERY_H
#include "PowerballTicket.h"
#include "RandomNumber.h"
#include <iostream>

class PowerballLottery
{
public:
	enum class WinningPossibility{POWERBALL, ONEPLUSPOWERBALL, TWOPLUSPOWERBALL, THREE, THREEPLUSPOWERBALL, FOUR, FOURPLUSPOWERBALL, FIVE, FIVEPLUSPOWERBALL, NOTWINNING};
	PowerballLottery();
	PowerballLottery(int ball1, int ball2, int ball3, int ball4, int ball5, int powerball);
	int getBall1();
	int getBall2();
	int getBall3();
	int getBall4();
	int getBall5();
	int getPowerball();

	PowerballTicket quickPick();
	WinningPossibility checkTicket(PowerballTicket ticket);
	void printWhatHappened(PowerballTicket ticket);

private:
	int mBall1;
	int mBall2;
	int mBall3;
	int mBall4;
	int mBall5;
	int mPowerball;
};

#endif