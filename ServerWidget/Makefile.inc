
SERVER_WIDGET_UNIT_TEST  ?=  $(SERVER_WIDGET_BASE)/unitTest
SERVER_WIDGET_UI         ?=  $(SERVER_WIDGET_BASE)/Ui

__DIRECTORY_VARIABLES :=    \
	SERVER_WIDGET_UNIT_TEST          \
  SERVER_WIDGET_UI

override SERVER_WIDGET_BASE        := $(abspath $(SERVER_WIDGET_BASE))
override SERVER_WIDGET_UNIT_TEST   := $(abspath $(SERVER_WIDGET_UNIT_TEST))
override SERVER_WIDGET_UI          := $(abspath $(SERVER_WIDGET_UI))

# Ensure that all directories are set and don't contain spaces.
ifneq (, $(filter-out 1, $(foreach v,$(__DIRECTORY_VARIABLES),$(words $($(v))))))
  $(info Aborting compilation for your safety.)
  $(info Related variables = $(__DIRECTORY_VARIABLES))
  $(error Make sure no path override is empty or contains spaces!)
endif

# Use absolute paths in recusive "make" even if overriden on command line.
MAKEOVERRIDES 	+= $(sort $(foreach v,$(__DIRECTORY_VARIABLES),$($(v))))

# include all make file
SERVER_WIDGET_CLIENT_MAKEFILE 	+=	$(foreach sdir, $(MAKEOVERRIDES), $(addprefix $(sdir)/, Makefile))
SUBDIR                +=	$(foreach sdir, $(MAKEOVERRIDES), $(sdir))
# filter-out
SUBDIR_OUT            :=  $(SERVER_WIDGET_UNIT_TEST)
# Add include
SUBDIR_MDL            :=  $(filter-out $(SUBDIR_OUT), $(SUBDIR))
MLD_INC               +=  $(addprefix -I,$(SUBDIR_MDL))
include $(SERVER_WIDGET_CLIENT_MAKEFILE)
