/**
 * \file Source.h
 *
 * \author Avni Avdulla
 */
#pragma once

#include <vector>
#include "Sink.h"


/// Class representing a source type object 
class CSource
{

public:

    /// Deafult constructor 
    CSource();

    /** \brief Copy constructor disabled */
    CSource(const CSource&) = delete;
    /** \brief Assignment operator disabled */
    void operator=(const CSource&) = delete;

    /**
    * Add sink 
    * \param sink to add
    */
    void AddSink(CSink sink);

    /**
    * Set Rotation 
    * \param rotation to set to 
    */
    void CSource::SetRotation(double rotation);

private:

    std::vector<CSink> mSinks; ///< sinks associated with this source 

};

