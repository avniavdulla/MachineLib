/**
 * \file Source.cpp
 *
 * \author Avni Avdulla
 */
#include "pch.h"
#include "Source.h"

CSource::CSource()
{
}

void CSource::AddSink(CSink sink)
{
    mSinks.push_back(sink);
}

void CSource::SetRotation(double rotation) 
{
    for (auto sink : mSinks) 
    {
        sink.SetRotation(rotation);
    }
}