/**
 * \file Component.h
 *
 * \author Avni Avdulla
 */
#pragma once
#include "Polygon.h"

/// Class representing a component in the machine 
class CComponent :
	public CPolygon
{
public:

    CComponent();

    /** \brief Copy constructor disabled */
    CComponent(const CComponent&) = delete;
    /** \brief Assignment operator disabled */
    void operator=(const CComponent&) = delete;

    /**
    * Base class version of draw function 
    * \param graphics Graphics to draw to 
    * \param x  location of x 
    * \param y  location of y 
    */
    virtual void Draw(Gdiplus::Graphics *graphics, int x, int y);

    /**
    * Computes Rotation and returns computed rotation 
    * \param time time to compute rotation for 
    * \returns rotation 
    */
    virtual double ComputeRotation(double time);

    /**
    * Base class version of updating snow, gets overriden in snowblower
    * \param graphics Graphics to draw to
    */
    virtual void UpdateSnow(Gdiplus::Graphics *graphics);

    /**
    * Gets the center of object 
    * \returns point to center of object 
    */
    Gdiplus::Point GetCenter() { return mCenter; }


    /**
    * Sets the center of object 
    * \param center point to center 
    */
    void SetCenter(Gdiplus::Point center) { mCenter = center; }


    /**
    * Sets the time of the machine 
    * \param time time to set 
    */
    void SetTime(double time) { mTime = time; }


private:

    Gdiplus::Point mCenter; ///< center of the component 
    double mTime; ///< Current time of component  



};

