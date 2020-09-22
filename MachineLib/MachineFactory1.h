/**
 * \file MachineFactory1.h
 *
 * \author Avni Avdulla
 */

#pragma once
#include <memory>

class CMachineActual;

/**
* Factory Class used to create Machine Actual
*/
class CMachineFactory1
{

public:
    CMachineFactory1();
    ~CMachineFactory1();

    std::shared_ptr<CMachineActual> CreateMachine();
};

