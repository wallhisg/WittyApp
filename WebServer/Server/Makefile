# Build Flag
# BF_RESERVED	:=	0	BF_NOT_USE		:=	1
# BF_NOT_INC	:=	2	BF_NOT_BUILD	:=	3
# BF_BUILD		:=	4	BF_TEST			:=	5
BFLAG	:= $(BF_BUILD)
#----------------------------------------------------------------------------------
WEB_SERVER_LOCAL_BASE		:= $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
WEB_SERVER_LOCAL_MDL		:= $(sort $(dir $(wildcard $(WEB_SERVER_LOCAL_BASE)*/)))
WEB_SERVER_LOCAL_SUB_MDL	:= $(filter-out $(WEB_SERVER_LOCAL_BASE), $(WEB_SERVER_LOCAL_MDL))
LOCAL_BUILD_DIR		:=	$(subst $(WEB_SERVER_PATH), $(BUILD_PATH), $(WEB_SERVER_LOCAL_BASE))
#----------------------------------------------------------------------------------
# source
WEB_SERVER_LOCAL_SRC_C		:= $(wildcard $(WEB_SERVER_LOCAL_BASE)*.c)
WEB_SERVER_LOCAL_SRC_CPP	:= $(wildcard $(WEB_SERVER_LOCAL_BASE)*.cpp)
#----------------------------------------------------------------------------------
# dep
WEB_SERVER_LOCAL_DEP_C		:= $(subst $(WEB_SERVER_PATH), $(BUILD_PATH), $(patsubst %.c, %.deps, $(WEB_SERVER_LOCAL_SRC_C)))
WEB_SERVER_LOCAL_DEP_CPP	:= $(subst $(WEB_SERVER_PATH), $(BUILD_PATH), $(patsubst %.cpp, %.deps, $(WEB_SERVER_LOCAL_SRC_CPP)))

WEB_SERVER_LOCAL_DEP 		+=	$(WEB_SERVER_LOCAL_DEP_C)
WEB_SERVER_LOCAL_DEP 		+=	$(WEB_SERVER_LOCAL_DEP_CPP)
#----------------------------------------------------------------------------------
# object
WEB_SERVER_LOCAL_OBJ_C		:= $(subst $(WEB_SERVER_PATH), $(BUILD_PATH), $(patsubst %.c, %.o, $(WEB_SERVER_LOCAL_SRC_C)))
WEB_SERVER_LOCAL_OBJ_CPP	:= $(subst $(WEB_SERVER_PATH), $(BUILD_PATH), $(patsubst %.cpp, %.o, $(WEB_SERVER_LOCAL_SRC_CPP)))

WEB_SERVER_LOCAL_OBJ 		+=	$(WEB_SERVER_LOCAL_OBJ_C)
WEB_SERVER_LOCAL_OBJ 		+=	$(WEB_SERVER_LOCAL_OBJ_CPP)
#----------------------------------------------------------------------------------
include $(WEB_SERVER_BASE)/Makefile.bas
#----------------------------------------------------------------------------------
ifneq ($(BF_NOT_USE), $(BFLAG))
SUBMAKEFILE	= $(foreach sdir, $(WEB_SERVER_LOCAL_SUB_MDL), $(addprefix $(sdir), Makefile))
include $(SUBMAKEFILE)
endif