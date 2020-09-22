/**
 * \file Sink.h
 *
 * \author Avni Avdulla
 */

#pragma once
#include <memory>

class CComponent;

/// Class representing a sink of rotation 
class CSink
{
public:

    CSink();

    /**
    * Set Rotation
    * \param rotation to set to
    */
    void SetRotation(double rotation);

    /**
    * Set Component 
    * \param component to set to
    */
    void SetComponent(CComponent *component);

    /**
    * Get the component 
    * \returns component pointer to compononent 
    */
    CComponent* GetComponent() { return mComponent; }
    
private:

    CComponent* mComponent = nullptr; ///< component associated with this sink 

};

