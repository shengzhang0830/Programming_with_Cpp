/**************************************************************************************************
** hw4.cpp
** Create An Animation of Buu from User Input Points
** Sheng Zhang
** SID 604029836
***************************************************************************************************/


#include "ccc_win.h"
#include "time.h"

// Define a function that draws Buu
void drawObject(Point center, double scale)
{
	// Draw the body
	Point center_body = center;
	Circle body (center_body, 2*scale/3);

	// Draw the head
	Point center_head = center;
	center_head.move(0, scale);
	Circle head (center_head, scale / 3);

	// Draw the left eye
	Point eye_leftl = center_head; 
	eye_leftl.move(-scale/5, scale/8);
	Point eye_leftr = eye_leftl;
	eye_leftr.move(scale / 7, -scale/20);
	Line left_eye(eye_leftl, eye_leftr);

	// Draw the right eye
	Point eye_rightr = center_head;
	eye_rightr.move(scale / 5, scale / 8);
	Point eye_rightl = eye_rightr;
	eye_rightl.move(-scale / 7, -scale / 20);
	Line right_eye(eye_rightl, eye_rightr);

	// Draw the mouth
	Point mouth_left = center_head;
	mouth_left.move(-scale/7, -scale / 7);
	Point mouth_right = mouth_left;
	mouth_right.move(2*scale / 7, 0);
	Line mouth(mouth_left, mouth_right);

	// Draw the left arm
	Point arm_leftr = center_body;
	arm_leftr.move(-2*scale / 3, scale / 6);
	Point arm_leftl = arm_leftr;
	arm_leftl.move(-scale / 3, scale / 5);
	Line left_arm(arm_leftl, arm_leftr);

	// Draw the right arm
	Point arm_rightl = center_body;
	arm_rightl.move(2 * scale / 3, scale / 6);
	Point arm_rightr = arm_rightl;
	arm_rightr.move(scale / 3, scale / 5);
	Line right_arm(arm_rightl, arm_rightr);

	// Draw the left hand
	Point center_handl = arm_leftl;
	center_handl.move(-scale/7, scale/7);
	Circle left_hand (center_handl, 1.4142*scale / 7);

	// Draw the right hand
	Point center_handr = arm_rightr;
	center_handr.move(scale / 7, scale / 7);
	Circle right_hand (center_handr, 1.4142*scale / 7);

	// Draw the left leg
	Point leg_leftr = center_body;
	leg_leftr.move(-scale / 3, -1.7321*scale / 3);
	Point leg_leftl = leg_leftr;
	leg_leftl.move(-scale / 3, -scale / 7);
	Line left_leg(leg_leftl, leg_leftr);

	// Draw the right leg
	Point leg_rightl = center_body;
	leg_rightl.move(scale / 3, -1.7321*scale / 3);
	Point leg_rightr = leg_rightl;
	leg_rightr.move(scale / 3, -scale / 7);
	Line right_leg(leg_rightl, leg_rightr);

	// Draw the tail
	Point tail_start = center_head;
	tail_start.move(0, scale / 3);
	Point tail_end = tail_start;
	tail_end.move(scale / 4, scale / 4);
	Line tail(tail_start, tail_end);

	// Construct a belt
	Point Q = center_body;
	Q.move(-0.15, 0.15);
	Message M(Q, "M");
	Point belt_leftr = center_body;
	belt_leftr.move(-scale / 5, 0);
	Point belt_leftl = belt_leftr;
	belt_leftl.move(-scale / 3, scale / 10);
	Line left_belt(belt_leftl, belt_leftr);
	Point belt_rightl = center_body;
	belt_rightl.move(scale / 5, 0);
	Point belt_rightr = belt_rightl;
	belt_rightr.move(scale / 3, scale / 10);
	Line right_belt(belt_rightl, belt_rightr);

	cwin << body << head << left_eye << right_eye << mouth << left_arm << right_arm << left_hand << right_hand << left_leg << right_leg << tail << M << left_belt << right_belt;

}

// Define the pause function
void pause(int x)
{
	clock_t goal = x + clock();
	while (goal > clock());
}

int ccc_win_main()
{
	// Ask the user to click for 3 points
	Point P = cwin.get_mouse("Click somewhere to set the birth point of Buu");
	Point Q = cwin.get_mouse("Click somewhere to tell Buu where to move to");
	Point R = cwin.get_mouse("Click somewhere to tell Buu where to teleport to");
	
	// Build a for loop that moves and enlarges Buu from the 1st point to the 2nd point
	double scale = 1.0;
	for (double i = 1; i <= 4.0; i = i + .1)
	{
			drawObject(P, i);
			P.move((i - 1) * 10 * (Q.get_x() - P.get_x()) / 30, (i - 1) * 10 * (Q.get_y() - P.get_y()) / 30);
			pause(50);
			cwin.clear();
	}

	// Build a for loop that teleports and shrinks Buu from the 2nd point to the 3rd point
	for (double j = 4.0; j >= 1.0; j = j - .1)
	{
			drawObject(Q, j);
			Q.move((j - 1) * 10 * (R.get_x() - Q.get_x()) / 30, (j - 1) * 10 * (R.get_y() - Q.get_y()) / 30);
			pause(50);
			cwin.clear();
	}

	return 0;
}
