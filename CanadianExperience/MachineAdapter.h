/**
 * \file MachineAdapter.h
 *
 * \author Avni Avdulla
 */

#pragma once
#include "Drawable.h"

class CMachine;

/// Adapter class used to adapt MachineLib to drawable
class CMachineAdapter :
    public CDrawable
{
public:

    /**
    * Constructor for adapter 
    * \param name of drawable
    */
    CMachineAdapter(const std::wstring& name);
    virtual ~CMachineAdapter();

    /** \brief Default constructor deleted */
    CMachineAdapter() = delete;
    /** \brief Copy constructor disabled */
    CMachineAdapter(const CMachineAdapter&) = delete;
    /** \brief Assignment operator disabled */
    void operator=(const CMachineAdapter&) = delete;

    /**
    * Draw the machine
    * \param graphics GDI+ Graphics object
    */
    void Draw(Gdiplus::Graphics* graphics) override;

    /**
    * Test to see if you have clicked on this object, this always returns false 
    * \param pos position to check 
    * \returns bool if you hit or not 
    */
    bool HitTest(Gdiplus::Point pos) override;

    /**
    * Set the current machine animation frame
    * \param frame Frame number
    */
    void SetMachineFrame(int frame);

    /**
    * Set the machine number
    * \param number An integer number. Each number makes a different machine
    */
    void SetMachineNumber(int number);

    /// Get the current frame in the timeline
    virtual void GetKeyframe() override;

private:
    std::wstring mName; ///< name of drawable 
    std::shared_ptr<CMachine> mMachine; ///< pointer to actual machine object 
};

