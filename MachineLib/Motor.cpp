/**
 * \file Motor.cpp
 *
 * \author Avni Avdulla
 */
#include "pch.h"
#include "Motor.h"

using namespace std;

CMotor::CMotor()
{
	// makes the shaft 
	auto shaft = make_shared<CComponent>();
	int wid = 20;
	shaft->Circle(wid/2);
	shaft->SetCenter(Gdiplus::Point(0, -35)); // make it so it is centered with the motor (halfway up the motor)
	shaft->SetImage(L"images/electric-wheel.png"); 
	mShaft = shaft;
	
}

void CMotor::Draw(Gdiplus::Graphics *graphics, int x, int y)
{
	CComponent::Draw(graphics, x , y);
	mShaft->Draw(graphics, x + GetCenter().X, y + GetCenter().Y );
}

double CMotor::ComputeRotation(double time)
{
	double rotation = time * mSpeed;
	mShaft->SetRotation(rotation);

	GetSource()->SetRotation(rotation);
	return rotation;
}
