#pragma once

#include "MachineAdapter.h"

// CMachineDlg dialog

class CMachineDlg : public CDialog
{
	DECLARE_DYNAMIC(CMachineDlg)

public:
	/**
	* Standard constructor 
	* \param pParent parent 
	*/
	CMachineDlg(CWnd* pParent = nullptr);   
	/// Virtual destructor 
	virtual ~CMachineDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MACHINEDLG };
#endif

protected:
	/**
	* Do data exchange 
	* \param pDX no idea
	*/
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	int mMachineNum;  ///< Machine number 

	/// The timeline we are editing
	std::shared_ptr<CMachineAdapter> mMachine = nullptr;
};
