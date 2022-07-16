
WEB_SERVER_UNIT_TEST      ?=  $(WEB_SERVER_BASE)/unitTest
WEB_SERVER_SERVER         ?=  $(WEB_SERVER_BASE)/Server
WEB_SERVER_CLIENT         ?=  $(WEB_SERVER_BASE)/Client
WEB_SERVER_WRESOURCE      ?=  $(WEB_SERVER_BASE)/WResource
WEB_SERVER_DEVICE_EVENT   ?=  $(WEB_SERVER_BASE)/DeviceEvent
WEB_SERVER_WIDGET         ?=  $(WEB_SERVER_BASE)/ServerWidget

__DIRECTORY_VARIABLES :=          \
 	WEB_SERVER_SERVER               \
 	WEB_SERVER_CLIENT               \
  WEB_SERVER_WRESOURCE            \
  WEB_SERVER_DEVICE_EVENT         \
	WEB_SERVER_WIDGET               \
	WEB_SERVER_UNIT_TEST			

override WEB_SERVER_BASE         := $(abspath $(WEB_SERVER_BASE))
override WEB_SERVER_UNIT_TEST    := $(abspath $(WEB_SERVER_UNIT_TEST))
override WEB_SERVER_SERVER       := $(abspath $(WEB_SERVER_SERVER))
override WEB_SERVER_CLIENT       := $(abspath $(WEB_SERVER_CLIENT))
override WEB_SERVER_WRESOURCE    := $(abspath $(WEB_SERVER_WRESOURCE))
override WEB_SERVER_DEVICE_EVENT := $(abspath $(WEB_SERVER_DEVICE_EVENT))
override WEB_SERVER_WIDGET       := $(abspath $(WEB_SERVER_WIDGET))

# Ensure that all directories are set and don't contain spaces.
ifneq (, $(filter-out 1, $(foreach v,$(__DIRECTORY_VARIABLES),$(words $($(v))))))
  $(info Aborting compilation for your safety.)
  $(info Related variables = $(__DIRECTORY_VARIABLES))
  $(error Make sure no path override is empty or contains spaces!)
endif

# Use absolute paths in recusive "make" even if overriden on command line.
MAKEOVERRIDES 	+= $(sort $(foreach v,$(__DIRECTORY_VARIABLES),$($(v))))

# include all make file
WEB_SERVER_MAKEFILE    +=	$(foreach sdir, $(MAKEOVERRIDES), $(addprefix $(sdir)/, Makefile))
SUBDIR          +=	$(foreach sdir, $(MAKEOVERRIDES), $(sdir))
# filter-out
SUBDIR_OUT      :=  $(WEB_SERVER_UNIT_TEST)
# Add include
SUBDIR_MDL      :=  $(filter-out $(SUBDIR_OUT), $(SUBDIR))

MLD_INC         +=  $(addprefix -I,$(SUBDIR_MDL))
include $(WEB_SERVER_MAKEFILE)