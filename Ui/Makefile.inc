
UI_UNIT_TEST  ?=  $(UI_BASE)/unitTest
UI_UI        ?=  $(UI_BASE)/Ui

__DIRECTORY_VARIABLES :=      \
	UI_UNIT_TEST     \
  UI_UI  
          

override UI_BASE         := $(abspath $(UI_BASE))
override UI_UNIT_TEST    := $(abspath $(UI_UNIT_TEST))
override UI_UI           := $(abspath $(UI_UI))


# Ensure that all directories are set and don't contain spaces.
ifneq (, $(filter-out 1, $(foreach v,$(__DIRECTORY_VARIABLES),$(words $($(v))))))
  $(info Aborting compilation for your safety.)
  $(info Related variables = $(__DIRECTORY_VARIABLES))
  $(error Make sure no path override is empty or contains spaces!)
endif

# Use absolute paths in recusive "make" even if overriden on command line.
MAKEOVERRIDES 	         += $(sort $(foreach v,$(__DIRECTORY_VARIABLES),$($(v))))

# include all make file
UI_MAKEFILE  +=	$(foreach sdir, $(MAKEOVERRIDES), $(addprefix $(sdir)/, Makefile))
SUBDIR                  +=	$(foreach sdir, $(MAKEOVERRIDES), $(sdir))
# filter-out
SUBDIR_OUT              :=  $(UI_UNIT_TEST)
# Add include
SUBDIR_MDL              :=  $(filter-out $(SUBDIR_OUT), $(SUBDIR))
MLD_INC                 +=  $(addprefix -I,$(SUBDIR_MDL))
include $(UI_MAKEFILE)