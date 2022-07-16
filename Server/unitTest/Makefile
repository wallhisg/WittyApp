# Build Flag
# BF_RESERVED	:=	0	BF_NOT_USE		:=	1
# BF_NOT_INC	:=	2	BF_NOT_BUILD	:=	3
# BF_BUILD		:=	4	BF_TEST			:=	5
BFLAG	:= $(BF_TEST)
#----------------------------------------------------------------------------------
WEB_SERVER_LOCAL_BASE		:= $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
WEB_SERVER_LOCAL_MDL		:= $(sort $(dir $(wildcard $(WEB_SERVER_LOCAL_BASE)*/)))
WEB_SERVER_LOCAL_SUB_MDL	:= $(filter-out $(WEB_SERVER_LOCAL_BASE), $(WEB_SERVER_LOCAL_MDL))
LOCAL_BUILD_DIR		:=	$(subst $(WEB_SERVER_PATH), $(BUILD_PATH), $(WEB_SERVER_LOCAL_BASE))
#----------------------------------------------------------------------------------
include $(WEB_SERVER_BASE)/Makefile.bas
#----------------------------------------------------------------------------------
ifneq ($(BF_NOT_USE), $(BFLAG))
SUBMAKEFILE	= $(foreach sdir, $(WEB_SERVER_LOCAL_SUB_MDL), $(addprefix $(sdir), Makefile))
include $(SUBMAKEFILE)
endif