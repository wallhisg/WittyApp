export ROOT_BASE			?=	$(abspath $(dir $(abspath $(dir $$PWD))))
export WEB_SERVER_BASE		?=	$(abspath $(dir $$PWD))
export WEB_SERVER_PATH		?=	$(dir $(realpath $(firstword $(MAKEFILE_LIST))))

export WEB_SERVER_SRC_C		:=
export WEB_SERVER_OBJ_C		:=
export WEB_SERVER_DEP_C		:=

export WEB_SERVER_SRC_CPP	:=
export WEB_SERVER_OBJ_CPP	:=
export WEB_SERVER_DEP_CPP	:=

export WEB_SERVER_OBJ		:=
export WEB_SERVER_DEPS		:=

export WEB_SERVER_LIB		:=
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
export BUILD_BASE		=	$(WEB_SERVER_BASE)/$(BUILD)
export BUILD_PATH		=	$(WEB_SERVER_BASE)/$(BUILD)/
export BUILD_DIR		=	$(subst $(WEB_SERVER_PATH),$(BUILD_PATH), $(MDL_PATH))
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

include $(WEB_SERVER_BASE)/Makefiles/Makefile
include $(WEB_SERVER_BASE)/Makefile.inc
include $(WEB_SERVER_BASE)/Makefile.bas
include $(WEB_SERVER_BASE)/Makefile.env

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
	@echo	$(EXTERNAL_BUILD_DIR)
	@echo	$(EXTERNAL_BUILD_BASE)
	@echo	$(EXTERNAL_BASE)