
.PHONY: build

build:
	thrift --gen cpp thrift/finkel.thrift
