/**
 * \file Sink.cpp
 *
 * \author Avni Avdulla
 */
#include "pch.h"
#include "Sink.h"
#include "Component.h"

CSink::CSink()
{
}

void CSink::SetRotation(double rotation)
{
    GetComponent()->SetRotation(rotation);
}

void CSink::SetComponent(CComponent *component)
{
    mComponent = component;
}
