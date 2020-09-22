/**
 * \file MachineFactory2.h
 *
 * \author Avni Avdulla
 *
 * 
 */

#pragma once
#include "MachineActual.h"

 /**
 * Factory Class used to create Machine Actual
 */
class CMachineFactory2
{

public:
    CMachineFactory2();
    ~CMachineFactory2();

    std::shared_ptr<CMachineActual> CreateMachine();
};

