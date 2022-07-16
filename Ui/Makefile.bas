
# ifeq ($(BFLAG),$(filter $(BFLAG),$(BF_BUILD) $(BF_NOT_BUILD)))
ifneq ($(BF_NOT_USE), $(BFLAG))
	# BF_NOT_INC
	ifeq ($(BF_NOT_INC), $(BFLAG))

	else ifeq ($(BF_NOT_BUILD), $(BFLAG))
		
	# BF_BUILD && BF_NOT_BUILD
	else ifeq ($(BF_BUILD), $(BFLAG))
		# add module path
		MDL_PATH	+= $(UI_LOCAL_MDL)
		MDL_PATH	:= $(sort $(MDL_PATH))
		# add include
		MLD_INC		+= $(addprefix -I,$(MDL_PATH))
		MLD_INC		:= $(sort $(MLD_INC))
		# dep
		UI_DEP		+=	$(UI_LOCAL_DEP)
		UI_DEP		:=	$(sort $(UI_DEP))
		# object
		UI_OBJ 	+=	$(UI_LOCAL_OBJ_C)
		UI_OBJ 	+=	$(UI_LOCAL_OBJ_CPP)
		UI_OBJ		:=	$(sort $(UI_OBJ))
		ifeq ($(BF_BUILD), $(BFLAG))
			UI_BUILD_DIR	+=	$(LOCAL_BUILD_DIR)
			UI_BUILD_DIR	:=	$(sort $(UI_BUILD_DIR))
		endif
	else ifeq ($(BF_TEST), $(BFLAG))
		# dep
		UI_DEP			+=	$(UI_LOCAL_DEP)
		UI_DEP			:=	$(sort $(UI_DEP))
		# build directory
		UI_BUILD_DIR	+=	$(LOCAL_BUILD_DIR)
		UI_BUILD_DIR	:=	$(sort $(UI_BUILD_DIR))
		# programs
		PROGRAMS		+=	$(PROGRAM)
		PROGRAMS		:=	$(sort $(PROGRAMS))
	endif
endif