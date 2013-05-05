
UNAME=$(shell uname)
ifeq ($(findstring MINGW32_NT, $(UNAME)),)
	THRIFT="thrift"
else
	SHELL=/c/Windows/System32/cmd.exe
	THRIFT="thrift-0.7.0.exe"
endif

THRIFT_CLIENT_OUT="client/lib/gen-js"
THRIFT_SERVER_OUT="server/lib/gen-cpp"


.PHONY: build clean


build: clean
	mkdir $(THRIFT_SERVER_OUT)
	$(THRIFT) --gen cpp -r -out $(THRIFT_SERVER_OUT) thrift/finkel.thrift
	mkdir $(THRIFT_CLIENT_OUT)
	$(THRIFT) --gen js -r -out $(THRIFT_CLIENT_OUT) thrift/finkel.thrift


clean:
	rm -rf $(THRIFT_SERVER_OUT)
	rm -rf $(THRIFT_CLIENT_OUT)

