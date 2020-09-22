/**
* \file MikeFactory.h
*
* \author Avni Avdulla
*
*/
#pragma once
#include "Actor.h"
#include "ActorFactory.h"

/** Class for factory that creates a Mike character */
class CMikeFactory :
	public CActorFactory
{
public:
	std::shared_ptr<CActor> Create();
};

