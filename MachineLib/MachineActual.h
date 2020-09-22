/**
 * \file MachineActual.h
 *
 * \author Avni Avdulla
 */
#pragma once
#include <memory>
#include <vector>
#include "Component.h"

/**
* Class describing an actual machine 
*/ 
class CMachineActual
{
public:

    /// Constructor 
    CMachineActual() {};

    /// Destructor
    virtual ~CMachineActual() {}

    /** \brief Copy constructor disabled */
    CMachineActual(const CMachineActual&) = delete;
    /** \brief Assignment operator disabled */
    void operator=(const CMachineActual&) = delete;

    /**
    * Set the position for the root of the machine
    * \param x X location (pixels)
    * \param y Y location (pixels)
    */
    void SetLocation(int x, int y);

    /**
    * Draw the machine at the currently specified location
    * \param graphics GDI+ Graphics object
    */
    void DrawMachine(Gdiplus::Graphics* graphics);

    /**
    * Set the current machine animation frame
    * \param frame Frame number
    */
    void SetMachineFrame(int frame);

    /**
    * Set the machine number
    * \param machine An integer number. Each number makes a different machine
    */
    void SetMachineNumber(int machine);

    /**
     * Get the current machine number
     * \return Machine number integer
     */
    int GetMachineNumber();

    /**
    * Add a component to component list 
    * \param component Component to add to list
    */
    void AddComponent(std::shared_ptr<CComponent> component);

    /**
     * Get the current machine position
     * \return Position of machine
     */
    Gdiplus::Point GetPosition() { return mPosition; }

    /**
     * Set the current machine position
     * \param position of machine
     */
    void SetPosition(Gdiplus::Point position) { mPosition = position; }


private:

    double mTime; ///< current time 
    int mNumber; ///< Machine number 
    Gdiplus::Point mPosition; ///< Position of machine 

    std::vector<std::shared_ptr<CComponent> > mComponents; ///< List of components 

};

