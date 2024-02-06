.PHONY: release
release:
	@meson setup --buildtype=release build/ && meson compile -C build/

.PHONY: debug
debug:
	@meson setup --buildtype=debug build/ && meson compile -C build/

.PHONY: test
test:
	@ninja -C build/ coverage || (echo "Use 'make debug' to generate needed files")

.PHONY: cov
cov:
	@open build/coverage/index.html || (echo "Use 'make test' to generate Gcovr files")

.PHONY: clean
clean:
	@rm -rf build/