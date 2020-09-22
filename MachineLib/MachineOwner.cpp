/**
 * \file MachineOwner.cpp
 *
 * \author Avni Avdulla
 */
#include "pch.h"
#include "MachineOwner.h"
#include "MachineActual.h"
#include "MachineFactory1.h"
#include "MachineFactory2.h"


CMachineOwner::CMachineOwner() {
	SetMachineNumber(1);
}

void CMachineOwner::SetLocation(int x, int y)
{
	mPosition = Gdiplus::Point(x, y);
	mMachine->SetLocation(x, y);
}

void CMachineOwner::DrawMachine(Gdiplus::Graphics* graphics)
{
	mMachine->DrawMachine(graphics);
}

void CMachineOwner::SetMachineFrame(int frame)
{
	mMachine->SetMachineFrame(frame);
}

void CMachineOwner::SetMachineNumber(int machine)
{
	if (machine == 1) {
		CMachineFactory1 factory1;
		mMachine = factory1.CreateMachine();
		mMachine->SetMachineNumber(machine);
		mMachine->SetLocation(mPosition.X, mPosition.Y);
	}
	else if (machine == 2) {
		CMachineFactory2 factory2;
		mMachine = factory2.CreateMachine();
		mMachine->SetMachineNumber(machine);
		mMachine->SetLocation(mPosition.X, mPosition.Y);
	}

}

int CMachineOwner::GetMachineNumber()
{
	return mMachine->GetMachineNumber();
}
