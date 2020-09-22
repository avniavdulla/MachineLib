/**
 * \file MachineActorFactory.cpp
 *
 * \author Avni Avdulla
 */

#include "pch.h"
#include "MachineActorFactory.h"
#include "MachineAdapter.h"
#include "Picture.h"
#include "Actor.h"

using namespace std;
using namespace Gdiplus;

/// Constructor 
CMachineActorFactory::CMachineActorFactory()
{
}
/// Destructor 
CMachineActorFactory::~CMachineActorFactory()
{
}

/*
* Concrete method to create a machine actor
*/
std::shared_ptr<CActor> CMachineActorFactory::Create() 
{
    shared_ptr<CActor> actor = make_shared<CActor>(L"Machine1");

    auto machine = make_shared<CMachineAdapter>(L"Machine");

    // Machine 1 
    machine->SetMachineNumber(1);
    machine->SetPosition(Point(900, 620));


    actor->AddDrawable(machine);
    
    return actor;
}

