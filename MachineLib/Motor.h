/**
 * \file Motor.h
 *
 * \author Avni Avdulla
 */
#pragma once
#include "Component.h"
#include "Source.h"

/// Class representing a motor 
class CMotor :
	public CComponent
{
public:
    CMotor();

    /**
    * Draw's the shape
    * \param graphics Graphics to draw to
    * \param x location
    * \param y location
    */
    void Draw(Gdiplus::Graphics *graphics, int x, int y) override;

    /**
    * Computes Rotation and returns computed rotation
    * \param time time to compute rotation for
    * \returns rotation
    */
    virtual double ComputeRotation(double time) override;

    /**
    * Get the source object 
    * \returns source Source object 
    */
    CSource* GetSource() { return &mSource; }

private:

    double mSpeed = 1; ///< speed of motor 

    std::shared_ptr<CComponent> mShaft; ///< part that spins 

    CSource mSource;  ///< The motor is a source 

    
};

