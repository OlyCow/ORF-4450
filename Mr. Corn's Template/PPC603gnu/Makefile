# Wind River Workbench generated Makefile.
# Do not edit!!!
#
# The file ".wrmakefile" is the template used by the Wind River Workbench to
# generate the makefiles of this project. Add user-specific build targets and
# make rules only(!) in this project's ".wrmakefile" file. These will then be
# automatically dumped into the makefiles.

WIND_HOME := $(subst \,/,$(WIND_HOME))
WIND_BASE := $(subst \,/,$(WIND_BASE))
WIND_USR := $(subst \,/,$(WIND_USR))

all : pre_build main_all post_build

_clean ::
	@echo "make: removing targets and objects of `pwd`"

TRACE=0
TRACEON=$(TRACE:0=@)
TRACE_FLAG=$(TRACEON:1=)

MAKEFILE := Makefile

FLEXIBLE_BUILD := 1

BUILD_SPEC = PPC603gnu
DEBUG_MODE = 1
ifeq ($(DEBUG_MODE),1)
MODE_DIR := Debug
else
MODE_DIR := NonDebug
endif
OBJ_DIR := .
WS_ROOT_DIR := C:/WindRiver/workspace
PRJ_ROOT_DIR := $(WS_ROOT_DIR)/MyRobot3



#Global Build Macros
PROJECT_TYPE = DKM
DEFINES = 
EXPAND_DBG = 0


#BuildSpec specific Build Macros
VX_CPU_FAMILY = ppc
CPU = PPC603
TOOL_FAMILY = gnu
TOOL = gnu
TOOL_PATH = 
CC_ARCH_SPEC = -mcpu=603 -mstrict-align -mno-implicit-fp -mlongcall
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h/wrn/coreip 

IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 

IDE_DEFINES = 



#BuildTool flags
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
DEBUGFLAGS_C++-Compiler = -g
DEBUGFLAGS_Linker = -g
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif


#Project Targets
PROJECT_TARGETS = MyRobot3/$(MODE_DIR)/MyRobot3.out \
	 MyRobot3_partialImage/$(MODE_DIR)/MyRobot3_partialImage.o


#Rules

# MyRobot3
ifeq ($(DEBUG_MODE),1)
MyRobot3/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
MyRobot3/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
MyRobot3/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
MyRobot3/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
MyRobot3/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
MyRobot3/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
MyRobot3/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
MyRobot3/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
MyRobot3/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
MyRobot3/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
MyRobot3/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
MyRobot3/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif
MyRobot3/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h/wrn/coreip 
MyRobot3/$(MODE_DIR)/% : IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 
MyRobot3/$(MODE_DIR)/% : IDE_DEFINES = 
MyRobot3/$(MODE_DIR)/% : PROJECT_TYPE = DKM
MyRobot3/$(MODE_DIR)/% : DEFINES = 
MyRobot3/$(MODE_DIR)/% : EXPAND_DBG = 0
MyRobot3/$(MODE_DIR)/% : VX_CPU_FAMILY = ppc
MyRobot3/$(MODE_DIR)/% : CPU = PPC603
MyRobot3/$(MODE_DIR)/% : TOOL_FAMILY = gnu
MyRobot3/$(MODE_DIR)/% : TOOL = gnu
MyRobot3/$(MODE_DIR)/% : TOOL_PATH = 
MyRobot3/$(MODE_DIR)/% : CC_ARCH_SPEC = -mcpu=603 -mstrict-align -mno-implicit-fp -mlongcall
MyRobot3/$(MODE_DIR)/% : LIBPATH = 
MyRobot3/$(MODE_DIR)/% : LIBS = 
MyRobot3/$(MODE_DIR)/% : OBJ_DIR := MyRobot3/$(MODE_DIR)

OBJECTS_MyRobot3 = MyRobot3_partialImage/$(MODE_DIR)/MyRobot3_partialImage.o

MyRobot3/$(MODE_DIR)/MyRobot3.out : $(OBJECTS_MyRobot3)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@";rm -f "$@";nmppc $(OBJECTS_MyRobot3) $(IDE_LIBRARIES) | tclsh $(WIND_BASE)/host/resource/hutils/tcl/munch.tcl -c ppc > $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)ccppc $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -fdollars-in-identifiers -Wall $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES)  -o $(OBJ_DIR)/ctdt.o -c $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)ccppc -r -nostdlib -Wl,-X -T $(WIND_BASE)/target/h/tool/gnu/ldscripts/link.OUT -o "$@" $(OBJ_DIR)/ctdt.o $(OBJECTS_MyRobot3) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS)  $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

MyRobot3/$(MODE_DIR)/MyRobot3_compile_file : $(FILE) ;

_clean :: MyRobot3/$(MODE_DIR)/MyRobot3_clean

MyRobot3/$(MODE_DIR)/MyRobot3_clean : 
	$(TRACE_FLAG)if [ -d "MyRobot3" ]; then cd "MyRobot3"; rm -rf $(MODE_DIR); fi


# MyRobot3_partialImage
ifeq ($(DEBUG_MODE),1)
MyRobot3_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
MyRobot3_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
MyRobot3_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
MyRobot3_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
MyRobot3_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
MyRobot3_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
MyRobot3_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
MyRobot3_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
MyRobot3_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
MyRobot3_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
MyRobot3_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
MyRobot3_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif
MyRobot3_partialImage/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h/wrn/coreip 
MyRobot3_partialImage/$(MODE_DIR)/% : IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 
MyRobot3_partialImage/$(MODE_DIR)/% : IDE_DEFINES = 
MyRobot3_partialImage/$(MODE_DIR)/% : PROJECT_TYPE = DKM
MyRobot3_partialImage/$(MODE_DIR)/% : DEFINES = 
MyRobot3_partialImage/$(MODE_DIR)/% : EXPAND_DBG = 0
MyRobot3_partialImage/$(MODE_DIR)/% : VX_CPU_FAMILY = ppc
MyRobot3_partialImage/$(MODE_DIR)/% : CPU = PPC603
MyRobot3_partialImage/$(MODE_DIR)/% : TOOL_FAMILY = gnu
MyRobot3_partialImage/$(MODE_DIR)/% : TOOL = gnu
MyRobot3_partialImage/$(MODE_DIR)/% : TOOL_PATH = 
MyRobot3_partialImage/$(MODE_DIR)/% : CC_ARCH_SPEC = -mcpu=603 -mstrict-align -mno-implicit-fp -mlongcall
MyRobot3_partialImage/$(MODE_DIR)/% : LIBPATH = 
MyRobot3_partialImage/$(MODE_DIR)/% : LIBS = 
MyRobot3_partialImage/$(MODE_DIR)/% : OBJ_DIR := MyRobot3_partialImage/$(MODE_DIR)

MyRobot3_partialImage/$(MODE_DIR)/Objects/MyRobot3/InsightLT/DecimalData.o : $(PRJ_ROOT_DIR)/InsightLT/DecimalData.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


MyRobot3_partialImage/$(MODE_DIR)/Objects/MyRobot3/InsightLT/DisplayData.o : $(PRJ_ROOT_DIR)/InsightLT/DisplayData.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


MyRobot3_partialImage/$(MODE_DIR)/Objects/MyRobot3/InsightLT/InsightLT.o : $(PRJ_ROOT_DIR)/InsightLT/InsightLT.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


MyRobot3_partialImage/$(MODE_DIR)/Objects/MyRobot3/InsightLT/IntegerData.o : $(PRJ_ROOT_DIR)/InsightLT/IntegerData.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


MyRobot3_partialImage/$(MODE_DIR)/Objects/MyRobot3/InsightLT/StringData.o : $(PRJ_ROOT_DIR)/InsightLT/StringData.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


MyRobot3_partialImage/$(MODE_DIR)/Objects/MyRobot3/InsightLT/Zone.o : $(PRJ_ROOT_DIR)/InsightLT/Zone.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


MyRobot3_partialImage/$(MODE_DIR)/Objects/MyRobot3/LCD.o : $(PRJ_ROOT_DIR)/LCD.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


MyRobot3_partialImage/$(MODE_DIR)/Objects/MyRobot3/MyAutonomous.o : $(PRJ_ROOT_DIR)/MyAutonomous.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


MyRobot3_partialImage/$(MODE_DIR)/Objects/MyRobot3/MyClimber.o : $(PRJ_ROOT_DIR)/MyClimber.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


MyRobot3_partialImage/$(MODE_DIR)/Objects/MyRobot3/MyDiscShooter.o : $(PRJ_ROOT_DIR)/MyDiscShooter.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


MyRobot3_partialImage/$(MODE_DIR)/Objects/MyRobot3/MyDiscShooterCmd.o : $(PRJ_ROOT_DIR)/MyDiscShooterCmd.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


MyRobot3_partialImage/$(MODE_DIR)/Objects/MyRobot3/MyRobot.o : $(PRJ_ROOT_DIR)/MyRobot.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


MyRobot3_partialImage/$(MODE_DIR)/Objects/MyRobot3/MyTeleop.o : $(PRJ_ROOT_DIR)/MyTeleop.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


OBJECTS_MyRobot3_partialImage = MyRobot3_partialImage/$(MODE_DIR)/Objects/MyRobot3/InsightLT/DecimalData.o \
	 MyRobot3_partialImage/$(MODE_DIR)/Objects/MyRobot3/InsightLT/DisplayData.o \
	 MyRobot3_partialImage/$(MODE_DIR)/Objects/MyRobot3/InsightLT/InsightLT.o \
	 MyRobot3_partialImage/$(MODE_DIR)/Objects/MyRobot3/InsightLT/IntegerData.o \
	 MyRobot3_partialImage/$(MODE_DIR)/Objects/MyRobot3/InsightLT/StringData.o \
	 MyRobot3_partialImage/$(MODE_DIR)/Objects/MyRobot3/InsightLT/Zone.o \
	 MyRobot3_partialImage/$(MODE_DIR)/Objects/MyRobot3/LCD.o \
	 MyRobot3_partialImage/$(MODE_DIR)/Objects/MyRobot3/MyAutonomous.o \
	 MyRobot3_partialImage/$(MODE_DIR)/Objects/MyRobot3/MyClimber.o \
	 MyRobot3_partialImage/$(MODE_DIR)/Objects/MyRobot3/MyDiscShooter.o \
	 MyRobot3_partialImage/$(MODE_DIR)/Objects/MyRobot3/MyDiscShooterCmd.o \
	 MyRobot3_partialImage/$(MODE_DIR)/Objects/MyRobot3/MyRobot.o \
	 MyRobot3_partialImage/$(MODE_DIR)/Objects/MyRobot3/MyTeleop.o

MyRobot3_partialImage/$(MODE_DIR)/MyRobot3_partialImage.o : $(OBJECTS_MyRobot3_partialImage)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc -r -nostdlib -Wl,-X  -o "$@" $(OBJECTS_MyRobot3_partialImage) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS)  && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

MyRobot3_partialImage/$(MODE_DIR)/MyRobot3_partialImage_compile_file : $(FILE) ;

_clean :: MyRobot3_partialImage/$(MODE_DIR)/MyRobot3_partialImage_clean

MyRobot3_partialImage/$(MODE_DIR)/MyRobot3_partialImage_clean : 
	$(TRACE_FLAG)if [ -d "MyRobot3_partialImage" ]; then cd "MyRobot3_partialImage"; rm -rf $(MODE_DIR); fi

force : 

DEP_FILES := MyRobot3_partialImage/$(MODE_DIR)/Objects/MyRobot3/InsightLT/DecimalData.d MyRobot3_partialImage/$(MODE_DIR)/Objects/MyRobot3/InsightLT/DisplayData.d MyRobot3_partialImage/$(MODE_DIR)/Objects/MyRobot3/InsightLT/InsightLT.d \
	 MyRobot3_partialImage/$(MODE_DIR)/Objects/MyRobot3/InsightLT/IntegerData.d MyRobot3_partialImage/$(MODE_DIR)/Objects/MyRobot3/InsightLT/StringData.d MyRobot3_partialImage/$(MODE_DIR)/Objects/MyRobot3/InsightLT/Zone.d \
	 MyRobot3_partialImage/$(MODE_DIR)/Objects/MyRobot3/LCD.d MyRobot3_partialImage/$(MODE_DIR)/Objects/MyRobot3/MyAutonomous.d MyRobot3_partialImage/$(MODE_DIR)/Objects/MyRobot3/MyClimber.d \
	 MyRobot3_partialImage/$(MODE_DIR)/Objects/MyRobot3/MyDiscShooter.d MyRobot3_partialImage/$(MODE_DIR)/Objects/MyRobot3/MyDiscShooterCmd.d MyRobot3_partialImage/$(MODE_DIR)/Objects/MyRobot3/MyRobot.d \
	 MyRobot3_partialImage/$(MODE_DIR)/Objects/MyRobot3/MyTeleop.d
-include $(DEP_FILES)



-include $(PRJ_ROOT_DIR)/*.makefile

-include *.makefile

main_all : external_build $(PROJECT_TARGETS)
	@echo "make: built targets of `pwd`"

# entry point for extending the build
external_build ::
	@echo ""

# main entry point for pre processing prior to the build
pre_build :: $(PRE_BUILD_STEP) generate_sources
	@echo ""

# entry point for generating sources prior to the build
generate_sources ::
	@echo ""

# main entry point for post processing after the build
post_build :: $(POST_BUILD_STEP) deploy_output
	@echo ""

# entry point for deploying output after the build
deploy_output ::
	@echo ""

clean :: external_clean $(CLEAN_STEP) _clean

# entry point for extending the build clean
external_clean ::
	@echo ""
