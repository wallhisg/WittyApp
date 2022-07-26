# Build Flag
# BF_RESERVED	:=	0	BF_NOT_USE		:=	1
# BF_NOT_INC	:=	2	BF_NOT_BUILD	:=	3
# BF_BUILD		:=	4	BF_TEST			:=	5
BFLAG	:= $(BF_NOT_BUILD)
#----------------------------------------------------------------------------------
LAYOUT_LOCAL_BASE		:= $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
LAYOUT_LOCAL_MDL		:= $(sort $(dir $(wildcard $(LAYOUT_LOCAL_BASE)*/)))
LAYOUT_LOCAL_SUB_MDL	:= $(filter-out $(LAYOUT_LOCAL_BASE), $(LAYOUT_LOCAL_MDL))
LOCAL_BUILD_DIR			:= $(subst $(LAYOUT_PATH), $(BUILD_PATH), $(LAYOUT_LOCAL_BASE))
#----------------------------------------------------------------------------------
# source
LAYOUT_LOCAL_SRC_C		:= $(wildcard $(LAYOUT_LOCAL_BASE)*.c)
LAYOUT_LOCAL_SRC_CPP	:= $(wildcard $(LAYOUT_LOCAL_BASE)*.cpp)
#----------------------------------------------------------------------------------
# dep
LAYOUT_LOCAL_DEP_C		:= $(subst $(LAYOUT_PATH), $(BUILD_PATH), $(patsubst %.c, %.deps, $(LAYOUT_LOCAL_SRC_C)))
LAYOUT_LOCAL_DEP_CPP	:= $(subst $(LAYOUT_PATH), $(BUILD_PATH), $(patsubst %.cpp, %.deps, $(LAYOUT_LOCAL_SRC_CPP)))

LAYOUT_LOCAL_DEP 		+=	$(LAYOUT_LOCAL_DEP_C)
LAYOUT_LOCAL_DEP 		+=	$(LAYOUT_LOCAL_DEP_CPP)
#----------------------------------------------------------------------------------
# object
MAIN_LAYOUT_OBJ_C		:= $(subst $(LAYOUT_PATH), $(BUILD_PATH), $(patsubst %.c, %.o, $(LAYOUT_LOCAL_SRC_C)))
MAIN_LAYOUT_OBJ_CPP	:= $(subst $(LAYOUT_PATH), $(BUILD_PATH), $(patsubst %.cpp, %.o, $(LAYOUT_LOCAL_SRC_CPP)))

LAYOUT_TEST_OBJ		+=	$(MAIN_LAYOUT_OBJ_C)
LAYOUT_TEST_OBJ		+=	$(MAIN_LAYOUT_OBJ_CPP)
#----------------------------------------------------------------------------------
# target
TARGET		:= $(shell basename $(LAYOUT_LOCAL_BASE))
PROGRAM		:= $(addprefix $(LAYOUT_LOCAL_BASE), $(TARGET))
PROGRAM		:= $(subst $(LAYOUT_PATH), $(BUILD_PATH), $(PROGRAM))

$(PROGRAM): $(MAIN_LAYOUT_OBJ_C) $(MAIN_LAYOUT_OBJ_CPP) $(EXTERNAL_OBJ)
	$(CXX) $(LAYOUT_OBJ) $(EXTERNAL_OBJ) $^ $(LIBS) -lstdc++ -o $@
#----------------------------------------------------------------------------------
include $(LAYOUT_BASE)/Makefile.bas