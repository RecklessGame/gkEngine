//
//  MFCForWxWidgets.h
//  gkStudio
//
//  Created by Corleone on 7/15/15.
//  Copyright (c) 2015 TARSPowered. All rights reserved.
//

#ifndef gkStudio_MFCForWxWidgets_h
#define gkStudio_MFCForWxWidgets_h

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#   include <wx/wx.h>
#endif

#include <wx/app.h>
#include <wx/docview.h>

typedef bool    BOOL;
typedef void    VOID;
typedef int32_t INT;
typedef uint32_t    UINT;
typedef long    LONG;

//#define BOOL        bool
//#define VOID        void
//#define INT         int32_t
//#define UINT        uint32_t
//#define LONG        long
//
//#define TCHAR       char

#define afx_msg     

#define BEGIN_MESSAGE_MAP 	BEGIN_EVENT_TABLE
#define END_MESSAGE_MAP     END_EVENT_TABLE
#define DECLARE_DYNAMIC     DECLARE_CLASS
#define DECLARE_DYNCREATE   DECLARE_DYMAMIC_CLASS
#define IMPLEMENT_DYNAMIC   IMPLEMENT_CLASS
#define IMPLEMENT_DYNCREATE IMPLEMENT_DYNAMIC_CLASS

#define RUNTIME_CLASS       CLASSINFO

#if 1
typedef wxChar  TCHAR;
typedef wxApp   CWinApp;

typedef wxApp CWinApp;
typedef wxObject            CObject;
typedef wxEvtHandler        CCmdTarget;
typedef wxCmdLineParser     CCommandLineInfo;
typedef wxMenu              CMenu;
typedef wxMenuBar           CMenuBar;
typedef wxMenuItem          CMenuItem;
typedef wxBusyCursor        CWaitCursor;
typedef wxValidator         CDataExchange;

#else 

#define CWinApp             wxApp
#define CObject             wxObject
#define CCmdTarget          wxEvtHandler
#define CCommandLineInfo 	wxCmdLineParser
#define CMenu               wxMenu, wMenuBar, wxMenuItem
#define CWaitCursor         wxBusyCursor
#define CDataExchange       wxValidator

#define CFrameWnd       wxFrame
#define CMDIFrameWnd 	wxMDIParentFrame
#define CMDIChildWnd 	wxMDIChildFrame
#define CSplitterWnd 	wxSplitterWindow
#define CToolBar        wxToolBar
#define CStatusBar      wxStatusBar
#define CReBar          wxCoolBar
#define CPropertyPage 	wxPanel
#define CPropertySheet 	wxNotebook, wxPropertySheetDialog

#define CDialog 	wxDialog
#define CColorDialog 	wxColourDialog
#define CFileDialog 	wxFileDialog
#define CFindReplaceDialog 	wxFindReplaceDialog
#define CFontDialog 	wxFontDialog
#define CPageSetupDialog 	wxPageSetupDialog
#define CPrintDialog 	wxPrintDialog

#define CAnimateCtrl 	wxMediaCtrl, wxAnimationCtrl
#define CButton 	wxButton
#define CBitmapButton 	wxBitmapButton
#define CComboBox 	wxComboBox, wxChoice
#define CDateTimeCtrl 	wxDatePickerCtrl
#define CEdit 	wxTextCtrl
#define CHotKeyCtrl 	//None, but see Keybinder
#define CListBox        wxListBox
#define CDragListBox 	wxListBox
#define CCheckListBox 	wxCheckListBox
#define CListCtrl 	wxListCtrl, wxListView
#define CMonthCalCtrl 	wxCalendarCtrl
#define CProgressCtrl 	wxGauge
#define CReBarCtrl      //None, but see contrib/src/fl and wxAUI, wxDockIt
#define CRichEditCtrl 	wxTextCtrl
#define CScrollBar 	wxScrollBar
#define CSliderCtrl 	wxSlider
#define CSpinButtonCtrl 	wxSpinButton, wxSpinCtrl
#define CStatic         wxStaticText, wxStaticLine, wxStaticBox, wxStaticBitmap
#define CStatusBarCtrl 	wxStatusBar
#define CTabCtrl 	wxTabCtrl
#define CToolBarCtrl 	wxToolBar
#define CToolTipCtrl 	wxToolTip
#define CTreeCtrl 	wxTreeCtrl

#define CBitmap 	wxBitmap, wxImage, wxIcon, wxCursor
#define CBrush 	wxBrush
#define CPen 	wxPen
#define CFont 	wxFont
#define CImageList 	wxImageList, wxIconBundle
#define CPalette 	wxPalette
#define CRgn 	wxRegion
#define CClientDC 	wxClientDC
#define CMetaFileDC 	wxMetaFileDC
#define CPaintDC 	wxPaintDC
#define CWindowDC 	wxWindowDC
#define CDC 	wxDC, wxMemoryDC

#define CArray      wxArray
#define CObArray    wxArray
#define CPtrArray 	wxArray
#define CStringArray 	wxArrayString
#define CDWordArray wxArrayInt
#define CByteArray  wxArrayInt
#define CUIntArray 	wxArrayInt
#define CList       wxList
#define CPtrList    wxList
#define CObList 	wxList
#define CStringList 	wxArrayString, wxStringList
#define CMap 	wxHashMap
#define CString 	wxString
#define CPoint 	wxPoint
#define CRect 	wxRect
#define CSize 	wxSize
#define CTime 	wxDateTime
#define CTimeSpan 	wxTimeSpan, wxDateSpan
#define COleVariant 	wxVariant

#define CSocket 	wxSocket
#define CFtpConnection 	wxFTP
#define CHttpConnection 	wxHTTP

#define CDocument 	wxDocument
#define CView 	wxView
#define CDocTemplate        wxDocTemplate
#define CSingleDocTemplate  wxDocTemplate
#define CMultiDocTemplate 	wxDocTemplate

#define COleDataSource 	wxDataObject
#define COleDropSource 	wxDropSource
#define COleDropTarget 	wxDropTarget

#define CFile 	wxFile, wxFFile, wxTextFile
#define CMemFile 	wxMemoryInputStream, wxMemoryOutputStream
#define CSocketFile 	wxSocketInputStream, wxSocketOutputStream
#define CRecentFileList 	wxFileHistory

#define CWinThread 	wxThread
#define CCriticalSection 	wxCriticalSection
#define CMutex 	wxMutex
#define CSemaphore 	wxSemaphore

#endif      //// 0 -> 1

#endif
