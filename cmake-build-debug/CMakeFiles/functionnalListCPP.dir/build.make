# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\sorge\CLionProjects\functionnalListCPP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\sorge\CLionProjects\functionnalListCPP\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\functionnalListCPP.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\functionnalListCPP.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\functionnalListCPP.dir\flags.make

CMakeFiles\functionnalListCPP.dir\main.cpp.obj: CMakeFiles\functionnalListCPP.dir\flags.make
CMakeFiles\functionnalListCPP.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\sorge\CLionProjects\functionnalListCPP\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/functionnalListCPP.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\functionnalListCPP.dir\main.cpp.obj /FdCMakeFiles\functionnalListCPP.dir\ /FS -c C:\Users\sorge\CLionProjects\functionnalListCPP\main.cpp
<<

CMakeFiles\functionnalListCPP.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/functionnalListCPP.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe > CMakeFiles\functionnalListCPP.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\sorge\CLionProjects\functionnalListCPP\main.cpp
<<

CMakeFiles\functionnalListCPP.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/functionnalListCPP.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\functionnalListCPP.dir\main.cpp.s /c C:\Users\sorge\CLionProjects\functionnalListCPP\main.cpp
<<

# Object files for target functionnalListCPP
functionnalListCPP_OBJECTS = \
"CMakeFiles\functionnalListCPP.dir\main.cpp.obj"

# External object files for target functionnalListCPP
functionnalListCPP_EXTERNAL_OBJECTS =

functionnalListCPP.exe: CMakeFiles\functionnalListCPP.dir\main.cpp.obj
functionnalListCPP.exe: CMakeFiles\functionnalListCPP.dir\build.make
functionnalListCPP.exe: src\FListLib.lib
functionnalListCPP.exe: spdlog\spdlogd.lib
functionnalListCPP.exe: CMakeFiles\functionnalListCPP.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\sorge\CLionProjects\functionnalListCPP\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable functionnalListCPP.exe"
	"C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\functionnalListCPP.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\mt.exe --manifests -- C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\functionnalListCPP.dir\objects1.rsp @<<
 /out:functionnalListCPP.exe /implib:functionnalListCPP.lib /pdb:C:\Users\sorge\CLionProjects\functionnalListCPP\cmake-build-debug\functionnalListCPP.pdb /version:0.0 /machine:X86 /debug /INCREMENTAL /subsystem:console  src\FListLib.lib spdlog\spdlogd.lib kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\functionnalListCPP.dir\build: functionnalListCPP.exe

.PHONY : CMakeFiles\functionnalListCPP.dir\build

CMakeFiles\functionnalListCPP.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\functionnalListCPP.dir\cmake_clean.cmake
.PHONY : CMakeFiles\functionnalListCPP.dir\clean

CMakeFiles\functionnalListCPP.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\sorge\CLionProjects\functionnalListCPP C:\Users\sorge\CLionProjects\functionnalListCPP C:\Users\sorge\CLionProjects\functionnalListCPP\cmake-build-debug C:\Users\sorge\CLionProjects\functionnalListCPP\cmake-build-debug C:\Users\sorge\CLionProjects\functionnalListCPP\cmake-build-debug\CMakeFiles\functionnalListCPP.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\functionnalListCPP.dir\depend
