SDCC=sdcc
SDLD=sdld
OBJECTS=blinky.ihx

.PHONY: all clean flash

all: $(OBJECTS)

clean:
	rm -f $(OBJECTS) *.list *.map *.asm *.sym *.lk *.rst *.cdb *.rel *.lst

flash: $(OBJECTS)
	stm8flash -cstlinkv2 -pstm8s003k3 -w $(OBJECTS)

%.ihx: %.c
	$(SDCC) -lstm8 -mstm8 --out-fmt-ihx $(CFLAGS) $(LDFLAGS) $<
