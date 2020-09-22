/**
 * \file Pulley.h
 *
 * \author Avni Avdulla
 */

#include "pch.h"
#include "Pulley.h"

CPulley::CPulley(double radius)
{
    mRadius = radius;
    mSink.SetComponent(this);
}

/**
* Draw's the shape
* \param graphics Graphics to draw to
* \param x location 
* \param y location 
*/
void CPulley::Draw(Gdiplus::Graphics* graphics, int x, int y)
{
    // Draw belt if driving another pulley 
    if (mOtherPulley) 
    {

        auto saveSM = graphics->GetSmoothingMode();
        graphics->SetSmoothingMode(Gdiplus::SmoothingMode::SmoothingModeHighQuality);

        //
        // Copmute belt location  
        //
        int x1 = GetCenter().X;
        int y1 = GetCenter().Y;
        double r1 = mRadius - 3;

        int x2 = mOtherPulley->GetCenter().X;
        int y2 = mOtherPulley->GetCenter().Y;
        double r2 = mOtherPulley->GetRadius() - 3;

        double theta = atan2(y2 - y1, x2 - x1);

        double phi = asin((r2 - r1) / (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1))));

        double beta = theta - phi - 3.14 / 2;
        double beta2 = theta - phi + 3.14 / 2;

        Gdiplus::Pen pen(Gdiplus::Color::Black, 2);

        // 
        // Draw the belt line 1 
        //
        Gdiplus::Point endpoint1 = Gdiplus::Point(x1, y1) + Gdiplus::Point(r1 * cos(beta), r1 * sin(beta));
        Gdiplus::Point endpoint2 = Gdiplus::Point(x2, y2) + Gdiplus::Point(r2 * cos(beta), r2 * sin(beta));

     
        graphics->DrawLine(&pen, x + endpoint1.X, y + endpoint1.Y, x + endpoint2.X, y + endpoint2.Y); 

        // 
        // Draw the belt line 2 with new endpoints
        //
        endpoint1 = Gdiplus::Point(x1, y1) + Gdiplus::Point(double(r1) * cos(beta2), double(r1) * sin(beta2));
        endpoint2 = Gdiplus::Point(x2, y2) + Gdiplus::Point(double(r2) * cos(beta2), double(r2) * sin(beta2));

        graphics->DrawLine(&pen, x + endpoint1.X, y + endpoint1.Y, x + endpoint2.X, y + endpoint2.Y);

        graphics->SetSmoothingMode(saveSM);

    }
    // Draw pulley after lines 
    CComponent::Draw(graphics, x, y);
}


double CPulley::ComputeRotation(double time) 
{
    double rotation = time ;

    //
    // Update other pulley if one connected using belt  
    //
    if (mOtherPulley) { UpdatePulley(rotation ); }
    
    GetSource()->SetRotation(rotation);
    return rotation;
}

void CPulley::UpdatePulley(double rotation)
{

    double factor = double(mRadius) / double(mOtherPulley->GetRadius());
    rotation = rotation * factor;

    mOtherPulley->SetRotation(rotation);

}
