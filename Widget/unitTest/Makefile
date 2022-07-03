# Build Flag
# BF_RESERVED	:=	0	BF_NOT_USE		:=	1
# BF_NOT_INC	:=	2	BF_NOT_BUILD	:=	3
# BF_BUILD		:=	4	BF_TEST			:=	5
BFLAG	:= $(BF_TEST)
#----------------------------------------------------------------------------------
WIDGET_LOCAL_BASE		:= $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
WIDGET_LOCAL_MDL		:= $(sort $(dir $(wildcard $(WIDGET_LOCAL_BASE)*/)))
WIDGET_LOCAL_SUB_MDL	:= $(filter-out $(WIDGET_LOCAL_BASE), $(WIDGET_LOCAL_MDL))
LOCAL_BUILD_DIR		:=	$(subst $(WIDGET_PATH), $(BUILD_PATH), $(WIDGET_LOCAL_BASE))
#----------------------------------------------------------------------------------
include $(WIDGET_BASE)/Makefile.bas
#----------------------------------------------------------------------------------
ifneq ($(BF_NOT_USE), $(BFLAG))
SUBMAKEFILE	= $(foreach sdir, $(WIDGET_LOCAL_SUB_MDL), $(addprefix $(sdir), Makefile))
include $(SUBMAKEFILE)
endif