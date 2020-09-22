/**
 * \file MachineActorFactory2.cpp
 *
 * \author Avni Avdulla
 */

#include "pch.h"
#include "MachineActorFactory2.h"
#include "MachineAdapter.h"
#include "Actor.h"
#include "Picture.h"

using namespace std;
using namespace Gdiplus;

/// Constructor 
CMachineActorFactory2::CMachineActorFactory2()
{
}
/// Destructor 
CMachineActorFactory2::~CMachineActorFactory2()
{
}

/*
* Concrete method to create a machine actor
*/
std::shared_ptr<CActor> CMachineActorFactory2::Create()
{
    shared_ptr<CActor> actor = make_shared<CActor>(L"Machine2");

    auto machine = make_shared<CMachineAdapter>(L"Machine");

    // Machine 2 
    machine->SetMachineNumber(2);
    machine->SetPosition(Point(200, 620));

    actor->AddDrawable(machine);

    return actor;
}