/**
 * \file MachineOwner.h
 *
 * \author Avni Avdulla
 */
#pragma once
#include "Machine.h"
class CMachineActual;

/// Class representing the owner of the machine 
class CMachineOwner :
	public CMachine
{
public:
    /// Constructor
    CMachineOwner();

    /// Destructor
    virtual ~CMachineOwner() {}

    /** \brief Copy constructor disabled */
    CMachineOwner(const CMachineOwner&) = delete;
    /** \brief Assignment operator disabled */
    void operator=(const CMachineOwner&) = delete;

    /**
    * Set the position for the root of the machine
    * \param x X location (pixels)
    * \param y Y location (pixels)
    */
    virtual void SetLocation(int x, int y) override;

    /**
    * Draw the machine at the currently specified location
    * \param graphics GDI+ Graphics object
    */
    virtual void DrawMachine(Gdiplus::Graphics* graphics) override;

    /**
    * Set the current machine animation frame
    * \param frame Frame number
    */
    virtual void SetMachineFrame(int frame) override;

    /**
    * Set the machine number
    * \param machine An integer number. Each number makes a different machine
    */
    virtual void SetMachineNumber(int machine) override;

    /**
     * Get the current machine number
     * \returns Machine number integer
     */
    virtual int GetMachineNumber();

    /**
    * Get Position of the machine 
    * \returns position Gdiplus::Point position 
    */
    Gdiplus::Point GetPosition() { return mPosition; };


private:
    
    std::shared_ptr<CMachineActual> mMachine; ///< pointer to current machine 
    Gdiplus::Point mPosition = Gdiplus::Point(400, 400); ///< default location for machine 

};

