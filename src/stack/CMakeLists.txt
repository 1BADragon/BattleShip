set(stack_src
	getSize.c
	makeStack.c
	killStack.c
	pop.c
	push.c
)

add_library(stack ${stack_src})

target_include_directories(stack PUBLIC ${CMAKE_CURRENT_LIST_DIR})