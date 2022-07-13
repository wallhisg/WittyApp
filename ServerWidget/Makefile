export ROOT_BASE		?=	$(abspath $(dir $(abspath $(dir $$PWD))))
export SERVER_WIDGET_BASE			?=	$(abspath $(dir $$PWD))
export SERVER_WIDGET_PATH			?=	$(dir $(realpath $(firstword $(MAKEFILE_LIST))))

export SERVER_WIDGET_SRC_C		:=
export SERVER_WIDGET_OBJ_C		:=
export SERVER_WIDGET_DEP_C		:=

export SERVER_WIDGET_SRC_CPP		:=
export SERVER_WIDGET_OBJ_CPP		:=
export SERVER_WIDGET_DEP_CPP		:=

export SERVER_WIDGET_OBJ			:=
export SERVER_WIDGET_DEPS			:=

export SERVER_WIDGET_LIB			:=
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
export BUILD_BASE		=	$(SERVER_WIDGET_BASE)/$(BUILD)
export BUILD_PATH		=	$(SERVER_WIDGET_BASE)/$(BUILD)/
export BUILD_DIR		=	$(subst $(SERVER_WIDGET_PATH),$(BUILD_PATH), $(MDL_PATH))
export BUILD_TEST_DIR	=

# define build flag BFLAG
export	BF_RESERVED		:=	0
export	BF_NOT_USE		:=	1
export	BF_NOT_INC		:=	2
export	BF_NOT_BUILD	:=	3
export	BF_BUILD		:=	4
export	BF_TEST			:=	5

export	RESOURCES_DIR	:=	

include $(SERVER_WIDGET_BASE)/ExtraMake/Makefile
include $(SERVER_WIDGET_BASE)/Makefile.inc
include $(SERVER_WIDGET_BASE)/Makefile.bas
include $(SERVER_WIDGET_BASE)/Makefile.env

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

