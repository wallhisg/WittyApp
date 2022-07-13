
# ifeq ($(BFLAG),$(filter $(BFLAG),$(BF_BUILD) $(BF_NOT_BUILD)))
ifneq ($(BF_NOT_USE), $(BFLAG))
	# BF_NOT_INC
	ifeq ($(BF_NOT_INC), $(BFLAG))

	else ifeq ($(BF_NOT_BUILD), $(BFLAG))
		
	# BF_BUILD && BF_NOT_BUILD
	else ifeq ($(BF_BUILD), $(BFLAG))
		# add module path
		MDL_PATH	+= $(SERVER_WIDGET_LOCAL_MDL)
		MDL_PATH	:= $(sort $(MDL_PATH))
		# add include
		MLD_INC		+= $(addprefix -I,$(MDL_PATH))
		MLD_INC		:= $(sort $(MLD_INC))
		# dep
		SERVER_WIDGET_DEP		+=	$(SERVER_WIDGET_LOCAL_DEP)
		SERVER_WIDGET_DEP		:=	$(sort $(SERVER_WIDGET_DEP))
		# object
		SERVER_WIDGET_OBJ 	+=	$(SERVER_WIDGET_LOCAL_OBJ_C)
		SERVER_WIDGET_OBJ 	+=	$(SERVER_WIDGET_LOCAL_OBJ_CPP)
		SERVER_WIDGET_OBJ		:=	$(sort $(SERVER_WIDGET_OBJ))
		ifeq ($(BF_BUILD), $(BFLAG))
			SERVER_WIDGET_BUILD_DIR	+=	$(LOCAL_BUILD_DIR)
			SERVER_WIDGET_BUILD_DIR	:=	$(sort $(SERVER_WIDGET_BUILD_DIR))
		endif
	else ifeq ($(BF_TEST), $(BFLAG))
		# dep
		SERVER_WIDGET_DEP			+=	$(SERVER_WIDGET_LOCAL_DEP)
		SERVER_WIDGET_DEP			:=	$(sort $(SERVER_WIDGET_DEP))
		# build directory
		SERVER_WIDGET_BUILD_DIR	+=	$(LOCAL_BUILD_DIR)
		SERVER_WIDGET_BUILD_DIR	:=	$(sort $(SERVER_WIDGET_BUILD_DIR))
		# programs
		PROGRAMS		+=	$(PROGRAM)
		PROGRAMS		:=	$(sort $(PROGRAMS))
	endif
endif