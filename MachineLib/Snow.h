/**
 * \file Snow.h
 *
 * \author Avni Avdulla
 */

#pragma once
#include "Polygon.h"
#include "SnowBlower.h"

/// Class Representing snow particles
class CSnow : 
    public CPolygon
{
public:

    /**
    * Constructor for snow
    * \param position position of snow particle
    * \param velocity velocity of snow particle 
    */
    CSnow(Gdiplus::PointF position, Gdiplus::PointF velocity);

    /** \brief Default constructor disabled */
    CSnow() = delete;
    /** \brief Copy constructor disabled */
    CSnow(const CSnow&) = delete;
    /** \brief Assignment operator disabled */
    void operator=(const CSnow&) = delete;

    /**
    * Update the position of the snow particles
    * \param delta amount of time that has passed since last update 
    */
    void Update(double delta);

    /**
    * Draw snow on the screen 
    * \param graphics graphics object to draw to 
    * \param x X location 
    * \param y Y location 
    */
    virtual void Draw(Gdiplus::Graphics* graphics, int x, int y);

    /**
    * Get Position 
    * \returns Position of snow
    */
    Gdiplus::PointF GetPosition() { return mPosition; }
    
private:
    
    Gdiplus::PointF mVelocity; ///< velocity of snow particle 
    Gdiplus::PointF mPosition; ///< position of snow particle 

};

