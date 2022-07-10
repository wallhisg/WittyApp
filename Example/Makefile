export ROOT_BASE		?=	$(abspath $(dir $(abspath $(dir $$PWD))))
export WIDGET_BASE			?=	$(abspath $(dir $$PWD))
export WIDGET_PATH			?=	$(dir $(realpath $(firstword $(MAKEFILE_LIST))))

export WIDGET_SRC_C		:=
export WIDGET_OBJ_C		:=
export WIDGET_DEP_C		:=

export WIDGET_SRC_CPP		:=
export WIDGET_OBJ_CPP		:=
export WIDGET_DEP_CPP		:=

export WIDGET_OBJ			:=
export WIDGET_DEPS			:=

export WIDGET_LIB			:=
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
export BUILD_BASE		=	$(WIDGET_BASE)/$(BUILD)
export BUILD_PATH		=	$(WIDGET_BASE)/$(BUILD)/
export BUILD_DIR		=	$(subst $(WIDGET_PATH),$(BUILD_PATH), $(MDL_PATH))
export BUILD_TEST_DIR	=

# define build flag BFLAG
export	BF_RESERVED		:=	0
export	BF_NOT_USE		:=	1
export	BF_NOT_INC		:=	2
export	BF_NOT_BUILD	:=	3
export	BF_BUILD		:=	4
export	BF_TEST			:=	5

export	RESOURCES_DIR	:=	

include $(WIDGET_BASE)/Makefile.inc
include $(WIDGET_BASE)/Makefile.bas
include $(WIDGET_BASE)/Makefile.env

# resources-dir
# Make build multi
MAKEFLAGS += "-j$(NUM_CORES) -l$(NUM_CORES)

.PHONY: all build clean checkdirs test run

#======================================================================
# Enviroment
#======================================================================
MKDIR	:= @mkdir -p
RMDIR	:= @rm -rf	
RM	:= rm -f
MV	:= mf -f
#======================================================================

test:
	@echo	$(WIDGET_MAKEFILE)

