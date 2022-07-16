# Build Flag
# BF_RESERVED	:=	0	BF_NOT_USE		:=	1
# BF_NOT_INC	:=	2	BF_NOT_BUILD	:=	3
# BF_BUILD		:=	4	BF_TEST			:=	5
BFLAG	:= $(BF_TEST)
#----------------------------------------------------------------------------------
UI_LOCAL_BASE		:= $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
UI_LOCAL_MDL		:= $(sort $(dir $(wildcard $(UI_LOCAL_BASE)*/)))
UI_LOCAL_SUB_MDL	:= $(filter-out $(UI_LOCAL_BASE), $(UI_LOCAL_MDL))
LOCAL_BUILD_DIR		:=	$(subst $(UI_PATH), $(BUILD_PATH), $(UI_LOCAL_BASE))
#----------------------------------------------------------------------------------
include $(UI_BASE)/Makefile.bas
#----------------------------------------------------------------------------------
ifneq ($(BF_NOT_USE), $(BFLAG))
SUBMAKEFILE	= $(foreach sdir, $(UI_LOCAL_SUB_MDL), $(addprefix $(sdir), Makefile))
include $(SUBMAKEFILE)
endif