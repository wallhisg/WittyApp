
# ifeq ($(BFLAG),$(filter $(BFLAG),$(BF_BUILD) $(BF_NOT_BUILD)))
ifneq ($(BF_NOT_USE), $(BFLAG))
	# BF_NOT_INC
	ifeq ($(BF_NOT_INC), $(BFLAG))

	else ifeq ($(BF_NOT_BUILD), $(BFLAG))
		
	# BF_BUILD && BF_NOT_BUILD
	else ifeq ($(BF_BUILD), $(BFLAG))
		# add module path
		MDL_PATH	+= $(PRJ_LOCAL_MDL)
		MDL_PATH	:= $(sort $(MDL_PATH))
		# add include
		MLD_INC		+= $(addprefix -I,$(MDL_PATH))
		MLD_INC		:= $(sort $(MLD_INC))
		# dep
		PRJ_DEP		+=	$(PRJ_LOCAL_DEP)
		PRJ_DEP		:=	$(sort $(PRJ_DEP))
		# object
		PRJ_OBJ 	+=	$(PRJ_LOCAL_OBJ_C)
		PRJ_OBJ 	+=	$(PRJ_LOCAL_OBJ_CPP)
		PRJ_OBJ		:=	$(sort $(PRJ_OBJ))
		ifeq ($(BF_BUILD), $(BFLAG))
			PRJ_BUILD_DIR	+=	$(LOCAL_BUILD_DIR)
			PRJ_BUILD_DIR	:=	$(sort $(PRJ_BUILD_DIR))
		endif
	else ifeq ($(BF_TEST), $(BFLAG))
		# dep
		PRJ_DEP			+=	$(PRJ_LOCAL_DEP)
		PRJ_DEP			:=	$(sort $(PRJ_DEP))
		# build directory
		PRJ_BUILD_DIR	+=	$(LOCAL_BUILD_DIR)
		PRJ_BUILD_DIR	:=	$(sort $(PRJ_BUILD_DIR))
		# programs
		PROGRAMS		+=	$(PROGRAM)
		PROGRAMS		:=	$(sort $(PROGRAMS))
	endif
endif