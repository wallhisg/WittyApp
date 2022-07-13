# Build Flag
# BF_RESERVED	:=	0	BF_NOT_USE		:=	1
# BF_NOT_INC	:=	2	BF_NOT_BUILD	:=	3
# BF_BUILD		:=	4	BF_TEST			:=	5
BFLAG	:= $(BF_TEST)
#----------------------------------------------------------------------------------
SERVER_WIDGET_LOCAL_BASE		:= $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
SERVER_WIDGET_LOCAL_MDL		:= $(sort $(dir $(wildcard $(SERVER_WIDGET_LOCAL_BASE)*/)))
SERVER_WIDGET_LOCAL_SUB_MDL	:= $(filter-out $(SERVER_WIDGET_LOCAL_BASE), $(SERVER_WIDGET_LOCAL_MDL))
LOCAL_BUILD_DIR		:=	$(subst $(SERVER_WIDGET_PATH), $(BUILD_PATH), $(SERVER_WIDGET_LOCAL_BASE))
#----------------------------------------------------------------------------------
include $(SERVER_WIDGET_BASE)/Makefile.bas
#----------------------------------------------------------------------------------
ifneq ($(BF_NOT_USE), $(BFLAG))
SUBMAKEFILE	= $(foreach sdir, $(SERVER_WIDGET_LOCAL_SUB_MDL), $(addprefix $(sdir), Makefile))
include $(SUBMAKEFILE)
endif