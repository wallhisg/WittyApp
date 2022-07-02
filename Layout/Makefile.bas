
# ifeq ($(BFLAG),$(filter $(BFLAG),$(BF_BUILD) $(BF_NOT_BUILD)))
ifneq ($(BF_NOT_USE), $(BFLAG))
	# BF_NOT_INC
	ifeq ($(BF_NOT_INC), $(BFLAG))

	else ifeq ($(BF_NOT_BUILD), $(BFLAG))
		
	# BF_BUILD && BF_NOT_BUILD
	else ifeq ($(BF_BUILD), $(BFLAG))
		# add module path
		MDL_PATH	+= $(LAYOUT_LOCAL_MDL)
		MDL_PATH	:= $(sort $(MDL_PATH))
		# add include
		MLD_INC		+= $(addprefix -I,$(MDL_PATH))
		MLD_INC		:= $(sort $(MLD_INC))
		# dep
		LAYOUT_DEP		+=	$(LAYOUT_LOCAL_DEP)
		LAYOUT_DEP		:=	$(sort $(LAYOUT_DEP))
		# object
		LAYOUT_OBJ 	+=	$(LAYOUT_LOCAL_OBJ_C)
		LAYOUT_OBJ 	+=	$(LAYOUT_LOCAL_OBJ_CPP)
		LAYOUT_OBJ		:=	$(sort $(LAYOUT_OBJ))
		ifeq ($(BF_BUILD), $(BFLAG))
			LAYOUT_BUILD_DIR	+=	$(LOCAL_BUILD_DIR)
			LAYOUT_BUILD_DIR	:=	$(sort $(LAYOUT_BUILD_DIR))
		endif
	else ifeq ($(BF_TEST), $(BFLAG))
		# dep
		LAYOUT_DEP			+=	$(LAYOUT_LOCAL_DEP)
		LAYOUT_DEP			:=	$(sort $(LAYOUT_DEP))
		# build directory
		LAYOUT_BUILD_DIR	+=	$(LOCAL_BUILD_DIR)
		LAYOUT_BUILD_DIR	:=	$(sort $(LAYOUT_BUILD_DIR))
		# programs
		PROGRAMS		+=	$(PROGRAM)
		PROGRAMS		:=	$(sort $(PROGRAMS))
	endif
endif