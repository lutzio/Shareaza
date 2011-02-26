//
// DlgCollectionExport.h
//
// Copyright (c) Shareaza Development Team, 2002-2011.
// This file is part of SHAREAZA (shareaza.sourceforge.net)
//
// Shareaza is free software; you can redistribute it
// and/or modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2 of
// the License, or (at your option) any later version.
//
// Shareaza is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Shareaza; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//

#pragma once

#include "DlgSkinDialog.h"
#include "CtrlWizard.h"

class CAlbumFolder;
class CXMLElement;


class CCollectionExportDlg : public CSkinDialog
{
	DECLARE_DYNAMIC(CCollectionExportDlg)

public:
	CCollectionExportDlg(CAlbumFolder* pFolder, CWnd* pParent = NULL);
	virtual ~CCollectionExportDlg();
	
	enum { IDD = IDD_COLLECTION_EXPORT };

	CButton	m_wndOK;
	CStatic m_wndExplain;
	CStatic m_wndLblAuthor;
	CStatic m_wndLblName;
	CStatic m_wndLblDesc;
	CStatic m_wndGroupBox;
	CButton	m_wndDelete;
	CEdit	m_wndDesc;
	CStatic	m_wndName;
	CStatic	m_wndAuthor;
	CListCtrl m_wndList;

	void	EnumerateTemplates(LPCTSTR pszPath = NULL);
	BOOL	AddTemplate(LPCTSTR pszPath, LPCTSTR pszName);
	CString DirFromPath(LPCTSTR szPath);

protected:
	CAlbumFolder*	m_pFolder;
	CImageList		m_gdiImageList;
	int				m_nSelected;
	int				m_nStep;
	CString			m_sBtnBack;
	CString			m_sBtnDelete;
	CString			m_sBtnExport;
	CString			m_sBtnNext;
	CString			m_sLblExplain1;
	CString			m_sLblExplain2;
	CWizardCtrl		m_wndWizard;

	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual void DoDataExchange(CDataExchange* pDX);
	virtual void OnOK();
	virtual BOOL OnInitDialog();

	afx_msg void OnTemplatesDeleteOrBack();
	afx_msg void OnItemChangedTemplates(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);

	DECLARE_MESSAGE_MAP()
};

#define IDC_WIZARD		99
