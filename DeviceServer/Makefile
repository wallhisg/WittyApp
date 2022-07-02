export ROOT_BASE		?=	$(abspath $(dir $(abspath $(dir $$PWD))))
export PRJ_BASE			?=	$(abspath $(dir $$PWD))
export PRJ_PATH			?=	$(dir $(realpath $(firstword $(MAKEFILE_LIST))))

export PRJ_SRC_C		:=
export PRJ_OBJ_C		:=
export PRJ_DEP_C		:=

export PRJ_SRC_CPP		:=
export PRJ_OBJ_CPP		:=
export PRJ_DEP_CPP		:=

export PRJ_OBJ			:=
export PRJ_DEPS			:=

export PRJ_LIB			:=
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
export BUILD_BASE		=	$(PRJ_BASE)/$(BUILD)
export BUILD_PATH		=	$(PRJ_BASE)/$(BUILD)/
export BUILD_DIR		=	$(subst $(PRJ_PATH),$(BUILD_PATH), $(MDL_PATH))
export BUILD_TEST_DIR	=
export EXTEND_BUILD_DIR	:=
# define build flag BFLAG
export	BF_RESERVED		:=	0
export	BF_NOT_USE		:=	1
export	BF_NOT_INC		:=	2
export	BF_NOT_BUILD	:=	3
export	BF_BUILD		:=	4
export	BF_TEST			:=	5

export	RESOURCES_DIR	:=	

include $(PRJ_BASE)/Makefile.WebLayout
include $(PRJ_BASE)/Makefile.inc
include $(PRJ_BASE)/Makefile.bas
include $(PRJ_BASE)/Makefile.env

# Make build multi cores
MAKEFLAGS += "-j$(NUM_CORES) -l$(NUM_CORES)

.PHONY: all build clean checkdirs test run

#======================================================================
# Enviroment
#======================================================================
MKDIR	:= @mkdir -p
RMDIR	:= @rm -rf	
RM		:= @rm -f
MV		:= @mf -f
#======================================================================

test:
	@echo	$(BUILD_PATH)
	@echo	$(LAYOUT_BUILD_BASE)
	@echo	$(LAYOUT_BUILD_PATH)
	@echo	$(LAYOUT_DIR)
	@echo	$(LAYOUT_OBJ)
	@echo	$(BUILD_PATH)
# 	@echo	$(EXTERNAL_BUILD_BASE)
	
