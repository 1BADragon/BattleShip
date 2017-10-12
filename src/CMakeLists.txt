add_subdirectory(stack)

set(project_srcs
	main.c
	checkBoard.c
	computerTurn.c
	placeShip.c
	playerTurn.c
	printBoard.c
	printSym.c
	quitHndl.c
	setUpBoard.c
	shipSymbol.c
	getSizeOfShip.c
	makeHit.c
	killHit.c
	getDelta.c
)

add_executable(BattleShip ${project_srcs})

target_compile_options(BattleShip PRIVATE "-Wall")
target_link_libraries(BattleShip stack)

set_target_properties(BattleShip
	PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
)