/**
 * \file SnowBlower.h
 *
 * \author Avni Avdulla
 */
#pragma once
#include <random>
#include <list>
#include "Component.h"
#include "Sink.h"
#include "Snow.h"


class CSnow;
 /**
* Class representing a snow blower object 
*/
class CSnowBlower :
	public CComponent
{
public:

    /**
    * Constructor for snow blower 
    * \param initialRotation the intial rotation of the machine 
    */
    CSnowBlower(double initialRotation);
    
    /** \brief Default constructor disabled*/
    CSnowBlower() = delete;

    /** \brief Copy constructor disabled */
    CSnowBlower(const CSnowBlower&) = delete;
    /** \brief Assignment operator disabled */
    void operator=(const CSnowBlower&) = delete;

    /// Produce snow acording to rotation change 
    void ProduceSnow();

    /**
    * Base class version of draw function
    * \param graphics Graphics to draw to
    * \param x X location 
    * \param y Y location 
    */
    virtual void Draw(Gdiplus::Graphics* graphics, int x, int y);

    /**
    * Gets sink
    * \returns mSink sink object
    */
    CSink* GetSink() { return &mSink; }

    /**
    * Set rotation 
    * \param rotation new roatation to set to
    */
    void SetRotation(double rotation) override;

    /**
    * Generate a uniform distribution random number from fmValue to toValue
    * \param fmValue Minimum value to generate
    * \param toValue Maximum value to generate
    * \return Random number
    */
    double Random(double fmValue, double toValue);

private: 
    double mRotationChange = 0; ///< change in rotation since last update 

    CSink mSink; ///< This object is a rotation sink 
    
    std::list<std::shared_ptr<CSnow> > mSnow; ///< list of snow particles blown by this blower

    std::mt19937 mRandom; ///< Random number used for snow generation 
    
    double mCurrRotation = 0; ///< Current rotation of the entire machine 
};

