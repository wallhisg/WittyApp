# Build Flag
# BF_RESERVED	:=	0	BF_NOT_USE		:=	1
# BF_NOT_INC	:=	2	BF_NOT_BUILD	:=	3
# BF_BUILD		:=	4	BF_TEST			:=	5
BFLAG	:= $(BF_BUILD)
#----------------------------------------------------------------------------------
WIDGET_LOCAL_BASE		:= $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
WIDGET_LOCAL_MDL		:= $(sort $(dir $(wildcard $(WIDGET_LOCAL_BASE)*/)))
WIDGET_LOCAL_SUB_MDL	:= $(filter-out $(WIDGET_LOCAL_BASE), $(WIDGET_LOCAL_MDL))
LOCAL_BUILD_DIR		:=	$(subst $(WIDGET_PATH), $(BUILD_PATH), $(WIDGET_LOCAL_BASE))
#----------------------------------------------------------------------------------
# source
WIDGET_LOCAL_SRC_C		:= $(wildcard $(WIDGET_LOCAL_BASE)*.c)
WIDGET_LOCAL_SRC_CPP	:= $(wildcard $(WIDGET_LOCAL_BASE)*.cpp)
#----------------------------------------------------------------------------------
# dep
WIDGET_LOCAL_DEP_C		:= $(subst $(WIDGET_PATH), $(BUILD_PATH), $(patsubst %.c, %.deps, $(WIDGET_LOCAL_SRC_C)))
WIDGET_LOCAL_DEP_CPP	:= $(subst $(WIDGET_PATH), $(BUILD_PATH), $(patsubst %.cpp, %.deps, $(WIDGET_LOCAL_SRC_CPP)))

WIDGET_LOCAL_DEP 		+=	$(WIDGET_LOCAL_DEP_C)
WIDGET_LOCAL_DEP 		+=	$(WIDGET_LOCAL_DEP_CPP)
#----------------------------------------------------------------------------------
# object
WIDGET_LOCAL_OBJ_C		:= $(subst $(WIDGET_PATH), $(BUILD_PATH), $(patsubst %.c, %.o, $(WIDGET_LOCAL_SRC_C)))
WIDGET_LOCAL_OBJ_CPP	:= $(subst $(WIDGET_PATH), $(BUILD_PATH), $(patsubst %.cpp, %.o, $(WIDGET_LOCAL_SRC_CPP)))

WIDGET_LOCAL_OBJ 		+=	$(WIDGET_LOCAL_OBJ_C)
WIDGET_LOCAL_OBJ 		+=	$(WIDGET_LOCAL_OBJ_CPP)
#----------------------------------------------------------------------------------
include $(WIDGET_BASE)/Makefile.bas
#----------------------------------------------------------------------------------
ifneq ($(BF_NOT_USE), $(BFLAG))
SUBMAKEFILE	= $(foreach sdir, $(WIDGET_LOCAL_SUB_MDL), $(addprefix $(sdir), Makefile))
include $(SUBMAKEFILE)
endif