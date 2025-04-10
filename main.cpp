import Common;
import Chunk;
import Debug;
import Vm;

#include <glog/logging.h>
#include <print>
#include <array>
#include <fstream>
#include <sstream>

void repl() {
	std::string line;
	line.reserve(1024);
	for (;;) {
		std::print("> ");
		if (!fgets(line.data(), sizeof(line), stdin)){
			std::print("\n");
			break;
		}

		interpret(line);
	}
}

static std::string readFile(const char* path) {
	std::ifstream in(path);
	return {(std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>()};
}

void runFile(const char* path) {
  std::string source = readFile(path);
  InterpretResult result = interpret(source);

  if (result == INTERPRET_COMPILE_ERROR) exit(65);
  if (result == INTERPRET_RUNTIME_ERROR) exit(70);
}

int main(int argc, char* argv[]) {
	google::InitGoogleLogging(argv[0]);
	FLAGS_logtostdout = true;
	if (argc == 1) {
		repl();
	} else if (argc == 2) {
		runFile(argv[1]);
	} else {
		std::print(stderr, "Usage: clox [path]\n");
		exit(64);
	}
	return 0;
}