/**
 * \file Component.h
 *
 * \author Avni Avdulla
 */

#include "pch.h"
#include "Component.h"

CComponent::CComponent()
{
}


void CComponent::Draw(Gdiplus::Graphics* graphics, int x, int y)
{
    DrawPolygon(graphics, x + GetCenter().X, y + GetCenter().Y);
}

double CComponent::ComputeRotation(double time)
{
    return 0.0;
}

void CComponent::UpdateSnow(Gdiplus::Graphics *graphics)
{
}
