/**
 * \file MachineActorFactory2.h
 *
 * \author Avni Avdulla
 *
 * 
 */

#pragma once
#include "ActorFactory.h"

/// Concrete factory to create machine 2 
class CMachineActorFactory2 :
	public CActorFactory
{
public:
    CMachineActorFactory2();
    virtual ~CMachineActorFactory2();
    /**
    * Concrete method for creating a machine 2
    * \returns actor machine actor
    */
    std::shared_ptr<CActor> Create();
};

