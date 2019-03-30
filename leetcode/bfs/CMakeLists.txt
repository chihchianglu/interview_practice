add_executable(max-area-of-island
        max-area-of-island.cpp
        )
add_custom_target(max-area-of-island_run
        COMMAND max-area-of-island
        )

add_executable(minesweeper
        minesweeper.cpp
        )
add_custom_target(minesweeper_run
        COMMAND minesweeper
        )

add_executable(number-of-islands
        number-of-islands.cpp
        )
add_custom_target(number-of-islands_run
        COMMAND number-of-islands
        )

add_executable(surrounded-regions
        surrounded-regions.cpp
        )
add_custom_target(surrounded-regions_run
        COMMAND surrounded-regions
        )

add_executable(the-maze
        the-maze.cpp
        )
add_custom_target(the-maze_run
        COMMAND the-maze
        )

add_executable(the-maze-ii
        the-maze-ii.cpp
        )
add_custom_target(the-maze-ii_run
        COMMAND the-maze-ii
        )

add_executable(word-ladder
        word-ladder.cpp
        )
add_custom_target(word-ladder_run
        COMMAND word-ladder
        )

add_executable(triggering_run_bfs
        ../triggering_run.cpp
        )

add_dependencies(triggering_run_bfs
        max-area-of-island_run
        minesweeper_run
        number-of-islands_run
        surrounded-regions_run
        the-maze_run
        the-maze-ii_run
        word-ladder_run
        )
