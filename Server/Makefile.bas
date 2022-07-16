
# ifeq ($(BFLAG),$(filter $(BFLAG),$(BF_BUILD) $(BF_NOT_BUILD)))
ifneq ($(BF_NOT_USE), $(BFLAG))
	# BF_NOT_INC
	ifeq ($(BF_NOT_INC), $(BFLAG))

	else ifeq ($(BF_NOT_BUILD), $(BFLAG))
		
	# BF_BUILD && BF_NOT_BUILD
	else ifeq ($(BF_BUILD), $(BFLAG))
		# add module path
		MDL_PATH	+= $(WEB_SERVER_LOCAL_MDL)
		MDL_PATH	:= $(sort $(MDL_PATH))
		# add include
		MLD_INC		+= $(addprefix -I,$(MDL_PATH))
		MLD_INC		:= $(sort $(MLD_INC))
		# dep
		WEB_SERVER_DEP		+=	$(WEB_SERVER_LOCAL_DEP)
		WEB_SERVER_DEP		:=	$(sort $(WEB_SERVER_DEP))
		# object
		WEB_SERVER_OBJ 	+=	$(WEB_SERVER_LOCAL_OBJ_C)
		WEB_SERVER_OBJ 	+=	$(WEB_SERVER_LOCAL_OBJ_CPP)
		WEB_SERVER_OBJ		:=	$(sort $(WEB_SERVER_OBJ))
		ifeq ($(BF_BUILD), $(BFLAG))
			WEB_SERVER_BUILD_DIR	+=	$(LOCAL_BUILD_DIR)
			WEB_SERVER_BUILD_DIR	:=	$(sort $(WEB_SERVER_BUILD_DIR))
		endif
	else ifeq ($(BF_TEST), $(BFLAG))
		# dep
		WEB_SERVER_DEP			+=	$(WEB_SERVER_LOCAL_DEP)
		WEB_SERVER_DEP			:=	$(sort $(WEB_SERVER_DEP))
		# build directory
		WEB_SERVER_BUILD_DIR	+=	$(LOCAL_BUILD_DIR)
		WEB_SERVER_BUILD_DIR	:=	$(sort $(WEB_SERVER_BUILD_DIR))
		# programs
		PROGRAMS		+=	$(PROGRAM)
		PROGRAMS		:=	$(sort $(PROGRAMS))
	endif
endif