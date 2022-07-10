# Build Flag
# BF_RESERVED	:=	0	BF_NOT_USE		:=	1
# BF_NOT_INC	:=	2	BF_NOT_BUILD	:=	3
# BF_BUILD		:=	4	BF_TEST			:=	5
BFLAG	:= $(BF_BUILD)
#----------------------------------------------------------------------------------
APPLICATION_LOCAL_BASE		:= $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
APPLICATION_LOCAL_MDL		:= $(sort $(dir $(wildcard $(APPLICATION_LOCAL_BASE)*/)))
APPLICATION_LOCAL_SUB_MDL	:= $(filter-out $(APPLICATION_LOCAL_BASE), $(APPLICATION_LOCAL_MDL))
LOCAL_BUILD_DIR		:=	$(subst $(APPLICATION_PATH), $(BUILD_PATH), $(APPLICATION_LOCAL_BASE))
#----------------------------------------------------------------------------------
# source
APPLICATION_LOCAL_SRC_C		:= $(wildcard $(APPLICATION_LOCAL_BASE)*.c)
APPLICATION_LOCAL_SRC_CPP	:= $(wildcard $(APPLICATION_LOCAL_BASE)*.cpp)
#----------------------------------------------------------------------------------
# dep
APPLICATION_LOCAL_DEP_C		:= $(subst $(APPLICATION_PATH), $(BUILD_PATH), $(patsubst %.c, %.deps, $(APPLICATION_LOCAL_SRC_C)))
APPLICATION_LOCAL_DEP_CPP	:= $(subst $(APPLICATION_PATH), $(BUILD_PATH), $(patsubst %.cpp, %.deps, $(APPLICATION_LOCAL_SRC_CPP)))

APPLICATION_LOCAL_DEP 		+=	$(APPLICATION_LOCAL_DEP_C)
APPLICATION_LOCAL_DEP 		+=	$(APPLICATION_LOCAL_DEP_CPP)
#----------------------------------------------------------------------------------
# object
APPLICATION_LOCAL_OBJ_C		:= $(subst $(APPLICATION_PATH), $(BUILD_PATH), $(patsubst %.c, %.o, $(APPLICATION_LOCAL_SRC_C)))
APPLICATION_LOCAL_OBJ_CPP	:= $(subst $(APPLICATION_PATH), $(BUILD_PATH), $(patsubst %.cpp, %.o, $(APPLICATION_LOCAL_SRC_CPP)))

APPLICATION_LOCAL_OBJ 		+=	$(APPLICATION_LOCAL_OBJ_C)
APPLICATION_LOCAL_OBJ 		+=	$(APPLICATION_LOCAL_OBJ_CPP)
#----------------------------------------------------------------------------------
include $(APPLICATION_BASE)/Makefile.bas
#----------------------------------------------------------------------------------
ifneq ($(BF_NOT_USE), $(BFLAG))
SUBMAKEFILE	= $(foreach sdir, $(APPLICATION_LOCAL_SUB_MDL), $(addprefix $(sdir), Makefile))
include $(SUBMAKEFILE)
endif