
# ifeq ($(BFLAG),$(filter $(BFLAG),$(BF_BUILD) $(BF_NOT_BUILD)))
ifneq ($(BF_NOT_USE), $(BFLAG))
	# BF_NOT_INC
	ifeq ($(BF_NOT_INC), $(BFLAG))

	else ifeq ($(BF_NOT_BUILD), $(BFLAG))
		
	# BF_BUILD && BF_NOT_BUILD
	else ifeq ($(BF_BUILD), $(BFLAG))
		# add module path
		MDL_PATH	+= $(APPLICATION_LOCAL_MDL)
		MDL_PATH	:= $(sort $(MDL_PATH))
		# add include
		MLD_INC		+= $(addprefix -I,$(MDL_PATH))
		MLD_INC		:= $(sort $(MLD_INC))
		# dep
		APPLICATION_DEP		+=	$(APPLICATION_LOCAL_DEP)
		APPLICATION_DEP		:=	$(sort $(APPLICATION_DEP))
		# object
		APPLICATION_OBJ 	+=	$(APPLICATION_LOCAL_OBJ_C)
		APPLICATION_OBJ 	+=	$(APPLICATION_LOCAL_OBJ_CPP)
		APPLICATION_OBJ		:=	$(sort $(APPLICATION_OBJ))
		ifeq ($(BF_BUILD), $(BFLAG))
			APPLICATION_BUILD_DIR	+=	$(LOCAL_BUILD_DIR)
			APPLICATION_BUILD_DIR	:=	$(sort $(APPLICATION_BUILD_DIR))
		endif
	else ifeq ($(BF_TEST), $(BFLAG))
		# dep
		APPLICATION_DEP			+=	$(APPLICATION_LOCAL_DEP)
		APPLICATION_DEP			:=	$(sort $(APPLICATION_DEP))
		# build directory
		APPLICATION_BUILD_DIR	+=	$(LOCAL_BUILD_DIR)
		APPLICATION_BUILD_DIR	:=	$(sort $(APPLICATION_BUILD_DIR))
		# programs
		PROGRAMS		+=	$(PROGRAM)
		PROGRAMS		:=	$(sort $(PROGRAMS))
	endif
endif