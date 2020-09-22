/**
 * \file SnowBlower.cpp
 *
 * \author Avni Avdulla
 */
#include "pch.h"
#include "SnowBlower.h"

using namespace std;

 /// Average amount of snow created per rotation
const double SnowPerRotation = 600;

/// Variance in how much snow is created
const double SnowVariancePerSecond = 100;

/// Range of the random angle snow will be thrown in
const double SnowAngleVariance = 0.1;

/// Angle range for the end of the snow machine in radians.
const double SnowMachineAngleRange = 0.25;

/// Offset to end of snow blower from middle in pixels
const double SnowBlowerOffset = 150;

/// Random variance in the snowblower offset
const double SnowBlowerOffsetVariance = 5;

/// Minimum snow particle velocity
const double SnowMinimumVelocity = 100;

/// Maximum snow particle velocity
const double SnowMaximumVelocity = 120;

/// Width of the snow blower in pixels
const int SnowBlowerWidth = 60;

/// Height of the snow blower in pixels
const int SnowBlowerHeight = 160;

/// Y offset to the center of the snow blower in pixels
const int SnowBlowerCenterOffset = 60;


CSnowBlower::CSnowBlower(double initialRotation) 
{
	mSink.SetComponent(this);
	CPolygon::SetRotation(initialRotation);

	std::random_device rd;	// Generates a random seed
	mRandom.seed(rd());		// Seed the random number generator
}

void CSnowBlower::ProduceSnow()
{
	// Compute how much snow to generate for this amount of rotation.
	auto num = (int)(mRotationChange * (SnowPerRotation + Random(-SnowVariancePerSecond, SnowVariancePerSecond)));
	
    while (num > 0) {
	
        // GetRotation gets the rotation of the snow machine.
        // This code computes a vector to the emitting end of the
        // snow machine. The random value means that position is over
        // the entire end of the machine, not just a single point.
        auto angle = GetRotation() * 2 * M_PI + Random(-SnowMachineAngleRange, SnowMachineAngleRange);
        auto dx = sin(angle);
        auto dy = -cos(angle);


        auto angle1 = angle + Random(-SnowAngleVariance, SnowAngleVariance);
        auto dx1 = sin(angle1);
        auto dy1 = -cos(angle1);

        double offset = SnowBlowerOffset + Random(-SnowBlowerOffsetVariance, SnowBlowerOffsetVariance);
        double velocity = Random(SnowMinimumVelocity, SnowMaximumVelocity);

        Gdiplus::PointF snowPosition((float)(GetCenter().X + dx * offset), (float)(GetCenter().Y + dy * offset));
        Gdiplus::PointF snowVelocity((float)(dx1 * velocity), (float)(dy1 * velocity));
       
        shared_ptr<CSnow> snow = make_shared<CSnow>(snowPosition, snowVelocity);
        
        mSnow.push_back(snow);

		num--;
	}
}


double CSnowBlower::Random(double fmValue, double toValue)
{
    std::uniform_real_distribution<> distribution(fmValue, toValue);
    return distribution(mRandom);
}

void CSnowBlower::Draw(Gdiplus::Graphics* graphics, int x, int y)
{
    
    std::list<std::shared_ptr<CSnow> >::iterator it;
    for (it = mSnow.begin(); it != mSnow.end(); it++)
    {
        std::shared_ptr<CSnow> snow = *it;
        snow->Draw(graphics, x, y);
    }

    CComponent::Draw(graphics, x, y);
}

/**
* Checker function that checks if snow is off screen 
* \param snow snow object to check position of 
* \returns bool true if off screen, false otherwise
*/
bool OffScreen(const shared_ptr<CSnow> snow) { return (snow->GetPosition().Y > 200); }

void CSnowBlower::SetRotation(double rotation)
{
    mRotationChange = rotation - mCurrRotation;
    mCurrRotation = rotation;

    if (mRotationChange > 0) {
        ProduceSnow();
    
        // Update every snow particle with new location 
        std::list<std::shared_ptr<CSnow> >::iterator it;
        for (it = mSnow.begin(); it != mSnow.end(); it++)
        {
            std::shared_ptr<CSnow> snow = *it;
            // otherwise update by 1/framerate 
            snow->Update(mRotationChange);
        }
        // removes snow if it is off screen 
        mSnow.remove_if(OffScreen);

    }
    
}
