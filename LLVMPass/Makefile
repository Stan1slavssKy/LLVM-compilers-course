pass:
	clang++ pass_cfg.cpp -c -fPIC -I`llvm-config --includedir` -o pass.o

shared_logger:
	clang log.c -c -fPIC -o log.o

lib_pass: pass
	clang++ pass.o -fPIC -shared -o lib_pass.so

app: lib_pass
	clang ../GameOfLife/app.cpp -c -o app.o -Xclang -load -Xclang ./lib_pass.so -O2

trace: app shared_logger
	clang++ ../GameOfLife/game_of_life.cpp log.o app.o ../GameOfLife/build/grlib/libgraph-lib.a -lsfml-graphics -lsfml-window -lsfml-system -o trace.out

run_with_pass: trace
	./trace.out > insn.trace

build_chart:
	python3 trace_analizer.py

create_ll_dump: lib_pass
	clang ../GameOfLife/app.cpp -c -S -emit-llvm -Xclang -load -Xclang ./lib_pass.so -O2

clean:
	rm -rf *.o *.out *.so *.trace *.ll
