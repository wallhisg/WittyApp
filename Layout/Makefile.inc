
LAYOUT_UNIT_TEST  ?=  $(LAYOUT_BASE)/unitTest
LAYOUT_LAYOUT     ?=  $(LAYOUT_BASE)/Layout
LAYOUT_UI         ?=  $(LAYOUT_BASE)/Ui

__DIRECTORY_VARIABLES :=    \
	LAYOUT_UNIT_TEST          \
	LAYOUT_LAYOUT             \
  LAYOUT_UI                 

override LAYOUT_BASE        := $(abspath $(LAYOUT_BASE))
override LAYOUT_UNIT_TEST   := $(abspath $(LAYOUT_UNIT_TEST))
override LAYOUT_LAYOUT      := $(abspath $(LAYOUT_LAYOUT))
override LAYOUT_UI          := $(abspath $(LAYOUT_UI))

# Ensure that all directories are set and don't contain spaces.
ifneq (, $(filter-out 1, $(foreach v,$(__DIRECTORY_VARIABLES),$(words $($(v))))))
  $(info Aborting compilation for your safety.)
  $(info Related variables = $(__DIRECTORY_VARIABLES))
  $(error Make sure no path override is empty or contains spaces!)
endif

# Use absolute paths in recusive "make" even if overriden on command line.
MAKEOVERRIDES 	+= $(sort $(foreach v,$(__DIRECTORY_VARIABLES),$($(v))))

# include all make file
LAYOUT_CLIENT_MAKEFILE 	+=	$(foreach sdir, $(MAKEOVERRIDES), $(addprefix $(sdir)/, Makefile))
SUBDIR                +=	$(foreach sdir, $(MAKEOVERRIDES), $(sdir))
# filter-out
SUBDIR_OUT            :=  $(LAYOUT_UNIT_TEST)
# Add include
SUBDIR_MDL            :=  $(filter-out $(SUBDIR_OUT), $(SUBDIR))
MLD_INC               +=  $(addprefix -I,$(SUBDIR_MDL))
include $(LAYOUT_CLIENT_MAKEFILE)
