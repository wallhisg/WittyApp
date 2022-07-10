# Build Flag
# BF_RESERVED	:=	0	BF_NOT_USE		:=	1
# BF_NOT_INC	:=	2	BF_NOT_BUILD	:=	3
# BF_BUILD		:=	4	BF_TEST			:=	5
BFLAG	:= $(BF_BUILD)
#----------------------------------------------------------------------------------
DEVICE_LOCAL_BASE		:= $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
DEVICE_LOCAL_MDL		:= $(sort $(dir $(wildcard $(DEVICE_LOCAL_BASE)*/)))
DEVICE_LOCAL_SUB_MDL	:= $(filter-out $(DEVICE_LOCAL_BASE), $(DEVICE_LOCAL_MDL))
LOCAL_BUILD_DIR		:=	$(subst $(DEVICE_PATH), $(BUILD_PATH), $(DEVICE_LOCAL_BASE))
#----------------------------------------------------------------------------------
# source
DEVICE_LOCAL_SRC_C		:= $(wildcard $(DEVICE_LOCAL_BASE)*.c)
DEVICE_LOCAL_SRC_CPP	:= $(wildcard $(DEVICE_LOCAL_BASE)*.cpp)
#----------------------------------------------------------------------------------
# dep
DEVICE_LOCAL_DEP_C		:= $(subst $(DEVICE_PATH), $(BUILD_PATH), $(patsubst %.c, %.deps, $(DEVICE_LOCAL_SRC_C)))
DEVICE_LOCAL_DEP_CPP	:= $(subst $(DEVICE_PATH), $(BUILD_PATH), $(patsubst %.cpp, %.deps, $(DEVICE_LOCAL_SRC_CPP)))

DEVICE_LOCAL_DEP 		+=	$(DEVICE_LOCAL_DEP_C)
DEVICE_LOCAL_DEP 		+=	$(DEVICE_LOCAL_DEP_CPP)
#----------------------------------------------------------------------------------
# object
DEVICE_LOCAL_OBJ_C		:= $(subst $(DEVICE_PATH), $(BUILD_PATH), $(patsubst %.c, %.o, $(DEVICE_LOCAL_SRC_C)))
DEVICE_LOCAL_OBJ_CPP	:= $(subst $(DEVICE_PATH), $(BUILD_PATH), $(patsubst %.cpp, %.o, $(DEVICE_LOCAL_SRC_CPP)))

DEVICE_LOCAL_OBJ 		+=	$(DEVICE_LOCAL_OBJ_C)
DEVICE_LOCAL_OBJ 		+=	$(DEVICE_LOCAL_OBJ_CPP)
#----------------------------------------------------------------------------------
include $(DEVICE_BASE)/Makefile.bas
#----------------------------------------------------------------------------------
ifneq ($(BF_NOT_USE), $(BFLAG))
SUBMAKEFILE	= $(foreach sdir, $(DEVICE_LOCAL_SUB_MDL), $(addprefix $(sdir), Makefile))
include $(SUBMAKEFILE)
endif