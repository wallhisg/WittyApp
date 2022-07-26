export ROOT_BASE				?=	$(abspath $(dir $(abspath $(dir $$PWD))))
export UI_BASE		?=	$(abspath $(dir $$PWD))
export UI_PATH		?=	$(dir $(realpath $(firstword $(MAKEFILE_LIST))))

export UI_SRC_C		:=
export UI_OBJ_C		:=
export UI_DEP_C		:=

export UI_SRC_CPP	:=
export UI_OBJ_CPP	:=
export UI_DEP_CPP	:=

export UI_OBJ		:=
export UI_DEPS		:=

export UI_LIB		:=
export EXTRA_LIB		:=

export MDL_PATH			:=
export EXTRA_MDL_PATH	:=

export TEST_PATH		:=

# Using in Makefile.bas, Makefile.inc
export MDL_INC			:=
export EXTRA_MLD_INC	:=

export TARGET			:=
export PROGRAMS			:=

export BUILD			=	build
export BUILD_BASE		=	$(UI_BASE)/$(BUILD)
export BUILD_PATH		=	$(UI_BASE)/$(BUILD)/
export BUILD_DIR		=	$(subst $(UI_PATH),$(BUILD_PATH), $(MDL_PATH))
export BUILD_TEST_DIR	=

# define build flag BFLAG
export	BF_RESERVED		:=	0
export	BF_NOT_USE		:=	1
export	BF_NOT_INC		:=	2
export	BF_NOT_BUILD	:=	3
export	BF_BUILD		:=	4
export	BF_TEST			:=	5

export	RESOURCES_DIR	:=	

include $(UI_BASE)/Makefiles/Makefile
include $(UI_BASE)/Makefile.inc
include $(UI_BASE)/Makefile.bas
include $(UI_BASE)/Makefile.env

# resources-dir
# Make build multi
MAKEFLAGS += "-j$(NUM_CORES) -l$(NUM_CORES)

.PHONY: all build clean checkdirs test run

#======================================================================
# Enviroment
#======================================================================
MKDIR	:= @mkdir -p
RMDIR	:= @rm -rf	
RM		:= rm -f
MV		:= mf -f
#======================================================================

test:
	@echo	$(WIDGET_DIR)
	@echo	$(EXTRA_MLD_INC)