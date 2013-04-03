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
PRJ_ROOT_DIR := $(WS_ROOT_DIR)/ORFv2



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

IDE_INCLUDES = -I$(WIND_BASE)/target/h/wrn/coreip -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h -I$(WIND_BASE)/host 

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
PROJECT_TARGETS = ORFv2_partialImage/$(MODE_DIR)/ORFv2_partialImage.o \
	 ORFv2/$(MODE_DIR)/ORFv2.out


#Rules

# ORFv2_partialImage
ifeq ($(DEBUG_MODE),1)
ORFv2_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
ORFv2_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
ORFv2_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
ORFv2_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
ORFv2_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
ORFv2_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
ORFv2_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
ORFv2_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
ORFv2_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
ORFv2_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
ORFv2_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
ORFv2_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif
ORFv2_partialImage/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h/wrn/coreip -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h -I$(WIND_BASE)/host 
ORFv2_partialImage/$(MODE_DIR)/% : IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 
ORFv2_partialImage/$(MODE_DIR)/% : IDE_DEFINES = 
ORFv2_partialImage/$(MODE_DIR)/% : PROJECT_TYPE = DKM
ORFv2_partialImage/$(MODE_DIR)/% : DEFINES = 
ORFv2_partialImage/$(MODE_DIR)/% : EXPAND_DBG = 0
ORFv2_partialImage/$(MODE_DIR)/% : VX_CPU_FAMILY = ppc
ORFv2_partialImage/$(MODE_DIR)/% : CPU = PPC603
ORFv2_partialImage/$(MODE_DIR)/% : TOOL_FAMILY = gnu
ORFv2_partialImage/$(MODE_DIR)/% : TOOL = gnu
ORFv2_partialImage/$(MODE_DIR)/% : TOOL_PATH = 
ORFv2_partialImage/$(MODE_DIR)/% : CC_ARCH_SPEC = -mcpu=603 -mstrict-align -mno-implicit-fp -mlongcall
ORFv2_partialImage/$(MODE_DIR)/% : LIBPATH = 
ORFv2_partialImage/$(MODE_DIR)/% : LIBS = 
ORFv2_partialImage/$(MODE_DIR)/% : OBJ_DIR := ORFv2_partialImage/$(MODE_DIR)

ORFv2_partialImage/$(MODE_DIR)/Objects/ORFv2/InsightLT/DecimalData.o : $(PRJ_ROOT_DIR)/InsightLT/DecimalData.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


ORFv2_partialImage/$(MODE_DIR)/Objects/ORFv2/InsightLT/DisplayData.o : $(PRJ_ROOT_DIR)/InsightLT/DisplayData.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


ORFv2_partialImage/$(MODE_DIR)/Objects/ORFv2/InsightLT/InsightLT.o : $(PRJ_ROOT_DIR)/InsightLT/InsightLT.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


ORFv2_partialImage/$(MODE_DIR)/Objects/ORFv2/InsightLT/IntegerData.o : $(PRJ_ROOT_DIR)/InsightLT/IntegerData.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


ORFv2_partialImage/$(MODE_DIR)/Objects/ORFv2/InsightLT/StringData.o : $(PRJ_ROOT_DIR)/InsightLT/StringData.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


ORFv2_partialImage/$(MODE_DIR)/Objects/ORFv2/InsightLT/Zone.o : $(PRJ_ROOT_DIR)/InsightLT/Zone.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


ORFv2_partialImage/$(MODE_DIR)/Objects/ORFv2/Modes/Autonomous.o : $(PRJ_ROOT_DIR)/Modes/Autonomous.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


ORFv2_partialImage/$(MODE_DIR)/Objects/ORFv2/Modes/Teleop.o : $(PRJ_ROOT_DIR)/Modes/Teleop.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


ORFv2_partialImage/$(MODE_DIR)/Objects/ORFv2/Modes/Test.o : $(PRJ_ROOT_DIR)/Modes/Test.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


ORFv2_partialImage/$(MODE_DIR)/Objects/ORFv2/Robot.o : $(PRJ_ROOT_DIR)/Robot.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


ORFv2_partialImage/$(MODE_DIR)/Objects/ORFv2/Systems/DriveBase.o : $(PRJ_ROOT_DIR)/Systems/DriveBase.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


ORFv2_partialImage/$(MODE_DIR)/Objects/ORFv2/Systems/Launcher.o : $(PRJ_ROOT_DIR)/Systems/Launcher.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


ORFv2_partialImage/$(MODE_DIR)/Objects/ORFv2/Utilities/LCD.o : $(PRJ_ROOT_DIR)/Utilities/LCD.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


ORFv2_partialImage/$(MODE_DIR)/Objects/ORFv2/Utilities/Motor.o : $(PRJ_ROOT_DIR)/Utilities/Motor.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


ORFv2_partialImage/$(MODE_DIR)/Objects/ORFv2/Utilities/math.o : $(PRJ_ROOT_DIR)/Utilities/math.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


ORFv2_partialImage/$(MODE_DIR)/Objects/ORFv2/Utilities/wiring.o : $(PRJ_ROOT_DIR)/Utilities/wiring.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


OBJECTS_ORFv2_partialImage = ORFv2_partialImage/$(MODE_DIR)/Objects/ORFv2/InsightLT/DecimalData.o \
	 ORFv2_partialImage/$(MODE_DIR)/Objects/ORFv2/InsightLT/DisplayData.o \
	 ORFv2_partialImage/$(MODE_DIR)/Objects/ORFv2/InsightLT/InsightLT.o \
	 ORFv2_partialImage/$(MODE_DIR)/Objects/ORFv2/InsightLT/IntegerData.o \
	 ORFv2_partialImage/$(MODE_DIR)/Objects/ORFv2/InsightLT/StringData.o \
	 ORFv2_partialImage/$(MODE_DIR)/Objects/ORFv2/InsightLT/Zone.o \
	 ORFv2_partialImage/$(MODE_DIR)/Objects/ORFv2/Modes/Autonomous.o \
	 ORFv2_partialImage/$(MODE_DIR)/Objects/ORFv2/Modes/Teleop.o \
	 ORFv2_partialImage/$(MODE_DIR)/Objects/ORFv2/Modes/Test.o \
	 ORFv2_partialImage/$(MODE_DIR)/Objects/ORFv2/Robot.o \
	 ORFv2_partialImage/$(MODE_DIR)/Objects/ORFv2/Systems/DriveBase.o \
	 ORFv2_partialImage/$(MODE_DIR)/Objects/ORFv2/Systems/Launcher.o \
	 ORFv2_partialImage/$(MODE_DIR)/Objects/ORFv2/Utilities/LCD.o \
	 ORFv2_partialImage/$(MODE_DIR)/Objects/ORFv2/Utilities/Motor.o \
	 ORFv2_partialImage/$(MODE_DIR)/Objects/ORFv2/Utilities/math.o \
	 ORFv2_partialImage/$(MODE_DIR)/Objects/ORFv2/Utilities/wiring.o

ORFv2_partialImage/$(MODE_DIR)/ORFv2_partialImage.o : $(OBJECTS_ORFv2_partialImage)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc -r -nostdlib -Wl,-X  -o "$@" $(OBJECTS_ORFv2_partialImage) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS)  && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

ORFv2_partialImage/$(MODE_DIR)/ORFv2_partialImage_compile_file : $(FILE) ;

_clean :: ORFv2_partialImage/$(MODE_DIR)/ORFv2_partialImage_clean

ORFv2_partialImage/$(MODE_DIR)/ORFv2_partialImage_clean : 
	$(TRACE_FLAG)if [ -d "ORFv2_partialImage" ]; then cd "ORFv2_partialImage"; rm -rf $(MODE_DIR); fi


# ORFv2
ifeq ($(DEBUG_MODE),1)
ORFv2/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
ORFv2/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
ORFv2/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
ORFv2/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
ORFv2/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
ORFv2/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
ORFv2/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
ORFv2/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
ORFv2/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
ORFv2/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
ORFv2/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
ORFv2/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif
ORFv2/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h/wrn/coreip -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h -I$(WIND_BASE)/host 
ORFv2/$(MODE_DIR)/% : IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 
ORFv2/$(MODE_DIR)/% : IDE_DEFINES = 
ORFv2/$(MODE_DIR)/% : PROJECT_TYPE = DKM
ORFv2/$(MODE_DIR)/% : DEFINES = 
ORFv2/$(MODE_DIR)/% : EXPAND_DBG = 0
ORFv2/$(MODE_DIR)/% : VX_CPU_FAMILY = ppc
ORFv2/$(MODE_DIR)/% : CPU = PPC603
ORFv2/$(MODE_DIR)/% : TOOL_FAMILY = gnu
ORFv2/$(MODE_DIR)/% : TOOL = gnu
ORFv2/$(MODE_DIR)/% : TOOL_PATH = 
ORFv2/$(MODE_DIR)/% : CC_ARCH_SPEC = -mcpu=603 -mstrict-align -mno-implicit-fp -mlongcall
ORFv2/$(MODE_DIR)/% : LIBPATH = 
ORFv2/$(MODE_DIR)/% : LIBS = 
ORFv2/$(MODE_DIR)/% : OBJ_DIR := ORFv2/$(MODE_DIR)

OBJECTS_ORFv2 = ORFv2_partialImage/$(MODE_DIR)/ORFv2_partialImage.o

ORFv2/$(MODE_DIR)/ORFv2.out : $(OBJECTS_ORFv2)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@";rm -f "$@";nmppc $(OBJECTS_ORFv2) $(IDE_LIBRARIES) | tclsh $(WIND_BASE)/host/resource/hutils/tcl/munch.tcl -c ppc > $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)ccppc $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -fdollars-in-identifiers -Wall $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES)  -o $(OBJ_DIR)/ctdt.o -c $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)ccppc -r -nostdlib -Wl,-X -T $(WIND_BASE)/target/h/tool/gnu/ldscripts/link.OUT -o "$@" $(OBJ_DIR)/ctdt.o $(OBJECTS_ORFv2) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS)  $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

ORFv2/$(MODE_DIR)/ORFv2_compile_file : $(FILE) ;

_clean :: ORFv2/$(MODE_DIR)/ORFv2_clean

ORFv2/$(MODE_DIR)/ORFv2_clean : 
	$(TRACE_FLAG)if [ -d "ORFv2" ]; then cd "ORFv2"; rm -rf $(MODE_DIR); fi

force : 

DEP_FILES := ORFv2_partialImage/$(MODE_DIR)/Objects/ORFv2/InsightLT/DecimalData.d ORFv2_partialImage/$(MODE_DIR)/Objects/ORFv2/InsightLT/DisplayData.d ORFv2_partialImage/$(MODE_DIR)/Objects/ORFv2/InsightLT/InsightLT.d \
	 ORFv2_partialImage/$(MODE_DIR)/Objects/ORFv2/InsightLT/IntegerData.d ORFv2_partialImage/$(MODE_DIR)/Objects/ORFv2/InsightLT/StringData.d ORFv2_partialImage/$(MODE_DIR)/Objects/ORFv2/InsightLT/Zone.d \
	 ORFv2_partialImage/$(MODE_DIR)/Objects/ORFv2/Modes/Autonomous.d ORFv2_partialImage/$(MODE_DIR)/Objects/ORFv2/Modes/Teleop.d ORFv2_partialImage/$(MODE_DIR)/Objects/ORFv2/Modes/Test.d \
	 ORFv2_partialImage/$(MODE_DIR)/Objects/ORFv2/Robot.d ORFv2_partialImage/$(MODE_DIR)/Objects/ORFv2/Systems/DriveBase.d ORFv2_partialImage/$(MODE_DIR)/Objects/ORFv2/Systems/Launcher.d \
	 ORFv2_partialImage/$(MODE_DIR)/Objects/ORFv2/Utilities/LCD.d ORFv2_partialImage/$(MODE_DIR)/Objects/ORFv2/Utilities/Motor.d ORFv2_partialImage/$(MODE_DIR)/Objects/ORFv2/Utilities/math.d \
	 ORFv2_partialImage/$(MODE_DIR)/Objects/ORFv2/Utilities/wiring.d
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
