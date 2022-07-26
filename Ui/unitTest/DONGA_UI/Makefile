# Build Flag
# BF_RESERVED	:=	0	BF_NOT_USE		:=	1
# BF_NOT_INC	:=	2	BF_NOT_BUILD	:=	3
# BF_BUILD		:=	4	BF_TEST			:=	5
BFLAG	:= $(BF_NOT_BUILD)
#----------------------------------------------------------------------------------
UI_LOCAL_BASE		:= $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
UI_LOCAL_MDL			:= $(sort $(dir $(wildcard $(UI_LOCAL_BASE)*/)))
UI_LOCAL_SUB_MDL		:= $(filter-out $(UI_LOCAL_BASE), $(UI_LOCAL_MDL))
LOCAL_BUILD_DIR					:= $(subst $(UI_PATH), $(BUILD_PATH), $(UI_LOCAL_BASE))
#----------------------------------------------------------------------------------
# source
UI_LOCAL_SRC_C		:= $(wildcard $(UI_LOCAL_BASE)*.c)
UI_LOCAL_SRC_CPP		:= $(wildcard $(UI_LOCAL_BASE)*.cpp)
#----------------------------------------------------------------------------------
# dep
UI_LOCAL_DEP_C		:= $(subst $(UI_PATH), $(BUILD_PATH), $(patsubst %.c, %.deps, $(UI_LOCAL_SRC_C)))
UI_LOCAL_DEP_CPP		:= $(subst $(UI_PATH), $(BUILD_PATH), $(patsubst %.cpp, %.deps, $(UI_LOCAL_SRC_CPP)))

UI_LOCAL_DEP 		+=	$(UI_LOCAL_DEP_C)
UI_LOCAL_DEP 		+=	$(UI_LOCAL_DEP_CPP)
#----------------------------------------------------------------------------------
# object
TABLE_UI_OBJ_C		:= $(subst $(UI_PATH), $(BUILD_PATH), $(patsubst %.c, %.o, $(UI_LOCAL_SRC_C)))
TABLE_UI_OBJ_CPP		:= $(subst $(UI_PATH), $(BUILD_PATH), $(patsubst %.cpp, %.o, $(UI_LOCAL_SRC_CPP)))

UI_TEST_OBJ			+=	$(TABLE_UI_OBJ_C)
UI_TEST_OBJ			+=	$(TABLE_UI_OBJ_CPP)
#----------------------------------------------------------------------------------
# target
TARGET		:= $(shell basename $(UI_LOCAL_BASE))
PROGRAM		:= $(addprefix $(UI_LOCAL_BASE), $(TARGET))
PROGRAM		:= $(subst $(UI_PATH), $(BUILD_PATH), $(PROGRAM))

$(PROGRAM): $(TABLE_UI_OBJ_C) $(TABLE_UI_OBJ_CPP) $(EXTERNAL_OBJ)
	$(CXX) $(UI_OBJ) $^ $(LIBS) -lstdc++ -o $@
#----------------------------------------------------------------------------------
include $(UI_BASE)/Makefile.bas