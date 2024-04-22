Q := $(if $(filter 1,$(V) $(VERBOSE)),,@)
MAKE := make $(if $(filter 1,$(V) $(VERBOSE)),,--no-print-directory)
GIT_REMOTE_URL := git@vogsphere.42adel.org.au:vogsphere/intra-uuid-79300c28-e1c3-4950-bfa6-ca1fd9558bfb-5603274-hyunski2

all: test

clean:
	$Qrm -rf ./tmp
	$Q$(MAKE) -C src clean
	$Q$(MAKE) -C test clean
fclean: clean
	$Q$(MAKE) -C src fclean
	$Q$(MAKE) -C test fclean
re:
	$Q$(MAKE) -C src fclean
	$Q$(MAKE) test
test:
	$Q$(MAKE) -C src
	$Q$(MAKE) -C test

run: test
	./test/test.a

publish_without_test:
ifndef GIT_REMOTE_URL
	$(error GIT_REMOTE_URL is undefined)
endif
	$Qcp -r ./src ./tmp
	$Q$(MAKE) -C tmp fclean
	$Qprintf "# script-generated file list\nSRCS := %s\n\n" "$$(cd src && find . -name "*.c" | cut -c 3- | xargs)" | cat - src/Makefile > tmp/Makefile
	$Q(cd tmp && git init && git add . && git commit -m "Initial commit" && git push $(GIT_REMOTE_URL) HEAD:master)
	$Qrm -rf tmp
	$Qgit push $(GIT_REMOTE_URL) HEAD:source || echo "Failed to push HEAD to source"
publish: test publish_without_test
.PHONY: all clean fclean re test publish publish_without_test

#"$(GIT_REMOTE_URL)"
