export ROOT_BASE		?=	$(abspath $(dir $(abspath $(dir $$PWD))))
export LAYOUT_BASE			?=	$(abspath $(dir $$PWD))
export LAYOUT_PATH			?=	$(dir $(realpath $(firstword $(MAKEFILE_LIST))))

export LAYOUT_SRC_C		:=
export LAYOUT_OBJ_C		:=
export LAYOUT_DEP_C		:=

export LAYOUT_SRC_CPP		:=
export LAYOUT_OBJ_CPP		:=
export LAYOUT_DEP_CPP		:=

export LAYOUT_OBJ			:=
export LAYOUT_DEPS			:=

export LAYOUT_LIB			:=
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
export BUILD_BASE		=	$(LAYOUT_BASE)/$(BUILD)
export BUILD_PATH		=	$(LAYOUT_BASE)/$(BUILD)/
export BUILD_DIR		=	$(subst $(LAYOUT_PATH),$(BUILD_PATH), $(MDL_PATH))
export BUILD_TEST_DIR	=

# define build flag BFLAG
export	BF_RESERVED		:=	0
export	BF_NOT_USE		:=	1
export	BF_NOT_INC		:=	2
export	BF_NOT_BUILD	:=	3
export	BF_BUILD		:=	4
export	BF_TEST			:=	5

export	RESOURCES_DIR	:=	

include $(LAYOUT_BASE)/Makefile.Widget
include $(LAYOUT_BASE)/Makefile.inc
include $(LAYOUT_BASE)/Makefile.bas
include $(LAYOUT_BASE)/Makefile.env

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

