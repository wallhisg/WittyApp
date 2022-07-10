
# ifeq ($(BFLAG),$(filter $(BFLAG),$(BF_BUILD) $(BF_NOT_BUILD)))
ifneq ($(BF_NOT_USE), $(BFLAG))
	# BF_NOT_INC
	ifeq ($(BF_NOT_INC), $(BFLAG))

	else ifeq ($(BF_NOT_BUILD), $(BFLAG))
		
	# BF_BUILD && BF_NOT_BUILD
	else ifeq ($(BF_BUILD), $(BFLAG))
		# add module path
		MDL_PATH	+= $(WIDGET_LOCAL_MDL)
		MDL_PATH	:= $(sort $(MDL_PATH))
		# add include
		MLD_INC		+= $(addprefix -I,$(MDL_PATH))
		MLD_INC		:= $(sort $(MLD_INC))
		# dep
		WIDGET_DEP		+=	$(WIDGET_LOCAL_DEP)
		WIDGET_DEP		:=	$(sort $(WIDGET_DEP))
		# object
		WIDGET_OBJ 	+=	$(WIDGET_LOCAL_OBJ_C)
		WIDGET_OBJ 	+=	$(WIDGET_LOCAL_OBJ_CPP)
		WIDGET_OBJ		:=	$(sort $(WIDGET_OBJ))
		ifeq ($(BF_BUILD), $(BFLAG))
			WIDGET_BUILD_DIR	+=	$(LOCAL_BUILD_DIR)
			WIDGET_BUILD_DIR	:=	$(sort $(WIDGET_BUILD_DIR))
		endif
	else ifeq ($(BF_TEST), $(BFLAG))
		# dep
		WIDGET_DEP			+=	$(WIDGET_LOCAL_DEP)
		WIDGET_DEP			:=	$(sort $(WIDGET_DEP))
		# build directory
		WIDGET_BUILD_DIR	+=	$(LOCAL_BUILD_DIR)
		WIDGET_BUILD_DIR	:=	$(sort $(WIDGET_BUILD_DIR))
		# programs
		PROGRAMS		+=	$(PROGRAM)
		PROGRAMS		:=	$(sort $(PROGRAMS))
	endif
endif