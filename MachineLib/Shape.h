/**
 * \file Shape.h
 *
 * \author Avni Avdulla
 */

#pragma once
#include "Component.h"
#include "Sink.h"

/// Class representing a shape in the system, this is a sink of rotation 
class CShape :
	public CComponent
{
public:
    CShape();

    /**
    * Get sink of component
    * \returns Sink pointer to sink 
    */
    CSink* GetSink() { return &mSink; }
       
private:
    CSink mSink; ///< sink associated with this shape 
};

