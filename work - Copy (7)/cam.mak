# Microsoft Developer Studio Generated NMAKE File, Based on cam.dsp
!IF "$(CFG)" == ""
CFG=cam - Win32 Debug
!MESSAGE No configuration specified. Defaulting to cam - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "cam - Win32 Release" && "$(CFG)" != "cam - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "cam.mak" CFG="cam - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "cam - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "cam - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "cam - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\cam.exe"


CLEAN :
	-@erase "$(INTDIR)\cam.obj"
	-@erase "$(INTDIR)\cam.pch"
	-@erase "$(INTDIR)\cam.res"
	-@erase "$(INTDIR)\camDlg.obj"
	-@erase "$(INTDIR)\dsp.obj"
	-@erase "$(INTDIR)\label.obj"
	-@erase "$(INTDIR)\misc.obj"
	-@erase "$(INTDIR)\mxpad.obj"
	-@erase "$(INTDIR)\PlaySound.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\Support.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\cam.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\cam.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\cam.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\cam.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=wsock32.lib winmm.lib /nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\cam.pdb" /machine:I386 /out:"$(OUTDIR)\cam.exe" 
LINK32_OBJS= \
	"$(INTDIR)\cam.obj" \
	"$(INTDIR)\camDlg.obj" \
	"$(INTDIR)\dsp.obj" \
	"$(INTDIR)\label.obj" \
	"$(INTDIR)\misc.obj" \
	"$(INTDIR)\mxpad.obj" \
	"$(INTDIR)\PlaySound.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\Support.obj" \
	"$(INTDIR)\cam.res"

"$(OUTDIR)\cam.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "cam - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\cam.exe"


CLEAN :
	-@erase "$(INTDIR)\cam.obj"
	-@erase "$(INTDIR)\cam.pch"
	-@erase "$(INTDIR)\cam.res"
	-@erase "$(INTDIR)\camDlg.obj"
	-@erase "$(INTDIR)\dsp.obj"
	-@erase "$(INTDIR)\label.obj"
	-@erase "$(INTDIR)\misc.obj"
	-@erase "$(INTDIR)\mxpad.obj"
	-@erase "$(INTDIR)\PlaySound.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\Support.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\cam.exe"
	-@erase "$(OUTDIR)\cam.ilk"
	-@erase "$(OUTDIR)\cam.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\cam.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\cam.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\cam.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=winmm.lib /nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\cam.pdb" /debug /machine:I386 /out:"$(OUTDIR)\cam.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\cam.obj" \
	"$(INTDIR)\camDlg.obj" \
	"$(INTDIR)\dsp.obj" \
	"$(INTDIR)\label.obj" \
	"$(INTDIR)\misc.obj" \
	"$(INTDIR)\mxpad.obj" \
	"$(INTDIR)\PlaySound.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\Support.obj" \
	"$(INTDIR)\cam.res"

"$(OUTDIR)\cam.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("cam.dep")
!INCLUDE "cam.dep"
!ELSE 
!MESSAGE Warning: cannot find "cam.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "cam - Win32 Release" || "$(CFG)" == "cam - Win32 Debug"
SOURCE=.\cam.cpp

"$(INTDIR)\cam.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\cam.pch"


SOURCE=.\cam.rc

"$(INTDIR)\cam.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\camDlg.cpp

"$(INTDIR)\camDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\cam.pch"


SOURCE=.\dsp.cpp

"$(INTDIR)\dsp.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\cam.pch"


SOURCE=.\label.cpp

"$(INTDIR)\label.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\cam.pch"


SOURCE=.\misc.cpp

"$(INTDIR)\misc.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\cam.pch"


SOURCE=..\..\common\work2\mxpad.cpp

"$(INTDIR)\mxpad.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\cam.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\PlaySound.cpp

"$(INTDIR)\PlaySound.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\cam.pch"


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "cam - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\cam.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\cam.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "cam - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\cam.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\cam.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\Support.cpp

"$(INTDIR)\Support.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\cam.pch"



!ENDIF 

