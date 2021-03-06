#ifndef _DEBUG_H_INCLUDED_
#define _DEBUG_H_INCLUDED_
#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////////////////////
// MessageBoxFmt

UINT MessageBoxFmt(HWND hwnd, LPCTSTR pszTextFmt, LPCTSTR pszTitle, UINT uType, ...);

/////////////////////////////////////////////////////////////////////////////
// DebugReport

#ifdef DEBUG
	#ifdef ASSERT_NO_BREAK
		int _DebugReport(LPCSTR pszFile, int iLine, LPCSTR pszExpr, UINT gle, BOOL bConsoleOnly);
		#ifdef _ASSERTE
			#undef _ASSERTE
		#endif
		#define _ASSERTE(x) if(!(x) && _DebugReport(__FILE__, __LINE__, #x, GetLastError(), true)) while(0)
		#define _ASSERTC(x) if(!(x) && _DebugReport(__FILE__, __LINE__, #x, GetLastError(), true)) while(0)
	#else
		int _DebugReport(LPCSTR pszFile, int iLine, LPCSTR pszExpr, UINT gle, BOOL bConsoleOnly);
		#ifdef _ASSERTE
			#undef _ASSERTE
		#endif
		#define _ASSERTE(x) if(!(x) && _DebugReport(__FILE__, __LINE__, #x, GetLastError(), false)) DebugBreak()
		#define _ASSERTC(x) if(!(x) && _DebugReport(__FILE__, __LINE__, #x, GetLastError(), true)) DebugBreak()
	#endif
#else
	#ifndef _ASSERTE
	#define _ASSERTE(x)
	#endif
	#define _ASSERTC(x)
#endif

/////////////////////////////////////////////////////////////////////////////
// DebugTrace

#if defined(DEBUG)
	void _TRACE(LPCSTR fmt, ...);
#else
	__inline void _TRACE(LPCSTR fmt, ...) {}
#endif//defined(DEBUG)


#ifdef __cplusplus
}
#endif
#endif//_DEBUG_H_INCLUDED_
