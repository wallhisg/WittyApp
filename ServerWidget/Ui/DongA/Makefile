# Build Flag
# BF_RESERVED	:=	0	BF_NOT_USE		:=	1
# BF_NOT_INC	:=	2	BF_NOT_BUILD	:=	3
# BF_BUILD		:=	4	BF_TEST			:=	5
BFLAG	:= $(BF_BUILD)
#----------------------------------------------------------------------------------
SERVER_WIDGET_LOCAL_BASE		:= $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
SERVER_WIDGET_LOCAL_MDL			:= $(sort $(dir $(wildcard $(SERVER_WIDGET_LOCAL_BASE)*/)))
SERVER_WIDGET_LOCAL_SUB_MDL		:= $(filter-out $(SERVER_WIDGET_LOCAL_BASE), $(SERVER_WIDGET_LOCAL_MDL))
LOCAL_BUILD_DIR		:=	$(subst $(SERVER_WIDGET_PATH), $(BUILD_PATH), $(SERVER_WIDGET_LOCAL_BASE))
#----------------------------------------------------------------------------------
# source
SERVER_WIDGET_LOCAL_SRC_C		:= $(wildcard $(SERVER_WIDGET_LOCAL_BASE)*.c)
SERVER_WIDGET_LOCAL_SRC_CPP		:= $(wildcard $(SERVER_WIDGET_LOCAL_BASE)*.cpp)
#----------------------------------------------------------------------------------
# dep
SERVER_WIDGET_LOCAL_DEP_C		:= $(subst $(SERVER_WIDGET_PATH), $(BUILD_PATH), $(patsubst %.c, %.deps, $(SERVER_WIDGET_LOCAL_SRC_C)))
SERVER_WIDGET_LOCAL_DEP_CPP		:= $(subst $(SERVER_WIDGET_PATH), $(BUILD_PATH), $(patsubst %.cpp, %.deps, $(SERVER_WIDGET_LOCAL_SRC_CPP)))

SERVER_WIDGET_LOCAL_DEP 		+=	$(SERVER_WIDGET_LOCAL_DEP_C)
SERVER_WIDGET_LOCAL_DEP 		+=	$(SERVER_WIDGET_LOCAL_DEP_CPP)
#----------------------------------------------------------------------------------
# object
SERVER_WIDGET_LOCAL_OBJ_C		:= $(subst $(SERVER_WIDGET_PATH), $(BUILD_PATH), $(patsubst %.c, %.o, $(SERVER_WIDGET_LOCAL_SRC_C)))
SERVER_WIDGET_LOCAL_OBJ_CPP		:= $(subst $(SERVER_WIDGET_PATH), $(BUILD_PATH), $(patsubst %.cpp, %.o, $(SERVER_WIDGET_LOCAL_SRC_CPP)))

SERVER_WIDGET_LOCAL_OBJ 		+=	$(SERVER_WIDGET_LOCAL_OBJ_C)
SERVER_WIDGET_LOCAL_OBJ 		+=	$(SERVER_WIDGET_LOCAL_OBJ_CPP)
#----------------------------------------------------------------------------------
include $(SERVER_WIDGET_BASE)/Makefile.bas
#----------------------------------------------------------------------------------
ifneq ($(BF_NOT_USE), $(BFLAG))
SUBMAKEFILE	= $(foreach sdir, $(SERVER_WIDGET_LOCAL_SUB_MDL), $(addprefix $(sdir), Makefile))
include $(SUBMAKEFILE)
endif