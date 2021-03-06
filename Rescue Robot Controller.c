#pragma config(Motor,  port1,           backLeftBottom, tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           backLeftTop,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           frontLeftBottom, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           frontLeftTop,  tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           leftArm,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           rightArm,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           frontRightTop, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           frontRightBottom, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           backRightTop,  tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          backRightBottom, tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	while(true)
	{
		motor[backLeftBottom] = vexRT[Ch1] + vexRT[Ch3];
		motor[backLeftTop] = vexRT[Ch1] + vexRT[Ch3];
		motor[frontLeftBottom] = vexRT[Ch1] + vexRT[Ch3];
		motor[frontLeftTop] = vexRT[Ch1] + vexRT[Ch3];

		motor[backRightBottom] = vexRT[Ch1] - vexRT[Ch3];
		motor[backRightTop] = vexRT[Ch1] - vexRT[Ch3];
		motor[frontRightBottom] = vexRT[Ch1] - vexRT[Ch3];
		motor[frontRightTop] = vexRT[Ch1] - vexRT[Ch3];

		if (vexRT[Btn6U] == 1)
		{
			motor[leftArm] = 127;
			motor[rightArm] = 127;
		}
		else if (vexRT[Btn6D] == 1)
		{
			motor[leftArm] = -127;
			motor[rightArm] = -127;
		}
		else
		{
			motor[leftArm] = 0;
			motor[rightArm] = 0;
		}
	}
}
