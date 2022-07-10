
APPLICATION_UNIT_TEST   ?=  $(APPLICATION_BASE)/unitTest
APPLICATION             ?=  $(APPLICATION_BASE)/Application

__DIRECTORY_VARIABLES :=      \
	APPLICATION_UNIT_TEST			  \
	APPLICATION

override APPLICATION_BASE         := $(abspath $(APPLICATION_BASE))
override APPLICATION_UNIT_TEST    := $(abspath $(APPLICATION_UNIT_TEST))
override APPLICATION              := $(abspath $(APPLICATION))

# Ensure that all directories are set and don't contain spaces.
ifneq (, $(filter-out 1, $(foreach v,$(__DIRECTORY_VARIABLES),$(words $($(v))))))
  $(info Aborting compilation for your safety.)
  $(info Related variables = $(__DIRECTORY_VARIABLES))
  $(error Make sure no path override is empty or contains spaces!)
endif

# Use absolute paths in recusive "make" even if overriden on command line.
MAKEOVERRIDES 	+= $(sort $(foreach v,$(__DIRECTORY_VARIABLES),$($(v))))

# include all make file
APPLICATION_MAKEFILE     +=	$(foreach sdir, $(MAKEOVERRIDES), $(addprefix $(sdir)/, Makefile))
SUBDIR              +=	$(foreach sdir, $(MAKEOVERRIDES), $(sdir))
# filter-out
SUBDIR_OUT          :=  $(APPLICATION_UNIT_TEST)
# Add include
SUBDIR_MDL          :=  $(filter-out $(SUBDIR_OUT), $(SUBDIR))
MLD_INC             +=  $(addprefix -I,$(SUBDIR_MDL))
include $(APPLICATION_MAKEFILE)
