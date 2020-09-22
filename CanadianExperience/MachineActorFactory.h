/**
 * \file MachineActorFactory.h
 *
 * \author Avni Avdulla
 *
 * 
 */

#pragma once
#include "ActorFactory.h"

/// Concrete factory to create machine 1 
class CMachineActorFactory :
	public CActorFactory
{
public:
    CMachineActorFactory();
    virtual ~CMachineActorFactory();

    /**
    * Concrete method for creating a machine 1
    * \returns actor machine actor
    */
    std::shared_ptr<CActor> Create();

};

