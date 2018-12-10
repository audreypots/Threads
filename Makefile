.PHONY: clean All

All:
	@echo "----------Building project:[ Threads - Debug ]----------"
	@cd "Threads" && "$(MAKE)" -f  "Threads.mk"
clean:
	@echo "----------Cleaning project:[ Threads - Debug ]----------"
	@cd "Threads" && "$(MAKE)" -f  "Threads.mk" clean
