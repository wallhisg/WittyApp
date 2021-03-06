
PRJ_UNIT_TEST   ?=  $(PRJ_BASE)/unitTest
PRJ_SERVER      ?=  $(PRJ_BASE)/Server
PRJ_CLIENT      ?=  $(PRJ_BASE)/Client
PRJ_DEVICE      ?=  $(PRJ_BASE)/Device
PRJ_APPLICATION ?=  $(PRJ_BASE)/Application
PRJ_WIDGET      ?=  $(PRJ_BASE)/ServerWidget

__DIRECTORY_VARIABLES :=  \
 	PRJ_SERVER              \
 	PRJ_CLIENT              \
  PRJ_DEVICE              \
  PRJ_APPLICATION         \
	PRJ_WIDGET              \
	PRJ_UNIT_TEST			


override PRJ_BASE         := $(abspath $(PRJ_BASE))
override PRJ_UNIT_TEST    := $(abspath $(PRJ_UNIT_TEST))
override PRJ_SERVER       := $(abspath $(PRJ_SERVER))
override PRJ_CLIENT       := $(abspath $(PRJ_CLIENT))
override PRJ_DEVICE       := $(abspath $(PRJ_DEVICE))
override PRJ_APPLICATION  := $(abspath $(PRJ_APPLICATION))
override PRJ_WIDGET       := $(abspath $(PRJ_WIDGET))

# Ensure that all directories are set and don't contain spaces.
ifneq (, $(filter-out 1, $(foreach v,$(__DIRECTORY_VARIABLES),$(words $($(v))))))
  $(info Aborting compilation for your safety.)
  $(info Related variables = $(__DIRECTORY_VARIABLES))
  $(error Make sure no path override is empty or contains spaces!)
endif

# Use absolute paths in recusive "make" even if overriden on command line.
MAKEOVERRIDES 	+= $(sort $(foreach v,$(__DIRECTORY_VARIABLES),$($(v))))

# include all make file
PRJ_MAKEFILE    +=	$(foreach sdir, $(MAKEOVERRIDES), $(addprefix $(sdir)/, Makefile))
SUBDIR          +=	$(foreach sdir, $(MAKEOVERRIDES), $(sdir))
# filter-out
SUBDIR_OUT      :=  $(PRJ_UNIT_TEST)
# Add include
SUBDIR_MDL      :=  $(filter-out $(SUBDIR_OUT), $(SUBDIR))

MLD_INC         +=  $(addprefix -I,$(SUBDIR_MDL))
include $(PRJ_MAKEFILE)