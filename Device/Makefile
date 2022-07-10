export ROOT_BASE		?=	$(abspath $(dir $(abspath $(dir $$PWD))))
export DEVICE_BASE		?=	$(abspath $(dir $$PWD))
export DEVICE_PATH		?=	$(dir $(realpath $(firstword $(MAKEFILE_LIST))))

export DEVICE_SRC_C		:=
export DEVICE_OBJ_C		:=
export DEVICE_DEP_C		:=

export DEVICE_SRC_CPP	:=
export DEVICE_OBJ_CPP	:=
export DEVICE_DEP_CPP	:=

export DEVICE_OBJ		:=
export DEVICE_DEPS		:=

export DEVICE_LIB		:=
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
export BUILD_BASE		=	$(DEVICE_BASE)/$(BUILD)
export BUILD_PATH		=	$(DEVICE_BASE)/$(BUILD)/
export BUILD_DIR		=	$(subst $(DEVICE_PATH),$(BUILD_PATH), $(MDL_PATH))
export BUILD_TEST_DIR	=

# define build flag BFLAG
export	BF_RESERVED		:=	0
export	BF_NOT_USE		:=	1
export	BF_NOT_INC		:=	2
export	BF_NOT_BUILD	:=	3
export	BF_BUILD		:=	4
export	BF_TEST			:=	5

export	RESOURCES_DIR	:=	

include $(DEVICE_BASE)/Makefile.inc
include $(DEVICE_BASE)/Makefile.bas
include $(DEVICE_BASE)/Makefile.env

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
	@echo	$(APPLICATION_BASE)
	@echo	$(APPLICATION_BUILD)
	@echo	$(APPLICATION_BUILD_BASE)
# 	@echo	$(DEVICE_BASE)
# 	@echo	$(EXTERNAL_BUILD_DIR)

