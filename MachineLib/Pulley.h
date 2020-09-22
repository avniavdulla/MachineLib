/**
 * \file Pulley.h
 *
 * \author Avni Avdulla
 */
#pragma once
#include"Component.h"
#include "Sink.h"
#include "Source.h"
#include "Pulley.h"
#include <memory>


/// Class representing a pulley, which is a sink and source of ratation 
class CPulley :
	public CComponent
{
public:

    /**
    * Constructor 
    * \param radius radius of pulley 
    */
    CPulley(double radius);

    /** \brief Default constructor disabled */
    CPulley() = delete;
    /** \brief Copy constructor disabled */
    CPulley(const CPulley&) = delete;
    /** \brief Assignment operator disabled */
    void operator=(const CPulley&) = delete;

    /**
    * Draw's the motor
    * \param graphics Graphics to draw to
    * \param x X location
    * \param y Y location
    */
    void Draw(Gdiplus::Graphics* graphics, int x, int y) override;

    /**
    * Get sink of component
    * \returns Sink pointer to sink
    */
    CSink* GetSink() { return &mSink; }

    /**
    * Get source of component
    * \returns Source pointer to source
    */
    CSource* GetSource() { return &mSource; }

    /**
    * Copmute the rotation to be passed down to other components 
    * \param time current time 
    * \returns rotation Computed Rotation 
    */
    double CPulley::ComputeRotation(double time) override;

    /** 
    * Updates a pulley driven by belt 
    * \param rotation Rotation to set 
    */
    void UpdatePulley(double rotation);


    /**
    * Sets a pulley driven by this pulley
    * \param pulley pulley to drive 
    */
    void Drive(std::shared_ptr<CPulley> pulley) { mOtherPulley = pulley; }

    /**
    * Get radius of pulley
    * \returns radius of pulley
    */
    double GetRadius() { return mRadius; }

private:

    double mRadius; ///< Radius of pulley

    CSink mSink;  ///< Sink of component 
    CSource mSource; ///< Source of component 

    std::shared_ptr<CPulley> mOtherPulley; ///< Pulley being driven 

};

