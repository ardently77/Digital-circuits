CSRC=csrc/*.cpp
VSRC=vsrc/*.v

sim:
	$(call git_commit, "sim RTL")

run:
	verilator -Wall --trace -cc $(VSRC) --exe $(CSRC)
	make -C obj_dir -f Vtop.mk Vtop
	./obj_dir/Vtop

clean:
	rm -rf obj_dir

include ~/ysyx/ysyx-workbench/Makefile
