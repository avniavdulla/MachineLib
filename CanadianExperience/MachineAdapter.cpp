/**
 * \file MachineAdapter.cpp
 *
 * \author Avni Avdulla
 */

#include "pch.h"
#include "MachineAdapter.h"
#include "Machine.h"
#include "MachineOwner.h"
#include "MachineFactory.h"
#include "Timeline.h"

using namespace Gdiplus;
using namespace std;

CMachineAdapter::CMachineAdapter(const std::wstring &name) : CDrawable(name)
{
    CMachineFactory factory;
    mMachine = factory.CreateMachine();
}

CMachineAdapter::~CMachineAdapter() 
{
    
}

void CMachineAdapter::Draw(Gdiplus::Graphics* graphics)
{
    mMachine->SetLocation(GetPosition().X, GetPosition().Y);
    mMachine->DrawMachine(graphics);
}

bool CMachineAdapter::HitTest(Gdiplus::Point pos)
{
    return false;
}

void CMachineAdapter::SetMachineFrame(int frame)
{
    mMachine->SetMachineFrame(frame);
}

void CMachineAdapter::SetMachineNumber(int number)
{
    mMachine->SetMachineNumber(number);
}

void CMachineAdapter::GetKeyframe()
{
    CDrawable::GetKeyframe();
    auto channel = CDrawable::GetAngleChannel();
    auto timeline = channel->GetTimeline();
    auto frame = timeline->GetCurrentFrame();

    SetMachineFrame(frame);
    
}
