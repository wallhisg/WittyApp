
DEVICE_UNIT_TEST   ?=  $(DEVICE_BASE)/unitTest
DEVICE_DEVICE      ?=  $(DEVICE_BASE)/Device

__DIRECTORY_VARIABLES :=  \
	DEVICE_UNIT_TEST			  \
  DEVICE_DEVICE

override DEVICE_BASE         := $(abspath $(DEVICE_BASE))
override DEVICE_UNIT_TEST    := $(abspath $(DEVICE_UNIT_TEST))
override DEVICE_DEVICE       := $(abspath $(DEVICE_DEVICE))

# Ensure that all directories are set and don't contain spaces.
ifneq (, $(filter-out 1, $(foreach v,$(__DIRECTORY_VARIABLES),$(words $($(v))))))
  $(info Aborting compilation for your safety.)
  $(info Related variables = $(__DIRECTORY_VARIABLES))
  $(error Make sure no path override is empty or contains spaces!)
endif

# Use absolute paths in recusive "make" even if overriden on command line.
MAKEOVERRIDES 	+= $(sort $(foreach v,$(__DIRECTORY_VARIABLES),$($(v))))

# include all make file
DEVICE_MAKEFILE     +=	$(foreach sdir, $(MAKEOVERRIDES), $(addprefix $(sdir)/, Makefile))
SUBDIR              +=	$(foreach sdir, $(MAKEOVERRIDES), $(sdir))
# filter-out
SUBDIR_OUT          :=  $(DEVICE_UNIT_TEST)
# Add include
SUBDIR_MDL          :=  $(filter-out $(SUBDIR_OUT), $(SUBDIR))
MLD_INC             +=  $(addprefix -I,$(SUBDIR_MDL))
include $(DEVICE_MAKEFILE)
