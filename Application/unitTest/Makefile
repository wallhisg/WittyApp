# Build Flag
# BF_RESERVED	:=	0	BF_NOT_USE		:=	1
# BF_NOT_INC	:=	2	BF_NOT_BUILD	:=	3
# BF_BUILD		:=	4	BF_TEST			:=	5
BFLAG	:= $(BF_TEST)
#----------------------------------------------------------------------------------
APPLICATION_LOCAL_BASE		:= $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
APPLICATION_LOCAL_MDL		:= $(sort $(dir $(wildcard $(APPLICATION_LOCAL_BASE)*/)))
APPLICATION_LOCAL_SUB_MDL	:= $(filter-out $(APPLICATION_LOCAL_BASE), $(APPLICATION_LOCAL_MDL))
LOCAL_BUILD_DIR		:=	$(subst $(APPLICATION_PATH), $(BUILD_PATH), $(APPLICATION_LOCAL_BASE))
#----------------------------------------------------------------------------------
include $(APPLICATION_BASE)/Makefile.bas
#----------------------------------------------------------------------------------
ifneq ($(BF_NOT_USE), $(BFLAG))
SUBMAKEFILE	= $(foreach sdir, $(APPLICATION_LOCAL_SUB_MDL), $(addprefix $(sdir), Makefile))
include $(SUBMAKEFILE)
endif