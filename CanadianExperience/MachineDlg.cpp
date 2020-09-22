// MachineDlg.cpp : implementation file
//

#include "pch.h"
#include "CanadianExperience.h"
#include "MachineDlg.h"
#include "afxdialogex.h"
#include "Actor.h"


// CMachineDlg dialog

IMPLEMENT_DYNAMIC(CMachineDlg, CDialog)

CMachineDlg::CMachineDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_MACHINEDLG, pParent)
	, mMachineNum(0)
{

}

CMachineDlg::~CMachineDlg()
{
}

void CMachineDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_MACHINENUM, mMachineNum);
	DDV_MinMaxInt(pDX, mMachineNum, 1, 2);
}


BEGIN_MESSAGE_MAP(CMachineDlg, CDialog)
END_MESSAGE_MAP()


// CMachineDlg message handlers

