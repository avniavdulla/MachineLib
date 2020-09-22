/**
 * \file MachineActual.cpp
 *
 * \author Avni Avdulla
 */
#include "pch.h"
#include "MachineActual.h"

void CMachineActual::SetLocation(int x, int y)
{
    mPosition = Gdiplus::Point(x, y);
}

void CMachineActual::DrawMachine(Gdiplus::Graphics* graphics)
{
    for (auto component : mComponents) {
        component->Draw(graphics, mPosition.X, mPosition.Y);
    }
}

void CMachineActual::SetMachineFrame(int frame)
{
    // frame rate of simulation
    double frameRate = 30;

    mTime = double(frame) / frameRate;

    for (auto component : mComponents) {
        component->SetTime(mTime);
        double rotate = component->ComputeRotation(mTime);

    }

}

void CMachineActual::SetMachineNumber(int machine)
{
    mNumber = machine;
}

int CMachineActual::GetMachineNumber()
{
    return mNumber;
}

void CMachineActual::AddComponent(std::shared_ptr<CComponent> component)
{
    mComponents.push_back(component);
}
