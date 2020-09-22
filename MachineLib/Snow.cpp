/**
 * \file Snow.cpp
 *
 * \author Avni Avdulla
 */

#include "pch.h"
#include "Snow.h"

using namespace std;
using namespace Gdiplus;

/// Gravity in pixels per second per second
const float Gravity = 15;


CSnow::CSnow(Gdiplus::PointF position, Gdiplus::PointF velocity)
{
    mVelocity = velocity;
    mPosition = position;
}

void CSnow::Update(double delta)
{
    mVelocity = PointF(mVelocity.X, mVelocity.Y + Gravity * (float)delta);
    mPosition = PointF(mPosition.X + mVelocity.X * (float)delta, mPosition.Y + mVelocity.Y * (float)delta);
}

void CSnow::Draw(Gdiplus::Graphics* graphics, int x, int y)
{
    SolidBrush brush(Color::White);
    graphics->FillRectangle(&brush, (int)mPosition.X + x , (int)mPosition.Y + y , 2, 2);

}
