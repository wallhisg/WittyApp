# Build Flag
# BF_RESERVED	:=	0	BF_NOT_USE		:=	1
# BF_NOT_INC	:=	2	BF_NOT_BUILD	:=	3
# BF_BUILD		:=	4	BF_TEST			:=	5
BFLAG	:= $(BF_NOT_USE)
#----------------------------------------------------------------------------------
LAYOUT_LOCAL_BASE		:= $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
LAYOUT_LOCAL_MDL		:= $(sort $(dir $(wildcard $(LAYOUT_LOCAL_BASE)*/)))
LAYOUT_LOCAL_SUB_MDL	:= $(filter-out $(LAYOUT_LOCAL_BASE), $(LAYOUT_LOCAL_MDL))
LOCAL_BUILD_DIR			:=	$(subst $(LAYOUT_PATH), $(BUILD_PATH), $(LAYOUT_LOCAL_BASE))
#----------------------------------------------------------------------------------
include $(LAYOUT_BASE)/Makefile.bas
#----------------------------------------------------------------------------------
ifneq ($(BF_NOT_USE), $(BFLAG))
SUBMAKEFILE	= $(foreach sdir, $(LAYOUT_LOCAL_SUB_MDL), $(addprefix $(sdir), Makefile))
include $(SUBMAKEFILE)
endif