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
PRJ_ROOT_DIR := $(WS_ROOT_DIR)/Test_Program



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
PROJECT_TARGETS = Test_Program/$(MODE_DIR)/Test_Program.out \
	 Test_Program_partialImage/$(MODE_DIR)/Test_Program_partialImage.o


#Rules

# Test_Program
ifeq ($(DEBUG_MODE),1)
Test_Program/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
Test_Program/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
Test_Program/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
Test_Program/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
Test_Program/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
Test_Program/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
Test_Program/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
Test_Program/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
Test_Program/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
Test_Program/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
Test_Program/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
Test_Program/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif
Test_Program/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h/wrn/coreip 
Test_Program/$(MODE_DIR)/% : IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 
Test_Program/$(MODE_DIR)/% : IDE_DEFINES = 
Test_Program/$(MODE_DIR)/% : PROJECT_TYPE = DKM
Test_Program/$(MODE_DIR)/% : DEFINES = 
Test_Program/$(MODE_DIR)/% : EXPAND_DBG = 0
Test_Program/$(MODE_DIR)/% : VX_CPU_FAMILY = ppc
Test_Program/$(MODE_DIR)/% : CPU = PPC603
Test_Program/$(MODE_DIR)/% : TOOL_FAMILY = gnu
Test_Program/$(MODE_DIR)/% : TOOL = gnu
Test_Program/$(MODE_DIR)/% : TOOL_PATH = 
Test_Program/$(MODE_DIR)/% : CC_ARCH_SPEC = -mcpu=603 -mstrict-align -mno-implicit-fp -mlongcall
Test_Program/$(MODE_DIR)/% : LIBPATH = 
Test_Program/$(MODE_DIR)/% : LIBS = 
Test_Program/$(MODE_DIR)/% : OBJ_DIR := Test_Program/$(MODE_DIR)

OBJECTS_Test_Program = Test_Program_partialImage/$(MODE_DIR)/Test_Program_partialImage.o

Test_Program/$(MODE_DIR)/Test_Program.out : $(OBJECTS_Test_Program)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@";rm -f "$@";nmppc $(OBJECTS_Test_Program) $(IDE_LIBRARIES) | tclsh $(WIND_BASE)/host/resource/hutils/tcl/munch.tcl -c ppc > $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)ccppc $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -fdollars-in-identifiers -Wall $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES)  -o $(OBJ_DIR)/ctdt.o -c $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)ccppc -r -nostdlib -Wl,-X -T $(WIND_BASE)/target/h/tool/gnu/ldscripts/link.OUT -o "$@" $(OBJ_DIR)/ctdt.o $(OBJECTS_Test_Program) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS)  $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

Test_Program/$(MODE_DIR)/Test_Program_compile_file : $(FILE) ;

_clean :: Test_Program/$(MODE_DIR)/Test_Program_clean

Test_Program/$(MODE_DIR)/Test_Program_clean : 
	$(TRACE_FLAG)if [ -d "Test_Program" ]; then cd "Test_Program"; rm -rf $(MODE_DIR); fi


# Test_Program_partialImage
ifeq ($(DEBUG_MODE),1)
Test_Program_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
Test_Program_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
Test_Program_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
Test_Program_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
Test_Program_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
Test_Program_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
Test_Program_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
Test_Program_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
Test_Program_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
Test_Program_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
Test_Program_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
Test_Program_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif
Test_Program_partialImage/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h/wrn/coreip 
Test_Program_partialImage/$(MODE_DIR)/% : IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 
Test_Program_partialImage/$(MODE_DIR)/% : IDE_DEFINES = 
Test_Program_partialImage/$(MODE_DIR)/% : PROJECT_TYPE = DKM
Test_Program_partialImage/$(MODE_DIR)/% : DEFINES = 
Test_Program_partialImage/$(MODE_DIR)/% : EXPAND_DBG = 0
Test_Program_partialImage/$(MODE_DIR)/% : VX_CPU_FAMILY = ppc
Test_Program_partialImage/$(MODE_DIR)/% : CPU = PPC603
Test_Program_partialImage/$(MODE_DIR)/% : TOOL_FAMILY = gnu
Test_Program_partialImage/$(MODE_DIR)/% : TOOL = gnu
Test_Program_partialImage/$(MODE_DIR)/% : TOOL_PATH = 
Test_Program_partialImage/$(MODE_DIR)/% : CC_ARCH_SPEC = -mcpu=603 -mstrict-align -mno-implicit-fp -mlongcall
Test_Program_partialImage/$(MODE_DIR)/% : LIBPATH = 
Test_Program_partialImage/$(MODE_DIR)/% : LIBS = 
Test_Program_partialImage/$(MODE_DIR)/% : OBJ_DIR := Test_Program_partialImage/$(MODE_DIR)

Test_Program_partialImage/$(MODE_DIR)/Objects/Test_Program/MyRobot.o : $(PRJ_ROOT_DIR)/MyRobot.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


OBJECTS_Test_Program_partialImage = Test_Program_partialImage/$(MODE_DIR)/Objects/Test_Program/MyRobot.o

Test_Program_partialImage/$(MODE_DIR)/Test_Program_partialImage.o : $(OBJECTS_Test_Program_partialImage)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc -r -nostdlib -Wl,-X  -o "$@" $(OBJECTS_Test_Program_partialImage) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS)  && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

Test_Program_partialImage/$(MODE_DIR)/Test_Program_partialImage_compile_file : $(FILE) ;

_clean :: Test_Program_partialImage/$(MODE_DIR)/Test_Program_partialImage_clean

Test_Program_partialImage/$(MODE_DIR)/Test_Program_partialImage_clean : 
	$(TRACE_FLAG)if [ -d "Test_Program_partialImage" ]; then cd "Test_Program_partialImage"; rm -rf $(MODE_DIR); fi

force : 

DEP_FILES := Test_Program_partialImage/$(MODE_DIR)/Objects/Test_Program/MyRobot.d
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
