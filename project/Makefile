.PHONY: vendor

JOBS = 4
MAKE = make -j $(JOBS)
SCONS = scons -Q -j $(JOBS)

BUILD_DIR             = build
LOADER_BUILD_DIR = $(BUILD_DIR)/loader

PRODUCTION ?= 0

STLINK_VER ?= v2
OPENOCD = openocd -f interface/stlink-$(STLINK_VER).cfg -c "transport select hla_swd" -f target/stm32f1x.cfg

BOARDLOADER_START   = 0x08000000
BOOTLOADER_START    = 0x08020000
BOARDLOADER_MAXSIZE = 49152
BOOTLOADER_MAXSIZE  = 131072


GITREV=$(shell git describe --always --dirty | tr '-' '_')
CFLAGS += -DGITREV=$(GITREV)

## help commands:

help: ## show this help
	@awk 'BEGIN {FS = ":.*?## "} /^[a-zA-Z0-9_-]+:.*?## / {printf "\033[36m  make %-20s\033[0m %s\n", $$1, $$2} /^##(.*)/ {printf "\033[33m%s\n", substr($$0, 4)}' $(MAKEFILE_LIST)


## build commands:

build: ## build boardloader
	$(SCONS) CFLAGS="$(CFLAGS)" PRODUCTION="$(PRODUCTION)" $(LOADER_BUILD_DIR)/boardloader.bin

## clean commands:

clean: ## clean boardloader build
	rm -rf $(LOADER_BUILD_DIR)


## flash commands:

flash: $(LOADER_BUILD_DIR)/boardloader.bin ## flash boardloader using OpenOCD
	$(OPENOCD) -c "init; reset halt; flash write_image erase $< $(BOARDLOADER_START); exit"

erase: ## erase all sectors in flash bank 0
	$(OPENOCD) -c "init; reset halt; flash info 0; flash erase_sector 0 0 last; flash erase_check 0; exit"

## openocd debug commands:

openocd: ## start openocd which connects to the device
	$(OPENOCD)

reset: ## cause a system reset using OpenOCD
	$(OPENOCD) -c "init; reset; exit"

GDB = arm-none-eabi-gdb --nx -ex 'set remotetimeout unlimited' -ex 'set confirm off' -ex 'target remote 127.0.0.1:3333' -ex 'monitor reset halt'

gdb: $(LOADER_BUILD_DIR)/boardloader.elf ## start remote gdb session to openocd with boardloader symbols
	$(GDB) $<

## misc commands:

sizecheck: ## check sizes of binary files
	test $(BOARDLOADER_MAXSIZE) -ge $(shell wc -c < $(LOADER_BUILD_DIR)/boardloader.bin)
