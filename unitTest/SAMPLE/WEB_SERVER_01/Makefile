# Build Flag
# BF_RESERVED	:=	0	BF_NOT_USE		:=	1
# BF_NOT_INC	:=	2	BF_NOT_BUILD	:=	3
# BF_BUILD		:=	4	BF_TEST			:=	5
BFLAG	:= $(BF_TEST)
#----------------------------------------------------------------------------------
PRJ_LOCAL_BASE		:= $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
PRJ_LOCAL_MDL		:= $(sort $(dir $(wildcard $(PRJ_LOCAL_BASE)*/)))
PRJ_LOCAL_SUB_MDL	:= $(filter-out $(PRJ_LOCAL_BASE), $(PRJ_LOCAL_MDL))
LOCAL_BUILD_DIR		:=	$(subst $(PRJ_PATH), $(BUILD_PATH), $(PRJ_LOCAL_BASE))
#----------------------------------------------------------------------------------
# source
PRJ_LOCAL_SRC_C		:= $(wildcard $(PRJ_LOCAL_BASE)*.c)
PRJ_LOCAL_SRC_CPP	:= $(wildcard $(PRJ_LOCAL_BASE)*.cpp)
#----------------------------------------------------------------------------------
# dep
PRJ_LOCAL_DEP_C		:= $(subst $(PRJ_PATH), $(BUILD_PATH), $(patsubst %.c, %.deps, $(PRJ_LOCAL_SRC_C)))
PRJ_LOCAL_DEP_CPP	:= $(subst $(PRJ_PATH), $(BUILD_PATH), $(patsubst %.cpp, %.deps, $(PRJ_LOCAL_SRC_CPP)))

PRJ_LOCAL_DEP 		+=	$(PRJ_LOCAL_DEP_C)
PRJ_LOCAL_DEP 		+=	$(PRJ_LOCAL_DEP_CPP)
#----------------------------------------------------------------------------------
# object
PRJ_SAMPLE_01_OBJ_C		:= $(subst $(PRJ_PATH), $(BUILD_PATH), $(patsubst %.c, %.o, $(PRJ_LOCAL_SRC_C)))
PRJ_SAMPLE_01_OBJ_CPP	:= $(subst $(PRJ_PATH), $(BUILD_PATH), $(patsubst %.cpp, %.o, $(PRJ_LOCAL_SRC_CPP)))

PRJ_TEST_OBJ		+=	$(PRJ_SAMPLE_01_OBJ_C)
PRJ_TEST_OBJ		+=	$(PRJ_SAMPLE_01_OBJ_CPP)

#----------------------------------------------------------------------------------
# target
TARGET		:= $(shell basename $(PRJ_LOCAL_BASE))
PROGRAM		:= $(addprefix $(PRJ_LOCAL_BASE), $(TARGET))
PROGRAM		:= $(subst $(PRJ_PATH), $(BUILD_PATH), $(PROGRAM))

$(PROGRAM): $(PRJ_SAMPLE_01_OBJ_C) $(PRJ_SAMPLE_01_OBJ_CPP)
	$(CXX) $(PRJ_OBJ) $^ $(LIBS) -lstdc++ -o $@
#----------------------------------------------------------------------------------
include $(PRJ_BASE)/Makefile.bas
