
PRJ_UNIT_TEST   ?=  $(PRJ_BASE)/unitTest
PRJ_LAYOUT      ?=  $(PRJ_BASE)/Layout

__DIRECTORY_VARIABLES :=   \
	PRJ_UNIT_TEST            \
	PRJ_LAYOUT               


override PRJ_BASE         := $(abspath $(PRJ_BASE))
override PRJ_UNIT_TEST    := $(abspath $(PRJ_UNIT_TEST))
override PRJ_LAYOUT       := $(abspath $(PRJ_LAYOUT))

# Ensure that all directories are set and don't contain spaces.
ifneq (, $(filter-out 1, $(foreach v,$(__DIRECTORY_VARIABLES),$(words $($(v))))))
  $(info Aborting compilation for your safety.)
  $(info Related variables = $(__DIRECTORY_VARIABLES))
  $(error Make sure no path override is empty or contains spaces!)
endif

# Use absolute paths in recusive "make" even if overriden on command line.
MAKEOVERRIDES 	+= $(sort $(foreach v,$(__DIRECTORY_VARIABLES),$($(v))))

# include all make file
PRJ_CLIENT_MAKEFILE 	+=	$(foreach sdir, $(MAKEOVERRIDES), $(addprefix $(sdir)/, Makefile))
SUBDIR                +=	$(foreach sdir, $(MAKEOVERRIDES), $(sdir))
# filter-out
SUBDIR_OUT            :=  $(PRJ_UNIT_TEST)
# Add include
SUBDIR_MDL            :=  $(filter-out $(SUBDIR_OUT), $(SUBDIR))
MLD_INC               +=  $(addprefix -I,$(SUBDIR_MDL))
include $(PRJ_CLIENT_MAKEFILE)
