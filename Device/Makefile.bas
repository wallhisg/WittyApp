
# ifeq ($(BFLAG),$(filter $(BFLAG),$(BF_BUILD) $(BF_NOT_BUILD)))
ifneq ($(BF_NOT_USE), $(BFLAG))
	# BF_NOT_INC
	ifeq ($(BF_NOT_INC), $(BFLAG))

	else ifeq ($(BF_NOT_BUILD), $(BFLAG))
		
	# BF_BUILD && BF_NOT_BUILD
	else ifeq ($(BF_BUILD), $(BFLAG))
		# add module path
		MDL_PATH	+= $(DEVICE_LOCAL_MDL)
		MDL_PATH	:= $(sort $(MDL_PATH))
		# add include
		MLD_INC		+= $(addprefix -I,$(MDL_PATH))
		MLD_INC		:= $(sort $(MLD_INC))
		# dep
		DEVICE_DEP		+=	$(DEVICE_LOCAL_DEP)
		DEVICE_DEP		:=	$(sort $(DEVICE_DEP))
		# object
		DEVICE_OBJ 	+=	$(DEVICE_LOCAL_OBJ_C)
		DEVICE_OBJ 	+=	$(DEVICE_LOCAL_OBJ_CPP)
		DEVICE_OBJ		:=	$(sort $(DEVICE_OBJ))
		ifeq ($(BF_BUILD), $(BFLAG))
			DEVICE_BUILD_DIR	+=	$(LOCAL_BUILD_DIR)
			DEVICE_BUILD_DIR	:=	$(sort $(DEVICE_BUILD_DIR))
		endif
	else ifeq ($(BF_TEST), $(BFLAG))
		# dep
		DEVICE_DEP			+=	$(DEVICE_LOCAL_DEP)
		DEVICE_DEP			:=	$(sort $(DEVICE_DEP))
		# build directory
		DEVICE_BUILD_DIR	+=	$(LOCAL_BUILD_DIR)
		DEVICE_BUILD_DIR	:=	$(sort $(DEVICE_BUILD_DIR))
		# programs
		PROGRAMS		+=	$(PROGRAM)
		PROGRAMS		:=	$(sort $(PROGRAMS))
	endif
endif