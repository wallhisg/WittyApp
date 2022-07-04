
WIDGET_UNIT_TEST   ?=  $(WIDGET_BASE)/unitTest
WIDGET_WIDGET      ?=  $(WIDGET_BASE)/Widget
WIDGET_DEVICE      ?=  $(WIDGET_BASE)/Device

__DIRECTORY_VARIABLES :=  \
	WIDGET_UNIT_TEST			  \
	WIDGET_WIDGET           \
  WIDGET_DEVICE

override WIDGET_BASE         := $(abspath $(WIDGET_BASE))
override WIDGET_UNIT_TEST    := $(abspath $(WIDGET_UNIT_TEST))
override WIDGET_WIDGET       := $(abspath $(WIDGET_WIDGET))
override WIDGET_DEVICE       := $(abspath $(WIDGET_DEVICE))

# Ensure that all directories are set and don't contain spaces.
ifneq (, $(filter-out 1, $(foreach v,$(__DIRECTORY_VARIABLES),$(words $($(v))))))
  $(info Aborting compilation for your safety.)
  $(info Related variables = $(__DIRECTORY_VARIABLES))
  $(error Make sure no path override is empty or contains spaces!)
endif

# Use absolute paths in recusive "make" even if overriden on command line.
MAKEOVERRIDES 	+= $(sort $(foreach v,$(__DIRECTORY_VARIABLES),$($(v))))

# include all make file
WIDGET_MAKEFILE     +=	$(foreach sdir, $(MAKEOVERRIDES), $(addprefix $(sdir)/, Makefile))
SUBDIR              +=	$(foreach sdir, $(MAKEOVERRIDES), $(sdir))
# filter-out
SUBDIR_OUT          :=  $(WIDGET_UNIT_TEST)
# Add include
SUBDIR_MDL          :=  $(filter-out $(SUBDIR_OUT), $(SUBDIR))
MLD_INC             +=  $(addprefix -I,$(SUBDIR_MDL))
include $(WIDGET_MAKEFILE)
