# Make as a task manager to run cmake to run make.
SRC=$(wildcard src/*.cpp)
WASM=build/wasm.html
NATIVE=build-native/native

.PHONY: all
all: $(WASM) $(NATIVE)

# Build WebAssembly and load in Python Webserver
.PHONY: wasm
wasm: $(WASM)
	python3 -m http.server --directory build > build/server.log 2>&1 & echo $$! > build/server.pid
	@ echo "Server running at http://localhost:8000"

# Stop the server
.PHONY: stop-server
stop-server:
	@if [ -f build/server.pid ]; then \
	    echo "Stopping server..."; \
	    kill $$(cat build/server.pid) && rm -f build/server.pid; \
	else \
	    echo "No server is running."; \
	fi

# Build Native and execute
.PHONY: native
native: $(NATIVE)
	$(NATIVE)

$(WASM): $(SRC)
	mkdir -p build
	cd build && cmake .. -DCMAKE_TOOLCHAIN_FILE=${EMSCRIPTEN}/cmake/Modules/Platform/Emscripten.cmake
	cd build && make

$(NATIVE): $(SRC)
	mkdir -p build-native
	cd build-native && cmake ../native
	cd build-native && make

.PHONY: clean
clean:
	@ echo "Cleaning up build directories..."
	@ rm -rf ./build ./build-native ./logs

.PHONY: clean-all
clean-all: stop-server clean
	@ echo "All cleaned up!"
