
// BookmanagementsystemView.cpp: CBookmanagementsystemView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Bookmanagementsystem.h"
#endif

#include "BookmanagementsystemDoc.h"
#include "BookmanagementsystemView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBookmanagementsystemView

IMPLEMENT_DYNCREATE(CBookmanagementsystemView, CView)

BEGIN_MESSAGE_MAP(CBookmanagementsystemView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CBookmanagementsystemView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CBookmanagementsystemView 构造/析构

CBookmanagementsystemView::CBookmanagementsystemView() noexcept
{
	// TODO: 在此处添加构造代码

}

CBookmanagementsystemView::~CBookmanagementsystemView()
{
}

BOOL CBookmanagementsystemView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CBookmanagementsystemView 绘图

void CBookmanagementsystemView::OnDraw(CDC* /*pDC*/)
{
	CBookmanagementsystemDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CBookmanagementsystemView 打印


void CBookmanagementsystemView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CBookmanagementsystemView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CBookmanagementsystemView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CBookmanagementsystemView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CBookmanagementsystemView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CBookmanagementsystemView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CBookmanagementsystemView 诊断

#ifdef _DEBUG
void CBookmanagementsystemView::AssertValid() const
{
	CView::AssertValid();
}

void CBookmanagementsystemView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBookmanagementsystemDoc* CBookmanagementsystemView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBookmanagementsystemDoc)));
	return (CBookmanagementsystemDoc*)m_pDocument;
}
#endif //_DEBUG


// CBookmanagementsystemView 消息处理程序
