void moveStraight(int power)
{
	motor[leftFront] = power;
	motor[leftBack] = power;
	motor[rightFront] = power;
	motor[rightBack] = power;
}

// Stops the base motors
void baseStop()
{
	motor[leftFront] = 0;
	motor[leftBack] = 0;
	motor[rightBack] = 0;
	motor[rightFront] = 0;
}

// Sets the motor speeds to the assigned value, depending on the direction assigned.
// If direction is 1, left motors will be set with negative power, whereas right motors will be set with positive power
// This allows the robot to turn left.
/// If direction is 2, it will cause the robot to turn right.
void turnOnSpot(int direction, int power)
{
	if (direction == 1)
	{
		motor[leftFront] = -power;
		motor[leftBack] = -power;
		motor[rightFront] = power;
		motor[rightBack] = power;
	}
	else if (direction == 2)
	{
		motor[leftFront] = power;
		motor[leftBack] = power;
		motor[rightFront] = -power;
		motor[rightBack] = -power;
	}
}

// Sets the lift motors' speed to the assigned value
void moveLift(int power)
{
	motor[leftArmTop] = power;
	motor[leftArmBottom] = power;
	motor[rightArmTop] = power;
	motor[rightArmBottom] = power;
}

// Stops all the lift motors
void liftStop()
{
	motor[leftArmTop] = 0;
	motor[leftArmBottom] = 0;
	motor[rightArmTop] = 0;
	motor[rightArmBottom] = 0;
}

// Sets the lifts to move at 127 in the direction desired until height desired is reached
// If direction is 1, while the height is not reached, the lift motors will move up and stop when it is reached.
// Similarly, if direction is -1 , while the height is not reached, the lift motors will cause the robot to go down until the desired height is reached.
void moveLiftAuto(int direction, int height)
{
	if (direction == 1)
	{
		while (SensorValue[rightLiftS] > height)
		{
			motor[leftArmTop] = 90;
			motor[leftArmBottom] = 90;
			motor[rightArmTop] = 90;
			motor[rightArmBottom] = 90;
		}
		motor[leftArmTop] = 0;
		motor[leftArmBottom] = 0;
		motor[rightArmTop] = 0;
		motor[rightArmBottom] = 0;
	}
	else if (direction == -1)
	{
		if (SensorValue[liftp] == 1) SensorValue[liftp] = 0;
		while (SensorValue[lift] < height)
		{
			motor[leftArmTop] = -90;
			motor[leftArmBottom] = -90;
			motor[rightArmTop] = -90;
			motor[rightArmBottom] = -90;
		}
		motor[leftArmTop] = 0;
		motor[leftArmBottom] = 0;
		motor[rightArmTop] = 0;
		motor[rightArmBottom] = 0;
	}
}

// Sets the value of the intake motors according to the direction determined. 1 for intake, -1 for output.
// Direction 2 and -2 is for testing purposes and is for turning both motors in the same direction.
void intake(int direction)
{
	if (direction == 1)
	{
		motor[intakeLeft] = 127;
		motor[intakeRight] = 127;
	}
	else if (direction == -1)
	{
		motor[intakeLeft] = -127;
		motor[intakeRight] = -127;
	}
	else if (direction == 2)
	{
		motor[intakeLeft] = 127;
		motor[intakeRight] = -127;
	}
	else if (direction == -2)
	{
		motor[intakeLeft] = -127;
		motor[intakeRight] = 127;
	}
	else
	{
		motor[intakeLeft] = 0;
		motor[intakeRight] = 0;
	}
}

// Sets the right base motors to the desired speed.
void moveRightSide(int power)
{
	motor[rightBack] = power;
	motor[rightFront] = power;
}

// Sets the left base motors to the desired speed.
void moveLeftSide(int power)
{
	motor[leftBack] = power;
	motor[leftFront] = power;
}

/*
// This is a programming function, preset to allow the robot to score the bucky balls as well as the large balls
// when Buckyball count = 3, large ball count = 1
void buckyLargeOutput()
{
// At the start, it outputs the bucky ball at the mouth of the intake
intake(-1);
wait10Msec(30);
// The robot intakes, making sure the large ball does not get disposed from the intake
intake(1);
wait10Msec(70);
intake(-1);
wait10Msec(50);
intake(1);
wait10Msec(90);
intake(-1);
wait10Msec(50);
intake(0);
// The process continues until the three bucky balls are scored.

// The robot then moves backwards, giving allowance for the large ball to be scored.
nMotorEncoder[leftmid] = 0;
while(abs(nMotorEncoder[leftmid]) < 120) moveStraight(-80);
moveStraight(20);
wait10Msec(20);
baseStop();

intake(-1);
wait10Msec(100);
}
*/

void blueSkyriseAuton()
{	
	//Deploy
	//Raise Lift
	//Move Forward
	//Move Backward
	//Turn around
	//Drop Lift
	//Score Skyrise
}

void blueOppoAuton()
{
	// Deploy
	// Move Forward to low pole
	// Raise Lift
	// Output
}

void redSkyriseAuton()
{
}

void redOppoAuton()
{
}

void autonLocation()
{
	if (SensorValue[progSel] < 1024)
	{
		//Blue Skyrise
	}
	else if (SensorValue[progSel] < 2048)
	{
		//Blue Opposite
	}
	else if (SensorValue[progSel] < 3072)
	{
		//Red Skyrise
	}
	else
	{
		//Red Opposite
	}
}
