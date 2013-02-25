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
WS_ROOT_DIR := C:/Users/thoward3200/Documents/012_GitHub/ORF-4450
PRJ_ROOT_DIR := $(WS_ROOT_DIR)/Mr.\ Corn's\ Template



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
PROJECT_TARGETS = MrCornsTemplate/$(MODE_DIR)/MrCornsTemplate.out \
	 MrCornsTemplate_partialImage/$(MODE_DIR)/MrCornsTemplate_partialImage.o


#Rules

# MrCornsTemplate
ifeq ($(DEBUG_MODE),1)
MrCornsTemplate/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
MrCornsTemplate/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
MrCornsTemplate/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
MrCornsTemplate/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
MrCornsTemplate/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
MrCornsTemplate/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
MrCornsTemplate/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
MrCornsTemplate/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
MrCornsTemplate/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
MrCornsTemplate/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
MrCornsTemplate/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
MrCornsTemplate/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif
MrCornsTemplate/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h/wrn/coreip 
MrCornsTemplate/$(MODE_DIR)/% : IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 
MrCornsTemplate/$(MODE_DIR)/% : IDE_DEFINES = 
MrCornsTemplate/$(MODE_DIR)/% : PROJECT_TYPE = DKM
MrCornsTemplate/$(MODE_DIR)/% : DEFINES = 
MrCornsTemplate/$(MODE_DIR)/% : EXPAND_DBG = 0
MrCornsTemplate/$(MODE_DIR)/% : VX_CPU_FAMILY = ppc
MrCornsTemplate/$(MODE_DIR)/% : CPU = PPC603
MrCornsTemplate/$(MODE_DIR)/% : TOOL_FAMILY = gnu
MrCornsTemplate/$(MODE_DIR)/% : TOOL = gnu
MrCornsTemplate/$(MODE_DIR)/% : TOOL_PATH = 
MrCornsTemplate/$(MODE_DIR)/% : CC_ARCH_SPEC = -mcpu=603 -mstrict-align -mno-implicit-fp -mlongcall
MrCornsTemplate/$(MODE_DIR)/% : LIBPATH = 
MrCornsTemplate/$(MODE_DIR)/% : LIBS = 
MrCornsTemplate/$(MODE_DIR)/% : OBJ_DIR := MrCornsTemplate/$(MODE_DIR)

OBJECTS_MrCornsTemplate = MrCornsTemplate_partialImage/$(MODE_DIR)/MrCornsTemplate_partialImage.o

MrCornsTemplate/$(MODE_DIR)/MrCornsTemplate.out : $(OBJECTS_MrCornsTemplate)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@";rm -f "$@";nmppc $(OBJECTS_MrCornsTemplate) $(IDE_LIBRARIES) | tclsh $(WIND_BASE)/host/resource/hutils/tcl/munch.tcl -c ppc > $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)ccppc $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -fdollars-in-identifiers -Wall $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES)  -o $(OBJ_DIR)/ctdt.o -c $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)ccppc -r -nostdlib -Wl,-X -T $(WIND_BASE)/target/h/tool/gnu/ldscripts/link.OUT -o "$@" $(OBJ_DIR)/ctdt.o $(OBJECTS_MrCornsTemplate) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS)  $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

MrCornsTemplate/$(MODE_DIR)/MrCornsTemplate_compile_file : $(FILE) ;

_clean :: MrCornsTemplate/$(MODE_DIR)/MrCornsTemplate_clean

MrCornsTemplate/$(MODE_DIR)/MrCornsTemplate_clean : 
	$(TRACE_FLAG)if [ -d "MrCornsTemplate" ]; then cd "MrCornsTemplate"; rm -rf $(MODE_DIR); fi


# MrCornsTemplate_partialImage
ifeq ($(DEBUG_MODE),1)
MrCornsTemplate_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
MrCornsTemplate_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
MrCornsTemplate_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
MrCornsTemplate_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
MrCornsTemplate_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
MrCornsTemplate_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
MrCornsTemplate_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
MrCornsTemplate_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
MrCornsTemplate_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
MrCornsTemplate_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
MrCornsTemplate_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
MrCornsTemplate_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif
MrCornsTemplate_partialImage/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h/wrn/coreip 
MrCornsTemplate_partialImage/$(MODE_DIR)/% : IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 
MrCornsTemplate_partialImage/$(MODE_DIR)/% : IDE_DEFINES = 
MrCornsTemplate_partialImage/$(MODE_DIR)/% : PROJECT_TYPE = DKM
MrCornsTemplate_partialImage/$(MODE_DIR)/% : DEFINES = 
MrCornsTemplate_partialImage/$(MODE_DIR)/% : EXPAND_DBG = 0
MrCornsTemplate_partialImage/$(MODE_DIR)/% : VX_CPU_FAMILY = ppc
MrCornsTemplate_partialImage/$(MODE_DIR)/% : CPU = PPC603
MrCornsTemplate_partialImage/$(MODE_DIR)/% : TOOL_FAMILY = gnu
MrCornsTemplate_partialImage/$(MODE_DIR)/% : TOOL = gnu
MrCornsTemplate_partialImage/$(MODE_DIR)/% : TOOL_PATH = 
MrCornsTemplate_partialImage/$(MODE_DIR)/% : CC_ARCH_SPEC = -mcpu=603 -mstrict-align -mno-implicit-fp -mlongcall
MrCornsTemplate_partialImage/$(MODE_DIR)/% : LIBPATH = 
MrCornsTemplate_partialImage/$(MODE_DIR)/% : LIBS = 
MrCornsTemplate_partialImage/$(MODE_DIR)/% : OBJ_DIR := MrCornsTemplate_partialImage/$(MODE_DIR)

MrCornsTemplate_partialImage/$(MODE_DIR)/Objects/InsightLT/DecimalData.o : $(PRJ_ROOT_DIR)/InsightLT/DecimalData.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


MrCornsTemplate_partialImage/$(MODE_DIR)/Objects/InsightLT/DisplayData.o : $(PRJ_ROOT_DIR)/InsightLT/DisplayData.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


MrCornsTemplate_partialImage/$(MODE_DIR)/Objects/InsightLT/InsightLT.o : $(PRJ_ROOT_DIR)/InsightLT/InsightLT.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


MrCornsTemplate_partialImage/$(MODE_DIR)/Objects/InsightLT/IntegerData.o : $(PRJ_ROOT_DIR)/InsightLT/IntegerData.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


MrCornsTemplate_partialImage/$(MODE_DIR)/Objects/InsightLT/StringData.o : $(PRJ_ROOT_DIR)/InsightLT/StringData.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


MrCornsTemplate_partialImage/$(MODE_DIR)/Objects/InsightLT/Zone.o : $(PRJ_ROOT_DIR)/InsightLT/Zone.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


MrCornsTemplate_partialImage/$(MODE_DIR)/Objects/cRIO.o : $(PRJ_ROOT_DIR)/cRIO.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


MrCornsTemplate_partialImage/$(MODE_DIR)/Objects/LCD.o : $(PRJ_ROOT_DIR)/LCD.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


MrCornsTemplate_partialImage/$(MODE_DIR)/Objects/MyAutonomous.o : $(PRJ_ROOT_DIR)/MyAutonomous.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


MrCornsTemplate_partialImage/$(MODE_DIR)/Objects/MyClimber.o : $(PRJ_ROOT_DIR)/MyClimber.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


MrCornsTemplate_partialImage/$(MODE_DIR)/Objects/MyDiscShooter.o : $(PRJ_ROOT_DIR)/MyDiscShooter.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


MrCornsTemplate_partialImage/$(MODE_DIR)/Objects/MyDiscShooterCmd.o : $(PRJ_ROOT_DIR)/MyDiscShooterCmd.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


MrCornsTemplate_partialImage/$(MODE_DIR)/Objects/MyRobot.o : $(PRJ_ROOT_DIR)/MyRobot.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


MrCornsTemplate_partialImage/$(MODE_DIR)/Objects/MyTeleop.o : $(PRJ_ROOT_DIR)/MyTeleop.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


OBJECTS_MrCornsTemplate_partialImage = MrCornsTemplate_partialImage/$(MODE_DIR)/Objects/InsightLT/DecimalData.o \
	 MrCornsTemplate_partialImage/$(MODE_DIR)/Objects/InsightLT/DisplayData.o \
	 MrCornsTemplate_partialImage/$(MODE_DIR)/Objects/InsightLT/InsightLT.o \
	 MrCornsTemplate_partialImage/$(MODE_DIR)/Objects/InsightLT/IntegerData.o \
	 MrCornsTemplate_partialImage/$(MODE_DIR)/Objects/InsightLT/StringData.o \
	 MrCornsTemplate_partialImage/$(MODE_DIR)/Objects/InsightLT/Zone.o \
	 MrCornsTemplate_partialImage/$(MODE_DIR)/Objects/cRIO.o \
	 MrCornsTemplate_partialImage/$(MODE_DIR)/Objects/LCD.o \
	 MrCornsTemplate_partialImage/$(MODE_DIR)/Objects/MyAutonomous.o \
	 MrCornsTemplate_partialImage/$(MODE_DIR)/Objects/MyClimber.o \
	 MrCornsTemplate_partialImage/$(MODE_DIR)/Objects/MyDiscShooter.o \
	 MrCornsTemplate_partialImage/$(MODE_DIR)/Objects/MyDiscShooterCmd.o \
	 MrCornsTemplate_partialImage/$(MODE_DIR)/Objects/MyRobot.o \
	 MrCornsTemplate_partialImage/$(MODE_DIR)/Objects/MyTeleop.o

MrCornsTemplate_partialImage/$(MODE_DIR)/MrCornsTemplate_partialImage.o : $(OBJECTS_MrCornsTemplate_partialImage)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc -r -nostdlib -Wl,-X  -o "$@" $(OBJECTS_MrCornsTemplate_partialImage) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS)  && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

MrCornsTemplate_partialImage/$(MODE_DIR)/MrCornsTemplate_partialImage_compile_file : $(FILE) ;

_clean :: MrCornsTemplate_partialImage/$(MODE_DIR)/MrCornsTemplate_partialImage_clean

MrCornsTemplate_partialImage/$(MODE_DIR)/MrCornsTemplate_partialImage_clean : 
	$(TRACE_FLAG)if [ -d "MrCornsTemplate_partialImage" ]; then cd "MrCornsTemplate_partialImage"; rm -rf $(MODE_DIR); fi

force : 

DEP_FILES := MrCornsTemplate_partialImage/$(MODE_DIR)/Objects/InsightLT/DecimalData.d MrCornsTemplate_partialImage/$(MODE_DIR)/Objects/InsightLT/DisplayData.d MrCornsTemplate_partialImage/$(MODE_DIR)/Objects/InsightLT/InsightLT.d \
	 MrCornsTemplate_partialImage/$(MODE_DIR)/Objects/InsightLT/IntegerData.d MrCornsTemplate_partialImage/$(MODE_DIR)/Objects/InsightLT/StringData.d MrCornsTemplate_partialImage/$(MODE_DIR)/Objects/InsightLT/Zone.d \
	 MrCornsTemplate_partialImage/$(MODE_DIR)/Objects/cRIO.d MrCornsTemplate_partialImage/$(MODE_DIR)/Objects/LCD.d MrCornsTemplate_partialImage/$(MODE_DIR)/Objects/MyAutonomous.d \
	 MrCornsTemplate_partialImage/$(MODE_DIR)/Objects/MyClimber.d MrCornsTemplate_partialImage/$(MODE_DIR)/Objects/MyDiscShooter.d MrCornsTemplate_partialImage/$(MODE_DIR)/Objects/MyDiscShooterCmd.d \
	 MrCornsTemplate_partialImage/$(MODE_DIR)/Objects/MyRobot.d MrCornsTemplate_partialImage/$(MODE_DIR)/Objects/MyTeleop.d
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
