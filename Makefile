
THRIFT_CLIENT_OUT="client/lib/gen-js"
THRIFT_SERVER_OUT="server/lib/gen-cpp"
UNAME=$(shell uname)
ifeq ($(findstring MINGW32_NT, $(UNAME)),)
	THRIFT="thrift"
else
	SHELL=/c/Windows/System32/cmd.exe
	THRIFT="thrift-0.7.0.exe"
endif


.PHONY: build build-client build-server clean clean-client clean-server

build: build-client build-server

build-client: clean-client
	mkdir $(THRIFT_CLIENT_OUT)
	$(THRIFT) --gen js:node -r -out $(THRIFT_CLIENT_OUT) thrift/finkel.thrift
	cd client && npm install

build-server: clean-server
	mkdir $(THRIFT_SERVER_OUT)
	$(THRIFT) --gen cpp -r -out $(THRIFT_SERVER_OUT) thrift/finkel.thrift

clean: clean-client clean-server

clean-client:
	rm -rf $(THRIFT_CLIENT_OUT)

clean-server:
	rm -rf $(THRIFT_SERVER_OUT)
